#!/bin/bash -xe

pushd ..
~/tmp/download/bazel/bazelisk-linux-amd64 build protoc-gen-validate --sandbox_debug
popd

protoc --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" smurf.proto validate/validate.proto

# mv generated/smurf.pb.validate.cc generated/smurf.pb.validate.cpp

autoformat --no-backup generated/smurf.pb.validate.cpp

diff generated/smurf.pb.validate.cpp generated/smurf.pb.validate_blipp3.cpp || true

time g++ -g -std=c++20 -o main main.cpp validate/validate.cpp generated/smurf.pb.cc generated/smurf.pb.validate.cpp generated/validate/validate.pb.cc -I generated/ -I .. -lprotobuf
./main
