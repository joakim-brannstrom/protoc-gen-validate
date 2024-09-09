// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: smurf.proto

#include "smurf.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace examplepb {
PROTOBUF_CONSTEXPR Person_Location::Person_Location(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.lat_)*/0
  , /*decltype(_impl_.lng_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct Person_LocationDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Person_LocationDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Person_LocationDefaultTypeInternal() {}
  union {
    Person_Location _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Person_LocationDefaultTypeInternal _Person_Location_default_instance_;
PROTOBUF_CONSTEXPR Person::Person(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.home_)*/nullptr
  , /*decltype(_impl_.id_)*/uint64_t{0u}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace examplepb
static ::_pb::Metadata file_level_metadata_smurf_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_smurf_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_smurf_2eproto = nullptr;

const uint32_t TableStruct_smurf_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::examplepb::Person_Location, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::examplepb::Person_Location, _impl_.lat_),
  PROTOBUF_FIELD_OFFSET(::examplepb::Person_Location, _impl_.lng_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::examplepb::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::examplepb::Person, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::examplepb::Person, _impl_.home_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::examplepb::Person_Location)},
  { 8, -1, -1, sizeof(::examplepb::Person)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::examplepb::_Person_Location_default_instance_._instance,
  &::examplepb::_Person_default_instance_._instance,
};

const char descriptor_table_protodef_smurf_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013smurf.proto\022\texamplepb\032\027validate/valid"
  "ate.proto\"\252\001\n\006Person\022\024\n\002id\030\001 \001(\004B\010\372B\0052\003 "
  "\347\007\0222\n\004home\030\004 \001(\0132\032.examplepb.Person.Loca"
  "tionB\010\372B\005\212\001\002\020\001\032V\n\010Location\022$\n\003lat\030\001 \001(\001B"
  "\027\372B\024\022\022\031\000\000\000\000\000\200V@)\000\000\000\000\000\200V\300\022$\n\003lng\030\002 \001(\001B\027\372"
  "B\024\022\022\031\000\000\000\000\000\200f@)\000\000\000\000\000\200f\300b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_smurf_2eproto_deps[1] = {
  &::descriptor_table_validate_2fvalidate_2eproto,
};
static ::_pbi::once_flag descriptor_table_smurf_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_smurf_2eproto = {
    false, false, 230, descriptor_table_protodef_smurf_2eproto,
    "smurf.proto",
    &descriptor_table_smurf_2eproto_once, descriptor_table_smurf_2eproto_deps, 1, 2,
    schemas, file_default_instances, TableStruct_smurf_2eproto::offsets,
    file_level_metadata_smurf_2eproto, file_level_enum_descriptors_smurf_2eproto,
    file_level_service_descriptors_smurf_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_smurf_2eproto_getter() {
  return &descriptor_table_smurf_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_smurf_2eproto(&descriptor_table_smurf_2eproto);
namespace examplepb {

// ===================================================================

class Person_Location::_Internal {
 public:
};

Person_Location::Person_Location(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:examplepb.Person.Location)
}
Person_Location::Person_Location(const Person_Location& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person_Location* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.lat_){}
    , decltype(_impl_.lng_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.lat_, &from._impl_.lat_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.lng_) -
    reinterpret_cast<char*>(&_impl_.lat_)) + sizeof(_impl_.lng_));
  // @@protoc_insertion_point(copy_constructor:examplepb.Person.Location)
}

