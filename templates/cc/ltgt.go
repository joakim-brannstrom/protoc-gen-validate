package cc

const ltgtTpl = `{{ $f := .Field }}{{ $r := .Rules }}{{ $v := (accessor .) }}
	//| GteExpr is {{ $r.GteExpr }} |
	//| smurf {{ getGte $r }} |
	//{{ if getGte $r }}
	//	{{ getGte $r }}
	//{{ end }}
	{{ if $r.Lt }}
		{{ if $r.Gt }}
            if ({{ $v }} <= {{ $r.Gt }} || {{ $v }} >= {{ $r.Lt }}) {
                {{ err . "value must be inside range (" $r.GetGt ", " $r.GetLt ")" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ getGte $r }} || {{ $v }} >= {{ $r.Lt }}) {
                {{ err . "value must be inside range [" getGte $r ", " $r.GetLt ")" }}
            }
		{{ else }}
			if ({{ accessor . }} >= {{ $r.Lt }}) {
				{{ err . "value must be less than " $r.GetLt }}
			}
		{{ end }}
	{{ else if $r.Lte }}
		{{ if $r.Gt }}
            if ({{ $v }} <= {{ $r.Gt }} || {{ $v }} > {{ $r.Lte }}) {
                {{ err . "value must be inside range (" $r.GetGt ", " $r.GetLte "]" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ $r.Gte }} || {{ $v }} > {{ $r.Lte }}) {
                {{ err . "value must be inside range [" $r.GetGte ", " $r.GetLte "]" }}
            }
		{{ else }}
			if ({{ accessor . }} > {{ $r.Lte }}) {
				{{ err . "value must be less than or equal to " $r.GetLte }}
			}
		{{ end }}
	{{ else if $r.Gt }}
		if ({{ accessor . }} <= {{ $r.Gt }}) {
			{{ err . "value must be greater than " $r.GetGt }}
		}
	{{ else if getGte $r }}
		if ({{ accessor . }} < {{ getGte $r }}) {
			{{ err . "value must be greater than or equal to " (getGte $r) }}
		}
	{{ end }}
`
