#pragma once

#include <functional>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "google/protobuf/message.h"

namespace pgv {
using std::string;

using ValidationMsg = std::string;

class ValidationLog {
public:
    /// Called one or more times to build up an error message.
    virtual void log(const std::string_view& v) = 0;

    /// An embedded message is done with its error logging.
    virtual void embedded() = 0;

    /// An index value in a repeated field.
    virtual void index(int i) = 0;

    /// Compilation of an error message done.
    virtual void done() = 0;

    /// The logger is activated.
    /// A logger that returns false will never be called when a message fail
    /// validation.
    virtual bool isActive() = 0;
};

class BaseValidator {
public:
    /**
     * Validate/check a generic message object with a registered validator for the concrete message
     * type.
     * @param m supplies the message to check.
     * @param err supplies the place to return error information.
     * @return true if the validation passes OR there is no registered validator for the concrete
     *         message type. false is returned if validation explicitly fails.
     */
    static bool AbstractCheckMessage(const google::protobuf::Message& topParent,
                                     const google::protobuf::Message& m, ValidationLog* err);

    /**
     * Validate/check a generic message object with a custom registered validator
     * for the concrete message type.
     * @param m supplies the parent message to check.
     * @param m supplies the message to check.
     * @param err supplies the place to return error information.
     * @return true if the validation passes OR there is no registered validator for the concrete
     *         message type. false is returned if validation explicitly fails.
     */
    static bool CustomCheckMessage(const google::protobuf::Message& topParent,
                                   const google::protobuf::Message& parent,
                                   const google::protobuf::Message& m, ValidationLog* err);

protected:
    // Used to implement AbstractCheckMessage() above. Every message that is linked into the binary
    // will register itself by type_index, allowing for polymorphic lookup later.
    static std::unordered_map<
        std::type_index, std::function<bool(const google::protobuf::Message&,
                                            const google::protobuf::Message&, ValidationLog*)>>&
    abstractValidators();

    static std::unordered_map<
        std::type_index,
        std::function<bool(const google::protobuf::Message&, const google::protobuf::Message&,
                           const google::protobuf::Message&, ValidationLog*)>>&
    customValidators();
};

template <typename T> class Validator : public BaseValidator {
public:
    Validator(
        std::function<bool(const google::protobuf::Message& topParent, const T&, ValidationLog*)>
            check)
        : check_(check) {
        abstractValidators()[std::type_index(typeid(T))] =
            [this](const google::protobuf::Message& topParent, const google::protobuf::Message& m,
                   ValidationLog* err) -> bool {
            return check_(topParent, dynamic_cast<const T&>(m), err);
        };
    }

private:
    std::function<bool(const google::protobuf::Message& topParent, const T&, ValidationLog*)>
        check_;
};

template <typename T> class CustomValidator : public BaseValidator {
public:
    template<typename Fn>
    CustomValidator(Fn fn) : check_(fn) {
        customValidators()[std::type_index(typeid(T))] =
            [this](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const google::protobuf::Message& m,
                   ValidationLog* err) -> bool {
            return check_(topParent, parent, dynamic_cast<const T&>(m), err);
        };
    }

    CustomValidator(std::function<bool(const T&, ValidationLog*)> check) {
        check_ = [check = std::move(check)](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const T& m,
                   ValidationLog* err) -> bool {
            return check(m, err);
        };

        customValidators()[std::type_index(typeid(T))] =
            [this](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const google::protobuf::Message& m,
                   ValidationLog* err) -> bool {
            return check_(topParent, parent, dynamic_cast<const T&>(m), err);
        };
    }
    CustomValidator(std::function<bool(const google::protobuf::Message&, const T&, ValidationLog*)> check) {
        check_ = [check = std::move(check)](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const T& m,
                   ValidationLog* err) -> bool {
            return check(parent, m, err);
        };

        customValidators()[std::type_index(typeid(T))] =
            [this](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const google::protobuf::Message& m,
                   ValidationLog* err) -> bool {
            return check_(topParent, parent, dynamic_cast<const T&>(m), err);
        };
    }
    CustomValidator(std::function<bool(const google::protobuf::Message&,
                                       const google::protobuf::Message&, const T&, ValidationLog*)>
                        check)
        : check_(check) {
        customValidators()[std::type_index(typeid(T))] =
            [this](const google::protobuf::Message& topParent,
                   const google::protobuf::Message& parent, const google::protobuf::Message& m,
                   ValidationLog* err) -> bool {
            return check_(topParent, parent, dynamic_cast<const T&>(m), err);
        };
    }

private:
    std::function<bool(const google::protobuf::Message& topParent,
                       const google::protobuf::Message& parent, const T&, ValidationLog*)>
        check_;
};

static inline std::string String(const ValidationMsg& msg) { return std::string(msg); }

static inline bool IsPrefix(const string& maybe_prefix, const string& search_in) {
    return search_in.compare(0, maybe_prefix.size(), maybe_prefix) == 0;
}

static inline bool IsSuffix(const string& maybe_suffix, const string& search_in) {
    return maybe_suffix.size() <= search_in.size() &&
           search_in.compare(search_in.size() - maybe_suffix.size(), maybe_suffix.size(),
                             maybe_suffix) == 0;
}

static inline bool Contains(const string& search_in, const string& to_find) {
    return search_in.find(to_find) != string::npos;
}

static inline bool NotContains(const string& search_in, const string& to_find) {
    return !Contains(search_in, to_find);
}

int OneCharLen(const char* src);

int UTF8FirstLetterNumBytes(const char* utf8_str, int str_len);

size_t Utf8Len(const string& narrow_string);

} // namespace pgv
