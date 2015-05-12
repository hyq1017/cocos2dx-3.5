// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "C2S_pb.h"

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

const ::google::protobuf::Descriptor* C2SLogin_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  C2SLogin_reflection_ = NULL;
const ::google::protobuf::Descriptor* C2SMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  C2SMsg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_C2S_2eproto() {
  protobuf_AddDesc_C2S_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "C2S.proto");
  GOOGLE_CHECK(file != NULL);
  C2SLogin_descriptor_ = file->message_type(0);
  static const int C2SLogin_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SLogin, channelid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SLogin, channelaccountid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SLogin, logintoken_),
  };
  C2SLogin_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      C2SLogin_descriptor_,
      C2SLogin::default_instance_,
      C2SLogin_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SLogin, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SLogin, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(C2SLogin));
  C2SMsg_descriptor_ = file->message_type(1);
  static const int C2SMsg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SMsg, msgid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SMsg, login_),
  };
  C2SMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      C2SMsg_descriptor_,
      C2SMsg::default_instance_,
      C2SMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(C2SMsg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_C2S_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    C2SLogin_descriptor_, &C2SLogin::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    C2SMsg_descriptor_, &C2SMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_C2S_2eproto() {
  delete C2SLogin::default_instance_;
  delete C2SLogin_reflection_;
  delete C2SMsg::default_instance_;
  delete C2SMsg_reflection_;
}

void protobuf_AddDesc_C2S_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::tetris_protocol::protobuf_AddDesc_MsgId_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\tC2S.proto\022\017tetris_protocol\032\013MsgId.prot"
    "o\"K\n\010C2SLogin\022\021\n\tchannelId\030\001 \002(\005\022\030\n\020chan"
    "nelAccountId\030\002 \002(\t\022\022\n\nloginToken\030\003 \001(\t\"Y"
    "\n\006C2SMsg\022%\n\005msgId\030\001 \002(\0162\026.tetris_protoco"
    "l.MsgId\022(\n\005login\030\002 \001(\0132\031.tetris_protocol"
    ".C2SLoginB\037\n\023com.tetris.protocolB\010C2SPro"
    "to", 242);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "C2S.proto", &protobuf_RegisterTypes);
  C2SLogin::default_instance_ = new C2SLogin();
  C2SMsg::default_instance_ = new C2SMsg();
  C2SLogin::default_instance_->InitAsDefaultInstance();
  C2SMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_C2S_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_C2S_2eproto {
  StaticDescriptorInitializer_C2S_2eproto() {
    protobuf_AddDesc_C2S_2eproto();
  }
} static_descriptor_initializer_C2S_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int C2SLogin::kChannelIdFieldNumber;
const int C2SLogin::kChannelAccountIdFieldNumber;
const int C2SLogin::kLoginTokenFieldNumber;
#endif  // !_MSC_VER

C2SLogin::C2SLogin()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void C2SLogin::InitAsDefaultInstance() {
}

C2SLogin::C2SLogin(const C2SLogin& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void C2SLogin::SharedCtor() {
  _cached_size_ = 0;
  channelid_ = 0;
  channelaccountid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  logintoken_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

C2SLogin::~C2SLogin() {
  SharedDtor();
}

void C2SLogin::SharedDtor() {
  if (channelaccountid_ != &::google::protobuf::internal::kEmptyString) {
    delete channelaccountid_;
  }
  if (logintoken_ != &::google::protobuf::internal::kEmptyString) {
    delete logintoken_;
  }
  if (this != default_instance_) {
  }
}

void C2SLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* C2SLogin::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return C2SLogin_descriptor_;
}

const C2SLogin& C2SLogin::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_C2S_2eproto();  return *default_instance_;
}

C2SLogin* C2SLogin::default_instance_ = NULL;

C2SLogin* C2SLogin::New() const {
  return new C2SLogin;
}

void C2SLogin::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    channelid_ = 0;
    if (has_channelaccountid()) {
      if (channelaccountid_ != &::google::protobuf::internal::kEmptyString) {
        channelaccountid_->clear();
      }
    }
    if (has_logintoken()) {
      if (logintoken_ != &::google::protobuf::internal::kEmptyString) {
        logintoken_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool C2SLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 channelId = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &channelid_)));
          set_has_channelid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_channelAccountId;
        break;
      }
      
      // required string channelAccountId = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_channelAccountId:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_channelaccountid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->channelaccountid().data(), this->channelaccountid().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_loginToken;
        break;
      }
      
      // optional string loginToken = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_loginToken:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_logintoken()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->logintoken().data(), this->logintoken().length(),
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

