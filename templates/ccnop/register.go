package ccnop

import (
	"text/template"

	pgs "github.com/joakim-brannstrom/protoc-gen-star"

	"github.com/joakim-brannstrom/protoc-gen-validate/templates/cc"
)

func RegisterModule(tpl *template.Template, params pgs.Parameters) {
	cc.RegisterModule(tpl, params)
	template.Must(tpl.Parse(moduleFileTpl))
}

func RegisterHeader(tpl *template.Template, params pgs.Parameters) {
	cc.RegisterHeader(tpl, params)
	template.Must(tpl.Parse(headerFileTpl))
}
