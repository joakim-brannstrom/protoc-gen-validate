package shared

import (
	"text/template"

	pgs "github.com/joakim-brannstrom/protoc-gen-star"
)

func RegisterFunctions(tpl *template.Template, params pgs.Parameters) {
	tpl.Funcs(map[string]interface{}{
		"disabled":  Disabled,
		"ignored":   Ignored,
        "custom_validate": CustomValidate,
		"required":  RequiredOneOf,
		"context":   rulesContext,
		"render":    Render(tpl),
		"has":       Has,
		"needs":     Needs,
		"fileneeds": FileNeeds,
		"isEnum":    isEnum,
		"enumList":  enumList,
		"enumVal":   enumVal,
	})
}
