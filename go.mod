module github.com/envoyproxy/protoc-gen-validate

go 1.19

require (
	github.com/iancoleman/strcase v0.3.0
	//github.com/vaidehi-figma/protoc-gen-star v1.0.1-0.20240827145011-84f66dcdf8b83b5b1cb2435d4cba27e87f370562
	github.com/vaidehi-figma/protoc-gen-star v1.0.2
	golang.org/x/net v0.28.0
	google.golang.org/protobuf v1.34.2
)

require (
	github.com/spf13/afero v1.11.0 // indirect
	github.com/vaidehi-figma/protoc-gen-star v1.0.2 // indirect
	golang.org/x/mod v0.17.0 // indirect
	golang.org/x/text v0.17.0 // indirect
	golang.org/x/tools v0.21.1-0.20240508182429-e35e4ccd0d2d // indirect
)

retract [v0.6.9, v0.6.12] // Published accidentally
