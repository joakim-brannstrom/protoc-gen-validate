package cc

const enumTpl = `
		{{ $f := .Field }}{{ $r := .Rules }}
        {{ template "required" . }}
		{{ template "const" . }}
		{{ template "in" . }}

		{{ if $r.GetDefinedOnly }}
			{{ if or $f.Type.IsRepeated $f.Type.IsMap }}
				if (!{{ class $f.Type.Element.Enum }}_IsValid({{ accessor . }})) {
			{{ else }}
				if (!{{ class $f.Type.Enum }}_IsValid({{ accessor . }})) {
			{{ end }}
				{{ err . "value must be one of the defined enum values" }}
			}
		{{ end }}
`
