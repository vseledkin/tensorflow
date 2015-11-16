// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// TODO(chai2010):

package tensorflow

/*
#include "./internal/tensorflow/tensor_c_api.h"

#include <stdlib.h>
*/
import "C"
import (
	"unsafe"
)

// --------------------------------------------------------------------------

// TF_DataType holds the type for a scalar value.  E.g., one slot in a tensor.
// The enum values here are identical to corresponding values in types.proto.
type _TF_DataType int

const (
	_TF_FLOAT    = _TF_DataType(C.TF_FLOAT)
	_TF_DOUBLE   = _TF_DataType(C.TF_DOUBLE)
	_TF_INT32    = _TF_DataType(C.TF_INT32) // Int32 tensors are always in 'host' memory.
	_TF_UINT8    = _TF_DataType(C.TF_UINT8)
	_TF_INT16    = _TF_DataType(C.TF_INT16)
	_TF_INT8     = _TF_DataType(C.TF_INT8)
	_TF_STRING   = _TF_DataType(C.TF_STRING)
	_TF_COMPLEX  = _TF_DataType(C.TF_COMPLEX) // Single-precision complex
	_TF_INT64    = _TF_DataType(C.TF_INT64)
	_TF_BOOL     = _TF_DataType(C.TF_BOOL)
	_TF_QINT8    = _TF_DataType(C.TF_QINT8)    // Quantized int8
	_TF_QUINT8   = _TF_DataType(C.TF_QUINT8)   // Quantized uint8
	_TF_QINT32   = _TF_DataType(C.TF_QINT32)   // Quantized int32
	_TF_BFLOAT16 = _TF_DataType(C.TF_BFLOAT16) // Float32 truncated to 16 bits.  Only for cast ops.
)

// TF_Code holds an error code.  The enum values here are identical to
// corresponding values in error_codes.proto.
type _TF_Code int

const (
	_TF_OK                  = _TF_Code(C.TF_OK)
	_TF_CANCELLED           = _TF_Code(C.TF_CANCELLED)
	_TF_UNKNOWN             = _TF_Code(C.TF_UNKNOWN)
	_TF_INVALID_ARGUMENT    = _TF_Code(C.TF_INVALID_ARGUMENT)
	_TF_DEADLINE_EXCEEDED   = _TF_Code(C.TF_DEADLINE_EXCEEDED)
	_TF_NOT_FOUND           = _TF_Code(C.TF_NOT_FOUND)
	_TF_ALREADY_EXISTS      = _TF_Code(C.TF_ALREADY_EXISTS)
	_TF_PERMISSION_DENIED   = _TF_Code(C.TF_PERMISSION_DENIED)
	_TF_RESOURCE_EXHAUSTED  = _TF_Code(C.TF_RESOURCE_EXHAUSTED)
	_TF_FAILED_PRECONDITION = _TF_Code(C.TF_FAILED_PRECONDITION)
	_TF_ABORTED             = _TF_Code(C.TF_ABORTED)
	_TF_OUT_OF_RANGE        = _TF_Code(C.TF_OUT_OF_RANGE)
	_TF_UNIMPLEMENTED       = _TF_Code(C.TF_UNIMPLEMENTED)
	_TF_INTERNAL            = _TF_Code(C.TF_INTERNAL)
	_TF_UNAVAILABLE         = _TF_Code(C.TF_UNAVAILABLE)
	_TF_DATA_LOSS           = _TF_Code(C.TF_DATA_LOSS)
	_TF_UNAUTHENTICATED     = _TF_Code(C.TF_UNAUTHENTICATED)
)

// --------------------------------------------------------------------------

// TF_Status holds error information.  It either has an OK code, or
// else an error code with an associated error message.
type _TF_Status C.TF_Status

// Return a new status object.
func _TF_NewStatus() *_TF_Status {
	return (*_TF_Status)(C.TF_NewStatus())
}

// Delete a previously created status object.
func _TF_DeleteStatus(s *_TF_Status) {
	C.TF_DeleteStatus((*C.TF_Status)(s))
}

// Record <code, msg> in *s.  Any previous information is lost.
// A common use is to clear a status: TF_SetStatus(s, TF_OK, "");
func _TF_SetStatus(s *_TF_Status, code _TF_Code, msg string) {
	cmsg := C.CString(msg)
	defer C.free(unsafe.Pointer(cmsg))
	C.TF_SetStatus((*C.TF_Status)(s), C.TF_Code(code), cmsg)
}

