#include "pgv/validate.hpp"

namespace pgv {

bool BaseValidator::AbstractCheckMessage(const google::protobuf::Message& topParent,
                                         const google::protobuf::Message& m, ValidationLog* err) {
    // Polymorphic lookup is used to see if there is a matching concrete validator. If so, call it.
    // Otherwise return success.
    auto it = abstractValidators().find(std::type_index(typeid(m)));
    if (it == abstractValidators().end()) {
        return true;
    }
    return it->second(topParent, m, err);
}

bool BaseValidator::CustomCheckMessage(const google::protobuf::Message& topParent,
                                       const google::protobuf::Message& parent,
                                       const google::protobuf::Message& m, ValidationLog* err) {
    // Polymorphic lookup is used to see if there is a matching concrete validator. If so, call it.
    // Otherwise return success.
    auto it = customValidators().find(std::type_index(typeid(m)));
    if (it == customValidators().end()) {
        return false;
    }
    return it->second(topParent, parent, m, err);
}

std::unordered_map<std::type_index,
                   std::function<bool(const google::protobuf::Message&,
                                      const google::protobuf::Message&, ValidationLog*)>>&
BaseValidator::abstractValidators() {
    static auto* validator_map = new std::unordered_map<
        std::type_index, std::function<bool(const google::protobuf::Message&,
                                            const google::protobuf::Message&, ValidationLog*)>>();
    return *validator_map;
}

std::unordered_map<
    std::type_index,
    std::function<bool(const google::protobuf::Message&, const google::protobuf::Message&,
                       const google::protobuf::Message&, ValidationLog*)>>&
BaseValidator::customValidators() {
    static auto* validator_map = new std::unordered_map<
        std::type_index,
        std::function<bool(const google::protobuf::Message&, const google::protobuf::Message&,
                           const google::protobuf::Message&, ValidationLog*)>>();
    return *validator_map;
}

int OneCharLen(const char* src) { return "\1\1\1\1\1\1\1\1\1\1\1\1\2\2\3\4"[(*src & 0xFF) >> 4]; }

int UTF8FirstLetterNumBytes(const char* utf8_str, int str_len) {
    if (str_len == 0)
        return 0;
    return OneCharLen(utf8_str);
}

size_t Utf8Len(const string& narrow_string) {
    const char* str_char = narrow_string.c_str();
    ptrdiff_t byte_len = narrow_string.length();
    size_t unicode_len = 0;
    int char_len = 1;
    while (byte_len > 0 && char_len > 0) {
        char_len = UTF8FirstLetterNumBytes(str_char, byte_len);
        str_char += char_len;
        byte_len -= char_len;
        ++unicode_len;
    }
    return unicode_len;
}

} // namespace pgv
