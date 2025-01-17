package cc

const ltgtTpl = `{{ $f := .Field }}{{ $r := .Rules }}{{ $v := (accessor .) }}
	//| GteExpr is {{ $r.GteExpr }} |
	//| smurf {{ getGte $r }} |
	//{{ if getGte $r }}
	//	{{ getGte $r }}
	//{{ end }}
	{{ if $r.Lt }}
		{{ if getGt $r }}
            if ({{ $v }} <= {{ getGt $r }} || {{ $v }} >= {{ $r.Lt }}) {
                {{ err . "value must be inside range (" (getGt $r) ", " $r.GetLt ")" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ getGte $r }} || {{ $v }} >= {{ $r.Lt }}) {
                {{ err . "value must be inside range [" (getGte $r) ", " $r.GetLt ")" }}
            }
		{{ else }}
			if ({{ accessor . }} >= {{ $r.Lt }}) {
				{{ err . "value must be less than " $r.GetLt }}
			}
		{{ end }}
	{{ else if $r.Lte }}
		{{ if getGt $r }}
            if ({{ $v }} <= {{ getGt $r }} || {{ $v }} > {{ $r.Lte }}) {
                {{ err . "value must be inside range (" (getGt $r) ", " $r.GetLte "]" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ getGte $r }} || {{ $v }} > {{ $r.Lte }}) {
                {{ err . "value must be inside range [" (getGte $r) ", " $r.GetLte "]" }}
            }
		{{ else }}
			if ({{ accessor . }} > {{ $r.Lte }}) {
				{{ err . "value must be less than or equal to " $r.GetLte }}
			}
		{{ end }}
	{{ else if getGt $r }}
		if ({{ accessor . }} <= {{ getGt $r }}) {
			{{ err . "value must be greater than " (getGt $r) }}
		}
	{{ else if getGte $r }}
		if ({{ accessor . }} < {{ getGte $r }}) {
			{{ err . "value must be greater than or equal to " (getGte $r) }}
		}
	{{ end }}
`
