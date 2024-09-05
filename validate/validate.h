#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "google/protobuf/message.h"

namespace pgv {
using std::string;

class UnimplementedException : public std::runtime_error {
public:
  UnimplementedException() : std::runtime_error("not yet implemented") {}
  UnimplementedException(const std::string& message) : std::runtime_error(message) {}
  // Thrown by C++ validation code that is not yet implemented.
};

using ValidationMsg = std::string;

class ValidationLog {
public:
    /// Called one or more times to build up an error message.
    virtual void log(const std::string_view& v) = 0;

    /// An embedded message is done with its error logging.
    virtual void embedded() = 0;

    // Compilation of an error message done.
    virtual void done() = 0;
};

class BasicValidationLog : public ValidationLog {
public:
    BasicValidationLog() = default;
    BasicValidationLog(const BasicValidationLog &other) = default;
    BasicValidationLog(BasicValidationLog&&) = default;
    BasicValidationLog& operator=(const BasicValidationLog &other) = default;
    BasicValidationLog& operator=(BasicValidationLog &&other) noexcept = default;
    virtual ~BasicValidationLog() = default;

    void log(const std::string_view& v) override {
        std::cout << v;
    }

    void done() override {
        std::cout << "\n";
    }

    void embedded() override {
        std::cout << " | parent: ";
    }
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
  static bool AbstractCheckMessage(const google::protobuf::Message& m, ValidationLog* err);

protected:
  // Used to implement AbstractCheckMessage() above. Every message that is linked into the binary
  // will register itself by type_index, allowing for polymorphic lookup later.
  static std::unordered_map<std::type_index,
                            std::function<bool(const google::protobuf::Message&, ValidationLog*)>>&
  abstractValidators();
};

template <typename T> class Validator : public BaseValidator {
public:
  Validator(std::function<bool(const T&, ValidationLog*)> check) : check_(check) {
    abstractValidators()[std::type_index(typeid(T))] = [this](const google::protobuf::Message& m,
                                                              ValidationLog* err) -> bool {
      return check_(dynamic_cast<const T&>(m), err);
    };
  }

private:
  std::function<bool(const T&, ValidationLog*)> check_;
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

int UTF8FirstLetterNumBytes(const char *utf8_str, int str_len);

size_t Utf8Len(const string& narrow_string);

} // namespace pgv
