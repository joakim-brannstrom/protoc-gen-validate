package main

import (
	pgs "github.com/vaidehi-figma/protoc-gen-star"
	pgsgo "github.com/vaidehi-figma/protoc-gen-star/lang/go"
	"google.golang.org/protobuf/types/pluginpb"

	"github.com/envoyproxy/protoc-gen-validate/module"
)

func main() {
	optional := uint64(pluginpb.CodeGeneratorResponse_FEATURE_PROTO3_OPTIONAL)
	pgs.
		Init(pgs.DebugEnv("DEBUG_PGV"), pgs.SupportedFeatures(&optional)).
		RegisterModule(module.Validator()).
		RegisterPostProcessor(pgsgo.GoFmt()).
		Render()
}
