#!/bin/bash -xe

if [[ -z "$PROTOC_BIN" ]]; then
    echo "Set \$PROTOC_BIN to the protoc to use"
    exit 1
fi

./local_build.sh

pushd test_proto
$PROTOC_BIN  --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" smurf.proto validate/validate.proto

autoformat --no-backup generated/smurf.pb.validate.cpp || true

LIBS=""
for LIB in $(find ../protobuf/third_party/abseil-cpp/install -iname "lib*absl*.a"); do
    P=$(basename $LIB)
    LIBS="$LIBS -l${P:3:-2}"
done

time g++ -g -std=c++20 -c main.cpp ../cpp/validate/validate.cpp generated/smurf.pb.cc generated/smurf.pb.validate.cpp generated/validate/validate.pb.cc -I generated/ -I ../cpp -I ../protobuf/src -I ../protobuf/third_party/abseil-cpp

time g++ -o main *.o -L ../protobuf/build/ -L ../protobuf/third_party/abseil-cpp/install/lib -L ../protobuf/build/third_party/utf8_range -Wl,--start-group -lprotobuf -lutf8_range -lutf8_validity $LIBS -Wl,--end-group
./main
popd
