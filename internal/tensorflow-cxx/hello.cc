// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>

#include "tensorflow/core/public/tensor_c_api.h"

int main() {
	printf("hello tensorflow!\n");
	return 0;
}

static void assert_build_succeed() {
	auto p0 = TF_NewStatus();
	auto p1 = TF_NewTensor(TF_FLOAT, NULL, 0, NULL, 0, NULL, NULL);
	auto p2 = TF_NewSessionOptions();
	auto p3 = TF_NewSession(NULL, NULL);
	TF_Run(NULL, NULL, NULL, 0, NULL, NULL, 0, NULL, 0, NULL);
}
