#include <iostream>
#include "custom.pb.custom.validate.h"

namespace custom_validate {
bool validate(const google::protobuf::Message& topParent, const ::custom::Outside& m, pgv::ValidationLog* err) {
    std::cout << "custom check called\n";
    return ::custom::validate(topParent, m, err);
}
}
