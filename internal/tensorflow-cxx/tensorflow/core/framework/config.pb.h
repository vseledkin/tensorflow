// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/framework/config.proto

#ifndef PROTOBUF_tensorflow_2fcore_2fframework_2fconfig_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2fcore_2fframework_2fconfig_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/map.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace tensorflow {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
void protobuf_AssignDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
void protobuf_ShutdownFile_tensorflow_2fcore_2fframework_2fconfig_2eproto();

class ConfigProto;
class GPUOptions;

// ===================================================================

class GPUOptions : public ::google::protobuf::Message {
 public:
  GPUOptions();
  virtual ~GPUOptions();

  GPUOptions(const GPUOptions& from);

  inline GPUOptions& operator=(const GPUOptions& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GPUOptions& default_instance();

  void Swap(GPUOptions* other);

  // implements Message ----------------------------------------------

  inline GPUOptions* New() const { return New(NULL); }

  GPUOptions* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GPUOptions& from);
  void MergeFrom(const GPUOptions& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GPUOptions* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double per_process_gpu_memory_fraction = 1;
  void clear_per_process_gpu_memory_fraction();
  static const int kPerProcessGpuMemoryFractionFieldNumber = 1;
  double per_process_gpu_memory_fraction() const;
  void set_per_process_gpu_memory_fraction(double value);

  // @@protoc_insertion_point(class_scope:tensorflow.GPUOptions)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  double per_process_gpu_memory_fraction_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2fcore_2fframework_2fconfig_2eproto();

  void InitAsDefaultInstance();
  static GPUOptions* default_instance_;
};
// -------------------------------------------------------------------

class ConfigProto : public ::google::protobuf::Message {
 public:
  ConfigProto();
  virtual ~ConfigProto();

  ConfigProto(const ConfigProto& from);