inline void Person_Location::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.lat_){0}
    , decltype(_impl_.lng_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Person_Location::~Person_Location() {
  // @@protoc_insertion_point(destructor:examplepb.Person.Location)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Person_Location::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Person_Location::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person_Location::Clear() {
// @@protoc_insertion_point(message_clear_start:examplepb.Person.Location)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.lat_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.lng_) -
      reinterpret_cast<char*>(&_impl_.lat_)) + sizeof(_impl_.lng_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person_Location::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double lat = 1 [(.validate.rules) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          _impl_.lat_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double lng = 2 [(.validate.rules) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _impl_.lng_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person_Location::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:examplepb.Person.Location)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double lat = 1 [(.validate.rules) = {
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lat = this->_internal_lat();
  uint64_t raw_lat;
  memcpy(&raw_lat, &tmp_lat, sizeof(tmp_lat));
  if (raw_lat != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(1, this->_internal_lat(), target);
  }

  // double lng = 2 [(.validate.rules) = {
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lng = this->_internal_lng();
  uint64_t raw_lng;
  memcpy(&raw_lng, &tmp_lng, sizeof(tmp_lng));
  if (raw_lng != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_lng(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:examplepb.Person.Location)
  return target;
}

size_t Person_Location::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:examplepb.Person.Location)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double lat = 1 [(.validate.rules) = {
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lat = this->_internal_lat();
  uint64_t raw_lat;
  memcpy(&raw_lat, &tmp_lat, sizeof(tmp_lat));
  if (raw_lat != 0) {
    total_size += 1 + 8;
  }

  // double lng = 2 [(.validate.rules) = {
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lng = this->_internal_lng();
  uint64_t raw_lng;
  memcpy(&raw_lng, &tmp_lng, sizeof(tmp_lng));
  if (raw_lng != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person_Location::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person_Location::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person_Location::GetClassData() const { return &_class_data_; }


void Person_Location::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person_Location*>(&to_msg);
  auto& from = static_cast<const Person_Location&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:examplepb.Person.Location)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lat = from._internal_lat();
  uint64_t raw_lat;
  memcpy(&raw_lat, &tmp_lat, sizeof(tmp_lat));
  if (raw_lat != 0) {
    _this->_internal_set_lat(from._internal_lat());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_lng = from._internal_lng();
  uint64_t raw_lng;
  memcpy(&raw_lng, &tmp_lng, sizeof(tmp_lng));
  if (raw_lng != 0) {
    _this->_internal_set_lng(from._internal_lng());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person_Location::CopyFrom(const Person_Location& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:examplepb.Person.Location)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person_Location::IsInitialized() const {
  return true;
}

void Person_Location::InternalSwap(Person_Location* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Person_Location, _impl_.lng_)
      + sizeof(Person_Location::_impl_.lng_)
      - PROTOBUF_FIELD_OFFSET(Person_Location, _impl_.lat_)>(
          reinterpret_cast<char*>(&_impl_.lat_),
          reinterpret_cast<char*>(&other->_impl_.lat_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Person_Location::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_smurf_2eproto_getter, &descriptor_table_smurf_2eproto_once,
      file_level_metadata_smurf_2eproto[0]);
}

// ===================================================================

class Person::_Internal {
 public:
  static const ::examplepb::Person_Location& home(const Person* msg);
};

const ::examplepb::Person_Location&
Person::_Internal::home(const Person* msg) {
  return *msg->_impl_.home_;
}
Person::Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:examplepb.Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.home_){nullptr}
    , decltype(_impl_.id_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_home()) {
    _this->_impl_.home_ = new ::examplepb::Person_Location(*from._impl_.home_);
  }
  _this->_impl_.id_ = from._impl_.id_;
  // @@protoc_insertion_point(copy_constructor:examplepb.Person)
}

inline void Person::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.home_){nullptr}
    , decltype(_impl_.id_){uint64_t{0u}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:examplepb.Person)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Person::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.home_;
}

void Person::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:examplepb.Person)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.home_ != nullptr) {
    delete _impl_.home_;
  }
  _impl_.home_ = nullptr;
  _impl_.id_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 id = 1 [(.validate.rules) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .examplepb.Person.Location home = 4 [(.validate.rules) = {
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_home(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:examplepb.Person)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 id = 1 [(.validate.rules) = {
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_id(), target);
  }

  // .examplepb.Person.Location home = 4 [(.validate.rules) = {
  if (this->_internal_has_home()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, _Internal::home(this),
        _Internal::home(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:examplepb.Person)
  return target;
}

size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:examplepb.Person)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .examplepb.Person.Location home = 4 [(.validate.rules) = {
  if (this->_internal_has_home()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.home_);
  }

  // uint64 id = 1 [(.validate.rules) = {
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person::GetClassData() const { return &_class_data_; }


void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:examplepb.Person)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_home()) {
    _this->_internal_mutable_home()->::examplepb::Person_Location::MergeFrom(
        from._internal_home());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:examplepb.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Person, _impl_.id_)
      + sizeof(Person::_impl_.id_)
      - PROTOBUF_FIELD_OFFSET(Person, _impl_.home_)>(
          reinterpret_cast<char*>(&_impl_.home_),
          reinterpret_cast<char*>(&other->_impl_.home_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_smurf_2eproto_getter, &descriptor_table_smurf_2eproto_once,
      file_level_metadata_smurf_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace examplepb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::examplepb::Person_Location*
Arena::CreateMaybeMessage< ::examplepb::Person_Location >(Arena* arena) {
  return Arena::CreateMessageInternal< ::examplepb::Person_Location >(arena);
}
template<> PROTOBUF_NOINLINE ::examplepb::Person*
Arena::CreateMaybeMessage< ::examplepb::Person >(Arena* arena) {
  return Arena::CreateMessageInternal< ::examplepb::Person >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>