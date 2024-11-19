package shared

import (
	"text/template"

	pgs "github.com/vaidehi-figma/protoc-gen-star"
)

func RegisterFunctions(tpl *template.Template, params pgs.Parameters) {
	tpl.Funcs(map[string]interface{}{
		"disabled":  Disabled,
		"ignored":   Ignored,
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
