#include "smurf.pb.validate.h"
#include "custom.pb.validate.h"
#include "custom.pb.custom.validate.h"
#include <iostream>

class BasicValidationLog : public pgv::ValidationLog {
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

    void index(int i) override {
        std::cout << "i=" << i;
    }

    void done() override {
        std::cout << "\n";
    }

    void embedded() override {
        std::cout << " | parent: ";
    }

    bool isActive() override {
        return true;
    }
};

bool customCheck(const google::protobuf::Message& topParent_, const google::protobuf::Message& parent_, const examplepb::inner::Person::Location& loc, pgv::ValidationLog* err) {
    std::cout << "custom called\n";
    if (const auto* parent = dynamic_cast<const examplepb::inner::Person*>(&parent_); parent) {
        std::cout << "running custom check\n";
        return parent->id() > loc.lat();
    }
    return true;
}

pgv::CustomValidator<examplepb::inner::Person::Location> register__customCheck__inner__person(&customCheck);

int main(int argc, char **argv) {
    BasicValidationLog log;
    {
        examplepb::inner::Person person;
        person.set_id(1000);
        person.mutable_home()->set_lat(10.0);
        person.mutable_home()->set_lng(-1000.0);
        person.mutable_amsg();
        std::cout << pgv::validate(person, &log) << "\n";
    }
    {
        custom::Outside outside;
        std::cout << pgv::validate(outside, &log) << "\n";
        std::cout << pgv::validate(*outside.mutable_amsg(), &log) << "\n";
    }
    return 0;
}