  inline ConfigProto& operator=(const ConfigProto& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigProto& default_instance();

  void Swap(ConfigProto* other);

  // implements Message ----------------------------------------------

  inline ConfigProto* New() const { return New(NULL); }

  ConfigProto* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigProto& from);
  void MergeFrom(const ConfigProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ConfigProto* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  // map<string, int32> device_count = 1;
  int device_count_size() const;
  void clear_device_count();
  static const int kDeviceCountFieldNumber = 1;
  const ::google::protobuf::Map< ::std::string, ::google::protobuf::int32 >&
      device_count() const;
  ::google::protobuf::Map< ::std::string, ::google::protobuf::int32 >*
      mutable_device_count();

  // optional int32 intra_op_parallelism_threads = 2;
  void clear_intra_op_parallelism_threads();
  static const int kIntraOpParallelismThreadsFieldNumber = 2;
  ::google::protobuf::int32 intra_op_parallelism_threads() const;
  void set_intra_op_parallelism_threads(::google::protobuf::int32 value);

  // optional int32 inter_op_parallelism_threads = 5;
  void clear_inter_op_parallelism_threads();
  static const int kInterOpParallelismThreadsFieldNumber = 5;
  ::google::protobuf::int32 inter_op_parallelism_threads() const;
  void set_inter_op_parallelism_threads(::google::protobuf::int32 value);

  // optional int32 placement_period = 3;
  void clear_placement_period();
  static const int kPlacementPeriodFieldNumber = 3;
  ::google::protobuf::int32 placement_period() const;
  void set_placement_period(::google::protobuf::int32 value);

  // repeated string device_filters = 4;
  int device_filters_size() const;
  void clear_device_filters();
  static const int kDeviceFiltersFieldNumber = 4;
  const ::std::string& device_filters(int index) const;
  ::std::string* mutable_device_filters(int index);
  void set_device_filters(int index, const ::std::string& value);
  void set_device_filters(int index, const char* value);
  void set_device_filters(int index, const char* value, size_t size);
  ::std::string* add_device_filters();
  void add_device_filters(const ::std::string& value);
  void add_device_filters(const char* value);
  void add_device_filters(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& device_filters() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_device_filters();

  // optional .tensorflow.GPUOptions gpu_options = 6;
  bool has_gpu_options() const;
  void clear_gpu_options();
  static const int kGpuOptionsFieldNumber = 6;
  const ::tensorflow::GPUOptions& gpu_options() const;
  ::tensorflow::GPUOptions* mutable_gpu_options();
  ::tensorflow::GPUOptions* release_gpu_options();
  void set_allocated_gpu_options(::tensorflow::GPUOptions* gpu_options);

  // optional bool allow_soft_placement = 7;
  void clear_allow_soft_placement();
  static const int kAllowSoftPlacementFieldNumber = 7;
  bool allow_soft_placement() const;
  void set_allow_soft_placement(bool value);

  // optional bool log_device_placement = 8;
  void clear_log_device_placement();
  static const int kLogDevicePlacementFieldNumber = 8;
  bool log_device_placement() const;
  void set_log_device_placement(bool value);

  // @@protoc_insertion_point(class_scope:tensorflow.ConfigProto)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  typedef ::google::protobuf::internal::MapEntryLite<
      ::std::string, ::google::protobuf::int32,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_INT32,
      0 >
      ConfigProto_DeviceCountEntry;
  ::google::protobuf::internal::MapField<
      ::std::string, ::google::protobuf::int32,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_INT32,
      0 > device_count_;
  ::google::protobuf::int32 intra_op_parallelism_threads_;
  ::google::protobuf::int32 inter_op_parallelism_threads_;
  ::google::protobuf::RepeatedPtrField< ::std::string> device_filters_;
  ::tensorflow::GPUOptions* gpu_options_;
  ::google::protobuf::int32 placement_period_;
  bool allow_soft_placement_;
  bool log_device_placement_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2fcore_2fframework_2fconfig_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2fcore_2fframework_2fconfig_2eproto();

  void InitAsDefaultInstance();
  static ConfigProto* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// GPUOptions

// optional double per_process_gpu_memory_fraction = 1;
inline void GPUOptions::clear_per_process_gpu_memory_fraction() {
  per_process_gpu_memory_fraction_ = 0;
}
inline double GPUOptions::per_process_gpu_memory_fraction() const {
  // @@protoc_insertion_point(field_get:tensorflow.GPUOptions.per_process_gpu_memory_fraction)
  return per_process_gpu_memory_fraction_;
}
inline void GPUOptions::set_per_process_gpu_memory_fraction(double value) {
  
  per_process_gpu_memory_fraction_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.GPUOptions.per_process_gpu_memory_fraction)
}

// -------------------------------------------------------------------

// ConfigProto

// map<string, int32> device_count = 1;
inline int ConfigProto::device_count_size() const {
  return device_count_.size();
}
inline void ConfigProto::clear_device_count() {
  device_count_.Clear();
}
inline const ::google::protobuf::Map< ::std::string, ::google::protobuf::int32 >&
ConfigProto::device_count() const {
  // @@protoc_insertion_point(field_map:tensorflow.ConfigProto.device_count)
  return device_count_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::google::protobuf::int32 >*
ConfigProto::mutable_device_count() {
  // @@protoc_insertion_point(field_mutable_map:tensorflow.ConfigProto.device_count)
  return device_count_.MutableMap();
}

// optional int32 intra_op_parallelism_threads = 2;
inline void ConfigProto::clear_intra_op_parallelism_threads() {
  intra_op_parallelism_threads_ = 0;
}
inline ::google::protobuf::int32 ConfigProto::intra_op_parallelism_threads() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.intra_op_parallelism_threads)
  return intra_op_parallelism_threads_;
}
inline void ConfigProto::set_intra_op_parallelism_threads(::google::protobuf::int32 value) {
  
  intra_op_parallelism_threads_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.intra_op_parallelism_threads)
}

// optional int32 inter_op_parallelism_threads = 5;
inline void ConfigProto::clear_inter_op_parallelism_threads() {
  inter_op_parallelism_threads_ = 0;
}
inline ::google::protobuf::int32 ConfigProto::inter_op_parallelism_threads() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.inter_op_parallelism_threads)
  return inter_op_parallelism_threads_;
}
inline void ConfigProto::set_inter_op_parallelism_threads(::google::protobuf::int32 value) {
  
  inter_op_parallelism_threads_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.inter_op_parallelism_threads)
}

