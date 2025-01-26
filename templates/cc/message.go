package cc

const messageTpl = `
	{{ $f := .Field }}{{ $r := .Rules }}
	{{ template "required" . }}
	{{ if .MessageRules.GetSkip }}
		// skipping validation for {{ $f.Name }}
    {{ else if .MessageRules.GetCustomValidate }}
		if ({{ hasAccessor .}} && !pgv::BaseValidator::CustomCheckMessage({{ topParent . }}, {{ parent . }}, {{ accessor . }}, err)) {
            if (err) { err->embedded(); }
			{{ errCause . "err" "embedded message failed validation" }}
		}
    {{ else }}
	{
		if ({{ hasAccessor .}} && !pgv::BaseValidator::AbstractCheckMessage({{ topParent . }}, {{ accessor . }}, err)) {
            if (err) { err->embedded(); }
			{{ errCause . "err" "embedded message failed validation" }}
		}
	}
	{{ end }}
`

const requiredTpl = `
	{{ if .Rules.GetRequired }}
		if (!{{ hasAccessor . }}) {
			{{ err . "value is required" }}
		}
	{{ end }}
`
