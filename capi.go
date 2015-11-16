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
