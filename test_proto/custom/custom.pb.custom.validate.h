#pragma once

#include "custom.pb.validate.h"

namespace pgv {
bool validate(const ::custom::Outside& m, pgv::ValidationLog* err = nullptr);
}
