package main

import (
	pgs "github.com/vaidehi-figma/protoc-gen-star"
	pgsgo "github.com/vaidehi-figma/protoc-gen-star/lang/go"
	"google.golang.org/protobuf/types/pluginpb"

	"github.com/envoyproxy/protoc-gen-validate/module"
)

func main() {
    supportedFeatures := uint64(pluginpb.CodeGeneratorResponse_FEATURE_PROTO3_OPTIONAL) | uint64(pluginpb.CodeGeneratorResponse_FEATURE_SUPPORTS_EDITIONS)
    minimumEdition := int32(2023)
	maximumEdition := int32(2024)
	pgs.
		Init(pgs.DebugEnv("DEBUG_PGV"),
            pgs.SupportedFeatures(&supportedFeatures),
            pgs.MinimumEdition(&minimumEdition),
            pgs.MaximumEdition(&maximumEdition)).
		RegisterModule(module.Validator()).
		RegisterPostProcessor(pgsgo.GoFmt()).
		Render()
}
