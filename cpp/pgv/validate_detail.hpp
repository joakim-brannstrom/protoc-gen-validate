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
#include "pgv/validate.hpp"

namespace pgv {
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

static inline std::string String(const std::string& msg) { return std::string(msg); }

static inline bool IsPrefix(const std::string& maybe_prefix, const std::string& search_in) {
    return search_in.starts_with(maybe_prefix);
}

static inline bool IsSuffix(const std::string& maybe_suffix, const std::string& search_in) {
    return search_in.ends_with(maybe_suffix);
}

static inline bool Contains(const std::string& search_in, const std::string& to_find) {
    return search_in.contains(to_find);
}

static inline bool NotContains(const std::string& search_in, const std::string& to_find) {
    return !Contains(search_in, to_find);
}

int OneCharLen(const char* src);

int UTF8FirstLetterNumBytes(const char* utf8_str, int str_len);

size_t Utf8Len(const std::string& narrow_string);

} // namespace pgv
