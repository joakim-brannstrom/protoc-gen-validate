To update the go protobuf generated code you need the go protobuf generator "protoc-gen-go".

Then run the following command:
```sh
protoc -I. --go_out=. validate.proto 
cp github.com/envoyproxy/protoc-gen-validate/validate/validate.pb.go validate.pb.go
```
