# tensorflow for Go

[![Build Status](https://travis-ci.org/chai2010/tensorflow.svg)](https://travis-ci.org/chai2010/tensorflow)
[![GoDoc](https://godoc.org/github.com/chai2010/tensorflow?status.svg)](https://godoc.org/github.com/chai2010/tensorflow)

Tensorflow homepage:

- http://tensorflow.org/
- https://github.com/tensorflow/tensorflow

## Example

```Go
package main

import (
	tf "github.com/chai2010/tensorflow"
)

func main() {
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
```

BUGS
====

Report bugs to <chaishushan@gmail.com>.

Thanks!
