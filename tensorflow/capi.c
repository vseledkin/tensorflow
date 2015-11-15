// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "../internal/tensorflow/tensor_c_api.h"


#include <stdlib.h>

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
