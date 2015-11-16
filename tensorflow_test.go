// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package tensorflow

import (
	"testing"
)

func TestTF_DataType(t *testing.T) {
	tests := []struct {
		expect _TF_DataType
		got    TF_DataType
	}{
		{_TF_FLOAT, TF_FLOAT},
		{_TF_DOUBLE, TF_DOUBLE},
		{_TF_INT32, TF_INT32},
		{_TF_UINT8, TF_UINT8},
		{_TF_INT16, TF_INT16},
		{_TF_INT8, TF_INT8},
		{_TF_STRING, TF_STRING},
		{_TF_COMPLEX, TF_COMPLEX},
		{_TF_INT64, TF_INT64},
		{_TF_BOOL, TF_BOOL},
		{_TF_QINT8, TF_QINT8},
		{_TF_QUINT8, TF_QUINT8},
		{_TF_QINT32, TF_QINT32},
		{_TF_BFLOAT16, TF_BFLOAT16},
	}
	for i, tt := range tests {
		if (tt.expect) != _TF_DataType(tt.got) {
			t.Fatalf("%d: expect = %v, got = %v", i, tt.expect, tt.got)
		}
	}
}

func TestTF_Code(t *testing.T) {
	tests := []struct {
		expect _TF_Code
		got    TF_Code
	}{
		{_TF_OK, TF_OK},
		{_TF_CANCELLED, TF_CANCELLED},
		{_TF_UNKNOWN, TF_UNKNOWN},
		{_TF_INVALID_ARGUMENT, TF_INVALID_ARGUMENT},
		{_TF_DEADLINE_EXCEEDED, TF_DEADLINE_EXCEEDED},
		{_TF_NOT_FOUND, TF_NOT_FOUND},
		{_TF_ALREADY_EXISTS, TF_ALREADY_EXISTS},
		{_TF_PERMISSION_DENIED, TF_PERMISSION_DENIED},
		{_TF_RESOURCE_EXHAUSTED, TF_RESOURCE_EXHAUSTED},
		{_TF_FAILED_PRECONDITION, TF_FAILED_PRECONDITION},
		{_TF_ABORTED, TF_ABORTED},
		{_TF_OUT_OF_RANGE, TF_OUT_OF_RANGE},
		{_TF_UNIMPLEMENTED, TF_UNIMPLEMENTED},
		{_TF_INTERNAL, TF_INTERNAL},
		{_TF_UNAVAILABLE, TF_UNAVAILABLE},
		{_TF_DATA_LOSS, TF_DATA_LOSS},
		{_TF_UNAUTHENTICATED, TF_UNAUTHENTICATED},
	}
	for i, tt := range tests {
		if (tt.expect) != _TF_Code(tt.got) {
			t.Fatalf("%d: expect = %v, got = %v", i, tt.expect, tt.got)
		}
	}
}
