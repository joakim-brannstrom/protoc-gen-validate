#pragma once

#include "custom.pb.validate.h"

namespace custom_validate {
bool validate(const google::protobuf::Message& topParent, const ::custom::Outside& m, pgv::ValidationLog* err = nullptr);
}

namespace pgv {
[[nodiscard]] static inline bool validate(const ::custom::Outside& m, pgv::ValidationLog* err = nullptr) {
    return custom_validate::validate(m, m, err);
}
}
