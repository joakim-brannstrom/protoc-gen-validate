package shared

import (
	pgs "github.com/joakim-brannstrom/protoc-gen-star"

	"github.com/joakim-brannstrom/protoc-gen-validate/validate"
)

// Disabled returns true if validations are disabled for msg
func Disabled(msg pgs.Message) (disabled bool, err error) {
	_, err = msg.Extension(validate.E_Disabled, &disabled)
	return
}

// Ignore returns true if validations aren't to be generated for msg
func Ignored(msg pgs.Message) (ignored bool, err error) {
	_, err = msg.Extension(validate.E_Ignored, &ignored)
	return
}

// RequiredOneOf returns true if the oneof field requires a field to be set
func RequiredOneOf(oo pgs.OneOf) (required bool, err error) {
	_, err = oo.Extension(validate.E_Required, &required)
	return
}


func CustomRegister(msg pgs.Message) (custom_register bool, err error) {
	_, err = msg.Extension(validate.E_CustomRegister, &custom_register)
    return
}
