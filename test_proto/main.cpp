#include "smurf.pb.validate.h"
#include <iostream>

int main(int argc, char **argv) {
    examplepb::Person person;
    person.set_id(1000);
    person.mutable_home()->set_lat(10.0);
    person.mutable_home()->set_lng(-1000.0);

    pgv::BasicValidationLog log;
    std::cout << examplepb::validate(person, &log) << "\n";
    return 0;
}
