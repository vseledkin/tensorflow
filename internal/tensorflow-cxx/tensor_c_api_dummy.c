// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "tensorflow/core/public/tensor_c_api.h"

#include <stdlib.h>

// --------------------------------------------------------------------------
// TF_Status holds error information.  It either has an OK code, or
// else an error code with an associated error message.
struct TF_Status {
    int todo;
};

// Return a new status object.
extern TF_Status* TF_NewStatus() {
    TF_Status* p = (TF_Status*)malloc(sizeof(*p));
    return p;
}

// Delete a previously created status object.
extern void TF_DeleteStatus(TF_Status* p) {
    //
}

// Record <code, msg> in *s.  Any previous information is lost.
// A common use is to clear a status: TF_SetStatus(s, TF_OK, "");
extern void TF_SetStatus(TF_Status* s, TF_Code code, const char* msg) {
    //
}

// Return the code record in *s.
extern TF_Code TF_GetCode(const TF_Status* s) {
    return TF_OK;
}

// Return a pointer to the error message in *s.  The return value
// points to memory that is only usable until the next mutation to *s.
// Always returns an empty string if TF_GetCode(s) is TF_OK.
extern const char* TF_Message(const TF_Status* s) {
    return "";
}

// --------------------------------------------------------------------------
// TF_Tensor holds a multi-dimensional array of elements of a single data type.
// For all types other than TF_STRING, the data buffer stores elements
// in row major order.  E.g. if data is treated as a vector of TF_DataType:
//
//   element 0:   index (0, ..., 0)
//   element 1:   index (0, ..., 1)
//   ...
//
// TODO(jeff,sanjay): Define format for TF_STRING tensors.  Perhaps:
//   start_offset: array[uint64]
//   data:         byte[...]
//
//   String length is encoded (varint?) starting at data[start_offset[i]]
//   String contents follow immediately after string length.
struct TF_Tensor {
    int todo;
};

// Return a new tensor that holds the bytes data[0,len-1].
//
// The data will be deallocated by a subsequent call to TF_DeleteTensor via:
//      (*deallocator_fn)(data, len, deallocator_arg)
// Clients can provide a custom deallocator function so they can pass in
// memory managed by something like numpy.
extern TF_Tensor* TF_NewTensor(
    TF_DataType dt, long long* dims, int num_dims,
    void* data, size_t len,
    void (*deallocator)(void* data, size_t len, void* arg),
    void* deallocator_arg
) {
    return NULL;
}

// Destroy a tensor.
extern void TF_DeleteTensor(TF_Tensor* tensor) {
    // TODO
}

// Return the type of a tensor element.
extern TF_DataType TF_TensorType(const TF_Tensor* tensor) {
    return 0;
}

// Return the number of dimensions that the tensor has.
extern int TF_NumDims(const TF_Tensor* tensor) {
    return 0;
}

// Return the length of the tensor in the "dim_index" dimension.
// REQUIRES: 0 <= dim_index < TF_NumDims(tensor)
extern long long TF_Dim(const TF_Tensor* tensor, int dim_index) {
    return 0;
}

// Return the size of the underlying data in bytes.
extern size_t TF_TensorByteSize(const TF_Tensor* tensor) {
    return 0;
}

// Return a pointer to the underlying data buffer.
extern void* TF_TensorData(const TF_Tensor* tensor) {
    return NULL;
}

// --------------------------------------------------------------------------
// TF_SessionOptions holds options that can be passed during session creation.
struct TF_SessionOptions {
    int todo;
};

// Return a new options object.
extern TF_SessionOptions* TF_NewSessionOptions() {
    return NULL;
}

// Set the target in TF_SessionOptions.options.
// target can be empty, a single entry, or a comma separated list of entries.
// Each entry is in one of the following formats :
// "local"
// ip:port
// host:port
extern void TF_SetTarget(TF_SessionOptions* options, const char* target) {
    // TODO
}

// Set the config in TF_SessionOptions.options.
// config should be a serialized brain.ConfigProto proto.
// If config was not parsed successfully as a ConfigProto, record the
// error information in *status.
extern void TF_SetConfig(
    TF_SessionOptions* options, const char* config,
    size_t config_len, TF_Status* status
) {
    // TODO
}

// Destroy an options object.
extern void TF_DeleteSessionOptions(TF_SessionOptions* sessionOpt) {
    // TODO
}

// TODO(jeff,sanjay):
// - export functions to set Config fields

// --------------------------------------------------------------------------
// TF_Session manages a single graph and execution.
struct TF_Session {
    int todo;
};

// Return a new execution session, or NULL on error.
extern TF_Session* TF_NewSession(const TF_SessionOptions* sessionOpt, TF_Status* status) {
    return NULL;
}

// Close a session.
extern void TF_CloseSession(TF_Session* session, TF_Status* status) {
    // TODO
}

// Destroy a session.  Even if error information is recorded in *status,
// this call discards all resources associated with the session.
extern void TF_DeleteSession(TF_Session* session, TF_Status* status) {
    // TODO
}

// Treat the bytes proto[0,proto_len-1] as a serialized GraphDef and
// add the nodes in that GraphDef to the graph for the session.
extern void TF_ExtendGraph(
    TF_Session* session, const void* proto, size_t proto_len,
    TF_Status* status
) {
    // TODO
}

// Run the graph associated with the session starting with the
// supplied inputs (inputs[0,ninputs-1]).  Regardless of success or
// failure, inputs[] become the property of the implementation (the
// implementation will eventually call TF_DeleteTensor on each input).
//
// On success, the tensors corresponding to output_names[0,noutputs-1]
// are placed in outputs[].  and these outputs[] become the property
// of the caller (the caller must eventually call TF_DeleteTensor on
// them).
//
// On failure, outputs[] contains nulls.
extern void TF_Run(TF_Session* session,
    // Input tensors
    const char** input_names, TF_Tensor** inputs, int ninputs,
    // Output tensors
    const char** output_tensor_names, TF_Tensor** outputs,
    int noutputs,
    // Target nodes
    const char** target_node_names, int ntargets,
    // Output status
    TF_Status* status
) {
    // TODO
}

// --------------------------------------------------------------------------
// END
