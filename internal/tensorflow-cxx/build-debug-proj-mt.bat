:: Copyright 2015 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

:: ----------------------------------------------------------------------------
:: Setup MSVC
:: ----------------------------------------------------------------------------

:: VS2013
if not "x%VS120COMNTOOLS%" == "x" (
	echo Setup VS2013 Win32 ...
	call "%VS120COMNTOOLS%\..\..\VC\vcvarsall.bat"
	goto build
)

:: VS2012
if not "x%VS110COMNTOOLS%" == "x" (
	echo Setup VS2012 Win32 ...
	call "%VS110COMNTOOLS%\..\..\VC\vcvarsall.bat"
	goto build
)

:: VS2010
if not "x%VS100COMNTOOLS%" == "x" (
	echo Setup VS2010 Win32 ...
	call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat"
	goto build
)

goto end

:: ----------------------------------------------------------------------------
:: build app
:: ----------------------------------------------------------------------------

:build

mkdir zz_build_debug_proj_mt_tmp
cd    zz_build_debug_proj_mt_tmp

cmake ..^
	-DCMAKE_BUILD_TYPE=debug^
	-DCMAKE_INSTALL_PREFIX=..^
	^
	-DCMAKE_C_FLAGS_DEBUG="/MTd /Zi /Od /Ob0 /RTC1"^
	-DCMAKE_CXX_FLAGS_DEBUG="/MTd /Zi /Od /Ob0 /RTC1"^
	^
	-DCMAKE_C_FLAGS_RELEASE="/MT /O2 /Ob2 /DNDEBUG"^
	-DCMAKE_CXX_FLAGS_RELEASE="/MT /O2 /Ob2 /DNDEBUG"^
	^
	-DCMAKE_EXE_LINKER_FLAGS="/MANIFEST:NO"

cd ..

:: ----------------------------------------------------------------------------
:end

