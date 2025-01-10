#include "smurf.pb.validate.hpp"
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

bool customCheck(const google::protobuf::Message& topParent_, const google::protobuf::Message& parent_, const examplepb::Person::Location& loc, pgv::ValidationLog* err) {
    std::cout << "custom called\n";
    if (const auto* parent = dynamic_cast<const examplepb::Person*>(&parent_); parent) {
        std::cout << "running custom check\n";
        return parent->id() > loc.lat();
    }
    return true;
}

//pgv::CustomValidator<examplepb::Person::Location> registerCustomCheck(static_cast<bool (*)(const google::protobuf::Message&,const google::protobuf::Message&, const examplepb::Person::Location& loc, pgv::ValidationLog* err)>(customCheck));
pgv::CustomValidator<examplepb::Person::Location> registerCustomCheck(&customCheck);

int main(int argc, char **argv) {
    examplepb::Person person;
    person.set_id(1000);
    person.mutable_home()->set_lat(10.0);
    person.mutable_home()->set_lng(-1000.0);
    person.mutable_amsg();

    BasicValidationLog log;
    std::cout << examplepb::validate(person, &log) << "\n";
    return 0;
}