// optional int32 placement_period = 3;
inline void ConfigProto::clear_placement_period() {
  placement_period_ = 0;
}
inline ::google::protobuf::int32 ConfigProto::placement_period() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.placement_period)
  return placement_period_;
}
inline void ConfigProto::set_placement_period(::google::protobuf::int32 value) {
  
  placement_period_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.placement_period)
}

// repeated string device_filters = 4;
inline int ConfigProto::device_filters_size() const {
  return device_filters_.size();
}
inline void ConfigProto::clear_device_filters() {
  device_filters_.Clear();
}
inline const ::std::string& ConfigProto::device_filters(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.device_filters)
  return device_filters_.Get(index);
}
inline ::std::string* ConfigProto::mutable_device_filters(int index) {
  // @@protoc_insertion_point(field_mutable:tensorflow.ConfigProto.device_filters)
  return device_filters_.Mutable(index);
}
inline void ConfigProto::set_device_filters(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.device_filters)
  device_filters_.Mutable(index)->assign(value);
}
inline void ConfigProto::set_device_filters(int index, const char* value) {
  device_filters_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:tensorflow.ConfigProto.device_filters)
}
inline void ConfigProto::set_device_filters(int index, const char* value, size_t size) {
  device_filters_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ConfigProto.device_filters)
}
inline ::std::string* ConfigProto::add_device_filters() {
  return device_filters_.Add();
}
inline void ConfigProto::add_device_filters(const ::std::string& value) {
  device_filters_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:tensorflow.ConfigProto.device_filters)
}
inline void ConfigProto::add_device_filters(const char* value) {
  device_filters_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:tensorflow.ConfigProto.device_filters)
}
inline void ConfigProto::add_device_filters(const char* value, size_t size) {
  device_filters_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:tensorflow.ConfigProto.device_filters)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
ConfigProto::device_filters() const {
  // @@protoc_insertion_point(field_list:tensorflow.ConfigProto.device_filters)
  return device_filters_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
ConfigProto::mutable_device_filters() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.ConfigProto.device_filters)
  return &device_filters_;
}

// optional .tensorflow.GPUOptions gpu_options = 6;
inline bool ConfigProto::has_gpu_options() const {
  return !_is_default_instance_ && gpu_options_ != NULL;
}
inline void ConfigProto::clear_gpu_options() {
  if (GetArenaNoVirtual() == NULL && gpu_options_ != NULL) delete gpu_options_;
  gpu_options_ = NULL;
}
inline const ::tensorflow::GPUOptions& ConfigProto::gpu_options() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.gpu_options)
  return gpu_options_ != NULL ? *gpu_options_ : *default_instance_->gpu_options_;
}
inline ::tensorflow::GPUOptions* ConfigProto::mutable_gpu_options() {
  
  if (gpu_options_ == NULL) {
    gpu_options_ = new ::tensorflow::GPUOptions;
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.ConfigProto.gpu_options)
  return gpu_options_;
}
inline ::tensorflow::GPUOptions* ConfigProto::release_gpu_options() {
  
  ::tensorflow::GPUOptions* temp = gpu_options_;
  gpu_options_ = NULL;
  return temp;
}
inline void ConfigProto::set_allocated_gpu_options(::tensorflow::GPUOptions* gpu_options) {
  delete gpu_options_;
  gpu_options_ = gpu_options;
  if (gpu_options) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ConfigProto.gpu_options)
}

// optional bool allow_soft_placement = 7;
inline void ConfigProto::clear_allow_soft_placement() {
  allow_soft_placement_ = false;
}
inline bool ConfigProto::allow_soft_placement() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.allow_soft_placement)
  return allow_soft_placement_;
}
inline void ConfigProto::set_allow_soft_placement(bool value) {
  
  allow_soft_placement_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.allow_soft_placement)
}

// optional bool log_device_placement = 8;
inline void ConfigProto::clear_log_device_placement() {
  log_device_placement_ = false;
}
inline bool ConfigProto::log_device_placement() const {
  // @@protoc_insertion_point(field_get:tensorflow.ConfigProto.log_device_placement)
  return log_device_placement_;
}
inline void ConfigProto::set_log_device_placement(bool value) {
  
  log_device_placement_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ConfigProto.log_device_placement)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2fcore_2fframework_2fconfig_2eproto__INCLUDED
