package main

import (
	pgs "github.com/joakim-brannstrom/protoc-gen-star"
	pgsgo "github.com/joakim-brannstrom/protoc-gen-star/lang/go"
	"google.golang.org/protobuf/types/pluginpb"
    "google.golang.org/protobuf/types/descriptorpb"

	"github.com/joakim-brannstrom/protoc-gen-validate/module"
)

func main() {
    supportedFeatures := uint64(pluginpb.CodeGeneratorResponse_FEATURE_PROTO3_OPTIONAL) | uint64(pluginpb.CodeGeneratorResponse_FEATURE_SUPPORTS_EDITIONS)
    minimumEdition := int32(descriptorpb.Edition_EDITION_PROTO3)
	maximumEdition := int32(descriptorpb.Edition_EDITION_2023)
	pgs.
		Init(pgs.DebugEnv("DEBUG_PGV"),
            pgs.SupportedFeatures(&supportedFeatures),
            pgs.MinimumEdition(&minimumEdition),
            pgs.MaximumEdition(&maximumEdition)).
		RegisterModule(module.Validator()).
		RegisterPostProcessor(pgsgo.GoFmt()).
		Render()
}
