#!/bin/bash -xe

if [[ -z "$PROTOC_BIN" ]]; then
    echo "Set \$PROTOC_BIN to the protoc to use"
    exit 1
fi
if [[ -z "$PROTOBUF_SRC" ]]; then
    echo "Set \$PROTOBUF_SRC to where the c++ headers are installed"
    exit 1
fi
if [[ -z "$PROTOBUF_LIB" ]]; then
    echo "Set \$PROTOBUF_LIB to where the libs are installed"
    exit 1
fi

./local_build.sh

pushd test_proto
mkdir -p generated
$PROTOC_BIN  --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" smurf.proto
#$PROTOC_BIN  --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" validate/validate.proto

autoformat --no-backup generated/smurf.pb.validate.cpp || true

LIBS=""
for LIB in $(find "$PROTOBUF_LIB" -iname "lib*absl*.a"); do
    P=$(basename $LIB)
    LIBS="$LIBS -l${P:3:-2}"
done

time g++ -g -std=c++20 -c main.cpp ../cpp/validate/validate.cpp generated/smurf.pb.cc generated/smurf.pb.validate.cpp generated/validate/validate.pb.cc -I generated/ -I ../cpp -I "$PROTOBUF_SRC" -I ../protobuf/third_party/abseil-cpp

time g++ -o main *.o -L $PROTOBUF_LIB -Wl,--start-group -lprotobuf -lutf8_range -lutf8_validity $LIBS -Wl,--end-group
./main
popd
