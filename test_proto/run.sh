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

pushd validate
rm -rf github.com
$PROTOC_BIN -I. --go_out=. validate.proto
cp github.com/envoyproxy/protoc-gen-validate/validate/validate.pb.go validate.pb.go
popd

./local_build.sh
export PATH=$PWD:$PATH

pushd test_proto
mkdir -p generated
$PROTOC_BIN  --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" validate/validate.proto

for FILE in $(ls *.proto); do
    $PROTOC_BIN  --proto_path=. --cpp_out=generated --validate_out="lang=cc:./generated" $FILE
done
for FILE in $(ls generated/*.validate.cc); do
    clang-format $FILE > $FILE.tmp
    mv $FILE.tmp $FILE
done

time g++ -g -std=c++23 -c main.cpp -I custom -I generated/ -I ../cpp -I "$PROTOBUF_SRC"

for FILE in $(ls generated/*.cc custom/*.cpp); do
    time g++ -g -std=c++23 -o $FILE.o -c $FILE -I generated/ -I custom -I ../cpp -I "$PROTOBUF_SRC"
done

time g++ -g -std=c++23 -c ../cpp/pgv/validate_detail.cpp -I ../cpp -I "$PROTOBUF_SRC"
time g++ -g -std=c++23 -c generated/validate/validate.pb.cc -I generated/ -I ../cpp -I "$PROTOBUF_SRC"

set +x
LIBS=""
for LIB in $(find "$PROTOBUF_LIB" -iname "lib*absl*.a"); do
    P=$(basename $LIB)
    LIBS="$LIBS -l${P:3:-2}"
done
set -x

time g++ -o main *.o generated/*.o -L $PROTOBUF_LIB -Wl,--start-group -lprotobuf -lutf8_range -lutf8_validity $LIBS -Wl,--end-group
./main
popd
