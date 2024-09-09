#include "smurf.pb.validate.hpp"
#include <iostream>

bool customCheck(const google::protobuf::Message& parent_, const examplepb::Person::Location& loc, pgv::ValidationLog* err) {
    std::cout << "custom called\n";
    if (const auto* parent = dynamic_cast<const examplepb::Person*>(&parent_); parent) {
        std::cout << "running custom check\n";
        return parent->id() > loc.lat();
    }
    return true;
}

pgv::CustomValidator<examplepb::Person::Location> registerCustomCheck(static_cast<bool (*)(const google::protobuf::Message& parent, const examplepb::Person::Location& loc, pgv::ValidationLog* err)>(customCheck));

int main(int argc, char **argv) {
    examplepb::Person person;
    person.set_id(1000);
    person.mutable_home()->set_lat(10.0);
    person.mutable_home()->set_lng(-10.0);
    person.mutable_amsg();

    pgv::BasicValidationLog log;
    std::cout << examplepb::validate(person, &log) << "\n";
    return 0;
}
