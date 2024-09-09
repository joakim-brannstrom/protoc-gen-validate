// Code generated by protoc-gen-validate
// source: smurf.proto
// DO NOT EDIT!!!

#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

#include "validate/validate.h"
#include "smurf.pb.h"


namespace examplepb {

using std::string;


extern bool validate(const ::examplepb::Person& m);
extern bool validate(const ::examplepb::Person& m, pgv::ValidationLog* err);

extern bool validate(const ::examplepb::Person_Location& m);
extern bool validate(const ::examplepb::Person_Location& m, pgv::ValidationLog* err);


} // namespace


#define X_EXAMPLEPB_SMURF(X) \
X(::examplepb::Person) \
X(::examplepb::Person_Location) \
