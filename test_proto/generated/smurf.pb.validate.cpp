// Code generated by protoc-gen-validate
// source: smurf.proto
// DO NOT EDIT!!!

#include "smurf.pb.validate.hpp"

#include <google/protobuf/message.h>
#include <google/protobuf/util/time_util.h>

namespace pgv {

namespace protobuf = google::protobuf;
namespace protobuf_wkt = google::protobuf;

namespace validate {
using std::string;

pgv::Validator<::examplepb::Person> validator___examplepb__Person(
    static_cast<bool (*)(const ::examplepb::Person&, pgv::ValidationLog*)>(::examplepb::validate));
pgv::Validator<::examplepb::Person_Location> validator___examplepb__Person_Location(
    static_cast<bool (*)(const ::examplepb::Person_Location&, pgv::ValidationLog*)>(
        ::examplepb::validate));

} // namespace validate
} // namespace pgv

namespace examplepb {

// Validate checks the field values on ::examplepb::Person with the rules
// defined in the proto definition for this message. If any rules are
// violated, the return value is false and an error message is written to the
// input string argument.

const std::set<MyEnum> _Person_Aenum_InLookup = {
    MyEnum(0),
};

bool validate(const ::examplepb::Person& m) { return validate(m, nullptr); }

bool validate(const ::examplepb::Person& m, pgv::ValidationLog* err) {
    (void)m;
    (void)err;

    if (m.id() <= 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Id"
                                     ": "
                                     "value must be greater than 999";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_home()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Home"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    {
        if (m.has_home() && !pgv::BaseValidator::AbstractCheckMessage(m.home(), err)) {
            if (err) {
                err->embedded();
            }
            {
                if (err) {
                    const char* errMsg = "PersonValidationError"
                                         "."
                                         "Home"
                                         ": "
                                         "embedded message failed validation";
                    err->log(errMsg);
                    err->done();
                }
                return false;
            }
        }
    }

    if (!m.has_auint64()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Auint64"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.auint64() <= 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Auint64"
                                     ": "
                                     "value must be greater than 999";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_aint64()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aint64"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.aint64() <= 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aint64"
                                     ": "
                                     "value must be greater than 999";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_auint32()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Auint32"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.auint32() <= 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Auint32"
                                     ": "
                                     "value must be greater than 999";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_aint32()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aint32"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.aint32() <= 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aint32"
                                     ": "
                                     "value must be greater than 999";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_astring()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Astring"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.astring().size() > 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Astring"
                                     ": "
                                     "value length must be at most 999 bytes";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_abytes()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Abytes"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.abytes().size() > 999) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Abytes"
                                     ": "
                                     "value length must be at most 999 bytes";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (!m.has_aenum()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aenum"
                                     ": "
                                     "value is required";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (_Person_Aenum_InLookup.find(static_cast<decltype(_Person_Aenum_InLookup)::key_type>(
            m.aenum())) == _Person_Aenum_InLookup.end()) {
        {
            if (err) {
                const char* errMsg = "PersonValidationError"
                                     "."
                                     "Aenum"
                                     ": "
                                     "value must be in list [foo]";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    return true;
}

// Validate checks the field values on ::examplepb::Person_Location with the
// rules defined in the proto definition for this message. If any rules are
// violated, the return value is false and an error message is written to the
// input string argument.

bool validate(const ::examplepb::Person_Location& m) { return validate(m, nullptr); }

bool validate(const ::examplepb::Person_Location& m, pgv::ValidationLog* err) {
    (void)m;
    (void)err;

    if (m.lat() < -90 || m.lat() > 90) {
        {
            if (err) {
                const char* errMsg = "LocationValidationError"
                                     "."
                                     "Lat"
                                     ": "
                                     "value must be inside range [-90, 90]";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    if (m.lng() < -180 || m.lng() > 180) {
        {
            if (err) {
                const char* errMsg = "LocationValidationError"
                                     "."
                                     "Lng"
                                     ": "
                                     "value must be inside range [-180, 180]";
                err->log(errMsg);
                err->done();
            }
            return false;
        }
    }

    return true;
}

} // namespace examplepb
