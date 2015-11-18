# Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(TESORFLOW)

#------------------------------------------------------------------------------
# google tensorflow

set(TF_ROOT
	${CMAKE_CURRENT_SOURCE_DIR}/.
)

include_directories(AFTER
	${TF_ROOT}
)

#include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists-protobuf.txt)

#------------------------------------------------------------------------------
# tf hello app

add_executable(hello
	./hello.cc
)

#------------------------------------------------------------------------------
