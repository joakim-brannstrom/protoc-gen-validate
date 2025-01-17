package cc

const ltgtTpl = `{{ $f := .Field }}{{ $r := .Rules }}{{ $v := (accessor .) }}
	{{ if getLt $r }}
		{{ if getGt $r }}
            if ({{ $v }} <= {{ getGt $r }} || {{ $v }} >= {{ getLt $r }}) {
                {{ err . "value must be inside range (" (getGt $r) ", " (getLt $r) ")" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ getGte $r }} || {{ $v }} >= {{ getLt $r }}) {
                {{ err . "value must be inside range [" (getGte $r) ", " (getLt $r) ")" }}
            }
		{{ else }}
			if ({{ accessor . }} >= {{ getLt $r }}) {
				{{ err . "value must be less than " (getLt $r) }}
			}
		{{ end }}
	{{ else if getLte $r }}
		{{ if getGt $r }}
            if ({{ $v }} <= {{ getGt $r }} || {{ $v }} > {{ getLte $r }}) {
                {{ err . "value must be inside range (" (getGt $r) ", " (getLte $r) "]" }}
            }
		{{ else if getGte $r }}
            if ({{ $v }} < {{ getGte $r }} || {{ $v }} > {{ getLte $r }}) {
                {{ err . "value must be inside range [" (getGte $r) ", " (getLte $r) "]" }}
            }
		{{ else }}
			if ({{ accessor . }} > {{ getLte $r }}) {
				{{ err . "value must be less than or equal to " (getLte $r) }}
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
