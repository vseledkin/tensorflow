// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Package tensorflow provides Go bindings tensorflow.
package tensorflow // import "github.com/chai2010/tensorflow"

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

// Code holds an error code.  The enum values here are identical to
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
type TF_Status struct {
	Code    TF_Code
	Message string
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
type TF_Tensor struct {
	DataType TF_DataType
	Dims []int
	Data []byte
}

// --------------------------------------------------------------------------
// END
