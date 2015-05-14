// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "S2C_pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace tetris_protocol {

namespace {

const ::google::protobuf::Descriptor* S2CLogin_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2CLogin_reflection_ = NULL;
const ::google::protobuf::Descriptor* S2CMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2CMsg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_S2C_2eproto() {
  protobuf_AddDesc_S2C_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "S2C.proto");
  GOOGLE_CHECK(file != NULL);
  S2CLogin_descriptor_ = file->message_type(0);
  static const int S2CLogin_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CLogin, result_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CLogin, accountid_),
  };
  S2CLogin_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2CLogin_descriptor_,
      S2CLogin::default_instance_,
      S2CLogin_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CLogin, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CLogin, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2CLogin));
  S2CMsg_descriptor_ = file->message_type(1);
  static const int S2CMsg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CMsg, msgid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CMsg, login_),
  };
  S2CMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2CMsg_descriptor_,
      S2CMsg::default_instance_,
      S2CMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2CMsg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_S2C_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2CLogin_descriptor_, &S2CLogin::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2CMsg_descriptor_, &S2CMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_S2C_2eproto() {
  delete S2CLogin::default_instance_;
  delete S2CLogin_reflection_;
  delete S2CMsg::default_instance_;
  delete S2CMsg_reflection_;
}

void protobuf_AddDesc_S2C_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::tetris_protocol::protobuf_AddDesc_MsgId_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\tS2C.proto\022\017tetris_protocol\032\013MsgId.prot"
    "o\"-\n\010S2CLogin\022\016\n\006result\030\001 \002(\005\022\021\n\taccount"
    "Id\030\002 \002(\t\"Y\n\006S2CMsg\022%\n\005msgId\030\001 \002(\0162\026.tetr"
    "is_protocol.MsgId\022(\n\005login\030\002 \001(\0132\031.tetri"
    "s_protocol.S2CLoginB\037\n\023com.tetris.protoc"
    "olB\010S2CProto", 212);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "S2C.proto", &protobuf_RegisterTypes);
  S2CLogin::default_instance_ = new S2CLogin();
  S2CMsg::default_instance_ = new S2CMsg();
  S2CLogin::default_instance_->InitAsDefaultInstance();
  S2CMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_S2C_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_S2C_2eproto {
  StaticDescriptorInitializer_S2C_2eproto() {
    protobuf_AddDesc_S2C_2eproto();
  }
} static_descriptor_initializer_S2C_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int S2CLogin::kResultFieldNumber;
const int S2CLogin::kAccountIdFieldNumber;
#endif  // !_MSC_VER

S2CLogin::S2CLogin()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2CLogin::InitAsDefaultInstance() {
}

S2CLogin::S2CLogin(const S2CLogin& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2CLogin::SharedCtor() {
  _cached_size_ = 0;
  result_ = 0;
  accountid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2CLogin::~S2CLogin() {
  SharedDtor();
}

void S2CLogin::SharedDtor() {
  if (accountid_ != &::google::protobuf::internal::kEmptyString) {
    delete accountid_;
  }
  if (this != default_instance_) {
  }
}

void S2CLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2CLogin::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2CLogin_descriptor_;
}

const S2CLogin& S2CLogin::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_S2C_2eproto();  return *default_instance_;
}

S2CLogin* S2CLogin::default_instance_ = NULL;

S2CLogin* S2CLogin::New() const {
  return new S2CLogin;
}

void S2CLogin::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    result_ = 0;
    if (has_accountid()) {
      if (accountid_ != &::google::protobuf::internal::kEmptyString) {
        accountid_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2CLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 result = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &result_)));
          set_has_result();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_accountId;
        break;
      }
      
      // required string accountId = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_accountId:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_accountid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->accountid().data(), this->accountid().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void S2CLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 result = 1;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->result(), output);
  }
  
  // required string accountId = 2;
  if (has_accountid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->accountid().data(), this->accountid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->accountid(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2CLogin::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 result = 1;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->result(), target);
  }
  
  // required string accountId = 2;
  if (has_accountid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->accountid().data(), this->accountid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->accountid(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2CLogin::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 result = 1;
    if (has_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->result());
    }
    
    // required string accountId = 2;
    if (has_accountid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->accountid());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void S2CLogin::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2CLogin* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2CLogin*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2CLogin::MergeFrom(const S2CLogin& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_result()) {
      set_result(from.result());
    }
    if (from.has_accountid()) {
      set_accountid(from.accountid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2CLogin::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2CLogin::CopyFrom(const S2CLogin& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2CLogin::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void S2CLogin::Swap(S2CLogin* other) {
  if (other != this) {
    std::swap(result_, other->result_);
    std::swap(accountid_, other->accountid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2CLogin::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2CLogin_descriptor_;
  metadata.reflection = S2CLogin_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int S2CMsg::kMsgIdFieldNumber;
const int S2CMsg::kLoginFieldNumber;
#endif  // !_MSC_VER

S2CMsg::S2CMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2CMsg::InitAsDefaultInstance() {
  login_ = const_cast< ::tetris_protocol::S2CLogin*>(&::tetris_protocol::S2CLogin::default_instance());
}

S2CMsg::S2CMsg(const S2CMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2CMsg::SharedCtor() {
  _cached_size_ = 0;
  msgid_ = 100000;
  login_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2CMsg::~S2CMsg() {
  SharedDtor();
}

void S2CMsg::SharedDtor() {
  if (this != default_instance_) {
    delete login_;
  }
}

void S2CMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2CMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2CMsg_descriptor_;
}

const S2CMsg& S2CMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_S2C_2eproto();  return *default_instance_;
}

S2CMsg* S2CMsg::default_instance_ = NULL;

S2CMsg* S2CMsg::New() const {
  return new S2CMsg;
}

void S2CMsg::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    msgid_ = 100000;
    if (has_login()) {
      if (login_ != NULL) login_->::tetris_protocol::S2CLogin::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2CMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .tetris_protocol.MsgId msgId = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (tetris_protocol::MsgId_IsValid(value)) {
            set_msgid(static_cast< tetris_protocol::MsgId >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_login;
        break;
      }
      
      // optional .tetris_protocol.S2CLogin login = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_login:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_login()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void S2CMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .tetris_protocol.MsgId msgId = 1;
  if (has_msgid()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->msgid(), output);
  }
  
  // optional .tetris_protocol.S2CLogin login = 2;
  if (has_login()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->login(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2CMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .tetris_protocol.MsgId msgId = 1;
  if (has_msgid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->msgid(), target);
  }
  
  // optional .tetris_protocol.S2CLogin login = 2;
  if (has_login()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->login(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2CMsg::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .tetris_protocol.MsgId msgId = 1;
    if (has_msgid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->msgid());
    }
    
    // optional .tetris_protocol.S2CLogin login = 2;
    if (has_login()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->login());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void S2CMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2CMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2CMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2CMsg::MergeFrom(const S2CMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_msgid()) {
      set_msgid(from.msgid());
    }
    if (from.has_login()) {
      mutable_login()->::tetris_protocol::S2CLogin::MergeFrom(from.login());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2CMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2CMsg::CopyFrom(const S2CMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2CMsg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  if (has_login()) {
    if (!this->login().IsInitialized()) return false;
  }
  return true;
}

void S2CMsg::Swap(S2CMsg* other) {
  if (other != this) {
    std::swap(msgid_, other->msgid_);
    std::swap(login_, other->login_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2CMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2CMsg_descriptor_;
  metadata.reflection = S2CMsg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace tetris_protocol

// @@protoc_insertion_point(global_scope)