void C2SLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 channelId = 1;
  if (has_channelid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->channelid(), output);
  }
  
  // required string channelAccountId = 2;
  if (has_channelaccountid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->channelaccountid().data(), this->channelaccountid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->channelaccountid(), output);
  }
  
  // optional string loginToken = 3;
  if (has_logintoken()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->logintoken().data(), this->logintoken().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->logintoken(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* C2SLogin::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 channelId = 1;
  if (has_channelid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->channelid(), target);
  }
  
  // required string channelAccountId = 2;
  if (has_channelaccountid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->channelaccountid().data(), this->channelaccountid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->channelaccountid(), target);
  }
  
  // optional string loginToken = 3;
  if (has_logintoken()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->logintoken().data(), this->logintoken().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->logintoken(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int C2SLogin::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 channelId = 1;
    if (has_channelid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->channelid());
    }
    
    // required string channelAccountId = 2;
    if (has_channelaccountid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->channelaccountid());
    }
    
    // optional string loginToken = 3;
    if (has_logintoken()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->logintoken());
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

void C2SLogin::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const C2SLogin* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const C2SLogin*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void C2SLogin::MergeFrom(const C2SLogin& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_channelid()) {
      set_channelid(from.channelid());
    }
    if (from.has_channelaccountid()) {
      set_channelaccountid(from.channelaccountid());
    }
    if (from.has_logintoken()) {
      set_logintoken(from.logintoken());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void C2SLogin::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void C2SLogin::CopyFrom(const C2SLogin& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool C2SLogin::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void C2SLogin::Swap(C2SLogin* other) {
  if (other != this) {
    std::swap(channelid_, other->channelid_);
    std::swap(channelaccountid_, other->channelaccountid_);
    std::swap(logintoken_, other->logintoken_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata C2SLogin::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = C2SLogin_descriptor_;
  metadata.reflection = C2SLogin_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int C2SMsg::kMsgIdFieldNumber;
const int C2SMsg::kLoginFieldNumber;
#endif  // !_MSC_VER

C2SMsg::C2SMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void C2SMsg::InitAsDefaultInstance() {
  login_ = const_cast< ::tetris_protocol::C2SLogin*>(&::tetris_protocol::C2SLogin::default_instance());
}

C2SMsg::C2SMsg(const C2SMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void C2SMsg::SharedCtor() {
  _cached_size_ = 0;
  msgid_ = 100000;
  login_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

C2SMsg::~C2SMsg() {
  SharedDtor();
}

void C2SMsg::SharedDtor() {
  if (this != default_instance_) {
    delete login_;
  }
}

void C2SMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* C2SMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return C2SMsg_descriptor_;
}

const C2SMsg& C2SMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_C2S_2eproto();  return *default_instance_;
}

C2SMsg* C2SMsg::default_instance_ = NULL;

C2SMsg* C2SMsg::New() const {
  return new C2SMsg;
}

void C2SMsg::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    msgid_ = 100000;
    if (has_login()) {
      if (login_ != NULL) login_->::tetris_protocol::C2SLogin::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool C2SMsg::MergePartialFromCodedStream(
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
      
      // optional .tetris_protocol.C2SLogin login = 2;
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

void C2SMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .tetris_protocol.MsgId msgId = 1;
  if (has_msgid()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->msgid(), output);
  }
  
  // optional .tetris_protocol.C2SLogin login = 2;
  if (has_login()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->login(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* C2SMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .tetris_protocol.MsgId msgId = 1;
  if (has_msgid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->msgid(), target);
  }
  
  // optional .tetris_protocol.C2SLogin login = 2;
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

int C2SMsg::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .tetris_protocol.MsgId msgId = 1;
    if (has_msgid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->msgid());
    }
    
    // optional .tetris_protocol.C2SLogin login = 2;
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

void C2SMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const C2SMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const C2SMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void C2SMsg::MergeFrom(const C2SMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_msgid()) {
      set_msgid(from.msgid());
    }
    if (from.has_login()) {
      mutable_login()->::tetris_protocol::C2SLogin::MergeFrom(from.login());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void C2SMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void C2SMsg::CopyFrom(const C2SMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool C2SMsg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  if (has_login()) {
    if (!this->login().IsInitialized()) return false;
  }
  return true;
}

void C2SMsg::Swap(C2SMsg* other) {
  if (other != this) {
    std::swap(msgid_, other->msgid_);
    std::swap(login_, other->login_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata C2SMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = C2SMsg_descriptor_;
  metadata.reflection = C2SMsg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace tetris_protocol

// @@protoc_insertion_point(global_scope)