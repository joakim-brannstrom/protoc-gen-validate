package cc

const declTpl = `
{{ if not (ignored .) -}}

{{ if disabled . -}}
/// Validate is disabled.
/// @return Always return true.
{{- else -}}
/// Checks the field values against the rules defined in the proto definition.
/// @return If any rules are violated return false and an error message is written to the logger
[[nodiscard]] bool validate(const {{ class . }}& m, pgv::ValidationLog* err = nullptr);

/// @overload
[[nodiscard]] bool validate(const google::protobuf::Message& topParent, const {{ class . }}& m, pgv::ValidationLog* err = nullptr);
{{- end -}}
{{- end -}}
`

const msgTpl = `
{{ if not (ignored .) -}}
{{ if disabled . -}}
	{{ cmt "Validate is disabled for " (class .) ". This method will always return true." }}
{{- else -}}
	{{ cmt "Validate checks on " (class .) "." }}
{{- end -}}

{{ range .Fields }}{{ with (context .) }}{{ $f := .Field }}
	{{ if has .Rules "In" }}{{ if .Rules.In }}
	const std::set<{{ inType .Field .Rules.In }}> {{ lookup .Field "InLookup" }} = {
			{{- range .Rules.In }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}

	{{ if has .Rules "NotIn" }}{{ if .Rules.NotIn }}
	const std::set<{{ inType .Field .Rules.NotIn }}> {{ lookup .Field "NotInLookup" }} = {
			{{- range .Rules.NotIn }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}

	{{ if has .Rules "Items"}}{{ if .Rules.Items }}
	{{ if has .Rules.Items.GetString_ "In" }} {{ if .Rules.Items.GetString_.In }}
	const std::set<string> {{ lookup .Field "InLookup" }} = {
			{{- range .Rules.Items.GetString_.In }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Items.GetEnum "In" }} {{ if .Rules.Items.GetEnum.In }}
	const std::set<{{ inType .Field .Rules.Items.GetEnum.In }}> {{ lookup .Field "InLookup" }} = {
			{{- range .Rules.Items.GetEnum.In }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Items.GetAny "In" }} {{ if .Rules.Items.GetAny.In }}
	const std::set<string> {{ lookup .Field "InLookup" }} = {
			{{- range .Rules.Items.GetAny.In }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ end }}{{ end }}

	{{ if has .Rules "Items"}}{{ if .Rules.Items }}
	{{ if has .Rules.Items.GetString_ "NotIn" }} {{ if .Rules.Items.GetString_.NotIn }}
	const std::set<string> {{ lookup .Field "NotInLookup" }} = {
			{{- range .Rules.Items.GetString_.NotIn }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Items.GetEnum "NotIn" }} {{ if .Rules.Items.GetEnum.NotIn }}
	const std::set<{{ inType .Field .Rules.Items.GetEnum.NotIn }}> {{ lookup .Field "NotInLookup" }} = {
			{{- range .Rules.Items.GetEnum.NotIn }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Items.GetAny "NotIn" }} {{ if .Rules.Items.GetAny.NotIn }}
	const std::set<string> {{ lookup .Field "NotInLookup" }} = {
			{{- range .Rules.Items.GetAny.NotIn }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ end }}{{ end }}
        {{ if has .Rules "Pattern"}}{{ if .Rules.Pattern }}
            // no validation rules for {{ .Field.Name }} = "{{ .Rules.Pattern }}"
	{{ end }}{{ end }}

	{{ if has .Rules "Items"}}{{ if .Rules.Items }}
        {{ if has .Rules.Items.GetString_ "Pattern" }} {{ if .Rules.Items.GetString_.Pattern }}
            // no validation rules for {{ .Field.Name }} = "{{ .Rules.Pattern }}"
            {{ unimplemented "Regexp matchning is not implemented" }}
	{{ end }}{{ end }}
        {{ end }}{{ end }}

	{{ if has .Rules "Keys"}}{{ if .Rules.Keys }}
	{{ if has .Rules.Keys.GetString_ "In" }} {{ if .Rules.Keys.GetString_.In }}
	const std::set<string> {{ lookup .Field "InLookup" }} = {
			{{- range .Rules.Keys.GetString_.In }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Keys.GetString_ "NotIn" }} {{ if .Rules.Keys.GetString_.NotIn }}
	const std::set<string> {{ lookup .Field "NotInLookup" }} = {
			{{- range .Rules.Keys.GetString_.NotIn }}
				{{ inKey $f . }},
			{{- end }}
		};
	{{ end }}{{ end }}
	{{ if has .Rules.Keys.GetString_ "Pattern" }} {{ if .Rules.Keys.GetString_.Pattern }}
        // no validation rules for {{ .Field.Name }} = "{{ .Rules.Pattern }}"
        {{ unimplemented "Regexp matchning is not implemented" }}
	{{ end }}{{ end }}
	{{ end }}{{ end }}

	{{ if has .Rules "Values"}}{{ if .Rules.Values }}
	{{ if has .Rules.Values.GetString_ "Pattern" }} {{ if .Rules.Values.GetString_.Pattern }}
        // no validation rules for {{ .Field.Name }} = "{{ .Rules.Pattern }}"
        {{ unimplemented "Regexp matchning is not implemented" }}
	{{ end }}{{ end }}
	{{ end }}{{ end }}

{{ end }}{{ end }}

bool validate(const {{ class . }}& m, pgv::ValidationLog* err) {
    return validate(m, m, err);
}

bool validate(const google::protobuf::Message& topParent, const {{ class . }}& m, pgv::ValidationLog* err) {
	(void)m;
	(void)err;
{{- if disabled . }}
	return true;
{{ else -}}
    if (err && !err->isActive()) {
        err = nullptr;
    }

		{{ range .NonOneOfFields }}
			{{- render (context .) -}}
		{{ end -}}
		{{ range .SyntheticOneOfFields }}
            {{ render (context .) }}
		{{ end }}
		{{ range .RealOneOfs }}
			switch (m.{{ .Name }}_case()) {
				{{ range .Fields -}}
					case {{ oneof . }}:
						{{ render (context .) }}
						break;
				{{ end -}}
					default:
				{{- if required . }}
						*err = "field: " {{ .Name | quote | lit }} ", reason: is required";
						return false;
				{{ end }}
					break;
			}
		{{ end }}
	return true;
{{ end -}}
}
{{- end -}}
`
