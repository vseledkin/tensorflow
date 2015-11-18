:: Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.
@echo off

setlocal

cd %~dp0

protoc.exe --cpp_out=.                                       ^
	.\tensorflow\core\framework\allocation_description.proto ^
	.\tensorflow\core\framework\attr_value.proto             ^
	.\tensorflow\core\framework\config.proto                 ^
	.\tensorflow\core\framework\device_attributes.proto      ^
	.\tensorflow\core\framework\function.proto               ^
	.\tensorflow\core\framework\graph.proto                  ^
	.\tensorflow\core\framework\kernel_def.proto             ^
	.\tensorflow\core\framework\op_def.proto                 ^
	.\tensorflow\core\framework\step_stats.proto             ^
	.\tensorflow\core\framework\summary.proto                ^
	.\tensorflow\core\framework\tensor.proto                 ^
	.\tensorflow\core\framework\tensor_description.proto     ^
	.\tensorflow\core\framework\tensor_shape.proto           ^
	.\tensorflow\core\framework\tensor_slice.proto           ^
	.\tensorflow\core\framework\types.proto

cd %~dp0

