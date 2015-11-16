// Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build ingore

package tensorflow_test

import (
	tf "github.com/chai2010/tensorflow"
)

func Example() {
	panic("TODO...")

	hello := tf.Constant("Hello, TensorFlow!")
	sess := tf.Session()
	println(sess.Run(hello))
	// Hello, TensorFlow!

	a := tf.Constant(10)
	b := tf.Constant(32)
	println(sess.Run(a, "+", b))
	// 42
}