// Return the code record in *s.
func _TF_GetCode(s *_TF_Status) _TF_Code {
	return _TF_Code(C.TF_GetCode(((*C.TF_Status)(s))))
}

// Return a pointer to the error message in *s.  The return value
// points to memory that is only usable until the next mutation to *s.
// Always returns an empty string if TF_GetCode(s) is TF_OK.
func _TF_Message(s *_TF_Status) string {
	cmsg := C.TF_Message(((*C.TF_Status)(s)))
	return C.GoString(cmsg)
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
type _TF_Tensor C.TF_Tensor

// Return a new tensor that holds the bytes data[0,len-1].
//
// The data will be deallocated by a subsequent call to TF_DeleteTensor via:
//      (*deallocator_fn)(data, len, deallocator_arg)
// Clients can provide a custom deallocator function so they can pass in
// memory managed by something like numpy.
func _TF_NewTensor(
	dt _TF_DataType, dims []int64, num_dims int, data []byte,
	// void (*deallocator)(void* data, size_t len, void* arg),
	// void* deallocator_arg
) *_TF_Tensor {
	panic("TODO")
}

// Destroy a tensor.
func _TF_DeleteTensor(p *_TF_Tensor) {
	// TODO
}

// Return the type of a tensor element.
func _TF_TensorType(p *_TF_Tensor) _TF_DataType {
	return 0
}

// Return the number of dimensions that the tensor has.
func _TF_NumDims(p *_TF_Tensor) int {
	return 0
}

// Return the length of the tensor in the "dim_index" dimension.
// REQUIRES: 0 <= dim_index < TF_NumDims(tensor)
func _TF_Dim(p *_TF_Tensor, dim_index int) int64 {
	return 0
}

// Return the size of the underlying data in bytes.
func _TF_TensorByteSize(p *_TF_Tensor) int {
	return 0
}

// Return a pointer to the underlying data buffer.
func _TF_TensorData(p *_TF_Tensor) []byte {
	return nil
}

// --------------------------------------------------------------------------

// TF_SessionOptions holds options that can be passed during session creation.
type _TF_SessionOptions C.TF_SessionOptions

// Return a new options object.
func _TF_NewSessionOptions() *_TF_SessionOptions {
	return nil
}

// Set the target in TF_SessionOptions.options.
// target can be empty, a single entry, or a comma separated list of entries.
// Each entry is in one of the following formats :
// "local"
// ip:port
// host:port
func _TF_SetTarget(options *_TF_SessionOptions, target string) {
	// TODO
}

// Set the config in TF_SessionOptions.options.
// config should be a serialized brain.ConfigProto proto.
// If config was not parsed successfully as a ConfigProto, record the
// error information in *status.
func _TF_SetConfig(
	options *_TF_SessionOptions, config string,
	status *_TF_Status,
) {
	// TODO
}

// Destroy an options object.
func _TF_DeleteSessionOptions(sessionOpt *_TF_SessionOptions) {
	// TODO
}

// TODO(jeff,sanjay):
// - export functions to set Config fields

// --------------------------------------------------------------------------

// TF_Session manages a single graph and execution.
type _TF_Session C.TF_Session

// Return a new execution session, or NULL on error.
func _TF_NewSession(sessionOpt *_TF_SessionOptions, status *_TF_Status) *_TF_Session {
	return nil
}

// Close a session.
func _TF_CloseSession(session *_TF_Session, status *_TF_Status) {
	// TODO
}

// Destroy a session.  Even if error information is recorded in *status,
// this call discards all resources associated with the session.
func _TF_DeleteSession(session *_TF_Session, status *_TF_Status) {
	// TODO
}

// Treat the bytes proto[0,proto_len-1] as a serialized GraphDef and
// add the nodes in that GraphDef to the graph for the session.
func _TF_ExtendGraph(
	session *_TF_Session, proto []byte,
	status *_TF_Status,
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
func _TF_Run(session *_TF_Session,
	// Input tensors
	input_names []string, inputs []*_TF_Tensor,
	// Output tensors
	output_tensor_names []string, outputs []*_TF_Tensor,
	// Target nodes
	target_node_names []string,
	// Output status
	status *_TF_Status,
) {
	// TODO
}

// --------------------------------------------------------------------------
// END
