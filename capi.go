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
type TF_DataType int

const (
	_ TF_DataType = iota
	TF_FLOAT
	TF_DOUBLE
	TF_INT32 // Int32 tensors are always in 'host' memory.
	TF_UINT8
	TF_INT16
	TF_INT8
	TF_STRING
	TF_COMPLEX // Single-precision complex
	TF_INT64
	TF_BOOL
	TF_QINT8    // Quantized int8
	TF_QUINT8   // Quantized uint8
	TF_QINT32   // Quantized int32
	TF_BFLOAT16 // Float32 truncated to 16 bits.  Only for cast ops.
)

// TF_Code holds an error code.  The enum values here are identical to
// corresponding values in error_codes.proto.
type TF_Code int

const (
	TF_OK TF_Code = iota
	TF_CANCELLED
	TF_UNKNOWN
	TF_INVALID_ARGUMENT
	TF_DEADLINE_EXCEEDED
	TF_NOT_FOUND
	TF_ALREADY_EXISTS
	TF_PERMISSION_DENIED
	TF_RESOURCE_EXHAUSTED
	TF_FAILED_PRECONDITION
	TF_ABORTED
	TF_OUT_OF_RANGE
	TF_UNIMPLEMENTED
	TF_INTERNAL
	TF_UNAVAILABLE
	TF_DATA_LOSS
	TF_UNAUTHENTICATED
)

// --------------------------------------------------------------------------

// TF_Status holds error information.  It either has an OK code, or
// else an error code with an associated error message.
type TF_Status C.TF_Status

// Return a new status object.
func TF_NewStatus() *TF_Status {
	return (*TF_Status)(C.TF_NewStatus())
}

// Delete a previously created status object.
func TF_DeleteStatus(s *TF_Status) {
	C.TF_DeleteStatus((*C.TF_Status)(s))
}

// Record <code, msg> in *s.  Any previous information is lost.
// A common use is to clear a status: TF_SetStatus(s, TF_OK, "");
func TF_SetStatus(s *TF_Status, code TF_Code, msg string) {
	cmsg := C.CString(msg)
	defer C.free(unsafe.Pointer(cmsg))
	C.TF_SetStatus((*C.TF_Status)(s), C.TF_Code(code), cmsg)
}

// Return the code record in *s.
func TF_GetCode(s *TF_Status) TF_Code {
	return TF_Code(C.TF_GetCode(((*C.TF_Status)(s))))
}

// Return a pointer to the error message in *s.  The return value
// points to memory that is only usable until the next mutation to *s.
// Always returns an empty string if TF_GetCode(s) is TF_OK.
func TF_Message(s *TF_Status) string {
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
type TF_Tensor C.TF_Tensor

// Return a new tensor that holds the bytes data[0,len-1].
//
// The data will be deallocated by a subsequent call to TF_DeleteTensor via:
//      (*deallocator_fn)(data, len, deallocator_arg)
// Clients can provide a custom deallocator function so they can pass in
// memory managed by something like numpy.
func TF_NewTensor(
	dt TF_DataType, dims []int64, num_dims int, data []byte,
	// void (*deallocator)(void* data, size_t len, void* arg),
	// void* deallocator_arg
) *TF_Tensor {
	panic("TODO")
}

// Destroy a tensor.
func TF_DeleteTensor(p *TF_Tensor) {
	// TODO
}

// Return the type of a tensor element.
func TF_TensorType(p *TF_Tensor) TF_DataType {
	return 0
}

// Return the number of dimensions that the tensor has.
func TF_NumDims(p *TF_Tensor) int {
	return 0
}

// Return the length of the tensor in the "dim_index" dimension.
// REQUIRES: 0 <= dim_index < TF_NumDims(tensor)
func TF_Dim(p *TF_Tensor, dim_index int) int64 {
	return 0
}

// Return the size of the underlying data in bytes.
func TF_TensorByteSize(p *TF_Tensor) int {
	return 0
}

// Return a pointer to the underlying data buffer.
func TF_TensorData(p *TF_Tensor) []byte {
	return nil
}

// TF_SessionOptions holds options that can be passed during session creation.
type TF_SessionOptions C.TF_SessionOptions

// Return a new options object.
func TF_NewSessionOptions() *TF_SessionOptions {
	return nil
}

// Set the target in TF_SessionOptions.options.
// target can be empty, a single entry, or a comma separated list of entries.
// Each entry is in one of the following formats :
// "local"
// ip:port
// host:port
func TF_SetTarget(options *TF_SessionOptions, target string) {
	// TODO
}

// Set the config in TF_SessionOptions.options.
// config should be a serialized brain.ConfigProto proto.
// If config was not parsed successfully as a ConfigProto, record the
// error information in *status.
func TF_SetConfig(
	options *TF_SessionOptions, config string,
	status *TF_Status,
) {
	// TODO
}

// Destroy an options object.
func TF_DeleteSessionOptions(sessionOpt *TF_SessionOptions) {
	// TODO
}

// TODO(jeff,sanjay):
// - export functions to set Config fields

// --------------------------------------------------------------------------

// TF_Session manages a single graph and execution.
type TF_Session C.TF_Session

// Return a new execution session, or NULL on error.
func TF_NewSession(sessionOpt *TF_SessionOptions, status *TF_Status) *TF_Session {
	return nil
}

// Close a session.
func TF_CloseSession(session *TF_Session, status *TF_Status) {
	// TODO
}

// Destroy a session.  Even if error information is recorded in *status,
// this call discards all resources associated with the session.
func TF_DeleteSession(session *TF_Session, status *TF_Status) {
	// TODO
}

// Treat the bytes proto[0,proto_len-1] as a serialized GraphDef and
// add the nodes in that GraphDef to the graph for the session.
func TF_ExtendGraph(
	session *TF_Session, proto []byte,
	status *TF_Status,
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
func TF_Run(session *TF_Session,
	// Input tensors
	input_names []string, inputs []*TF_Tensor,
	// Output tensors
	output_tensor_names []string, outputs []*TF_Tensor,
	// Target nodes
	target_node_names []string,
	// Output status
	status *TF_Status,
) {
	// TODO
}

// --------------------------------------------------------------------------
// END
