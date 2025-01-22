#include <iostream>
#include "custom.pb.custom.validate.h"

namespace {
pgv::Validator<::custom::Outside> validator___custom__Outside(static_cast<bool(*)(const google::protobuf::Message&, const ::custom::Outside&, pgv::ValidationLog*)>(::custom::validate));
}

namespace pgv {
bool validate(const ::custom::Outside& m, pgv::ValidationLog* err) {
    std::cout << "custom check called\n";
    return ::custom::validate(m, err);
}
}
