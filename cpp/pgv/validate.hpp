/*
 * This file is licensed under the Apache License, Version 2.0.
 * See http://www.apache.org/licenses/LICENSE-2.0 for details.
 */
#pragma once

#include <functional>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "google/protobuf/message.h"

namespace pgv {
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
     * If err is the nullptr then no logging when validation rule is violated is done.
     * @param topParent supplies the top parent of message m.
     * @param parent supplies the direct parent message of message m.
     * @param m supplies the message to check.
     * @param err supplies the place to return error information, can be nullptr.
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

} // namespace pgv
