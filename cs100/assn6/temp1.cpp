//================================================= 
// 
// Name: wong, christopher 
// Login id: wongc 
// Email: cwong030@student.ucr.edu 
// 
// Assignment name: assn6 
// Lab section: 022 
// 
// I hereby certify that the contents of this file 
// re ENTIRELY my own original work. 
// 
//================================================= 
 
 
//!This is very important and should not be printed 
//#include <iostream> 
 
// Standard iostream objects -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.3  Standard iostream objects 
// 
 


 */ 
 
#ifndef _GLIBCXX_IOSTREAM 
 
#pragma GCC system_header 
 
#ifndef _CPP_CPPCONFIG_WRAPPER 

 
#if __WORDSIZE == 32 
// Predefined symbols and macros -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
#ifndef _CXXCONFIG 
 
// Pick up any OS-specific definitions. 
// Specific definitions for GNU/Linux  -*- C++ -*- 
 
// Copyright (C) 2000, 2001, 2002, 2003 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
#ifndef _GLIBCXX_OS_DEFINES 
 
// System-specific #define, typedefs, corrections, etc, go here.  This 
// file will come before all others. 
 
// This keeps isanum, et al from being propagated as macros. 
 


   02111-1307 USA.  */ 
 
#ifndef	_FEATURES_H 
#define	_FEATURES_H	1 
 


   lack of any definitions) are defined by the file.  */ 
 
 


   for it.  */ 
#ifndef _LOOSE_KERNEL_NAMES 
# define __KERNEL_STRICT_NAMES 
#endif 
 


   were not defined then.  */ 
#if defined __GNUC__ && defined __GNUC_MINOR__ 
# define __GNUC_PREREQ(maj, min) \ 
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min)) 
#else 
# define __GNUC_PREREQ(maj, min) 0 
#endif 
 
 


/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */ 
#ifdef _GNU_SOURCE 
# undef  _ISOC99_SOURCE 
# define _ISOC99_SOURCE	1 
# undef  _POSIX_SOURCE 
# define _POSIX_SOURCE	1 
# undef  _POSIX_C_SOURCE 
# define _POSIX_C_SOURCE	200112L 
# undef  _XOPEN_SOURCE 
# define _XOPEN_SOURCE	600 
# undef  _XOPEN_SOURCE_EXTENDED 
# define _XOPEN_SOURCE_EXTENDED	1 
# undef	 _LARGEFILE64_SOURCE 
# define _LARGEFILE64_SOURCE	1 
# undef  _BSD_SOURCE 
# define _BSD_SOURCE	1 
# undef  _SVID_SOURCE 
# define _SVID_SOURCE	1 
# undef  _ATFILE_SOURCE 
# define _ATFILE_SOURCE	1 
#endif 
 


   define _BSD_SOURCE and _SVID_SOURCE.  */ 
#if (!defined __STRICT_ANSI__ && !defined _ISOC99_SOURCE && \ 
     !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE && \ 
     !defined _XOPEN_SOURCE && !defined _XOPEN_SOURCE_EXTENDED && \ 
     !defined _BSD_SOURCE && !defined _SVID_SOURCE) 
# define _BSD_SOURCE	1 
# define _SVID_SOURCE	1 
#endif 
 


   standard is widely adopted.  */ 
#if (defined _ISOC99_SOURCE || defined _ISOC9X_SOURCE \ 
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L)) 
# define __USE_ISOC99	1 
#endif 
 


   (and IEEE Std 1003.1b-1993 unless _XOPEN_SOURCE is defined).  */ 
#if ((!defined __STRICT_ANSI__ || (_XOPEN_SOURCE - 0) >= 500) && \ 
     !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE) 
# define _POSIX_SOURCE	1 
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500 
#  define _POSIX_C_SOURCE	2 
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600 
#  define _POSIX_C_SOURCE	199506L 
# else 
#  define _POSIX_C_SOURCE	200112L 
# endif 
#endif 
 
#if defined _POSIX_SOURCE || _POSIX_C_SOURCE >= 1 || defined _XOPEN_SOURCE 
# define __USE_POSIX	1 
#endif 
 
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE 
# define __USE_POSIX2	1 
#endif 
 
#if (_POSIX_C_SOURCE - 0) >= 199309L 
# define __USE_POSIX199309	1 
#endif 
 
#if (_POSIX_C_SOURCE - 0) >= 199506L 
# define __USE_POSIX199506	1 
#endif 
 
#if (_POSIX_C_SOURCE - 0) >= 200112L 
# define __USE_XOPEN2K		1 
#endif 
 
#ifdef	_XOPEN_SOURCE 
# define __USE_XOPEN	1 
# if (_XOPEN_SOURCE - 0) >= 500 
#  define __USE_XOPEN_EXTENDED	1 
#  define __USE_UNIX98	1 
#  undef _LARGEFILE_SOURCE 
#  define _LARGEFILE_SOURCE	1 
#  if (_XOPEN_SOURCE - 0) >= 600 
#   define __USE_XOPEN2K	1 
#   undef __USE_ISOC99 
#   define __USE_ISOC99		1 
#  endif 
# else 
#  ifdef _XOPEN_SOURCE_EXTENDED 
#   define __USE_XOPEN_EXTENDED	1 
#  endif 
# endif 
#endif 
 
#ifdef _LARGEFILE_SOURCE 
# define __USE_LARGEFILE	1 
#endif 
 
#ifdef _LARGEFILE64_SOURCE 
# define __USE_LARGEFILE64	1 
#endif 
 
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64 
# define __USE_FILE_OFFSET64	1 
#endif 
 
#if defined _BSD_SOURCE || defined _SVID_SOURCE 
# define __USE_MISC	1 
#endif 
 
#ifdef	_BSD_SOURCE 
# define __USE_BSD	1 
#endif 
 
#ifdef	_SVID_SOURCE 
# define __USE_SVID	1 
#endif 
 
#ifdef	_ATFILE_SOURCE 
# define __USE_ATFILE	1 
#endif 
 
#ifdef	_GNU_SOURCE 
# define __USE_GNU	1 
#endif 
 
#if defined _REENTRANT || defined _THREAD_SAFE 
# define __USE_REENTRANT	1 
#endif 
 
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0 \ 
    && defined __OPTIMIZE__ && __OPTIMIZE__ > 0 \ 
    && (__GNUC_PREREQ (4, 1) \ 
        || (defined __GNUC_RH_RELEASE__ && __GNUC_PREREQ (4, 0)) \ 
        || (defined __GNUC_RH_RELEASE__ && __GNUC_PREREQ (3, 4) \ 
            && __GNUC_MINOR__ == 4 \ 
            && (__GNUC_PATCHLEVEL__ > 2 \ 
                || (__GNUC_PATCHLEVEL__ == 2 && __GNUC_RH_RELEASE__ >= 8)))) 
# if _FORTIFY_SOURCE > 1 
#  define __USE_FORTIFY_LEVEL 2 
# else 
#  define __USE_FORTIFY_LEVEL 1 
# endif 
#else 
# define __USE_FORTIFY_LEVEL 0 
#endif 
 


/* wchar_t uses ISO 10646-1 (2nd ed., published 2000-09-15) / Unicode 3.1.  */ 
 


   the sonames of the shared libraries.  */ 
#undef  __GNU_LIBRARY__ 
 


   these macros to test for features in specific releases.  */ 
#define	__GLIBC__	2 
#define	__GLIBC_MINOR__	5 
 
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min)) 
 


/* This is here only because every header file already includes this one.  */ 
#ifndef __ASSEMBLER__ 
# ifndef _SYS_CDEFS_H 
#  include <sys/cdefs.h> 
# endif 
 


   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */ 
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT 
#  define __USE_LARGEFILE	1 
#  define __USE_LARGEFILE64	1 
# endif 
 
#endif	

/* Decide whether we can define 'extern inline' functions in headers.  */ 
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \ 
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ 
# define __USE_EXTERN_INLINES	1 
#endif 
 
 


   that will always return failure (and set errno to ENOSYS).  */ 


   based on the architecture being compiled for.  */ 
 
 
#if __WORDSIZE == 32 
# include <gnu/stubs-32.h> 
#elif __WORDSIZE == 64 
# include <gnu/stubs-64.h> 
#else 
# error "unexpected value for __WORDSIZE macro" 
#endif 
 
 
 
#endif	
 
 
// We must not see the optimized string functions GNU libc defines. 
#if defined __GLIBC__ && __GLIBC__ >= 2 
#endif 
 
#endif 
 
 
// Pick up any CPU-specific definitions. 
// Specific definitions for generic platforms  -*- C++ -*- 
 
// Copyright (C) 2005 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
#ifndef _GLIBCXX_CPU_DEFINES 
 
#endif 
 
 
// Debug mode support. Debug mode basic_string is not allowed to be 
// associated with std, because of locale and exception link 
// dependence. 
namespace __gnu_debug_def { } 
 
namespace __gnu_debug  
{  
  using namespace __gnu_debug_def; 
} 
 
#ifdef _GLIBCXX_DEBUG 
# define _GLIBCXX_STD __gnu_norm 
# define _GLIBCXX_EXTERN_TEMPLATE 0 
namespace __gnu_norm  
{  
  using namespace std;  
} 
namespace std 
{ 
  using namespace __gnu_debug_def __attribute__ ((strong)); 
} 
# if __NO_INLINE__ && !__GXX_WEAK__ 
#  warning debug mode without inlining may fail due to lack of weak symbols 
# endif 
#else 
# define _GLIBCXX_STD std 
#endif 
 


/* config.h.  Generated by configure.  */ 


/* Define to 1 if you have the `acosf' function. */ 
 


/* Define to 1 if you have the `asinf' function. */ 
 


/* Define to 1 if you have the `atan2f' function. */ 
 


/* Define to 1 if you have the `atanf' function. */ 
 


/* Define to 1 if you have the `ceilf' function. */ 
 


/* Define to 1 if you have the <complex.h> header file. */ 
 


/* Define to 1 if you have the `copysignf' function. */ 
 


/* Define to 1 if you have the `cosf' function. */ 
 


/* Define to 1 if you have the `coshl' function. */ 
 


/* Define to 1 if you have the <endian.h> header file. */ 
 


/* Define to 1 if you have the `expl' function. */ 
 


/* Define to 1 if you have the `fabsl' function. */ 
 


/* Define to 1 if you have the `finitef' function. */ 
 


/* Define to 1 if you have the <float.h> header file. */ 
 


/* Define to 1 if you have the `floorl' function. */ 
 


/* Define to 1 if you have the `fmodl' function. */ 
 


/* #undef _GLIBCXX_HAVE_FPCLASS */ 
 


/* #undef _GLIBCXX_HAVE_FP_H */ 
 


/* Define to 1 if you have the `frexpl' function. */ 
 


/* Define to 1 if you have the `getpagesize' function. */ 
 


   enabled). */ 
 


/* Define to 1 if you have the `hypotf' function. */ 
 


/* Define to 1 if you have the `iconv' function. */ 
 


/* Define to 1 if you have the `iconv_open' function. */ 
 


/* #undef _GLIBCXX_HAVE_IEEEFP_H */ 
 


/* Define to 1 if you have the <inttypes.h> header file. */ 
 


/* Define to 1 if you have the `isinff' function. */ 
 


/* Define to 1 if you have the `isnan' function. */ 
 


/* Define to 1 if you have the `isnanl' function. */ 
 


/* Define if LC_MESSAGES is available in <locale.h>. */ 
 


/* Define to 1 if you have the `ldexpl' function. */ 
 


/* Define to 1 if you have the `m' library (-lm). */ 
 


/* Only used in build directory testsuite_hooks.h. */ 
 


/* Only used in build directory testsuite_hooks.h. */ 
 


/* Define to 1 if you have the <locale.h> header file. */ 
 


/* Define to 1 if you have the `log10l' function. */ 
 


/* Define to 1 if you have the `logl' function. */ 
 


/* #undef _GLIBCXX_HAVE_MACHINE_ENDIAN_H */ 
 


/* #undef _GLIBCXX_HAVE_MACHINE_PARAM_H */ 
 


/* Define to 1 if you have the <memory.h> header file. */ 
 


/* Define to 1 if you have the `modf' function. */ 
 


/* Define to 1 if you have the `modfl' function. */ 
 


/* #undef _GLIBCXX_HAVE_NAN_H */ 
 


/* Define if poll is available in <poll.h>. */ 
 


/* Define to 1 if you have the `powl' function. */ 
 


/* #undef _GLIBCXX_HAVE_QFPCLASS */ 
 


/* Define if sigsetjmp is available. */ 
 


/* Define to 1 if you have the `sincosf' function. */ 
 


/* Define to 1 if you have the `sinf' function. */ 
 


/* Define to 1 if you have the `sinhl' function. */ 
 


/* Define to 1 if you have the `sqrtf' function. */ 
 


/* Define to 1 if you have the <stdint.h> header file. */ 
 


/* Define to 1 if you have the <strings.h> header file. */ 
 


/* Define to 1 if you have the `strtof' function. */ 
 


/* Define to 1 if you have the <sys/filio.h> header file. */ 


/* Define to 1 if you have the <sys/ioctl.h> header file. */ 
 


/* Define to 1 if you have the <sys/isa_defs.h> header file. */ 


/* Define to 1 if you have the <sys/machine.h> header file. */ 


/* Define to 1 if you have the <sys/param.h> header file. */ 


/* Define to 1 if you have the <sys/resource.h> header file. */ 
 


/* Define to 1 if you have the <sys/stat.h> header file. */ 
 


/* Define to 1 if you have the <sys/types.h> header file. */ 
 


/* Define if S_IFREG is available in <sys/stat.h>. */ 


/* Define if S_IFREG is available in <sys/stat.h>. */ 
 


/* Define to 1 if you have the `tanhf' function. */ 
 


/* Define to 1 if you have the `tanl' function. */ 
 


/* Define to 1 if you have the <unistd.h> header file. */ 
 


/* Defined if vswscanf exists. */ 
 


/* Define to 1 if you have the <wchar.h> header file. */ 
 


/* Define to 1 if you have the <wctype.h> header file. */ 
 


/* Define to 1 if you have the `_acosf' function. */ 


/* Define to 1 if you have the `_acosl' function. */ 


/* Define to 1 if you have the `_asinf' function. */ 


/* Define to 1 if you have the `_asinl' function. */ 


/* Define to 1 if you have the `_atan2f' function. */ 


/* Define to 1 if you have the `_atan2l' function. */ 


/* Define to 1 if you have the `_atanf' function. */ 


/* Define to 1 if you have the `_atanl' function. */ 


/* Define to 1 if you have the `_ceilf' function. */ 


/* Define to 1 if you have the `_ceill' function. */ 


/* Define to 1 if you have the `_copysign' function. */ 


/* Define to 1 if you have the `_copysignl' function. */ 


/* Define to 1 if you have the `_cosf' function. */ 


/* Define to 1 if you have the `_coshf' function. */ 


/* Define to 1 if you have the `_coshl' function. */ 


/* Define to 1 if you have the `_cosl' function. */ 


/* Define to 1 if you have the `_expf' function. */ 


/* Define to 1 if you have the `_expl' function. */ 


/* Define to 1 if you have the `_fabsf' function. */ 


/* Define to 1 if you have the `_fabsl' function. */ 


/* Define to 1 if you have the `_finite' function. */ 


/* Define to 1 if you have the `_finitef' function. */ 


/* Define to 1 if you have the `_finitel' function. */ 


/* Define to 1 if you have the `_floorf' function. */ 


/* Define to 1 if you have the `_floorl' function. */ 


/* Define to 1 if you have the `_fmodf' function. */ 


/* Define to 1 if you have the `_fmodl' function. */ 


/* Define to 1 if you have the `_fpclass' function. */ 


/* Define to 1 if you have the `_frexpf' function. */ 


/* Define to 1 if you have the `_frexpl' function. */ 


/* Define to 1 if you have the `_hypot' function. */ 


/* Define to 1 if you have the `_hypotf' function. */ 


/* Define to 1 if you have the `_hypotl' function. */ 


/* Define to 1 if you have the `_isinf' function. */ 


/* Define to 1 if you have the `_isinff' function. */ 


/* Define to 1 if you have the `_isinfl' function. */ 


/* Define to 1 if you have the `_isnan' function. */ 


/* Define to 1 if you have the `_isnanf' function. */ 


/* Define to 1 if you have the `_isnanl' function. */ 


/* Define to 1 if you have the `_ldexpf' function. */ 


/* Define to 1 if you have the `_ldexpl' function. */ 


/* Define to 1 if you have the `_log10f' function. */ 


/* Define to 1 if you have the `_log10l' function. */ 


/* Define to 1 if you have the `_logf' function. */ 


/* Define to 1 if you have the `_logl' function. */ 


/* Define to 1 if you have the `_modf' function. */ 


/* Define to 1 if you have the `_modff' function. */ 


/* Define to 1 if you have the `_modfl' function. */ 


/* Define to 1 if you have the `_powf' function. */ 


/* Define to 1 if you have the `_powl' function. */ 


/* Define to 1 if you have the `_qfpclass' function. */ 


/* Define to 1 if you have the `_sincos' function. */ 


/* Define to 1 if you have the `_sincosf' function. */ 


/* Define to 1 if you have the `_sincosl' function. */ 


/* Define to 1 if you have the `_sinf' function. */ 


/* Define to 1 if you have the `_sinhf' function. */ 


/* Define to 1 if you have the `_sinhl' function. */ 


/* Define to 1 if you have the `_sinl' function. */ 


/* Define to 1 if you have the `_sqrtf' function. */ 


/* Define to 1 if you have the `_sqrtl' function. */ 


/* Define to 1 if you have the `_tanf' function. */ 


/* Define to 1 if you have the `_tanhf' function. */ 


/* Define to 1 if you have the `_tanhl' function. */ 


/* Define to 1 if you have the `_tanl' function. */ 


/* Define if the compiler/host combination has __builtin_abs. */ 
 


/* Define if the compiler/host combination has __builtin_cosf. */ 
 


/* Define if the compiler/host combination has __builtin_fabs. */ 
 


/* Define if the compiler/host combination has __builtin_fabsl. */ 
 


/* Define if the compiler/host combination has __builtin_sin. */ 
 


/* Define if the compiler/host combination has __builtin_sinl. */ 
 


/* Define if the compiler/host combination has __builtin_sqrtf. */ 
 


/* Define to 1 if you have the `__signbit' function. */ 
 


/* Define to 1 if you have the `__signbitl' function. */ 
 


/* #undef _GLIBCXX_PACKAGE */ 
 


/* Define to the full name of this package. */ 
 


/* Define to the one symbol short name of this package. */ 
 


/* Define to 1 if you have the ANSI C header files. */ 
 


/* #undef _GLIBCXX_VERSION */ 
 


/* #undef _GLIBCXX_CONCEPT_CHECKS */ 
 


/* #undef _GLIBCXX_FULLY_DYNAMIC_STRING */ 
 


/* Define if compatibility should be provided for -mlong-double-64. */ 
 


/* Define if using setrlimit to set resource limits during "make check" */ 
 


/* Define if the compiler is configured for setjmp/longjmp exceptions. */ 


/* Define to use GNU symbol versioning in the shared library. */ 
 


   <stdio.h>, and <stdlib.h> can be used or exposed. */ 
 


   functions to be present. */ 
 


   in namespace std. */ 
 


/* Define if LFS support is available. */ 
 


/* Define if NLS translations are to be used. */ 
 


/* Define if compatibility should be provided for -mlong-double-64. */ 
#undef _GLIBCXX_LONG_DOUBLE_COMPAT 
 
// XXX GLIBCXX_ABI Deprecated 
// Namespace associations for long double 128 mode. 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
# define _GLIBCXX_LDBL_NAMESPACE __gnu_cxx_ldbl128:: 
# define _GLIBCXX_BEGIN_LDBL_NAMESPACE namespace __gnu_cxx_ldbl128 { 
# define _GLIBCXX_END_LDBL_NAMESPACE } 
namespace std 
{ 
  namespace __gnu_cxx_ldbl128 { } 
  using namespace __gnu_cxx_ldbl128 __attribute__((__strong__)); 
} 
#else 
# define _GLIBCXX_LDBL_NAMESPACE 
# define _GLIBCXX_BEGIN_LDBL_NAMESPACE 
# define _GLIBCXX_END_LDBL_NAMESPACE 
#endif 
 
// Allow use of "export template." This is currently not a feature 
// that g++ supports. 
// #define _GLIBCXX_EXPORT_TEMPLATE 1 
 
// Allow use of the GNU syntax extension, "extern template." This 
// extension is fully documented in the g++ manual, but in a nutshell, 
// it inhibits all implicit instantiations and is used throughout the 
// library to avoid multiple weak definitions for required types that 
// are already explicitly instantiated in the library binary. This 
// substantially reduces the binary size of resulting executables. 
#ifndef _GLIBCXX_EXTERN_TEMPLATE 
# define _GLIBCXX_EXTERN_TEMPLATE 1 
#endif 
 
// Certain function definitions that are meant to be overridable from 
// user code are decorated with this macro.  For some targets, this 
// macro causes these definitions to be weak. 
#ifndef _GLIBCXX_WEAK_DEFINITION 
# define _GLIBCXX_WEAK_DEFINITION 
#endif 
 
// The remainder of the prewritten config is automatic; all the 
// user hooks are listed above. 
 
// Create a boolean flag to be used to determine if --fast-math is set. 
#ifdef __FAST_MATH__ 
# define _GLIBCXX_FAST_MATH 1 
#else 
# define _GLIBCXX_FAST_MATH 0 
#endif 
 
// This marks string literals in header files to be extracted for eventual 
// translation.  It is primarily used for messages in thrown exceptions; see 
// src/functexcept.cc.  We use __N because the more traditional _N is used 
// for something else under certain OSes (see BADNAMES). 
 
// End of prewritten config; the discovered settings follow. 


/* config.h.in.  Generated from configure.ac by autoheader.  */ 
 


/* Define to 1 if you have the `acosl' function. */ 
 


/* Define to 1 if you have the `asinl' function. */ 
 


/* Define to 1 if you have the `atan2l' function. */ 
 


/* Define to 1 if you have the `atanl' function. */ 
 


/* Define to 1 if you have the `ceill' function. */ 
 


/* Define to 1 if you have the `copysign' function. */ 
 


/* Define to 1 if you have the `copysignl' function. */ 
 


/* Define to 1 if you have the `coshf' function. */ 
 


/* Define to 1 if you have the `cosl' function. */ 
 


/* Define to 1 if you have the `expf' function. */ 
 


/* Define to 1 if you have the `fabsf' function. */ 
 


/* Define to 1 if you have the `finite' function. */ 
 


/* Define to 1 if you have the `finitel' function. */ 
 


/* Define to 1 if you have the `floorf' function. */ 
 


/* Define to 1 if you have the `fmodf' function. */ 
 


/* Define to 1 if you have the `fpclass' function. */ 


/* Define to 1 if you have the <fp.h> header file. */ 


/* Define to 1 if you have the `frexpf' function. */ 
 


/* Define to 1 if you have the <gconv.h> header file. */ 
 


   enabled). */ 
 


/* Define to 1 if you have the `hypotf' function. */ 
 


/* Define to 1 if you have the `iconv' function. */ 
 


/* Define to 1 if you have the `iconv_open' function. */ 
 


/* #undef _GLIBCXX_HAVE_IEEEFP_H */ 
 


/* Define to 1 if you have the <inttypes.h> header file. */ 
 


/* Define to 1 if you have the `isinff' function. */ 
 


/* Define to 1 if you have the `isnan' function. */ 
 


/* Define to 1 if you have the `isnanl' function. */ 
 


/* Define if LC_MESSAGES is available in <locale.h>. */ 
 


/* Define to 1 if you have the `ldexpl' function. */ 
 


/* Define to 1 if you have the `m' library (-lm). */ 
 


/* Only used in build directory testsuite_hooks.h. */ 
 


/* Only used in build directory testsuite_hooks.h. */ 
 


/* Define to 1 if you have the <locale.h> header file. */ 
 


/* Define to 1 if you have the `log10l' function. */ 
 


/* Define to 1 if you have the `logl' function. */ 
 


/* #undef _GLIBCXX_HAVE_MACHINE_ENDIAN_H */ 
 


/* #undef _GLIBCXX_HAVE_MACHINE_PARAM_H */ 
 


/* Define to 1 if you have the <memory.h> header file. */ 
 


/* Define to 1 if you have the `modf' function. */ 
 


/* Define to 1 if you have the `modfl' function. */ 
 


/* #undef _GLIBCXX_HAVE_NAN_H */ 
 


/* Define if poll is available in <poll.h>. */ 
 


/* Define to 1 if you have the `powl' function. */ 
 


/* #undef _GLIBCXX_HAVE_QFPCLASS */ 
 


/* Define if sigsetjmp is available. */ 
 


/* Define to 1 if you have the `sincosf' function. */ 
 


/* Define to 1 if you have the `sinf' function. */ 
 


/* Define to 1 if you have the `sinhl' function. */ 
 


/* Define to 1 if you have the `sqrtf' function. */ 
 


/* Define to 1 if you have the <stdint.h> header file. */ 
 


/* Define to 1 if you have the <strings.h> header file. */ 
 


/* Define to 1 if you have the `strtof' function. */ 
 


/* Define to 1 if you have the <sys/filio.h> header file. */ 


/* Define to 1 if you have the <sys/ioctl.h> header file. */ 
 


/* Define to 1 if you have the <sys/isa_defs.h> header file. */ 


/* Define to 1 if you have the <sys/machine.h> header file. */ 


/* Define to 1 if you have the <sys/param.h> header file. */ 


/* Define to 1 if you have the <sys/resource.h> header file. */ 
 


/* Define to 1 if you have the <sys/stat.h> header file. */ 
 


/* Define to 1 if you have the <sys/types.h> header file. */ 
 


/* Define if S_IFREG is available in <sys/stat.h>. */ 


/* Define if S_IFREG is available in <sys/stat.h>. */ 
 


/* Define to 1 if you have the `tanhf' function. */ 
 


/* Define to 1 if you have the `tanl' function. */ 
 


/* Define to 1 if you have the <unistd.h> header file. */ 
 


/* Defined if vswscanf exists. */ 
 


/* Define to 1 if you have the <wchar.h> header file. */ 
 


/* Define to 1 if you have the <wctype.h> header file. */ 
 


/* Define to 1 if you have the `_acosf' function. */ 


/* Define to 1 if you have the `_acosl' function. */ 


/* Define to 1 if you have the `_asinf' function. */ 


/* Define to 1 if you have the `_asinl' function. */ 


/* Define to 1 if you have the `_atan2f' function. */ 


/* Define to 1 if you have the `_atan2l' function. */ 


/* Define to 1 if you have the `_atanf' function. */ 


/* Define to 1 if you have the `_atanl' function. */ 


/* Define to 1 if you have the `_ceilf' function. */ 


/* Define to 1 if you have the `_ceill' function. */ 


/* Define to 1 if you have the `_copysign' function. */ 


/* Define to 1 if you have the `_copysignl' function. */ 


/* Define to 1 if you have the `_cosf' function. */ 


/* Define to 1 if you have the `_coshf' function. */ 


/* Define to 1 if you have the `_coshl' function. */ 


/* Define to 1 if you have the `_cosl' function. */ 


/* Define to 1 if you have the `_expf' function. */ 


/* Define to 1 if you have the `_expl' function. */ 


/* Define to 1 if you have the `_fabsf' function. */ 


/* Define to 1 if you have the `_fabsl' function. */ 


/* Define to 1 if you have the `_finite' function. */ 


/* Define to 1 if you have the `_finitef' function. */ 


/* Define to 1 if you have the `_finitel' function. */ 


/* Define to 1 if you have the `_floorf' function. */ 


/* Define to 1 if you have the `_floorl' function. */ 


/* Define to 1 if you have the `_fmodf' function. */ 


/* Define to 1 if you have the `_fmodl' function. */ 


/* Define to 1 if you have the `_fpclass' function. */ 


/* Define to 1 if you have the `_frexpf' function. */ 


/* Define to 1 if you have the `_frexpl' function. */ 


/* Define to 1 if you have the `_hypot' function. */ 


/* Define to 1 if you have the `_hypotf' function. */ 


/* Define to 1 if you have the `_hypotl' function. */ 


/* Define to 1 if you have the `_isinf' function. */ 


/* Define to 1 if you have the `_isinff' function. */ 


/* Define to 1 if you have the `_isinfl' function. */ 


/* Define to 1 if you have the `_isnan' function. */ 


/* Define to 1 if you have the `_isnanf' function. */ 


/* Define to 1 if you have the `_isnanl' function. */ 


/* Define to 1 if you have the `_ldexpf' function. */ 


/* Define to 1 if you have the `_ldexpl' function. */ 


/* Define to 1 if you have the `_log10f' function. */ 


/* Define to 1 if you have the `_log10l' function. */ 


/* Define to 1 if you have the `_logf' function. */ 


/* Define to 1 if you have the `_logl' function. */ 


/* Define to 1 if you have the `_modf' function. */ 


/* Define to 1 if you have the `_modff' function. */ 


/* Define to 1 if you have the `_modfl' function. */ 


/* Define to 1 if you have the `_powf' function. */ 


/* Define to 1 if you have the `_powl' function. */ 


/* Define to 1 if you have the `_qfpclass' function. */ 


/* Define to 1 if you have the `_sincos' function. */ 


/* Define to 1 if you have the `_sincosf' function. */ 


/* Define to 1 if you have the `_sincosl' function. */ 


/* Define to 1 if you have the `_sinf' function. */ 


/* Define to 1 if you have the `_sinhf' function. */ 


/* Define to 1 if you have the `_sinhl' function. */ 


/* Define to 1 if you have the `_sinl' function. */ 


/* Define to 1 if you have the `_sqrtf' function. */ 


/* Define to 1 if you have the `_sqrtl' function. */ 


/* Define to 1 if you have the `_tanf' function. */ 


/* Define to 1 if you have the `_tanhf' function. */ 


/* Define to 1 if you have the `_tanhl' function. */ 


/* Define to 1 if you have the `_tanl' function. */ 


/* Define if the compiler/host combination has __builtin_abs. */ 
 


/* Define if the compiler/host combination has __builtin_cosf. */ 
 


/* Define if the compiler/host combination has __builtin_fabs. */ 
 


/* Define if the compiler/host combination has __builtin_fabsl. */ 
 


/* Define if the compiler/host combination has __builtin_sin. */ 
 


/* Define if the compiler/host combination has __builtin_sinl. */ 
 


/* Define if the compiler/host combination has __builtin_sqrtf. */ 
 


/* Define to 1 if you have the `__signbit' function. */ 
 


/* Define to 1 if you have the `__signbitl' function. */ 
 


/* #undef _GLIBCXX_PACKAGE */ 
 


/* Define to the full name of this package. */ 
 


/* Define to the one symbol short name of this package. */ 
 


/* Define to 1 if you have the ANSI C header files. */ 
 


/* #undef _GLIBCXX_VERSION */ 
 


/* #undef _GLIBCXX_CONCEPT_CHECKS */ 
 


/* #undef _GLIBCXX_FULLY_DYNAMIC_STRING */ 
 


/* Define if compatibility should be provided for -mlong-double-64. */ 
 


/* #undef _GLIBCXX_PTRDIFF_T_IS_INT */ 
 


/* Define if size_t is unsigned int. */ 


/* Define if the compiler is configured for setjmp/longjmp exceptions. */ 


/* Define to use GNU symbol versioning in the shared library. */ 
 


   <stdio.h>, and <stdlib.h> can be used or exposed. */ 
 


   functions to be present. */ 
 


   in namespace std. */ 
 


/* Define if LFS support is available. */ 
 


/* Define if NLS translations are to be used. */ 
 

 
// Output streams -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.6.2  Output streams 
// 
 


 */ 
 
#ifndef _GLIBCXX_OSTREAM 
 
#pragma GCC system_header 
 
// Iostreams base classes -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.4  Iostreams base classes 
// 
 


 */ 
 
#ifndef _GLIBCXX_IOS 
 
#pragma GCC system_header 
 
// Forwarding declarations -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.2  Forward declarations 
// 
 


 */ 
 
#ifndef _GLIBCXX_IOSFWD 
 
#pragma GCC system_header 
 
// Wrapper for underlying C-language localization -*- C++ -*- 
 
// Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 22.8  Standard locale categories. 
// 
 
// Written by Benjamin Kosnik <bkoz@redhat.com> 
 
#ifndef _C_LOCALE_H 
 
#pragma GCC system_header 
 
#include <cstring>              // This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CSTRING_HEADER 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_STRING_H 
#define	_STRING_H	1 
 
 
__BEGIN_DECLS 
 


/* Copy N bytes of SRC to DEST.  */ 
extern void *memcpy (void *__restrict __dest, 
		     __const void *__restrict __src, size_t __n) 
     __THROW __nonnull ((1, 2)); 


   correct behavior for overlapping strings.  */ 
extern void *memmove (void *__dest, __const void *__src, size_t __n) 
     __THROW __nonnull ((1, 2)); 
__END_NAMESPACE_STD 
 


   or NULL if C was not found in the first N bytes of SRC.  */ 
#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN 
extern void *memccpy (void *__restrict __dest, __const void *__restrict __src, 
		      int __c, size_t __n) 
     __THROW __nonnull ((1, 2)); 
#endif 

/* Set N bytes of S to C.  */ 
extern void *memset (void *__s, int __c, size_t __n) __THROW __nonnull ((1)); 
 


/* Search N bytes of S for C.  */ 
extern void *memchr (__const void *__s, int __c, size_t __n) 
      __THROW __attribute_pure__ __nonnull ((1)); 
__END_NAMESPACE_STD 
 
#ifdef __USE_GNU 


   length limit.  */ 
extern void *rawmemchr (__const void *__s, int __c) 
     __THROW __attribute_pure__ __nonnull ((1)); 
 


/* Copy SRC to DEST.  */ 
extern char *strcpy (char *__restrict __dest, __const char *__restrict __src) 
     __THROW __nonnull ((1, 2)); 


/* Append SRC onto DEST.  */ 
extern char *strcat (char *__restrict __dest, __const char *__restrict __src) 
     __THROW __nonnull ((1, 2)); 


/* Compare S1 and S2.  */ 
extern int strcmp (__const char *__s1, __const char *__s2) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 


/* Compare the collated forms of S1 and S2.  */ 
extern int strcoll (__const char *__s1, __const char *__s2) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 


   This is not standardsized but something like will come.  */ 
# include <xlocale.h> 
 


/* Put a transformation of SRC into no more than N bytes of DEST.  */ 
extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n, 
			 __locale_t __l) __THROW __nonnull ((2, 4)); 
#endif 
 
#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   appears before STRING[N].  */ 
#if defined __USE_GNU 
extern char *strndup (__const char *__string, size_t __n) 
     __THROW __attribute_malloc__ __nonnull ((1)); 
#endif 
 
#if defined __USE_GNU && defined __GNUC__ 


/* Return an alloca'd copy of at most N bytes of string.  */ 
# define strndupa(s, n)							      \ 
  (__extension__							      \ 
    ({									      \ 
      __const char *__old = (s);					      \ 
      size_t __len = strnlen (__old, (n));				      \ 
      char *__new = (char *) __builtin_alloca (__len + 1);		      \ 
      __new[__len] = '\0';						      \ 
      (char *) memcpy (__new, __old, __len);				      \ 
    })) 
#endif 
 
__BEGIN_NAMESPACE_STD 


/* Find the last occurrence of C in S.  */ 
extern char *strrchr (__const char *__s, int __c) 
     __THROW __attribute_pure__ __nonnull ((1)); 
__END_NAMESPACE_STD 
 
#ifdef __USE_GNU 


   the closing NUL byte in case C is not found in S.  */ 
extern char *strchrnul (__const char *__s, int __c) 
     __THROW __attribute_pure__ __nonnull ((1)); 
#endif 
 
__BEGIN_NAMESPACE_STD 


   consists entirely of characters not in REJECT.  */ 
extern size_t strcspn (__const char *__s, __const char *__reject) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 


   consists entirely of characters in ACCEPT.  */ 
extern size_t strspn (__const char *__s, __const char *__accept) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 


/* Find the first occurrence of NEEDLE in HAYSTACK.  */ 
extern char *strstr (__const char *__haystack, __const char *__needle) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 
 
 


   passed between calls are stored in SAVE_PTR.  */ 
extern char *__strtok_r (char *__restrict __s, 
			 __const char *__restrict __delim, 
			 char **__restrict __save_ptr) 
     __THROW __nonnull ((2, 3)); 
#if defined __USE_POSIX || defined __USE_MISC 
extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim, 
		       char **__restrict __save_ptr) 
     __THROW __nonnull ((2, 3)); 
#endif 
 
#ifdef __USE_GNU 


   HAYSTACK is HAYSTACKLEN bytes long.  */ 
extern void *memmem (__const void *__haystack, size_t __haystacklen, 
		     __const void *__needle, size_t __needlelen) 
     __THROW __attribute_pure__ __nonnull ((1, 3)); 
 


   last written byte.  */ 
extern void *__mempcpy (void *__restrict __dest, 
			__const void *__restrict __src, size_t __n) 
     __THROW __nonnull ((1, 2)); 
extern void *mempcpy (void *__restrict __dest, 
		      __const void *__restrict __src, size_t __n) 
     __THROW __nonnull ((1, 2)); 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   If no '\0' terminator is found in that many characters, return MAXLEN.  */ 
extern size_t strnlen (__const char *__string, size_t __maxlen) 
     __THROW __attribute_pure__ __nonnull ((1)); 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   preferred.  */ 
# if defined __USE_XOPEN2K && !defined __USE_GNU 


   ERRNUM.  */ 
#  ifdef __REDIRECT_NTH 
extern int __REDIRECT_NTH (strerror_r, 
			   (int __errnum, char *__buf, size_t __buflen), 
			   __xpg_strerror_r) __nonnull ((2)); 
#  else 
extern int __xpg_strerror_r (int __errnum, char *__buf, size_t __buflen) 
     __THROW __nonnull ((2)); 
#   define strerror_r __xpg_strerror_r 
#  endif 
# else 


   used.  */ 
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) 
     __THROW __nonnull ((2)); 
# endif 
#endif 
 


   the namespace rules does not allow this.  */ 
extern void __bzero (void *__s, size_t __n) __THROW __nonnull ((1)); 
 
#ifdef __USE_BSD 


/* Set N bytes of S to 0.  */ 
extern void bzero (void *__s, size_t __n) __THROW __nonnull ((1)); 
 


/* Find the first occurrence of C in S (same as strchr).  */ 
extern char *index (__const char *__s, int __c) 
     __THROW __attribute_pure__ __nonnull ((1)); 
 


   The least-significant bit is position 1, the most-significant 32.  */ 
extern int ffs (int __i) __THROW __attribute__ ((__const__)); 
 


   platforms.  */ 
# ifdef	__USE_GNU 
extern int ffsl (long int __l) __THROW __attribute__ ((__const__)); 
#  ifdef __GNUC__ 
__extension__ extern int ffsll (long long int __ll) 
     __THROW __attribute__ ((__const__)); 
#  endif 
# endif 
 


/* Compare no more than N chars of S1 and S2, ignoring case.  */ 
extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n) 
     __THROW __attribute_pure__ __nonnull ((1, 2)); 
#endif 

   of the global one.  */ 
extern int strcasecmp_l (__const char *__s1, __const char *__s2, 
			 __locale_t __loc) 
     __THROW __attribute_pure__ __nonnull ((1, 2, 3)); 
 
extern int strncasecmp_l (__const char *__s1, __const char *__s2, 
			  size_t __n, __locale_t __loc) 
     __THROW __attribute_pure__ __nonnull ((1, 2, 4)); 
#endif 
 
#ifdef	__USE_BSD 


   terminating it with a '\0', and update *STRINGP to point past it.  */ 
extern char *strsep (char **__restrict __stringp, 
		     __const char *__restrict __delim) 
     __THROW __nonnull ((1, 2)); 
#endif 
 
#ifdef	__USE_GNU 


/* Return a string describing the meaning of the signal number in SIG.  */ 
extern char *strsignal (int __sig) __THROW; 
 


   the last character written into DEST.  */ 
extern char *__stpncpy (char *__restrict __dest, 
			__const char *__restrict __src, size_t __n) 
     __THROW __nonnull ((1, 2)); 
extern char *stpncpy (char *__restrict __dest, 
		      __const char *__restrict __src, size_t __n) 
     __THROW __nonnull ((1, 2)); 
 


/* Frobnicate N bytes of S.  */ 
extern void *memfrob (void *__s, size_t __n) __THROW __nonnull ((1)); 
 
# ifndef basename 


   available.  */ 
extern char *basename (__const char *__filename) __THROW __nonnull ((1)); 
# endif 
#endif 
 
 
#if defined __GNUC__ && __GNUC__ >= 2 
# if defined __OPTIMIZE__ && !defined __OPTIMIZE_SIZE__ \ 
     && !defined __NO_INLINE__ && !defined __cplusplus 


   One can inhibit all optimizations by defining __NO_STRING_INLINES.  */ 
 


/* These are generic optimizations which do not add too much inline code.  */ 
#  include <bits/string2.h> 
# endif 
 
# if __USE_FORTIFY_LEVEL > 0 && !defined __cplusplus 


#endif /* string.h  */ 
 
 
namespace std { 
  using ::size_t; 
  using ::memchr; 
  using ::strcat; 
  using ::strcspn; 
  using ::strncpy; 
  using ::strtok; 
  using ::memcmp; 
  using ::strchr; 
  using ::strerror; 
  using ::strpbrk; 
  using ::strxfrm; 
  using ::memcpy; 
  using ::strcmp; 
  using ::strlen; 
  using ::strrchr; 
  using ::memmove; 
  using ::strcoll; 
  using ::strncat; 
  using ::strspn; 
  using ::memset; 
  using ::strcpy; 
  using ::strncmp; 
  using ::strstr; 
} 
 
#endif #endif // CSTRING_HEADER 
 
#include <cstdio>               // This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CSTDIO_HEADER 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef _STDIO_H 
 
#if !defined __need_FILE && !defined __need___FILE 
# define _STDIO_H	1 
# include <features.h> 
 
__BEGIN_DECLS 
 
# define __need_size_t 
# define __need_NULL 
# include <stddef.h> 
 
# include <bits/types.h> 
# define __need_FILE 
# define __need___FILE 
#endif 

/* The opaque type of streams.  This is the definition used elsewhere.  */ 
typedef struct _IO_FILE FILE; 
__END_NAMESPACE_STD 
#if defined __USE_LARGEFILE64 || defined __USE_SVID || defined __USE_POSIX \ 
    || defined __USE_BSD || defined __USE_ISOC99 || defined __USE_XOPEN \ 
    || defined __USE_POSIX2 
__USING_NAMESPACE_STD(FILE) 
#endif 
 
# define __FILE_defined	1 
#endif 

/* The opaque type of streams.  This is the definition used elsewhere.  */ 
typedef struct _IO_FILE __FILE; 
 
# define ____FILE_defined	1 
#endif 

/* The type of the second argument to `fgetpos' and `fsetpos'.  */ 
__BEGIN_NAMESPACE_STD 
#ifndef __USE_FILE_OFFSET64 
typedef _G_fpos_t fpos_t; 
#else 
typedef _G_fpos64_t fpos_t; 
#endif 
__END_NAMESPACE_STD 
#ifdef __USE_LARGEFILE64 
typedef _G_fpos64_t fpos64_t; 
#endif 
 


#define _IOLBF 1		

 
 


   Some things throughout the library rely on this being -1.  */ 
#ifndef EOF 
# define EOF (-1) 
#endif 
 
 


   These values should not be changed.  */ 
#define SEEK_SET	0	

#define SEEK_END	2	

/* Default path prefix for `tempnam' and `tmpnam'.  */ 
# define P_tmpdir	"/tmp" 
#endif 
 
 


   FILENAME_MAX	Maximum length of a filename.  */ 


   02111-1307 USA.  */ 
 
#if !defined _STDIO_H && !defined __need_FOPEN_MAX && !defined __need_IOV_MAX 
# error "Never include <bits/stdio_lim.h> directly; use <stdio.h> instead." 
#endif 
 
#ifdef _STDIO_H 
# define L_tmpnam 20 
# define TMP_MAX 238328 
# define FILENAME_MAX 4096 
 
# ifdef __USE_POSIX 
#  define L_ctermid 9 
#  define L_cuserid 9 
# endif 
#endif 
 
#if defined __need_FOPEN_MAX || defined _STDIO_H 
# undef  FOPEN_MAX 
# define FOPEN_MAX 16 
#endif 
 
#if defined __need_IOV_MAX && !defined IOV_MAX 
# define IOV_MAX 1024 
#endif 
 
 
 


extern struct _IO_FILE *stdin;		/* Standard input stream.  */ 
extern struct _IO_FILE *stdout;		

extern struct _IO_FILE *stderr;		/* Standard error output stream.  */ 
#ifdef __STDC__ 


/* Remove file FILENAME.  */ 
extern int remove (__const char *__filename) __THROW; 


/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */ 
extern int renameat (int __oldfd, __const char *__old, int __newfd, 
		     __const char *__new) __THROW; 
#endif 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
#ifndef __USE_FILE_OFFSET64 
extern FILE *tmpfile (void); 
#else 
# ifdef __REDIRECT 
extern FILE *__REDIRECT (tmpfile, (void), tmpfile64); 
# else 
#  define tmpfile tmpfile64 
# endif 
#endif 
 
#ifdef __USE_LARGEFILE64 
extern FILE *tmpfile64 (void); 
#endif 
 


   that it does not allow S to be NULL.  */ 
extern char *tmpnam_r (char *__s) __THROW; 
#endif 
 
 
#if defined __USE_SVID || defined __USE_XOPEN 


   is allocated by `malloc'.  */ 
extern char *tempnam (__const char *__dir, __const char *__pfx) 
     __THROW __attribute_malloc__; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern int fclose (FILE *__stream); 


   marked with __THROW.  */ 
extern int fflush (FILE *__stream); 
__END_NAMESPACE_STD 
 
#ifdef __USE_MISC 


   therefore not marked with __THROW.  */ 
extern int fflush_unlocked (FILE *__stream); 
#endif 
 
#ifdef __USE_GNU 


   therefore not marked with __THROW.  */ 
extern int fcloseall (void); 
#endif 
 
 
__BEGIN_NAMESPACE_STD 
#ifndef __USE_FILE_OFFSET64 


   marked with __THROW.  */ 
extern FILE *fopen (__const char *__restrict __filename, 
		    __const char *__restrict __modes); 


   marked with __THROW.  */ 
extern FILE *freopen (__const char *__restrict __filename, 
		      __const char *__restrict __modes, 
		      FILE *__restrict __stream); 
#else 
# ifdef __REDIRECT 
extern FILE *__REDIRECT (fopen, (__const char *__restrict __filename, 
				 __const char *__restrict __modes), fopen64); 
extern FILE *__REDIRECT (freopen, (__const char *__restrict __filename, 
				   __const char *__restrict __modes, 
				   FILE *__restrict __stream), freopen64); 
# else 
#  define fopen fopen64 
#  define freopen freopen64 
# endif 
#endif 
__END_NAMESPACE_STD 
#ifdef __USE_LARGEFILE64 
extern FILE *fopen64 (__const char *__restrict __filename, 
		      __const char *__restrict __modes); 
extern FILE *freopen64 (__const char *__restrict __filename, 
			__const char *__restrict __modes, 
			FILE *__restrict __stream); 
#endif 
 
#ifdef	__USE_POSIX 


   and uses the given functions for input and output.  */ 
extern FILE *fopencookie (void *__restrict __magic_cookie, 
			  __const char *__restrict __modes, 
			  _IO_cookie_io_functions_t __io_funcs) __THROW; 
 


   and the number of characters written on fflush or fclose.  */ 
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __THROW; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   Else make it use buffer BUF, of size BUFSIZ.  */ 
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __THROW; 


   else allocate an internal buffer N bytes long.  */ 
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf, 
		    int __modes, size_t __n) __THROW; 
__END_NAMESPACE_STD 
 
#ifdef	__USE_BSD 


   Else make it use SIZE bytes of BUF for buffering.  */ 
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf, 
		       size_t __size) __THROW; 
 


   marked with __THROW.  */ 
extern int fprintf (FILE *__restrict __stream, 
		    __const char *__restrict __format, ...); 


   marked with __THROW.  */ 
extern int printf (__const char *__restrict __format, ...); 


   marked with __THROW.  */ 
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format, 
		     _G_va_list __arg); 


   marked with __THROW.  */ 
extern int vprintf (__const char *__restrict __format, _G_va_list __arg); 


/* Maximum chars of output to write in MAXLEN.  */ 
extern int snprintf (char *__restrict __s, size_t __maxlen, 
		     __const char *__restrict __format, ...) 
     __THROW __attribute__ ((__format__ (__printf__, 3, 4))); 
 
extern int vsnprintf (char *__restrict __s, size_t __maxlen, 
		      __const char *__restrict __format, _G_va_list __arg) 
     __THROW __attribute__ ((__format__ (__printf__, 3, 0))); 
__END_NAMESPACE_C99 
#endif 
 
#ifdef __USE_GNU 


   Store the address of the string in *PTR.  */ 
extern int vasprintf (char **__restrict __ptr, __const char *__restrict __f, 
		      _G_va_list __arg) 
     __THROW __attribute__ ((__format__ (__printf__, 2, 0))); 
extern int __asprintf (char **__restrict __ptr, 
		       __const char *__restrict __fmt, ...) 
     __THROW __attribute__ ((__format__ (__printf__, 2, 3))); 
extern int asprintf (char **__restrict __ptr, 
		     __const char *__restrict __fmt, ...) 
     __THROW __attribute__ ((__format__ (__printf__, 2, 3))); 
 


   therefore not marked with __THROW.  */ 
extern int vdprintf (int __fd, __const char *__restrict __fmt, 
		     _G_va_list __arg) 
     __attribute__ ((__format__ (__printf__, 2, 0))); 
extern int dprintf (int __fd, __const char *__restrict __fmt, ...) 
     __attribute__ ((__format__ (__printf__, 2, 3))); 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern int fscanf (FILE *__restrict __stream, 
		   __const char *__restrict __format, ...) __wur; 


   marked with __THROW.  */ 
extern int scanf (__const char *__restrict __format, ...) __wur; 


   marked with __THROW.  */ 
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, 
		    _G_va_list __arg) 
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur; 
 


   marked with __THROW.  */ 
extern int vscanf (__const char *__restrict __format, _G_va_list __arg) 
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur; 
 


#endif /* Use ISO C9x.  */ 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern int fgetc (FILE *__stream); 
extern int getc (FILE *__stream); 
 


   marked with __THROW.  */ 
extern int getchar (void); 
__END_NAMESPACE_STD 
 


   optimization for it.  */ 
 
#if defined __USE_POSIX || defined __USE_MISC 


   marked with __THROW.  */ 
extern int getc_unlocked (FILE *__stream); 
extern int getchar_unlocked (void); 
#endif 

   therefore not marked with __THROW.  */ 
extern int fgetc_unlocked (FILE *__stream); 
#endif 

   marked with __THROW.  */ 
extern int fputc (int __c, FILE *__stream); 
extern int putc (int __c, FILE *__stream); 
 


   marked with __THROW.  */ 
extern int putchar (int __c); 
__END_NAMESPACE_STD 
 


   so we always do the optimization for it.  */ 
 
#ifdef __USE_MISC 


   therefore not marked with __THROW.  */ 
extern int fputc_unlocked (int __c, FILE *__stream); 
#endif 

   marked with __THROW.  */ 
extern int putc_unlocked (int __c, FILE *__stream); 
extern int putchar_unlocked (int __c); 
#endif 

/* Get a word (int) from STREAM.  */ 
extern int getw (FILE *__stream); 
 


   marked with __THROW.  */ 
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream) 
     __wur; 
 


   marked with __THROW.  */ 
extern char *gets (char *__s) __wur; 
__END_NAMESPACE_STD 
 
#ifdef __USE_GNU 


   therefore not marked with __THROW.  */ 
extern char *fgets_unlocked (char *__restrict __s, int __n, 
			     FILE *__restrict __stream) __wur; 
#endif 
 
 
#ifdef	__USE_GNU 


   therefore not marked with __THROW.  */ 
extern _IO_ssize_t __getdelim (char **__restrict __lineptr, 
			       size_t *__restrict __n, int __delimiter, 
			       FILE *__restrict __stream) __wur; 
extern _IO_ssize_t getdelim (char **__restrict __lineptr, 
			     size_t *__restrict __n, int __delimiter, 
			     FILE *__restrict __stream) __wur; 
 


   therefore not marked with __THROW.  */ 
extern _IO_ssize_t getline (char **__restrict __lineptr, 
			    size_t *__restrict __n, 
			    FILE *__restrict __stream) __wur; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern int fputs (__const char *__restrict __s, FILE *__restrict __stream); 
 


   marked with __THROW.  */ 
extern int puts (__const char *__s); 
 
 


   marked with __THROW.  */ 
extern int ungetc (int __c, FILE *__stream); 
 
 


   marked with __THROW.  */ 
extern size_t fread (void *__restrict __ptr, size_t __size, 
		     size_t __n, FILE *__restrict __stream) __wur; 


   marked with __THROW.  */ 
extern size_t fwrite (__const void *__restrict __ptr, size_t __size, 
		      size_t __n, FILE *__restrict __s) __wur; 
__END_NAMESPACE_STD 
 
#ifdef __USE_GNU 


   therefore not marked with __THROW.  */ 
extern int fputs_unlocked (__const char *__restrict __s, 
			   FILE *__restrict __stream); 
#endif 
 
#ifdef __USE_MISC 


   therefore not marked with __THROW.  */ 
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size, 
			      size_t __n, FILE *__restrict __stream) __wur; 
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size, 
			       size_t __n, FILE *__restrict __stream) __wur; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern int fseek (FILE *__stream, long int __off, int __whence); 


   marked with __THROW.  */ 
extern long int ftell (FILE *__stream) __wur; 


   marked with __THROW.  */ 
extern void rewind (FILE *__stream); 
__END_NAMESPACE_STD 
 


   are originally defined in the Large File Support API.  */ 
 
#if defined __USE_LARGEFILE || defined __USE_XOPEN2K 
# ifndef __USE_FILE_OFFSET64 


   marked with __THROW.  */ 
extern int fseeko (FILE *__stream, __off_t __off, int __whence); 


   marked with __THROW.  */ 
extern __off_t ftello (FILE *__stream) __wur; 
# else 
#  ifdef __REDIRECT 
extern int __REDIRECT (fseeko, 
		       (FILE *__stream, __off64_t __off, int __whence), 
		       fseeko64); 
extern __off64_t __REDIRECT (ftello, (FILE *__stream), ftello64); 
#  else 
#   define fseeko fseeko64 
#   define ftello ftello64 
#  endif 
# endif 
#endif 
 
__BEGIN_NAMESPACE_STD 
#ifndef __USE_FILE_OFFSET64 


   marked with __THROW.  */ 
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos); 


   marked with __THROW.  */ 
extern int fsetpos (FILE *__stream, __const fpos_t *__pos); 
#else 
# ifdef __REDIRECT 
extern int __REDIRECT (fgetpos, (FILE *__restrict __stream, 
				 fpos_t *__restrict __pos), fgetpos64); 
extern int __REDIRECT (fsetpos, 
		       (FILE *__stream, __const fpos_t *__pos), fsetpos64); 
# else 
#  define fgetpos fgetpos64 
#  define fsetpos fsetpos64 
# endif 
#endif 
__END_NAMESPACE_STD 
 
#ifdef __USE_LARGEFILE64 
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence); 
extern __off64_t ftello64 (FILE *__stream) __wur; 
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos); 
extern int fsetpos64 (FILE *__stream, __const fpos64_t *__pos); 
#endif 
 
__BEGIN_NAMESPACE_STD 


/* Return the EOF indicator for STREAM.  */ 
extern int feof (FILE *__stream) __THROW __wur; 


/* Faster versions when locking is not required.  */ 
extern void clearerr_unlocked (FILE *__stream) __THROW; 
extern int feof_unlocked (FILE *__stream) __THROW __wur; 
extern int ferror_unlocked (FILE *__stream) __THROW __wur; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   marked with __THROW.  */ 
extern void perror (__const char *__s); 
__END_NAMESPACE_STD 
 


   all the necessary functionality.  */ 


   02111-1307 USA.  */ 
 
#ifndef _STDIO_H 
# error "Never include <bits/sys_errlist.h> directly; use <stdio.h> instead." 
#endif 
 

 
 
 
#ifdef	__USE_POSIX 


#endif /* Use POSIX.  */ 
 
#ifdef __USE_MISC 


   marked with __THROW.  */ 
extern FILE *popen (__const char *__command, __const char *__modes) __wur; 
 


   marked with __THROW.  */ 
extern int pclose (FILE *__stream); 
#endif 
 
 
#ifdef	__USE_POSIX 


#endif /* Use POSIX.  */ 
 
 
#ifdef __USE_XOPEN 


#endif /* Use X/Open, but not issue 6.  */ 
 
 
#ifdef	__USE_GNU 
struct obstack;			

/* Write formatted output to an obstack.  */ 
extern int obstack_printf (struct obstack *__restrict __obstack, 
			   __const char *__restrict __format, ...) 
     __THROW __attribute__ ((__format__ (__printf__, 2, 3))); 
extern int obstack_vprintf (struct obstack *__restrict __obstack, 
			    __const char *__restrict __format, 
			    _G_va_list __args) 
     __THROW __attribute__ ((__format__ (__printf__, 2, 0))); 
#endif 

/* These are defined in POSIX.1:1996.  */ 
 


   possible.  */ 
extern int ftrylockfile (FILE *__stream) __THROW __wur; 
 


#endif /* POSIX || misc */ 
 
#if defined __USE_XOPEN && !defined __USE_XOPEN2K && !defined __USE_GNU 


   follow.  In GNU mode we don't do this nonsense.  */ 
# define __need_getopt 
# include <getopt.h> 
#endif	

   several optimizing inline functions and macros.  */ 
#ifdef __USE_EXTERN_INLINES 
# include <bits/stdio.h> 
#endif 
#if __USE_FORTIFY_LEVEL > 0 && !defined __cplusplus 
# include <bits/stdio2.h> 
#endif 
#ifdef __LDBL_COMPAT 
# include <bits/stdio-ldbl.h> 
#endif 
 
__END_DECLS 
 
#endif 

#endif /* !_STDIO_H */ 
 
 
namespace std { 
  using ::FILE; 
  using ::fpos_t; 
  using ::size_t; 
  using ::clearerr; 
  using ::fgets; 
  using ::fscanf; 
  using ::gets; 
  using ::rename; 
  using ::tmpfile; 
  using ::fclose; 
  using ::fopen; 
  using ::fseek; 
  using ::perror; 
  using ::rewind; 
  using ::tmpnam; 
  using ::feof; 
  using ::fprintf; 
  using ::fsetpos; 
  using ::printf; 
  using ::scanf; 
  using ::ungetc; 
  using ::ferror; 
  using ::fputc; 
  using ::ftell; 
  using ::putc; 
  using ::setbuf; 
  using ::vfprintf; 
  using ::fflush; 
  using ::fputs; 
  using ::fwrite; 
  using ::putchar; 
  using ::setvbuf; 
  using ::vprintf; 
  using ::fgetc; 
  using ::fread; 
  using ::getc; 
  using ::puts; 
  using ::sprintf; 
  using ::vsprintf; 
  using ::fgetpos; 
  using ::freopen; 
  using ::getchar; 
  using ::remove; 
  using ::sscanf; 
} 
 
#endif #endif // CSTDIO_HEADER 
 
// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CLOCALE_HEADER 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_LOCALE_H 
#define	_LOCALE_H	1 
 
 
#ifndef _LINUX_STDDEF_H 
 
 
#undef NULL 
#if defined(__cplusplus) 
#else 
#endif 
 
 
#endif 
 
 
__BEGIN_DECLS 
 


   The code assumes that the lowest LC_* symbol has the value zero.  */ 
#define	LC_ALL		  __LC_ALL 
 
 


  /* Numeric (non-monetary) information.  */ 
 
  char *decimal_point;		

  char *thousands_sep;		/* Thousands separator.  */ 
  

     for all groups farther left.  */ 
  char *grouping; 
 
  

     Fourth char is the separator.  Fifth char is '\0'.  */ 
  char *int_curr_symbol; 
  char *currency_symbol;	

  char *mon_decimal_point;	/* Decimal point character.  */ 
  char *mon_thousands_sep;	

  char *mon_grouping;		/* Like `grouping' element (above).  */ 
  char *positive_sign;		

  char *negative_sign;		/* Sign for negative values.  */ 
  char int_frac_digits;		

  char frac_digits;		/* Local fractional digits.  */ 
  

  /* 1 iff a space separates currency_symbol from a positive value.  */ 
  char p_sep_by_space; 
  

  /* 1 iff a space separates currency_symbol from a negative value.  */ 
  char n_sep_by_space; 
  

     4 The sign string immediately follows the currency_symbol.  */ 
  char p_sign_posn; 
  char n_sign_posn; 
#ifdef __USE_ISOC99 
  

  /* 1 iff a space separates int_curr_symbol from a positive value.  */ 
  char int_p_sep_by_space; 
  

  /* 1 iff a space separates int_curr_symbol from a negative value.  */ 
  char int_n_sep_by_space; 
  

     4 The sign string immediately follows the int_curr_symbol.  */ 
  char int_p_sign_posn; 
  char int_n_sign_posn; 
#else 
  char __int_p_cs_precedes; 
  char __int_p_sep_by_space; 
  char __int_n_cs_precedes; 
  char __int_n_sep_by_space; 
  char __int_p_sign_posn; 
  char __int_n_sign_posn; 
#endif 
}; 
 
 
__BEGIN_NAMESPACE_STD 
 


/* Return the numeric/monetary information for the current locale.  */ 
extern struct lconv *localeconv (void) __THROW; 
 
__END_NAMESPACE_STD 
 
 
#ifdef	__USE_GNU 


   This is a proof-of-concept implementation.  */ 
 


   made by OR'ing together LC_*_MASK bits above.  */ 
extern __locale_t newlocale (int __category_mask, __const char *__locale, 
			     __locale_t __base) __THROW; 
 


   callers can assume will be true.  */ 
# define LC_CTYPE_MASK		(1 << __LC_CTYPE) 
# define LC_NUMERIC_MASK	(1 << __LC_NUMERIC) 
# define LC_TIME_MASK		(1 << __LC_TIME) 
# define LC_COLLATE_MASK	(1 << __LC_COLLATE) 
# define LC_MONETARY_MASK	(1 << __LC_MONETARY) 
# define LC_MESSAGES_MASK	(1 << __LC_MESSAGES) 
# define LC_PAPER_MASK		(1 << __LC_PAPER) 
# define LC_NAME_MASK		(1 << __LC_NAME) 
# define LC_ADDRESS_MASK	(1 << __LC_ADDRESS) 
# define LC_TELEPHONE_MASK	(1 << __LC_TELEPHONE) 
# define LC_MEASUREMENT_MASK	(1 << __LC_MEASUREMENT) 
# define LC_IDENTIFICATION_MASK	(1 << __LC_IDENTIFICATION) 
# define LC_ALL_MASK		(LC_CTYPE_MASK \ 
				 | LC_NUMERIC_MASK \ 
				 | LC_TIME_MASK \ 
				 | LC_COLLATE_MASK \ 
				 | LC_MONETARY_MASK \ 
				 | LC_MESSAGES_MASK \ 
				 | LC_PAPER_MASK \ 
				 | LC_NAME_MASK \ 
				 | LC_ADDRESS_MASK \ 
				 | LC_TELEPHONE_MASK \ 
				 | LC_MEASUREMENT_MASK \ 
				 | LC_IDENTIFICATION_MASK \ 
				 ) 
 


   counters are increased if necessary.  */ 
extern __locale_t duplocale (__locale_t __dataset) __THROW; 
 


   by a call to `setlocale_r'.  */ 
extern void freelocale (__locale_t __dataset) __THROW; 
 


   the thread uses the global settings controlled by `setlocale'.  */ 
extern __locale_t uselocale (__locale_t __dataset) __THROW; 
 


   Passing this value to any other function has undefined behavior.  */ 
# define LC_GLOBAL_LOCALE	((__locale_t) -1L) 
 
#endif 
 
__END_DECLS 
 
#endif 
 
 
namespace std { 
  using ::lconv; 
  using ::localeconv; 
  using ::setlocale; 
} 
 
#endif #endif // CLOCALE_HEADER 
 
#include <langinfo.h>		

   02111-1307 USA.  */ 
 
#ifndef _LANGINFO_H 
#define	_LANGINFO_H 1 
 


 
 
__BEGIN_DECLS 
 


   indices.  */ 
 


/* Enumeration of locale items that can be queried with `nl_langinfo'.  */ 
enum 
{ 
  

  /* Abbreviated days of the week. */ 
  ABDAY_1 = _NL_ITEM (__LC_TIME, 0), 

  /* Long-named days of the week. */ 
  DAY_1,			

  DAY_2,			/* Monday */ 
  DAY_3,			

  DAY_4,			/* Wednesday */ 
  DAY_5,			

  DAY_6,			/* Friday */ 
  DAY_7,			

  /* Abbreviated month names.  */ 
  ABMON_1,			

  /* Long month names.  */ 
  MON_1,			

  AM_STR,			/* Ante meridiem string.  */ 
  PM_STR,			

  D_T_FMT,			/* Date and time format for strftime.  */ 
  D_FMT,			

  T_FMT,			/* Time format for strftime.  */ 
  T_FMT_AMPM,			

  ERA,				/* Alternate era.  */ 
  __ERA_YEAR,			

  ERA_D_FMT,			/* Date in alternate era format.  */ 
  ALT_DIGITS,			

  ERA_D_T_FMT,			/* Date and time in alternate era format.  */ 
  ERA_T_FMT,			

  _NL_TIME_ERA_NUM_ENTRIES,	/* Number entries in the era arrays.  */ 
  _NL_TIME_ERA_ENTRIES,		

  _NL_WABDAY_1,		/* Sun */ 
  _NL_WABDAY_2, 
  _NL_WABDAY_3, 
  _NL_WABDAY_4, 
  _NL_WABDAY_5, 
  _NL_WABDAY_6, 
  _NL_WABDAY_7, 
 
  

  _NL_WDAY_1,		/* Sunday */ 
  _NL_WDAY_2,		

  _NL_WDAY_3,		/* Tuesday */ 
  _NL_WDAY_4,		

  _NL_WDAY_5,		/* Thursday */ 
  _NL_WDAY_6,		

  _NL_WDAY_7,		/* Saturday */ 
 
  

  _NL_WABMON_1,		/* Jan */ 
  _NL_WABMON_2, 
  _NL_WABMON_3, 
  _NL_WABMON_4, 
  _NL_WABMON_5, 
  _NL_WABMON_6, 
  _NL_WABMON_7, 
  _NL_WABMON_8, 
  _NL_WABMON_9, 
  _NL_WABMON_10, 
  _NL_WABMON_11, 
  _NL_WABMON_12, 
 
  

  _NL_WMON_1,		/* January */ 
  _NL_WMON_2, 
  _NL_WMON_3, 
  _NL_WMON_4, 
  _NL_WMON_5, 
  _NL_WMON_6, 
  _NL_WMON_7, 
  _NL_WMON_8, 
  _NL_WMON_9, 
  _NL_WMON_10, 
  _NL_WMON_11, 
  _NL_WMON_12, 
 
  _NL_WAM_STR,		

  _NL_WPM_STR,		/* Post meridiem string.  */ 
 
  _NL_WD_T_FMT,		

  _NL_WD_FMT,		/* Date format for strftime.  */ 
  _NL_WT_FMT,		

  _NL_WT_FMT_AMPM,	/* 12-hour time format for strftime.  */ 
 
  _NL_WERA_YEAR,	

  _NL_WERA_D_FMT,	/* Date in alternate era format.  */ 
  _NL_WALT_DIGITS,	

  _NL_WERA_D_T_FMT,	/* Date and time in alternate era format.  */ 
  _NL_WERA_T_FMT,	

  _DATE_FMT,		/* strftime format for date.  */ 
  _NL_W_DATE_FMT, 
 
  _NL_TIME_CODESET, 
 
  _NL_NUM_LC_TIME,	

     These `nl_langinfo' names are used only internally.  */ 
  _NL_COLLATE_NRULES = _NL_ITEM (__LC_COLLATE, 0), 
  _NL_COLLATE_RULESETS, 
  _NL_COLLATE_TABLEMB, 
  _NL_COLLATE_WEIGHTMB, 
  _NL_COLLATE_EXTRAMB, 
  _NL_COLLATE_INDIRECTMB, 
  _NL_COLLATE_GAP1, 
  _NL_COLLATE_GAP2, 
  _NL_COLLATE_GAP3, 
  _NL_COLLATE_TABLEWC, 
  _NL_COLLATE_WEIGHTWC, 
  _NL_COLLATE_EXTRAWC, 
  _NL_COLLATE_INDIRECTWC, 
  _NL_COLLATE_SYMB_HASH_SIZEMB, 
  _NL_COLLATE_SYMB_TABLEMB, 
  _NL_COLLATE_SYMB_EXTRAMB, 
  _NL_COLLATE_COLLSEQMB, 
  _NL_COLLATE_COLLSEQWC, 
  _NL_COLLATE_CODESET, 
  _NL_NUM_LC_COLLATE, 
 
  

     These `nl_langinfo' names are used only internally.  */ 
  _NL_CTYPE_CLASS = _NL_ITEM (__LC_CTYPE, 0), 
  _NL_CTYPE_TOUPPER, 
  _NL_CTYPE_GAP1, 
  _NL_CTYPE_TOLOWER, 
  _NL_CTYPE_GAP2, 
  _NL_CTYPE_CLASS32, 
  _NL_CTYPE_GAP3, 
  _NL_CTYPE_GAP4, 
  _NL_CTYPE_GAP5, 
  _NL_CTYPE_GAP6, 
  _NL_CTYPE_CLASS_NAMES, 
  _NL_CTYPE_MAP_NAMES, 
  _NL_CTYPE_WIDTH, 
  _NL_CTYPE_MB_CUR_MAX, 
  _NL_CTYPE_CODESET_NAME, 
  CODESET = _NL_CTYPE_CODESET_NAME, 
  _NL_CTYPE_TOUPPER32, 
  _NL_CTYPE_TOLOWER32, 
  _NL_CTYPE_CLASS_OFFSET, 
  _NL_CTYPE_MAP_OFFSET, 
  _NL_CTYPE_INDIGITS_MB_LEN, 
  _NL_CTYPE_INDIGITS0_MB, 
  _NL_CTYPE_INDIGITS1_MB, 
  _NL_CTYPE_INDIGITS2_MB, 
  _NL_CTYPE_INDIGITS3_MB, 
  _NL_CTYPE_INDIGITS4_MB, 
  _NL_CTYPE_INDIGITS5_MB, 
  _NL_CTYPE_INDIGITS6_MB, 
  _NL_CTYPE_INDIGITS7_MB, 
  _NL_CTYPE_INDIGITS8_MB, 
  _NL_CTYPE_INDIGITS9_MB, 
  _NL_CTYPE_INDIGITS_WC_LEN, 
  _NL_CTYPE_INDIGITS0_WC, 
  _NL_CTYPE_INDIGITS1_WC, 
  _NL_CTYPE_INDIGITS2_WC, 
  _NL_CTYPE_INDIGITS3_WC, 
  _NL_CTYPE_INDIGITS4_WC, 
  _NL_CTYPE_INDIGITS5_WC, 
  _NL_CTYPE_INDIGITS6_WC, 
  _NL_CTYPE_INDIGITS7_WC, 
  _NL_CTYPE_INDIGITS8_WC, 
  _NL_CTYPE_INDIGITS9_WC, 
  _NL_CTYPE_OUTDIGIT0_MB, 
  _NL_CTYPE_OUTDIGIT1_MB, 
  _NL_CTYPE_OUTDIGIT2_MB, 
  _NL_CTYPE_OUTDIGIT3_MB, 
  _NL_CTYPE_OUTDIGIT4_MB, 
  _NL_CTYPE_OUTDIGIT5_MB, 
  _NL_CTYPE_OUTDIGIT6_MB, 
  _NL_CTYPE_OUTDIGIT7_MB, 
  _NL_CTYPE_OUTDIGIT8_MB, 
  _NL_CTYPE_OUTDIGIT9_MB, 
  _NL_CTYPE_OUTDIGIT0_WC, 
  _NL_CTYPE_OUTDIGIT1_WC, 
  _NL_CTYPE_OUTDIGIT2_WC, 
  _NL_CTYPE_OUTDIGIT3_WC, 
  _NL_CTYPE_OUTDIGIT4_WC, 
  _NL_CTYPE_OUTDIGIT5_WC, 
  _NL_CTYPE_OUTDIGIT6_WC, 
  _NL_CTYPE_OUTDIGIT7_WC, 
  _NL_CTYPE_OUTDIGIT8_WC, 
  _NL_CTYPE_OUTDIGIT9_WC, 
  _NL_CTYPE_TRANSLIT_TAB_SIZE, 
  _NL_CTYPE_TRANSLIT_FROM_IDX, 
  _NL_CTYPE_TRANSLIT_FROM_TBL, 
  _NL_CTYPE_TRANSLIT_TO_IDX, 
  _NL_CTYPE_TRANSLIT_TO_TBL, 
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN, 
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING, 
  _NL_CTYPE_TRANSLIT_IGNORE_LEN, 
  _NL_CTYPE_TRANSLIT_IGNORE, 
  _NL_CTYPE_MAP_TO_NONASCII, 
  _NL_CTYPE_EXTRA_MAP_1, 
  _NL_CTYPE_EXTRA_MAP_2, 
  _NL_CTYPE_EXTRA_MAP_3, 
  _NL_CTYPE_EXTRA_MAP_4, 
  _NL_CTYPE_EXTRA_MAP_5, 
  _NL_CTYPE_EXTRA_MAP_6, 
  _NL_CTYPE_EXTRA_MAP_7, 
  _NL_CTYPE_EXTRA_MAP_8, 
  _NL_CTYPE_EXTRA_MAP_9, 
  _NL_CTYPE_EXTRA_MAP_10, 
  _NL_CTYPE_EXTRA_MAP_11, 
  _NL_CTYPE_EXTRA_MAP_12, 
  _NL_CTYPE_EXTRA_MAP_13, 
  _NL_CTYPE_EXTRA_MAP_14, 
  _NL_NUM_LC_CTYPE, 
 
  

     defined in <locale.h>.  */ 
  __INT_CURR_SYMBOL = _NL_ITEM (__LC_MONETARY, 0), 
#ifdef __USE_GNU 
# define INT_CURR_SYMBOL	__INT_CURR_SYMBOL 
#endif 
  __CURRENCY_SYMBOL, 
#ifdef __USE_GNU 
# define CURRENCY_SYMBOL	__CURRENCY_SYMBOL 
#endif 
  __MON_DECIMAL_POINT, 
#ifdef __USE_GNU 
# define MON_DECIMAL_POINT	__MON_DECIMAL_POINT 
#endif 
  __MON_THOUSANDS_SEP, 
#ifdef __USE_GNU 
# define MON_THOUSANDS_SEP	__MON_THOUSANDS_SEP 
#endif 
  __MON_GROUPING, 
#ifdef __USE_GNU 
# define MON_GROUPING		__MON_GROUPING 
#endif 
  __POSITIVE_SIGN, 
#ifdef __USE_GNU 
# define POSITIVE_SIGN		__POSITIVE_SIGN 
#endif 
  __NEGATIVE_SIGN, 
#ifdef __USE_GNU 
# define NEGATIVE_SIGN		__NEGATIVE_SIGN 
#endif 
  __INT_FRAC_DIGITS, 
#ifdef __USE_GNU 
# define INT_FRAC_DIGITS	__INT_FRAC_DIGITS 
#endif 
  __FRAC_DIGITS, 
#ifdef __USE_GNU 
# define FRAC_DIGITS		__FRAC_DIGITS 
#endif 
  __P_CS_PRECEDES, 
#ifdef __USE_GNU 
# define P_CS_PRECEDES		__P_CS_PRECEDES 
#endif 
  __P_SEP_BY_SPACE, 
#ifdef __USE_GNU 
# define P_SEP_BY_SPACE		__P_SEP_BY_SPACE 
#endif 
  __N_CS_PRECEDES, 
#ifdef __USE_GNU 
# define N_CS_PRECEDES		__N_CS_PRECEDES 
#endif 
  __N_SEP_BY_SPACE, 
#ifdef __USE_GNU 
# define N_SEP_BY_SPACE		__N_SEP_BY_SPACE 
#endif 
  __P_SIGN_POSN, 
#ifdef __USE_GNU 
# define P_SIGN_POSN		__P_SIGN_POSN 
#endif 
  __N_SIGN_POSN, 
#ifdef __USE_GNU 
# define N_SIGN_POSN		__N_SIGN_POSN 
#endif 
  _NL_MONETARY_CRNCYSTR, 
  __INT_P_CS_PRECEDES, 
#ifdef __USE_GNU 
# define INT_P_CS_PRECEDES	__INT_P_CS_PRECEDES 
#endif 
  __INT_P_SEP_BY_SPACE, 
#ifdef __USE_GNU 
# define INT_P_SEP_BY_SPACE	__INT_P_SEP_BY_SPACE 
#endif 
  __INT_N_CS_PRECEDES, 
#ifdef __USE_GNU 
# define INT_N_CS_PRECEDES	__INT_N_CS_PRECEDES 
#endif 
  __INT_N_SEP_BY_SPACE, 
#ifdef __USE_GNU 
# define INT_N_SEP_BY_SPACE	__INT_N_SEP_BY_SPACE 
#endif 
  __INT_P_SIGN_POSN, 
#ifdef __USE_GNU 
# define INT_P_SIGN_POSN	__INT_P_SIGN_POSN 
#endif 
  __INT_N_SIGN_POSN, 
#ifdef __USE_GNU 
# define INT_N_SIGN_POSN	__INT_N_SIGN_POSN 
#endif 
  _NL_MONETARY_DUO_INT_CURR_SYMBOL, 
  _NL_MONETARY_DUO_CURRENCY_SYMBOL, 
  _NL_MONETARY_DUO_INT_FRAC_DIGITS, 
  _NL_MONETARY_DUO_FRAC_DIGITS, 
  _NL_MONETARY_DUO_P_CS_PRECEDES, 
  _NL_MONETARY_DUO_P_SEP_BY_SPACE, 
  _NL_MONETARY_DUO_N_CS_PRECEDES, 
  _NL_MONETARY_DUO_N_SEP_BY_SPACE, 
  _NL_MONETARY_DUO_INT_P_CS_PRECEDES, 
  _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE, 
  _NL_MONETARY_DUO_INT_N_CS_PRECEDES, 
  _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE, 
  _NL_MONETARY_DUO_P_SIGN_POSN, 
  _NL_MONETARY_DUO_N_SIGN_POSN, 
  _NL_MONETARY_DUO_INT_P_SIGN_POSN, 
  _NL_MONETARY_DUO_INT_N_SIGN_POSN, 
  _NL_MONETARY_UNO_VALID_FROM, 
  _NL_MONETARY_UNO_VALID_TO, 
  _NL_MONETARY_DUO_VALID_FROM, 
  _NL_MONETARY_DUO_VALID_TO, 
  _NL_MONETARY_CONVERSION_RATE, 
  _NL_MONETARY_DECIMAL_POINT_WC, 
  _NL_MONETARY_THOUSANDS_SEP_WC, 
  _NL_MONETARY_CODESET, 
  _NL_NUM_LC_MONETARY, 
 
  

     These also correspond to members of `struct lconv'; see <locale.h>.  */ 
  __DECIMAL_POINT = _NL_ITEM (__LC_NUMERIC, 0), 
#ifdef __USE_GNU 
# define DECIMAL_POINT		__DECIMAL_POINT 
#endif 
  RADIXCHAR = __DECIMAL_POINT, 
  __THOUSANDS_SEP, 
#ifdef __USE_GNU 
# define THOUSANDS_SEP		__THOUSANDS_SEP 
#endif 
  THOUSEP = __THOUSANDS_SEP, 
  __GROUPING, 
#ifdef __USE_GNU 
# define GROUPING		__GROUPING 
#endif 
  _NL_NUMERIC_DECIMAL_POINT_WC, 
  _NL_NUMERIC_THOUSANDS_SEP_WC, 
  _NL_NUMERIC_CODESET, 
  _NL_NUM_LC_NUMERIC, 
 
  __YESEXPR = _NL_ITEM (__LC_MESSAGES, 0), 

  __NOEXPR,			/* Regex matching ``no'' input.  */ 
  __YESSTR,			

  __NOSTR,			/* Output string for ``no''.  */ 
#if defined __USE_GNU || (defined __USE_XOPEN && !defined __USE_XOPEN2K) 
# define NOSTR			__NOSTR 
#endif 
  _NL_MESSAGES_CODESET, 
  _NL_NUM_LC_MESSAGES, 
 
  _NL_PAPER_HEIGHT = _NL_ITEM (__LC_PAPER, 0), 
  _NL_PAPER_WIDTH, 
  _NL_PAPER_CODESET, 
  _NL_NUM_LC_PAPER, 
 
  _NL_NAME_NAME_FMT = _NL_ITEM (__LC_NAME, 0), 
  _NL_NAME_NAME_GEN, 
  _NL_NAME_NAME_MR, 
  _NL_NAME_NAME_MRS, 
  _NL_NAME_NAME_MISS, 
  _NL_NAME_NAME_MS, 
  _NL_NAME_CODESET, 
  _NL_NUM_LC_NAME, 
 
  _NL_ADDRESS_POSTAL_FMT = _NL_ITEM (__LC_ADDRESS, 0), 
  _NL_ADDRESS_COUNTRY_NAME, 
  _NL_ADDRESS_COUNTRY_POST, 
  _NL_ADDRESS_COUNTRY_AB2, 
  _NL_ADDRESS_COUNTRY_AB3, 
  _NL_ADDRESS_COUNTRY_CAR, 
  _NL_ADDRESS_COUNTRY_NUM, 
  _NL_ADDRESS_COUNTRY_ISBN, 
  _NL_ADDRESS_LANG_NAME, 
  _NL_ADDRESS_LANG_AB, 
  _NL_ADDRESS_LANG_TERM, 
  _NL_ADDRESS_LANG_LIB, 
  _NL_ADDRESS_CODESET, 
  _NL_NUM_LC_ADDRESS, 
 
  _NL_TELEPHONE_TEL_INT_FMT = _NL_ITEM (__LC_TELEPHONE, 0), 
  _NL_TELEPHONE_TEL_DOM_FMT, 
  _NL_TELEPHONE_INT_SELECT, 
  _NL_TELEPHONE_INT_PREFIX, 
  _NL_TELEPHONE_CODESET, 
  _NL_NUM_LC_TELEPHONE, 
 
  _NL_MEASUREMENT_MEASUREMENT = _NL_ITEM (__LC_MEASUREMENT, 0), 
  _NL_MEASUREMENT_CODESET, 
  _NL_NUM_LC_MEASUREMENT, 
 
  _NL_IDENTIFICATION_TITLE = _NL_ITEM (__LC_IDENTIFICATION, 0), 
  _NL_IDENTIFICATION_SOURCE, 
  _NL_IDENTIFICATION_ADDRESS, 
  _NL_IDENTIFICATION_CONTACT, 
  _NL_IDENTIFICATION_EMAIL, 
  _NL_IDENTIFICATION_TEL, 
  _NL_IDENTIFICATION_FAX, 
  _NL_IDENTIFICATION_LANGUAGE, 
  _NL_IDENTIFICATION_TERRITORY, 
  _NL_IDENTIFICATION_AUDIENCE, 
  _NL_IDENTIFICATION_APPLICATION, 
  _NL_IDENTIFICATION_ABBREVIATION, 
  _NL_IDENTIFICATION_REVISION, 
  _NL_IDENTIFICATION_DATE, 
  _NL_IDENTIFICATION_CATEGORY, 
  _NL_IDENTIFICATION_CODESET, 
  _NL_NUM_LC_IDENTIFICATION, 
 
  

   `nl_langinfo_l' to get the name of the locale in use for CATEGORY.  */ 
#ifdef __USE_GNU 
# define NL_LOCALE_NAME(category)	_NL_LOCALE_NAME (category) 
#endif 
 
 


   it is usually in read-only memory and cannot be modified.  */ 
 
extern char *nl_langinfo (nl_item __item) __THROW; 
 
 
#ifdef	__USE_GNU 


   more information.  */ 
 


/* Just like nl_langinfo but get the information from the locale object L.  */ 
extern char *nl_langinfo_l (nl_item __item, __locale_t l); 
#endif 
 
__END_DECLS 
 
#endif	
 
#include <iconv.h>		

   02111-1307 USA.  */ 
 
#ifndef _ICONV_H 
 
 
 
__BEGIN_DECLS 
 


   marked with __THROW.  */ 
extern iconv_t iconv_open (__const char *__tocode, __const char *__fromcode); 
 


   *OUTBYTESLEFT bytes in buffer at *OUTBUF.  */ 
extern size_t iconv (iconv_t __cd, char **__restrict __inbuf, 
		     size_t *__restrict __inbytesleft, 
		     char **__restrict __outbuf, 
		     size_t *__restrict __outbytesleft); 
 


   marked with __THROW.  */ 
extern int iconv_close (iconv_t __cd); 
 
__END_DECLS 
 
#endif 
 
#include <libintl.h> 		

   02111-1307 USA.  */ 
 
#ifndef _LIBINTL_H 
 
 


   implementation of gettext.  */ 
 


   maximum minor revision number supported for a given major revision.  */ 
  ((major) == 0 ? 1 : -1) 
 
__BEGIN_DECLS 
 


   text).  */ 
extern char *gettext (__const char *__msgid) 
     __THROW __attribute_format_arg__ (1); 
 


         __LC_MESSAGES locale.  */ 
extern char *dgettext (__const char *__domainname, __const char *__msgid) 
     __THROW __attribute_format_arg__ (2); 
extern char *__dgettext (__const char *__domainname, __const char *__msgid) 
     __THROW __attribute_format_arg__ (2); 
 


   locale.  */ 
extern char *dcgettext (__const char *__domainname, 
			__const char *__msgid, int __category) 
     __THROW __attribute_format_arg__ (2); 
extern char *__dcgettext (__const char *__domainname, 
			  __const char *__msgid, int __category) 
     __THROW __attribute_format_arg__ (2); 
 
 


   number N.  */ 
extern char *ngettext (__const char *__msgid1, __const char *__msgid2, 
		       unsigned long int __n) 
     __THROW __attribute_format_arg__ (1) __attribute_format_arg__ (2); 
 


   number N.  */ 
extern char *dngettext (__const char *__domainname, __const char *__msgid1, 
			__const char *__msgid2, unsigned long int __n) 
     __THROW __attribute_format_arg__ (2) __attribute_format_arg__ (3); 
 


   number N.  */ 
extern char *dcngettext (__const char *__domainname, __const char *__msgid1, 
			 __const char *__msgid2, unsigned long int __n, 
			 int __category) 
     __THROW __attribute_format_arg__ (2) __attribute_format_arg__ (3); 
 
 


   If DOMAINNAME is "", reset to the default of "messages".  */ 
extern char *textdomain (__const char *__domainname) __THROW; 
 


   in DIRNAME rather than in the system locale data base.  */ 
extern char *bindtextdomain (__const char *__domainname, 
			     __const char *__dirname) __THROW; 
 


   DOMAINNAME message catalog will be returned.  */ 
extern char *bind_textdomain_codeset (__const char *__domainname, 
				      __const char *__codeset) __THROW; 
 
 


/* We need 0 for `gettext'.  */ 
# define #define __need_NULL 
# include <stddef.h> 
 


   false.  */ 
 
# define gettext(msgid) dgettext (NULL, msgid) 
 
# define dgettext(domainname, msgid) \ 
  dcgettext (domainname, msgid, LC_MESSAGES) 
 
# define ngettext(msgid1, msgid2, n) dngettext (NULL, msgid1, msgid2, n) 
 
# define dngettext(domainname, msgid1, msgid2, n) \ 
  dcngettext (domainname, msgid1, msgid2, n, LC_MESSAGES) 
 
#endif	

#endif /* libintl.h */ 
 
 
 
 
#if __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 2) 
namespace __gnu_cxx 
{ 
  extern "C" __typeof(uselocale) __uselocale; 
} 
#endif 
 
namespace std 
{ 
  typedef __locale_t		__c_locale; 
 
    // Convert numeric value of type _Tv to string and return length of 
    // string.  If snprintf is available use it, otherwise fall back to 
    // the unsafe sprintf which, in general, can be dangerous and should 
    // be avoided. 
  template<typename _Tv> 
    int 
    __convert_from_v(char* __out,  
		     const int __size __attribute__ ((__unused__)), 
		     const char* __fmt, 
#if __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 2) 
		     _Tv __v, const __c_locale& __cloc, int __prec) 
    { 
      __c_locale __old = __gnu_cxx::__uselocale(__cloc); 
#else 
		     _Tv __v, const __c_locale&, int __prec) 
    { 
      char* __old = std::setlocale(LC_ALL, NULL); 
      char* __sav = new char[std::strlen(__old) + 1]; 
      std::strcpy(__sav, __old); 
      std::setlocale(LC_ALL, "C"); 
#endif 
 
#ifdef 1 
      const int __ret = std::snprintf(__out, __size, __fmt, __prec, __v); 
#else 
      const int __ret = std::sprintf(__out, __fmt, __prec, __v); 
#endif 
 
#if __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 2) 
      __gnu_cxx::__uselocale(__old); 
#else 
      std::setlocale(LC_ALL, __sav); 
      delete [] __sav; 
#endif 
      return __ret; 
    } 
} 
 
#endif 
 
// underlying io library  -*- C++ -*- 
 
// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// c_io_stdio.h - Defines for using "C" stdio.h 
 
#ifndef _C_IO_STDIO_H 
 
// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CSTDDEF_HEADER 
 
 
namespace std { 
  using ::ptrdiff_t; 
  using ::size_t; 
} 
 
#endif #endif // CSTDDEF_HEADER 
 


/* Compile this one with gcc.  */ 


02110-1301, USA.  */ 
 


   the executable file might be covered by the GNU General Public License.  */ 
 
#ifndef _GLIBCXX_GCC_GTHR_H 
 
#ifndef _GLIBCXX_HIDE_EXPORTS 
#pragma GCC visibility push(default) 
#endif 
 


*/ 
 


/* Include GTHREAD_FILE if one is defined.  */ 
#elif defined(_GLIBCXX_HAVE_GTHR_DEFAULT) 
#if __GXX_WEAK__ 
#ifndef _GLIBCXX_GTHREAD_USE_WEAK 
#endif 
#endif 


/* Compile this one with gcc.  */ 


02110-1301, USA.  */ 
 


   the executable file might be covered by the GNU General Public License.  */ 
 
#ifndef _GLIBCXX_GCC_GTHR_POSIX_H 
 


   Easy, since the interface is just one-to-one mapping.  */ 
 
 


   in gthr.h for details. */ 
 
#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER) 
#elif defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP) 
#else 
#endif 
 
#if __GXX_WEAK__ && 1 
# ifndef __gthrw_pragma 
#  define __gthrw_pragma(pragma) 
# endif 
# define __gthrw2(name,name2,type) \ 
  extern __typeof(type) name __attribute__ ((__weakref__(#name2))); \ 
  __gthrw_pragma(weak type) 
# define __gthrw_(name) __gthrw_ ## name 
#else 
# define __gthrw2(name,name2,type) 
# define __gthrw_(name) name 
#endif 
 


   names.  */ 
#if defined(__osf__) && defined(_PTHREAD_USE_MANGLED_NAMES_) 
__gthrw3(pthread_once) 
__gthrw3(pthread_getspecific) 
__gthrw3(pthread_setspecific) 
__gthrw3(pthread_create) 
__gthrw3(pthread_cancel) 
__gthrw3(pthread_mutex_lock) 
__gthrw3(pthread_mutex_trylock) 
__gthrw3(pthread_mutex_unlock) 
__gthrw3(pthread_mutex_init) 
__gthrw3(pthread_cond_broadcast) 
__gthrw3(pthread_cond_wait) 
#else 
__gthrw(pthread_once) 
__gthrw(pthread_getspecific) 
__gthrw(pthread_setspecific) 
__gthrw(pthread_create) 
__gthrw(pthread_cancel) 
__gthrw(pthread_mutex_lock) 
__gthrw(pthread_mutex_trylock) 
__gthrw(pthread_mutex_unlock) 
__gthrw(pthread_mutex_init) 
__gthrw(pthread_cond_broadcast) 
__gthrw(pthread_cond_wait) 
#endif 
 
__gthrw(pthread_key_create) 
__gthrw(pthread_key_delete) 
__gthrw(pthread_mutexattr_init) 
__gthrw(pthread_mutexattr_settype) 
__gthrw(pthread_mutexattr_destroy) 
 
 
#if defined(_LIBOBJC) || defined(_LIBOBJC_WEAK) 


#endif /* __osf__ && _PTHREAD_USE_MANGLED_NAMES_ */ 
#ifdef _POSIX_PRIORITY_SCHEDULING 
#ifdef _POSIX_THREAD_PRIORITY_SCHEDULING 
__gthrw(sched_get_priority_max) 
__gthrw(sched_get_priority_min) 
#endif 

#endif /* _POSIX_PRIORITY_SCHEDULING */ 
__gthrw(sched_yield) 
__gthrw(pthread_attr_destroy) 
__gthrw(pthread_attr_init) 
__gthrw(pthread_attr_setdetachstate) 
#ifdef _POSIX_THREAD_PRIORITY_SCHEDULING 
__gthrw(pthread_getschedparam) 
__gthrw(pthread_setschedparam) 
#endif 

#endif /* _LIBOBJC || _LIBOBJC_WEAK */ 
 
#if __GXX_WEAK__ && 1 
 
static inline int 
__gthread_active_p (void) 
{ 
  static void *const __gthread_active_ptr  
    = __extension__ (void *) &__gthrw_(pthread_cancel); 
  return __gthread_active_ptr != 0; 
} 
 
#else 

#endif /* __GXX_WEAK__ */ 
 
#ifdef _LIBOBJC 
 


/* Key structure for maintaining thread specific storage */ 
static pthread_key_t _objc_thread_storage; 
static pthread_attr_t _objc_thread_attribs; 
 


/* Backend initialization functions */ 
 


      /* Initialize the thread storage key.  */ 
      if (__gthrw_(pthread_key_create) (&_objc_thread_storage, NULL) == 0) 
	{ 
	  

	   * when you think they should.  */ 
	  if (__gthrw_(pthread_attr_init) (&_objc_thread_attribs) == 0 
	      && __gthrw_(pthread_attr_setdetachstate) (&_objc_thread_attribs, 
					      PTHREAD_CREATE_DETACHED) == 0) 
	    return 0; 
	} 
    } 
 
  return -1; 
} 
 


/* Backend thread functions */ 
 


/* Set the current thread's priority.  */ 
static inline int 
__gthread_objc_thread_set_priority (int priority) 
{ 
  if (!__gthread_active_p ()) 
    return -1; 
  else 
    { 
#ifdef _POSIX_PRIORITY_SCHEDULING 
#ifdef _POSIX_THREAD_PRIORITY_SCHEDULING 
      pthread_t thread_id = __gthrw_(pthread_self) (); 
      int policy; 
      struct sched_param params; 
      int priority_min, priority_max; 
 
      if (__gthrw_(pthread_getschedparam) (thread_id, &policy, &params) == 0) 
	{ 
	  if ((priority_max = __gthrw_(sched_get_priority_max) (policy)) == -1) 
	    return -1; 
 
	  if ((priority_min = __gthrw_(sched_get_priority_min) (policy)) == -1) 
	    return -1; 
 
	  if (priority > priority_max) 
	    priority = priority_max; 
	  else if (priority < priority_min) 
	    priority = priority_min; 
	  params.sched_priority = priority; 
 
	  

	   */ 
	  if (__gthrw_(pthread_setschedparam) (thread_id, policy, &params) == 0) 
	    return 0; 
	} 
#endif 

#endif /* _POSIX_PRIORITY_SCHEDULING */ 
      return -1; 
    } 
} 
 


#endif /* _POSIX_THREAD_PRIORITY_SCHEDULING */ 
#endif 

/* Yield our process time to another thread.  */ 
static inline void 
__gthread_objc_thread_yield (void) 
{ 
  if (__gthread_active_p ()) 
    __gthrw_(sched_yield) (); 
} 
 


    /* exit the thread */ 
    __gthrw_(pthread_exit) (&__objc_thread_exit_status); 
 
  

/* Returns an integer value which uniquely describes a thread.  */ 
static inline objc_thread_t 
__gthread_objc_thread_id (void) 
{ 
  if (__gthread_active_p ()) 
    return (objc_thread_t) __gthrw_(pthread_self) (); 
  else 
    return (objc_thread_t) 1; 
} 
 


/* Returns the thread's local storage pointer.  */ 
static inline void * 
__gthread_objc_thread_get_data (void) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_getspecific) (_objc_thread_storage); 
  else 
    return thread_local_storage; 
} 
 


/* Allocate a mutex.  */ 
static inline int 
__gthread_objc_mutex_allocate (objc_mutex_t mutex) 
{ 
  if (__gthread_active_p ()) 
    { 
      mutex->backend = objc_malloc (sizeof (pthread_mutex_t)); 
 
      if (__gthrw_(pthread_mutex_init) ((pthread_mutex_t *) mutex->backend, NULL)) 
	{ 
	  objc_free (mutex->backend); 
	  mutex->backend = NULL; 
	  return -1; 
	} 
    } 
 
  return 0; 
} 
 


       */ 
 
      do 
	{ 
	  count = __gthrw_(pthread_mutex_unlock) ((pthread_mutex_t *) mutex->backend); 
	  if (count < 0) 
	    return -1; 
	} 
      while (count); 
 
      if (__gthrw_(pthread_mutex_destroy) ((pthread_mutex_t *) mutex->backend)) 
	return -1; 
 
      objc_free (mutex->backend); 
      mutex->backend = NULL; 
    } 
  return 0; 
} 
 


/* Try to grab a lock on a mutex.  */ 
static inline int 
__gthread_objc_mutex_trylock (objc_mutex_t mutex) 
{ 
  if (__gthread_active_p () 
      && __gthrw_(pthread_mutex_trylock) ((pthread_mutex_t *) mutex->backend) != 0) 
    { 
      return -1; 
    } 
 
  return 0; 
} 
 


/* Backend condition mutex functions */ 
 


/* Deallocate a condition.  */ 
static inline int 
__gthread_objc_condition_deallocate (objc_condition_t condition) 
{ 
  if (__gthread_active_p ()) 
    { 
      if (__gthrw_(pthread_cond_destroy) ((pthread_cond_t *) condition->backend)) 
	return -1; 
 
      objc_free (condition->backend); 
      condition->backend = NULL; 
    } 
  return 0; 
} 
 


/* Wake up all threads waiting on this condition.  */ 
static inline int 
__gthread_objc_condition_broadcast (objc_condition_t condition) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_cond_broadcast) ((pthread_cond_t *) condition->backend); 
  else 
    return 0; 
} 
 


#else /* _LIBOBJC */ 
 
static inline int 
__gthread_once (__gthread_once_t *once, void (*func) (void)) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_once) (once, func); 
  else 
    return -1; 
} 
 
static inline int 
__gthread_key_create (__gthread_key_t *key, void (*dtor) (void *)) 
{ 
  return __gthrw_(pthread_key_create) (key, dtor); 
} 
 
static inline int 
__gthread_key_delete (__gthread_key_t key) 
{ 
  return __gthrw_(pthread_key_delete) (key); 
} 
 
static inline void * 
__gthread_getspecific (__gthread_key_t key) 
{ 
  return __gthrw_(pthread_getspecific) (key); 
} 
 
static inline int 
__gthread_setspecific (__gthread_key_t key, const void *ptr) 
{ 
  return __gthrw_(pthread_setspecific) (key, ptr); 
} 
 
static inline int 
__gthread_mutex_lock (__gthread_mutex_t *mutex) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_mutex_lock) (mutex); 
  else 
    return 0; 
} 
 
static inline int 
__gthread_mutex_trylock (__gthread_mutex_t *mutex) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_mutex_trylock) (mutex); 
  else 
    return 0; 
} 
 
static inline int 
__gthread_mutex_unlock (__gthread_mutex_t *mutex) 
{ 
  if (__gthread_active_p ()) 
    return __gthrw_(pthread_mutex_unlock) (mutex); 
  else 
    return 0; 
} 
 
#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP 
static inline int 
__gthread_recursive_mutex_init_function (__gthread_recursive_mutex_t *mutex) 
{ 
  if (__gthread_active_p ()) 
    { 
      pthread_mutexattr_t attr; 
      int r; 
 
      r = __gthrw_(pthread_mutexattr_init) (&attr); 
      if (!r) 
	r = __gthrw_(pthread_mutexattr_settype) (&attr, PTHREAD_MUTEX_RECURSIVE); 
      if (!r) 
	r = __gthrw_(pthread_mutex_init) (mutex, &attr); 
      if (!r) 
	r = __gthrw_(pthread_mutexattr_destroy) (&attr); 
      return r; 
    } 
  return 0; 
} 
#endif 
 
static inline int 
__gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *mutex) 
{ 
  return __gthread_mutex_lock (mutex); 
} 
 
static inline int 
__gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *mutex) 
{ 
  return __gthread_mutex_trylock (mutex); 
} 
 
static inline int 
__gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *mutex) 
{ 
  return __gthread_mutex_unlock (mutex); 
} 
 
static inline int 
__gthread_cond_broadcast (__gthread_cond_t *cond) 
{ 
  return __gthrw_(pthread_cond_broadcast) (cond); 
} 
 
static inline int 
__gthread_cond_wait (__gthread_cond_t *cond, __gthread_mutex_t *mutex) 
{ 
  return __gthrw_(pthread_cond_wait) (cond, mutex); 
} 
 
static inline int 
__gthread_cond_wait_recursive (__gthread_cond_t *cond, 
			       __gthread_recursive_mutex_t *mutex) 
{ 
  return __gthread_cond_wait (cond, mutex); 
} 
 
#endif 

#endif /* ! #define _GLIBCXX_GCC_GTHR_POSIX_H */ 
 
 


#endif /* ! #define _GLIBCXX_GCC_GTHR_H */ 
 
 
namespace std  
{ 
  typedef __gthread_mutex_t __c_lock; 
 
    // for basic_file.h 
  typedef FILE __c_file; 
} 
 
#endif 
 
#include <cctype>		// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CCTYPE_HEADER 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_CTYPE_H 
#define	_CTYPE_H	1 
 


 */ 


 */ 
#ifndef GSSRPC_TYPES_H 
 
 


   02111-1307 USA.  */ 
 


/* Get definition of needed basic types.  */ 
 


/* Get __sigset_t.  */ 


   02111-1307 USA.  */ 
 
#ifndef	_SIGSET_H_types 
# define _SIGSET_H_types	1 
 
typedef int __sig_atomic_t; 
 


   register vars declared later will cause compilation errors).  */ 
 
#if !defined _SIGSET_H_fns && defined _SIGNAL_H 
# define _SIGSET_H_fns 1 
 
# ifndef _EXTERN_INLINE 
#  define _EXTERN_INLINE extern __inline 
# endif 
 


/* Return the word index for SIG.  */ 
# define __sigword(sig)	(((sig) - 1) / (8 * sizeof (unsigned long int))) 
 
# if defined __GNUC__ && __GNUC__ >= 2 
#  define __sigemptyset(set) \ 
  (__extension__ ({ int __cnt = _SIGSET_NWORDS;				      \ 
		    sigset_t *__set = (set);				      \ 
		    while (--__cnt >= 0) __set->__val[__cnt] = 0;	      \ 
		    0; })) 
#  define __sigfillset(set) \ 
  (__extension__ ({ int __cnt = _SIGSET_NWORDS;				      \ 
		    sigset_t *__set = (set);				      \ 
		    while (--__cnt >= 0) __set->__val[__cnt] = ~0UL;	      \ 
		    0; })) 
 
#  ifdef __USE_GNU 


   here.  */ 
#   define __sigisemptyset(set) \ 
  (__extension__ ({ int __cnt = _SIGSET_NWORDS;				      \ 
		    const sigset_t *__set = (set);			      \ 
		    int __ret = __set->__val[--__cnt];			      \ 
		    while (!__ret && --__cnt >= 0)			      \ 
			__ret = __set->__val[__cnt];			      \ 
		    __ret == 0; })) 
#   define __sigandset(dest, left, right) \ 
  (__extension__ ({ int __cnt = _SIGSET_NWORDS;				      \ 
		    sigset_t *__dest = (dest);				      \ 
		    const sigset_t *__left = (left);			      \ 
		    const sigset_t *__right = (right);			      \ 
		    while (--__cnt >= 0)				      \ 
		      __dest->__val[__cnt] = (__left->__val[__cnt]	      \ 
					      & __right->__val[__cnt]);	      \ 
		    0; })) 
#   define __sigorset(dest, left, right) \ 
  (__extension__ ({ int __cnt = _SIGSET_NWORDS;				      \ 
		    sigset_t *__dest = (dest);				      \ 
		    const sigset_t *__left = (left);			      \ 
		    const sigset_t *__right = (right);			      \ 
		    while (--__cnt >= 0)				      \ 
		      __dest->__val[__cnt] = (__left->__val[__cnt]	      \ 
					      | __right->__val[__cnt]);	      \ 
		    0; })) 
#  endif 
# endif 
 


   checking is done in the non __ versions.  */ 
 
extern int __sigismember (__const __sigset_t *, int); 
extern int __sigaddset (__sigset_t *, int); 
extern int __sigdelset (__sigset_t *, int); 
 
# ifdef __USE_EXTERN_INLINES 
#  define __SIGSETFN(NAME, BODY, CONST)					      \ 
  _EXTERN_INLINE int							      \ 
  NAME (CONST __sigset_t *__set, int __sig)				      \ 
  {									      \ 
    unsigned long int __mask = __sigmask (__sig);			      \ 
    unsigned long int __word = __sigword (__sig);			      \ 
    return BODY;							      \ 
  } 
 
__SIGSETFN (__sigismember, (__set->__val[__word] & __mask) ? 1 : 0, __const) 
__SIGSETFN (__sigaddset, ((__set->__val[__word] |= __mask), 0), ) 
__SIGSETFN (__sigdelset, ((__set->__val[__word] &= ~__mask), 0), ) 
 
#  undef __SIGSETFN 
# endif 
 
 
#endif 
 
 
#ifndef __sigset_t_defined 
# define __sigset_t_defined 
typedef __sigset_t sigset_t; 
#endif 
 


/* The fd_set member is required to be an array of longs.  */ 
typedef long int __fd_mask; 
 


/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */ 
#define	__FDELT(d)	((d) / __NFDBITS) 
#define	__FDMASK(d)	((__fd_mask) 1 << ((d) % __NFDBITS)) 
 


       from the global namespace.  */ 
#ifdef __USE_XOPEN 
    __fd_mask fds_bits[__FD_SETSIZE / __NFDBITS]; 
# define __FDS_BITS(set) ((set)->fds_bits) 
#else 
    __fd_mask __fds_bits[__FD_SETSIZE / __NFDBITS]; 
# define __FDS_BITS(set) ((set)->__fds_bits) 
#endif 
  } fd_set; 
 


/* Sometimes the fd_set member is assumed to have this type.  */ 
typedef __fd_mask fd_mask; 
 


/* Access macros for `fd_set'.  */ 
#define	FD_SET(fd, fdsetp)	__FD_SET (fd, fdsetp) 
#define	FD_CLR(fd, fdsetp)	__FD_CLR (fd, fdsetp) 
#define	FD_ISSET(fd, fdsetp)	__FD_ISSET (fd, fdsetp) 
#define	FD_ZERO(fdsetp)		__FD_ZERO (fdsetp) 
 
 
__BEGIN_DECLS 
 


   __THROW.  */ 
extern int select (int __nfds, fd_set *__restrict __readfds, 
		   fd_set *__restrict __writefds, 
		   fd_set *__restrict __exceptfds, 
		   struct timeval *__restrict __timeout); 
 
#ifdef __USE_XOPEN2K 


   __THROW.  */ 
extern int pselect (int __nfds, fd_set *__restrict __readfds, 
		    fd_set *__restrict __writefds, 
		    fd_set *__restrict __exceptfds, 
		    const struct timespec *__restrict __timeout, 
		    const __sigset_t *__restrict __sigmask); 
#endif 
 
__END_DECLS 
 
#endif 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_TIME_H 
 
#if (! defined __need_time_t && !defined __need_clock_t && \ 
     ! defined __need_timespec) 
# define _TIME_H	1 
# include <features.h> 
 
__BEGIN_DECLS 
 
#endif 
 
#ifdef	_TIME_H 


   ticks per second.  */ 
# include <bits/time.h> 
 


#endif /* <time.h> included.  */ 
 
#if !defined __clock_t_defined && (defined _TIME_H || defined __need_clock_t) 
# define __clock_t_defined	1 
 
# include <bits/types.h> 
 
__BEGIN_NAMESPACE_STD 


#endif /* clock_t not defined and <time.h> or need clock_t.  */ 
#undef	__need_clock_t 
 
#if !defined __time_t_defined && (defined _TIME_H || defined __need_time_t) 
# define __time_t_defined	1 
 
# include <bits/types.h> 
 
__BEGIN_NAMESPACE_STD 


#endif /* time_t not defined and <time.h> or need time_t.  */ 
#undef	__need_time_t 
 
#if !defined __clockid_t_defined && \ 
   ((defined _TIME_H && defined __USE_POSIX199309) || defined __need_clockid_t) 
# define __clockid_t_defined	1 
 
# include <bits/types.h> 
 


#endif /* clockid_t not defined and <time.h> or need clockid_t.  */ 
#undef	__clockid_time_t 
 
#if !defined __timer_t_defined && \ 
    ((defined _TIME_H && defined __USE_POSIX199309) || defined __need_timer_t) 
# define __timer_t_defined	1 
 
# include <bits/types.h> 
 


#endif /* timer_t not defined and <time.h> or need timer_t.  */ 
#undef	__need_timer_t 
 
 
#if !defined __timespec_defined &&				\ 
    ((defined _TIME_H &&					\ 
      (defined __USE_POSIX199309 || defined __USE_MISC)) ||	\ 
      defined __need_timespec) 
# define __timespec_defined	1 
 
# include <bits/types.h>	

   has nanoseconds instead of microseconds.  */ 
struct timespec 
  { 
    __time_t tv_sec;		

    long int tv_nsec;		/* Nanoseconds.  */ 
  }; 
 
#endif 

/* Used by other time functions.  */ 
struct tm 
{ 
  int tm_sec;			

  int tm_min;			/* Minutes.	[0-59] */ 
  int tm_hour;			

  int tm_mday;			/* Day.		[1-31] */ 
  int tm_mon;			

  int tm_year;			/* Year	- 1900.  */ 
  int tm_wday;			

  int tm_yday;			/* Days in year.[0-365]	*/ 
  int tm_isdst;			

  long int tm_gmtoff;		/* Seconds east of UTC.  */ 
  __const char *tm_zone;	

  long int __tm_gmtoff;		/* Seconds east of UTC.  */ 
  __const char *__tm_zone;	

/* POSIX.1b structure for timer start values and intervals.  */ 
struct itimerspec 
  { 
    struct timespec it_interval; 
    struct timespec it_value; 
  }; 
 


#endif	/* POSIX.1b */ 
 
#ifdef __USE_XOPEN2K 
# ifndef __pid_t_defined 
typedef __pid_t pid_t; 
#  define __pid_t_defined 
# endif 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   The result / CLOCKS_PER_SECOND is program time in seconds.  */ 
extern clock_t clock (void) __THROW; 
 


/* Return the difference between TIME1 and TIME0.  */ 
extern double difftime (time_t __time1, time_t __time0) 
     __THROW __attribute__ ((__const__)); 
 


   of characters written, or 0 if it would exceed MAXSIZE.  */ 
extern size_t strftime (char *__restrict __s, size_t __maxsize, 
			__const char *__restrict __format, 
			__const struct tm *__restrict __tp) __THROW; 
__END_NAMESPACE_STD 
 
# ifdef __USE_XOPEN 


   The return value is a pointer to the first unparsed character in S.  */ 
extern char *strptime (__const char *__restrict __s, 
		       __const char *__restrict __fmt, struct tm *__tp) 
     __THROW; 
# endif 
 
# ifdef __USE_GNU 


   the provided locale and not the global locale.  */ 
# include <xlocale.h> 
 
extern size_t strftime_l (char *__restrict __s, size_t __maxsize, 
			  __const char *__restrict __format, 
			  __const struct tm *__restrict __tp, 
			  __locale_t __loc) __THROW; 
 
extern char *strptime_l (__const char *__restrict __s, 
			 __const char *__restrict __fmt, struct tm *__tp, 
			 __locale_t __loc) __THROW; 
# endif 
 
 
__BEGIN_NAMESPACE_STD 


   in Universal Coordinated Time (aka Greenwich Mean Time).  */ 
extern struct tm *gmtime (__const time_t *__timer) __THROW; 
 


   of *TIMER in the local timezone.  */ 
extern struct tm *localtime (__const time_t *__timer) __THROW; 
__END_NAMESPACE_STD 
 
# if defined __USE_POSIX || defined __USE_MISC 


   using *TP to store the result.  */ 
extern struct tm *gmtime_r (__const time_t *__restrict __timer, 
			    struct tm *__restrict __tp) __THROW; 
 


   using *TP to store the result.  */ 
extern struct tm *localtime_r (__const time_t *__restrict __timer, 
			       struct tm *__restrict __tp) __THROW; 
# endif	

   that is the representation of TP in this format.  */ 
extern char *asctime (__const struct tm *__tp) __THROW; 
 


/* Reentrant versions of the above functions.  */ 
 


   that is the representation of TP in this format.  */ 
extern char *asctime_r (__const struct tm *__restrict __tp, 
			char *__restrict __buf) __THROW; 
 


# endif	/* POSIX or misc */ 
 
 


extern char *__tzname[2];	/* Current timezone names.  */ 
extern int __daylight;		

extern long int __timezone;	/* Seconds west of UTC.  */ 
 
 
# ifdef	__USE_POSIX 


   If TZ is not defined, a locale-dependent default is used.  */ 
extern void tzset (void) __THROW; 
# endif 
 
# if defined __USE_SVID || defined __USE_XOPEN 
extern int daylight; 
extern long int timezone; 
# endif 
 
# ifdef __USE_SVID 


   This call is restricted to the superuser.  */ 
extern int stime (__const time_t *__when) __THROW; 
# endif 
 
 


   except every 100th isn't, and every 400th is).  */ 
# define __isleap(year)	\ 
  ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0)) 
 
 
# ifdef __USE_MISC 


   localtime package.  These are included only for compatibility.  */ 
 


/* Another name for `mktime'.  */ 
extern time_t timelocal (struct tm *__tp) __THROW; 
 


   __THROW.  */ 
extern int nanosleep (__const struct timespec *__requested_time, 
		      struct timespec *__remaining); 
 
 


/* Get current value of clock CLOCK_ID and store it in TP.  */ 
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __THROW; 
 


   __THROW.  */ 
extern int clock_nanosleep (clockid_t __clock_id, int __flags, 
			    __const struct timespec *__req, 
			    struct timespec *__rem); 
 


/* Create new per-process timer using CLOCK_ID.  */ 
extern int timer_create (clockid_t __clock_id, 
			 struct sigevent *__restrict __evp, 
			 timer_t *__restrict __timerid) __THROW; 
 


/* Set timer TIMERID to VALUE, returning old value in OVLAUE.  */ 
extern int timer_settime (timer_t __timerid, int __flags, 
			  __const struct itimerspec *__restrict __value, 
			  struct itimerspec *__restrict __ovalue) __THROW; 
 


/* Get expiration overrun for timer TIMERID.  */ 
extern int timer_getoverrun (timer_t __timerid) __THROW; 
# endif 
 
 
# ifdef __USE_XOPEN_EXTENDED 


	the time in seconds since 00:00:00 UTC, January 1, 1970) */ 
extern int getdate_err; 
 


   marked with __THROW.  */ 
extern struct tm *getdate (__const char *__string); 
# endif 
 
# ifdef __USE_GNU 


   therefore not marked with __THROW.  */ 
extern int getdate_r (__const char *__restrict __string, 
		      struct tm *__restrict __resbufp); 
# endif 
 
__END_DECLS 
 
#endif 

#endif /* <time.h> not already included.  */ 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_UNISTD_H 
#define	_UNISTD_H	1 
 
 
__BEGIN_DECLS 
 


   Their values can be obtained at run time from `sysconf'.  */ 
 


   in the theoretically application-owned namespace.  */ 
 


   C Language Bindings Option.  */ 
#define	_POSIX2_C_BIND	200112L 
 


   C Language Development Utilities Option.  */ 
#define	_POSIX2_C_DEV	200112L 
 


   Software Development Utilities Option.  */ 
#define	_POSIX2_SW_DEV	200112L 
 


   creation of locales with the localedef utility.  */ 
 


/* Commands and utilities from XPG4 are available.  */ 
 


/* The X/Open Unix extensions are available.  */ 
 


   are present.  */ 
#define	_XOPEN_ENH_I18N	1 
 


   */ 
 


   Boston, MA 02111-1307, USA.  */ 
 
#ifndef	_POSIX_OPT_H 
#define	_POSIX_OPT_H	1 
 


/* Processes have a saved set-user-ID and a saved set-group-ID.  */ 
#define	_POSIX_SAVED_IDS	1 
 


/* Synchronizing file data is supported.  */ 
#define	_POSIX_SYNCHRONIZED_IO	200112L 
 


/* Mapping of files to memory is supported.  */ 
#define	_POSIX_MAPPED_FILES	200112L 
 


/* Locking of ranges of memory is supported.  */ 
#define	_POSIX_MEMLOCK_RANGE	200112L 
 


/* Only root can change owner of file.  */ 
#define	_POSIX_CHOWN_RESTRICTED	1 
 


   using the value _POSIX_VDISABLE.  */ 
#define	_POSIX_VDISABLE	'\0' 
 


/* X/Open realtime support is available.  */ 
 


/* XPG4.2 shared memory is supported.  */ 
#define	_XOPEN_SHM	1 
 


/* We have the reentrant functions described in POSIX.  */ 
 


/* We support user-defined stack sizes.  */ 
 


/* We support priority inheritence.  */ 
 


   mutexes.  */ 
 


/* Real-time signals are supported.  */ 
 


/* Alternative name for Unix98.  */ 


/* The LFS support in asynchronous I/O is also available.  */ 
 


/* POSIX shared memory objects are implemented.  */ 
 


/* Clock support in threads must be also checked at runtime.  */ 
 


/* Reader/Writer locks are available.  */ 
 


/* We support the Timeouts option.  */ 
 


/* The `spawn' function family is supported.  */ 
 


/* The barrier functions are available.  */ 
 


/* Thread process-shared synchronization is supported.  */ 
 


/* The clock selection interfaces are available.  */ 
 


/* IPv6 support is available.  */ 
 


/* We have at least one terminal.  */ 
 


/* trace.h is not available.  */ 
 


#endif /* posix_opt.h */ 
 
 


/* Standard file descriptors.  */ 
#define	STDIN_FILENO	0	

#define	STDOUT_FILENO	1	/* Standard output.  */ 
#define	STDERR_FILENO	2	

/* All functions that are not declared anywhere else.  */ 
 
 
#ifndef	__ssize_t_defined 
typedef __ssize_t ssize_t; 
# define __ssize_t_defined 
#endif 
 
#define	__need_size_t 
 
#if defined __USE_XOPEN || defined __USE_XOPEN2K 


   available here.  */ 
# ifndef __gid_t_defined 
typedef __gid_t gid_t; 
#  define __gid_t_defined 
# endif 
 
# ifndef __uid_t_defined 
typedef __uid_t uid_t; 
#  define __uid_t_defined 
# endif 
 
# ifndef __off_t_defined 
#  ifndef __USE_FILE_OFFSET64 
typedef __off_t off_t; 
#  else 
typedef __off64_t off_t; 
#  endif 
#  define __off_t_defined 
# endif 
# if defined __USE_LARGEFILE64 && !defined __off64_t_defined 
typedef __off64_t off64_t; 
#  define __off64_t_defined 
# endif 
 
# ifndef __useconds_t_defined 
typedef __useconds_t useconds_t; 
#  define __useconds_t_defined 
# endif 
 
# ifndef __pid_t_defined 
typedef __pid_t pid_t; 
#  define __pid_t_defined 
# endif 
#endif	

   These may be OR'd together.  */ 
#define	R_OK	4		

#define	W_OK	2		/* Test for write permission.  */ 
#define	X_OK	1		

#define	F_OK	0		/* Test for existence.  */ 
 


   (as normal file operations use).  */ 
extern int euidaccess (__const char *__name, int __type) 
     __THROW __nonnull ((1)); 
 


   otherwise use real IDs like `access'.  */ 
extern int faccessat (int __fd, __const char *__file, int __type, int __flag) 
     __THROW __nonnull ((2)) __wur; 
#endif 

/* Values for the WHENCE argument to lseek.  */ 
#ifndef	_STDIO_H		

# define SEEK_SET	0	/* Seek from beginning of file.  */ 
# define SEEK_CUR	1	

# define SEEK_END	2	/* Seek from end of file.  */ 
#endif 
 
#if defined __USE_BSD && !defined L_SET 


   Return the new file position.  */ 
#ifndef __USE_FILE_OFFSET64 
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __THROW; 
#else 
# ifdef __REDIRECT_NTH 
extern __off64_t __REDIRECT_NTH (lseek, 
				 (int __fd, __off64_t __offset, int __whence), 
				 lseek64); 
# else 
#  define lseek lseek64 
# endif 
#endif 
#ifdef __USE_LARGEFILE64 
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence) 
     __THROW; 
#endif 
 


   __THROW.  */ 
extern int close (int __fd); 
 


   __THROW.  */ 
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __wur; 
 


   __THROW.  */ 
extern ssize_t write (int __fd, __const void *__buf, size_t __n) __wur; 
 
#ifdef __USE_UNIX98 
# ifndef __USE_FILE_OFFSET64 


   __THROW.  */ 
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes, 
		      __off_t __offset) __wur; 
 


   __THROW.  */ 
extern ssize_t pwrite (int __fd, __const void *__buf, size_t __n, 
		       __off_t __offset) __wur; 
# else 
#  ifdef __REDIRECT 
extern ssize_t __REDIRECT (pread, (int __fd, void *__buf, size_t __nbytes, 
				   __off64_t __offset), 
			   pread64) __wur; 
extern ssize_t __REDIRECT (pwrite, (int __fd, __const void *__buf, 
				    size_t __nbytes, __off64_t __offset), 
			   pwrite64) __wur; 
#  else 
#   define pread pread64 
#   define pwrite pwrite64 
#  endif 
# endif 
 
# ifdef __USE_LARGEFILE64 


   or 0 for EOF.  */ 
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes, 
			__off64_t __offset) __wur; 


   changing the file pointer.  Return the number written, or -1.  */ 
extern ssize_t pwrite64 (int __fd, __const void *__buf, size_t __n, 
			 __off64_t __offset) __wur; 
# endif 
#endif 
 


   Returns 0 if successful, -1 if not.  */ 
extern int pipe (int __pipedes[2]) __THROW __wur; 
 


   The signal may come late due to processor scheduling.  */ 
extern unsigned int alarm (unsigned int __seconds) __THROW; 
 


   __THROW.  */ 
extern unsigned int sleep (unsigned int __seconds); 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   Returns the number of microseconds remaining before the alarm.  */ 
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval) 
     __THROW; 
 


   __THROW.  */ 
extern int usleep (__useconds_t __useconds); 
#endif 
 
 


   __THROW.  */ 
extern int pause (void); 
 
 


/* Change the owner and group of the file that FD is open on.  */ 
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __THROW __wur; 
 
 


   link the ownership of the symbolic link is changed.  */ 
extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group) 
     __THROW __nonnull ((1)) __wur; 
 
#endif 

   on.  */ 
extern int fchownat (int __fd, __const char *__file, __uid_t __owner, 
		     __gid_t __group, int __flag) 
     __THROW __nonnull ((2)) __wur; 
#endif 

/* Change the process's working directory to PATH.  */ 
extern int chdir (__const char *__path) __THROW __nonnull ((1)) __wur; 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   big as necessary.  */ 
extern char *getcwd (char *__buf, size_t __size) __THROW __wur; 
 
#ifdef	__USE_GNU 


   that value is used.  */ 
extern char *get_current_dir_name (void) __THROW; 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   BUF and return NULL.  BUF should be at least PATH_MAX bytes long.  */ 
extern char *getwd (char *__buf) 
     __THROW __nonnull ((1)) __attribute_deprecated__ __wur; 
#endif 
 
 


/* Duplicate FD to FD2, closing FD2 and making it open on the same file.  */ 
extern int dup2 (int __fd, int __fd2) __THROW; 
 


   environment ENVP.  ARGV and ENVP are terminated by 0 pointers.  */ 
extern int execve (__const char *__path, char *__const __argv[], 
		   char *__const __envp[]) __THROW __nonnull ((1)); 
 
#ifdef __USE_GNU 


   ARGV and ENVP are passed to the new program, as for `execve'.  */ 
extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[]) 
     __THROW; 
#endif 
 
 


   and the argument after that for environment.  */ 
extern int execle (__const char *__path, __const char *__arg, ...) 
     __THROW __nonnull ((1)); 
 


   a 0 pointer and environment from `environ'.  */ 
extern int execl (__const char *__path, __const char *__arg, ...) 
     __THROW __nonnull ((1)); 
 


   no slashes, with arguments ARGV and environment from `environ'.  */ 
extern int execvp (__const char *__file, char *__const __argv[]) 
     __THROW __nonnull ((1)); 
 


   0 pointer and environment from `environ'.  */ 
extern int execlp (__const char *__file, __const char *__arg, ...) 
     __THROW __nonnull ((1)); 
 
 
#if defined __USE_MISC || defined __USE_XOPEN 


/* Terminate program execution with the low-order 8 bits of STATUS.  */ 
extern void _exit (int __status) __attribute__ ((__noreturn__)); 
 
 


   and the `_CS_*' symbols for the NAME argument to `confstr'.  */ 


   02111-1307 USA.  */ 
 
#ifndef _UNISTD_H 
# error "Never use <bits/confname.h> directly; include <unistd.h> instead." 
#endif 
 


/* Values for the argument to `sysconf'.  */ 
enum 
  { 
    _SC_ARG_MAX, 
#define	_SC_ARG_MAX			_SC_ARG_MAX 
    _SC_CHILD_MAX, 
#define	_SC_CHILD_MAX			_SC_CHILD_MAX 
    _SC_CLK_TCK, 
#define	_SC_CLK_TCK			_SC_CLK_TCK 
    _SC_NGROUPS_MAX, 
#define	_SC_NGROUPS_MAX			_SC_NGROUPS_MAX 
    _SC_OPEN_MAX, 
#define	_SC_OPEN_MAX			_SC_OPEN_MAX 
    _SC_STREAM_MAX, 
#define	_SC_STREAM_MAX			_SC_STREAM_MAX 
    _SC_TZNAME_MAX, 
#define	_SC_TZNAME_MAX			_SC_TZNAME_MAX 
    _SC_JOB_CONTROL, 
#define	_SC_JOB_CONTROL			_SC_JOB_CONTROL 
    _SC_SAVED_IDS, 
#define	_SC_SAVED_IDS			_SC_SAVED_IDS 
    _SC_REALTIME_SIGNALS, 
#define	_SC_REALTIME_SIGNALS		_SC_REALTIME_SIGNALS 
    _SC_PRIORITY_SCHEDULING, 
#define	_SC_PRIORITY_SCHEDULING		_SC_PRIORITY_SCHEDULING 
    _SC_TIMERS, 
#define	_SC_TIMERS			_SC_TIMERS 
    _SC_ASYNCHRONOUS_IO, 
#define	_SC_ASYNCHRONOUS_IO		_SC_ASYNCHRONOUS_IO 
    _SC_PRIORITIZED_IO, 
#define	_SC_PRIORITIZED_IO		_SC_PRIORITIZED_IO 
    _SC_SYNCHRONIZED_IO, 
#define	_SC_SYNCHRONIZED_IO		_SC_SYNCHRONIZED_IO 
    _SC_FSYNC, 
#define	_SC_FSYNC			_SC_FSYNC 
    _SC_MAPPED_FILES, 
#define	_SC_MAPPED_FILES		_SC_MAPPED_FILES 
    _SC_MEMLOCK, 
#define	_SC_MEMLOCK			_SC_MEMLOCK 
    _SC_MEMLOCK_RANGE, 
#define	_SC_MEMLOCK_RANGE		_SC_MEMLOCK_RANGE 
    _SC_MEMORY_PROTECTION, 
#define	_SC_MEMORY_PROTECTION		_SC_MEMORY_PROTECTION 
    _SC_MESSAGE_PASSING, 
#define	_SC_MESSAGE_PASSING		_SC_MESSAGE_PASSING 
    _SC_SEMAPHORES, 
#define	_SC_SEMAPHORES			_SC_SEMAPHORES 
    _SC_SHARED_MEMORY_OBJECTS, 
#define	_SC_SHARED_MEMORY_OBJECTS	_SC_SHARED_MEMORY_OBJECTS 
    _SC_AIO_LISTIO_MAX, 
#define	_SC_AIO_LISTIO_MAX		_SC_AIO_LISTIO_MAX 
    _SC_AIO_MAX, 
#define	_SC_AIO_MAX			_SC_AIO_MAX 
    _SC_AIO_PRIO_DELTA_MAX, 
#define	_SC_AIO_PRIO_DELTA_MAX		_SC_AIO_PRIO_DELTA_MAX 
    _SC_DELAYTIMER_MAX, 
#define	_SC_DELAYTIMER_MAX		_SC_DELAYTIMER_MAX 
    _SC_MQ_OPEN_MAX, 
#define	_SC_MQ_OPEN_MAX			_SC_MQ_OPEN_MAX 
    _SC_MQ_PRIO_MAX, 
#define	_SC_MQ_PRIO_MAX			_SC_MQ_PRIO_MAX 
    _SC_VERSION, 
#define	_SC_VERSION			_SC_VERSION 
    _SC_PAGESIZE, 
#define	_SC_PAGESIZE			_SC_PAGESIZE 
#define	_SC_PAGE_SIZE			_SC_PAGESIZE 
    _SC_RTSIG_MAX, 
#define	_SC_RTSIG_MAX			_SC_RTSIG_MAX 
    _SC_SEM_NSEMS_MAX, 
#define	_SC_SEM_NSEMS_MAX		_SC_SEM_NSEMS_MAX 
    _SC_SEM_VALUE_MAX, 
#define	_SC_SEM_VALUE_MAX		_SC_SEM_VALUE_MAX 
    _SC_SIGQUEUE_MAX, 
#define	_SC_SIGQUEUE_MAX		_SC_SIGQUEUE_MAX 
    _SC_TIMER_MAX, 
#define	_SC_TIMER_MAX			_SC_TIMER_MAX 
 
    

       corresponding to _POSIX2_* symbols.  */ 
    _SC_BC_BASE_MAX, 
#define	_SC_BC_BASE_MAX			_SC_BC_BASE_MAX 
    _SC_BC_DIM_MAX, 
#define	_SC_BC_DIM_MAX			_SC_BC_DIM_MAX 
    _SC_BC_SCALE_MAX, 
#define	_SC_BC_SCALE_MAX		_SC_BC_SCALE_MAX 
    _SC_BC_STRING_MAX, 
#define	_SC_BC_STRING_MAX		_SC_BC_STRING_MAX 
    _SC_COLL_WEIGHTS_MAX, 
#define	_SC_COLL_WEIGHTS_MAX		_SC_COLL_WEIGHTS_MAX 
    _SC_EQUIV_CLASS_MAX, 
#define	_SC_EQUIV_CLASS_MAX		_SC_EQUIV_CLASS_MAX 
    _SC_EXPR_NEST_MAX, 
#define	_SC_EXPR_NEST_MAX		_SC_EXPR_NEST_MAX 
    _SC_LINE_MAX, 
#define	_SC_LINE_MAX			_SC_LINE_MAX 
    _SC_RE_DUP_MAX, 
#define	_SC_RE_DUP_MAX			_SC_RE_DUP_MAX 
    _SC_CHARCLASS_NAME_MAX, 
#define	_SC_CHARCLASS_NAME_MAX		_SC_CHARCLASS_NAME_MAX 
 
    _SC_2_VERSION, 
#define	_SC_2_VERSION			_SC_2_VERSION 
    _SC_2_C_BIND, 
#define	_SC_2_C_BIND			_SC_2_C_BIND 
    _SC_2_C_DEV, 
#define	_SC_2_C_DEV			_SC_2_C_DEV 
    _SC_2_FORT_DEV, 
#define	_SC_2_FORT_DEV			_SC_2_FORT_DEV 
    _SC_2_FORT_RUN, 
#define	_SC_2_FORT_RUN			_SC_2_FORT_RUN 
    _SC_2_SW_DEV, 
#define	_SC_2_SW_DEV			_SC_2_SW_DEV 
    _SC_2_LOCALEDEF, 
#define	_SC_2_LOCALEDEF			_SC_2_LOCALEDEF 
 
    _SC_PII, 
#define	_SC_PII				_SC_PII 
    _SC_PII_XTI, 
#define	_SC_PII_XTI			_SC_PII_XTI 
    _SC_PII_SOCKET, 
#define	_SC_PII_SOCKET			_SC_PII_SOCKET 
    _SC_PII_INTERNET, 
#define	_SC_PII_INTERNET		_SC_PII_INTERNET 
    _SC_PII_OSI, 
#define	_SC_PII_OSI			_SC_PII_OSI 
    _SC_POLL, 
#define	_SC_POLL			_SC_POLL 
    _SC_SELECT, 
#define	_SC_SELECT			_SC_SELECT 
    _SC_UIO_MAXIOV, 
#define	_SC_UIO_MAXIOV			_SC_UIO_MAXIOV 
    _SC_IOV_MAX = _SC_UIO_MAXIOV, 
    _SC_PII_INTERNET_STREAM, 
#define	_SC_PII_INTERNET_STREAM		_SC_PII_INTERNET_STREAM 
    _SC_PII_INTERNET_DGRAM, 
#define	_SC_PII_INTERNET_DGRAM		_SC_PII_INTERNET_DGRAM 
    _SC_PII_OSI_COTS, 
#define	_SC_PII_OSI_COTS		_SC_PII_OSI_COTS 
    _SC_PII_OSI_CLTS, 
#define	_SC_PII_OSI_CLTS		_SC_PII_OSI_CLTS 
    _SC_PII_OSI_M, 
#define	_SC_PII_OSI_M			_SC_PII_OSI_M 
    _SC_T_IOV_MAX, 
#define	_SC_T_IOV_MAX			_SC_T_IOV_MAX 
 
    

    /* Leave room here, maybe we need a few more cache levels some day.  */ 
 
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50, 
    _SC_RAW_SOCKETS 
  }; 
 


    _CS_PATH,			/* The default search path.  */ 
 
    _CS_V6_WIDTH_RESTRICTED_ENVS, 
# define _CS_V6_WIDTH_RESTRICTED_ENVS	_CS_V6_WIDTH_RESTRICTED_ENVS 
 
    _CS_GNU_LIBC_VERSION, 
    _CS_GNU_LIBPTHREAD_VERSION, 
 
    _CS_LFS_CFLAGS = 1000, 
    _CS_LFS_LDFLAGS, 
    _CS_LFS_LIBS, 
    _CS_LFS_LINTFLAGS, 
    _CS_LFS64_CFLAGS, 
    _CS_LFS64_LDFLAGS, 
    _CS_LFS64_LIBS, 
    _CS_LFS64_LINTFLAGS, 
 
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100, 
    _CS_XBS5_ILP32_OFF32_LDFLAGS, 
    _CS_XBS5_ILP32_OFF32_LIBS, 
    _CS_XBS5_ILP32_OFF32_LINTFLAGS, 
    _CS_XBS5_ILP32_OFFBIG_CFLAGS, 
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS, 
    _CS_XBS5_ILP32_OFFBIG_LIBS, 
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS, 
    _CS_XBS5_LP64_OFF64_CFLAGS, 
    _CS_XBS5_LP64_OFF64_LDFLAGS, 
    _CS_XBS5_LP64_OFF64_LIBS, 
    _CS_XBS5_LP64_OFF64_LINTFLAGS, 
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS, 
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS, 
    _CS_XBS5_LPBIG_OFFBIG_LIBS, 
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS, 
 
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS, 
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS, 
    _CS_POSIX_V6_ILP32_OFF32_LIBS, 
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS, 
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS, 
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS, 
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS, 
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS, 
    _CS_POSIX_V6_LP64_OFF64_CFLAGS, 
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS, 
    _CS_POSIX_V6_LP64_OFF64_LIBS, 
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS, 
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS, 
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS, 
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS, 
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS 
  }; 
 
 


/* Get file-specific configuration about descriptor FD.  */ 
extern long int fpathconf (int __fd, int __name) __THROW; 
 


/* Get the value of the string-valued system variable NAME.  */ 
extern size_t confstr (int __name, char *__buf, size_t __len) __THROW; 
#endif 
 
 


/* Get the process ID of the calling process's parent.  */ 
extern __pid_t getppid (void) __THROW; 
 


   This function is different on old BSD. */ 
#ifndef __FAVOR_BSD 
extern __pid_t getpgrp (void) __THROW; 
#else 
# ifdef __REDIRECT_NTH 
extern __pid_t __REDIRECT_NTH (getpgrp, (__pid_t __pid), __getpgid); 
# else 
#  define getpgrp __getpgid 
# endif 
#endif 
 


   If PGID is zero, the process ID of the process is used.  */ 
extern int setpgid (__pid_t __pid, __pid_t __pgid) __THROW; 
 
#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   function is available under -D_BSD_SOURCE.  */ 
 
# ifndef __FAVOR_BSD 
 


   This is exactly the same as `setpgid (0, 0)'.  */ 
extern int setpgrp (void) __THROW; 
 
# else 
 


# endif	/* Favor BSD.  */ 
#endif	

   are set to the process ID of the calling process, which is returned.  */ 
extern __pid_t setsid (void) __THROW; 
 
#ifdef __USE_XOPEN_EXTENDED 


/* Get the real user ID of the calling process.  */ 
extern __uid_t getuid (void) __THROW; 
 


/* Get the real group ID of the calling process.  */ 
extern __gid_t getgid (void) __THROW; 
 


   of its supplementary groups in LIST and return the number written.  */ 
extern int getgroups (int __size, __gid_t __list[]) __THROW __wur; 
 
#ifdef	__USE_GNU 


   if not, the effective user ID is set to UID.  */ 
extern int setuid (__uid_t __uid) __THROW; 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   and the effective user ID of the calling process to EUID.  */ 
extern int setreuid (__uid_t __ruid, __uid_t __euid) __THROW; 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN2K 


#endif /* Use BSD.  */ 
 


   if not, the effective group ID is set to GID.  */ 
extern int setgid (__gid_t __gid) __THROW; 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   and the effective group ID of the calling process to EGID.  */ 
extern int setregid (__gid_t __rgid, __gid_t __egid) __THROW; 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN2K 


#endif /* Use BSD.  */ 
 
#ifdef __USE_GNU 


   of the calling process.  */ 
extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid) 
     __THROW; 
 


   of the calling process.  */ 
extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid) 
     __THROW; 
 


   of the calling process to RUID, EUID, and SUID, respectively.  */ 
extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid) 
     __THROW; 
 


   of the calling process to RGID, EGID, and SGID, respectively.  */ 
extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid) 
     __THROW; 
#endif 
 
 


   and the process ID of the new process to the old process.  */ 
extern __pid_t fork (void) __THROW; 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   and the process ID of the new process to the old process.  */ 
extern __pid_t vfork (void) __THROW; 
#endif 

   The returned storage is good only until the next call to this function.  */ 
extern char *ttyname (int __fd) __THROW; 
 


   open on in BUF.  Return 0 on success, otherwise an error number.  */ 
extern int ttyname_r (int __fd, char *__buf, size_t __buflen) 
     __THROW __nonnull ((2)) __wur; 
 


   with a terminal, zero if not.  */ 
extern int isatty (int __fd) __THROW; 
 
#if defined __USE_BSD \ 
    || (defined __USE_XOPEN_EXTENDED && !defined __USE_UNIX98) 


   the controlling terminal.  */ 
extern int ttyslot (void) __THROW; 
#endif 
 
 


   to FROMFD and TOFD respectively.  */ 
extern int linkat (int __fromfd, __const char *__from, int __tofd, 
		   __const char *__to, int __flags) 
     __THROW __nonnull ((2, 4)) __wur; 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K 


   Returns the number of characters read, or -1 for errors.  */ 
extern ssize_t readlink (__const char *__restrict __path, 
			 char *__restrict __buf, size_t __len) 
     __THROW __nonnull ((1, 2)) __wur; 
#endif 

/* Like symlink but a relative path in TO is interpreted relative to TOFD.  */ 
extern int symlinkat (__const char *__from, int __tofd, 
		      __const char *__to) __THROW __nonnull ((1, 3)) __wur; 
 


/* Remove the link NAME.  */ 
extern int unlink (__const char *__name) __THROW __nonnull ((1)); 
 
#ifdef __USE_ATFILE 


/* Remove the directory PATH.  */ 
extern int rmdir (__const char *__path) __THROW __nonnull ((1)); 
 
 


/* Set the foreground process group ID of FD set PGRP_ID.  */ 
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __THROW; 
 
 


   marked with __THROW.  */ 
extern char *getlogin (void); 
#if defined __USE_REENTRANT || defined __USE_POSIX199506 


   marked with __THROW.  */ 
extern int getlogin_r (char *__name, size_t __name_len) __nonnull ((1)); 
#endif 
 
#ifdef	__USE_BSD 


   options given in OPTS.  */ 
# define __need_getopt 
# include <getopt.h> 
#endif 
 
 
#if defined __USE_BSD || defined __USE_UNIX98 


   name and the terminator.  */ 
extern int gethostname (char *__name, size_t __len) __THROW __nonnull ((1)); 
#endif 
 
 
#if defined __USE_BSD || (defined __USE_XOPEN && !defined __USE_UNIX98) 


   This call is restricted to the super-user.  */ 
extern int sethostname (__const char *__name, size_t __len) 
     __THROW __nonnull ((1)) __wur; 
 


   This call is restricted to the super-user.  */ 
extern int sethostid (long int __id) __THROW __wur; 
 
 


   The NIS domain name is usually the empty string when not using NIS.  */ 
extern int getdomainname (char *__name, size_t __len) 
     __THROW __nonnull ((1)) __wur; 
extern int setdomainname (__const char *__name, size_t __len) 
     __THROW __nonnull ((1)) __wur; 
 
 


   group of the control terminal.  */ 
extern int vhangup (void) __THROW; 
 


   disable profiling.  Returns zero on success, -1 on error.  */ 
extern int profil (unsigned short int *__sample_buffer, size_t __size, 
		   size_t __offset, unsigned int __scale) 
     __THROW __nonnull ((1)); 
 
 


   turn accounting off.  This call is restricted to the super-user.  */ 
extern int acct (__const char *__name) __THROW; 
 
 


extern void endusershell (void) __THROW; /* Discard cached info.  */ 
extern void setusershell (void) __THROW; 

   redirects stdin, stdout, and stderr to /dev/null.  */ 
extern int daemon (int __nochdir, int __noclose) __THROW __wur; 
#endif 

   This call is restricted to the super-user.  */ 
extern int chroot (__const char *__path) __THROW __nonnull ((1)) __wur; 
 


   Uses /dev/tty if possible; otherwise stderr and stdin.  */ 
extern char *getpass (__const char *__prompt) __nonnull ((1)); 
#endif 

   __THROW.  */ 
extern int fsync (int __fd); 
#endif 

/* Return identifier for the current host.  */ 
extern long int gethostid (void); 
 


   which is not necessarily the same as the hardware page size.  */ 
extern int getpagesize (void)  __THROW __attribute__ ((__const__)); 
 
 


   the current process could possibly have.  */ 
extern int getdtablesize (void) __THROW; 
 
 


#endif /* Use BSD || X/Open Unix.  */ 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K 
 


#endif /* Use BSD || X/Open Unix || POSIX 2003.  */ 
 
 
#if defined __USE_MISC || defined __USE_XOPEN_EXTENDED 
 


   Returns zero on success and -1 for errors (with errno set).  */ 
extern int brk (void *__addr) __THROW __wur; 
 


   returns (void *) -1 for errors (with errno set).  */ 
extern void *sbrk (intptr_t __delta) __THROW; 
#endif 
 
 
#ifdef __USE_MISC 


   error code (zero for success).  */ 
extern long int syscall (long int __sysno, ...) __THROW; 
 
#endif	

   software depends on the macros being defined without including both.  */ 
 


   __THROW.  */ 
 
# define F_ULOCK 0	

# define F_LOCK  1	/* Lock a region for exclusive use.  */ 
# define F_TLOCK 2	

# define F_TEST  3	/* Test a region for other processes locks.  */ 
 
# ifndef __USE_FILE_OFFSET64 
extern int lockf (int __fd, int __cmd, __off_t __len) __wur; 
# else 
#  ifdef __REDIRECT 
extern int __REDIRECT (lockf, (int __fd, int __cmd, __off64_t __len), 
		       lockf64) __wur; 
#  else 
#   define lockf lockf64 
#  endif 
# endif 
# ifdef __USE_LARGEFILE64 
extern int lockf64 (int __fd, int __cmd, __off64_t __len) __wur; 
# endif 
#endif 

   set to EINTR.  */ 
 
# define TEMP_FAILURE_RETRY(expression) \ 
  (__extension__							      \ 
    ({ long int __result;						      \ 
       do __result = (long int) (expression);				      \ 
       while (__result == -1L && errno == EINTR);			      \ 
       __result; })) 
#endif 
 
#if defined __USE_POSIX199309 || defined __USE_UNIX98 


   media.  */ 
extern int fdatasync (int __fildes); 
#endif 

   be defined here.  */ 
#ifdef	__USE_XOPEN 


   block in place.  */ 
extern void encrypt (char *__block, int __edflag) __THROW __nonnull ((1)); 
 
 


   is without partner.  */ 
extern void swab (__const void *__restrict __from, void *__restrict __to, 
		  ssize_t __n) __THROW __nonnull ((1, 2)); 
#endif 
 
 


   It is also found in <stdio.h>.  */ 
#ifdef __USE_XOPEN 


/* Define some macros helping to catch buffer overflows.  */ 
#if __USE_FORTIFY_LEVEL > 0 && !defined __cplusplus 
# include <bits/unistd.h> 
#endif 
 
__END_DECLS 
 
#endif 
 
 


 */ 


   02111-1307 USA.  */ 
 
#ifndef _SYS_PARAM_H 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef _LIBC_LIMITS_H_ 
 
 
 


   the correct value.  */ 
 
 


   Otherwise use gcc's definitions (see below).  */ 
#if !defined __GNUC__ || __GNUC__ < 2 
 


   multiple copies of this file before we get to GCC's.  */ 
# ifndef _LIMITS_H 
#  define _LIMITS_H	1 
 
 


   Define ANSI <limits.h> for standard 32-bit words.  */ 
 


   and 32-bit `int's and `long int's.  */ 
 


/* Minimum and maximum values a `signed char' can hold.  */ 
#  define SCHAR_MIN	(-128) 
#  define SCHAR_MAX	127 
 


/* Minimum and maximum values a `char' can hold.  */ 
#  ifdef __CHAR_UNSIGNED__ 
#   define CHAR_MIN	0 
#   define CHAR_MAX	UCHAR_MAX 
#  else 
#   define CHAR_MIN	SCHAR_MIN 
#   define CHAR_MAX	SCHAR_MAX 
#  endif 
 


/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */ 
#  define USHRT_MAX	65535 
 


/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */ 
#  define UINT_MAX	4294967295U 
 


/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */ 
#  if __WORDSIZE == 64 
#   define ULONG_MAX	18446744073709551615UL 
#  else 
#   define ULONG_MAX	4294967295UL 
#  endif 
 
#  ifdef __USE_ISOC99 
 


/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0.)  */ 
#   define ULLONG_MAX	18446744073709551615ULL 
 
#  endif 

# endif	/* limits.h  */ 
#endif	

#endif	/* !_LIBC_LIMITS_H_ */ 
 
 

    the definitions from gcc's header.  */ 
#if defined __GNUC__ && !defined _GCC_LIMITS_H_ 


   ages are available.  */ 
#if defined __USE_ISOC99 && defined __GNUC__ 
# ifndef LLONG_MIN 
#  define LLONG_MIN	(-LLONG_MAX-1) 
# endif 
# ifndef LLONG_MAX 
#  define LLONG_MAX	__LONG_LONG_MAX__ 
# endif 
# ifndef ULLONG_MAX 
#  define ULLONG_MAX	(LLONG_MAX * 2ULL + 1) 
# endif 
#endif 
 
#ifdef	__USE_POSIX 

 
 


   anyway.  */ 
 
 
 


/* Macros for counting and rounding.  */ 
#ifndef howmany 
# define howmany(x, y)	(((x) + ((y) - 1)) / (y)) 
#endif 
#ifdef __GNUC__ 
# define roundup(x, y)	(__builtin_constant_p (y) && powerof2 (y)	      \ 
			 ? (((x) + (y) - 1) & ~((y) - 1))		      \ 
			 : ((((x) + ((y) - 1)) / (y)) * (y))) 
#else 
# define roundup(x, y)	((((x) + ((y) - 1)) / (y)) * (y)) 
#endif 
 


/* Unit of `st_blocks'.  */ 
 
 
#endif	
 


/* Get htonl(), ntohl(), etc. */ 


   02111-1307 USA.  */ 
 
#ifndef	_NETINET_IN_H 
#define	_NETINET_IN_H	1 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef _STDINT_H 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef _WCHAR_H 
 
#ifndef __need_mbstate_t 
# define _WCHAR_H 1 
# include <features.h> 
#endif 
 
#ifdef _WCHAR_H 


/* Get va_list definition.  */ 
# define __need___va_list 
# include <stdarg.h> 
 


   there.  So define it ourselves if it remains undefined.  */ 
#ifndef _WINT_T 


   member of the extended character set.  */ 
# define _WINT_T 
typedef unsigned int wint_t; 
#else 


   wint_t in the std namespace.  */ 
# if defined __cplusplus && defined _GLIBCPP_USE_NAMESPACES \ 
     && defined __WINT_TYPE__ 
__BEGIN_NAMESPACE_STD 
typedef __WINT_TYPE__ wint_t; 
__END_NAMESPACE_STD 
# endif 
#endif 
 
 
#ifndef __mbstate_t_defined 
# define __mbstate_t_defined	1 


  } __value;		/* Value so far.  */ 
} __mbstate_t; 
#endif 
#undef __need_mbstate_t 
 
 


   defined.  */ 
#ifdef _WCHAR_H 
 
__BEGIN_NAMESPACE_C99 


/* These constants might also be defined in <inttypes.h>.  */ 
# define WCHAR_MIN __WCHAR_MIN 
# define WCHAR_MAX __WCHAR_MAX 
#endif 
 
#ifndef WEOF 
# define WEOF (0xffffffffu) 
#endif 
 


   as well.  */ 
#if defined __USE_XOPEN && !defined __USE_UNIX98 
# include <wctype.h> 
#endif 
 
 
__BEGIN_DECLS 
 
__BEGIN_NAMESPACE_STD 


   of `wcsftime'.  */ 
struct tm; 


   without inserting it in the global namespace.  */ 
__USING_NAMESPACE_STD(tm) 
__END_NAMESPACE_STD 
 
 
__BEGIN_NAMESPACE_C99 


/* Copy no more than N wide-characters of SRC to DEST.  */ 
extern wchar_t *wcsncpy (wchar_t *__restrict __dest, 
			 __const wchar_t *__restrict __src, size_t __n) 
     __THROW; 
 


/* Append no more than N wide-characters of SRC onto DEST.  */ 
extern wchar_t *wcsncat (wchar_t *__restrict __dest, 
			 __const wchar_t *__restrict __src, size_t __n) 
     __THROW; 
 


/* Compare N wide-characters of S1 and S2.  */ 
extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, size_t __n) 
     __THROW __attribute_pure__; 
__END_NAMESPACE_C99 
 
#ifdef __USE_GNU 


/* Compare no more than N chars of S1 and S2, ignoring case.  */ 
extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2, 
			size_t __n) __THROW; 
 


   the provided locale and not the global locale.  */ 
# include <xlocale.h> 
 
extern int wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2, 
			 __locale_t __loc) __THROW; 
 
extern int wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2, 
			  size_t __n, __locale_t __loc) __THROW; 
#endif 
 
__BEGIN_NAMESPACE_C99 


          __LC_COLLATE category of the current locale.  */ 
extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) __THROW; 


   `wcscoll' to the original strings.  */ 
extern size_t wcsxfrm (wchar_t *__restrict __s1, 
		       __const wchar_t *__restrict __s2, size_t __n) __THROW; 
__END_NAMESPACE_C99 
 
#ifdef __USE_GNU 


   the provided locale and not the global locale.  */ 
 


          __LC_COLLATE category of the given locale.  */ 
extern int wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2, 
		      __locale_t __loc) __THROW; 
 


   `wcscoll' to the original strings.  */ 
extern size_t wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2, 
			 size_t __n, __locale_t __loc) __THROW; 
 


/* Find the first occurrence of WC in WCS.  */ 
extern wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc) 
     __THROW __attribute_pure__; 


   the closing NUL wide character in case C is not found in S.  */ 
extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc) 
     __THROW __attribute_pure__; 
#endif 
 
__BEGIN_NAMESPACE_C99 


   consists entirely of wide characters not in REJECT.  */ 
extern size_t wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject) 
     __THROW __attribute_pure__; 


   consists entirely of wide characters in  ACCEPT.  */ 
extern size_t wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept) 
     __THROW __attribute_pure__; 


/* Find the first occurrence of NEEDLE in HAYSTACK.  */ 
extern wchar_t *wcsstr (__const wchar_t *__haystack, __const wchar_t *__needle) 
     __THROW __attribute_pure__; 
 


/* Return the number of wide characters in S.  */ 
extern size_t wcslen (__const wchar_t *__s) __THROW __attribute_pure__; 
__END_NAMESPACE_C99 
 
#ifdef __USE_XOPEN 


/* Return the number of wide characters in S, but at most MAXLEN.  */ 
extern size_t wcsnlen (__const wchar_t *__s, size_t __maxlen) 
     __THROW __attribute_pure__; 
#endif 
 
 
__BEGIN_NAMESPACE_C99 


/* Compare N wide characters of S1 and S2.  */ 
extern int wmemcmp (__const wchar_t *__restrict __s1, 
		    __const wchar_t *__restrict __s2, size_t __n) 
     __THROW __attribute_pure__; 
 


   correct behavior for overlapping strings.  */ 
extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, size_t __n) 
     __THROW; 
 


   wide character.  */ 
extern wchar_t *wmempcpy (wchar_t *__restrict __s1, 
			  __const wchar_t *__restrict __s2, size_t __n) 
     __THROW; 
#endif 
 
 
__BEGIN_NAMESPACE_C99 


   character.  */ 
extern wint_t btowc (int __c) __THROW; 
 


   character set whose multibyte representation is a single byte.  */ 
extern int wctob (wint_t __c) __THROW; 
 


   state.  */ 
extern int mbsinit (__const mbstate_t *__ps) __THROW __attribute_pure__; 
 


   to by S to PWC.  */ 
extern size_t mbrtowc (wchar_t *__restrict __pwc, 
		       __const char *__restrict __s, size_t __n, 
		       mbstate_t *__p) __THROW; 
 


/* Return number of bytes in multibyte character pointed to by S.  */ 
extern size_t __mbrlen (__const char *__restrict __s, size_t __n, 
			mbstate_t *__restrict __ps) __THROW; 
extern size_t mbrlen (__const char *__restrict __s, size_t __n, 
		      mbstate_t *__restrict __ps) __THROW; 
__END_NAMESPACE_C99 
 
#ifdef __USE_EXTERN_INLINES 


   and because the wchar_t encoding is always ISO 10646.  */ 
extern wint_t __btowc_alias (int __c) __asm ("btowc"); 
extern __inline wint_t 
__NTH (btowc (int __c)) 
{ return (__builtin_constant_p (__c) && __c >= '\0' && __c <= '\x7f' 
	  ? (wint_t) __c : __btowc_alias (__c)); } 
 
extern int __wctob_alias (wint_t __c) __asm ("wctob"); 
extern __inline int 
__NTH (wctob (wint_t __wc)) 
{ return (__builtin_constant_p (__wc) && __wc >= L'\0' && __wc <= L'\x7f' 
	  ? (int) __wc : __wctob_alias (__wc)); } 
# endif 
 
extern __inline size_t 
__NTH (mbrlen (__const char *__restrict __s, size_t __n, 
	       mbstate_t *__restrict __ps)) 
{ return (__ps != 0 
	  ? mbrtowc (NULL, __s, __n, __ps) : __mbrlen (__s, __n, NULL)); } 
#endif 
 
__BEGIN_NAMESPACE_C99 


   SRC to DST.  */ 
extern size_t mbsrtowcs (wchar_t *__restrict __dst, 
			 __const char **__restrict __src, size_t __len, 
			 mbstate_t *__restrict __ps) __THROW; 
 


   SRC to DST.  */ 
extern size_t wcsrtombs (char *__restrict __dst, 
			 __const wchar_t **__restrict __src, size_t __len, 
			 mbstate_t *__restrict __ps) __THROW; 
__END_NAMESPACE_C99 
 
 
#ifdef	__USE_GNU 


   multibyte character string SRC to DST.  */ 
extern size_t mbsnrtowcs (wchar_t *__restrict __dst, 
			  __const char **__restrict __src, size_t __nmc, 
			  size_t __len, mbstate_t *__restrict __ps) __THROW; 
 


   from the wide character string SRC to DST.  */ 
extern size_t wcsnrtombs (char *__restrict __dst, 
			  __const wchar_t **__restrict __src, 
			  size_t __nwc, size_t __len, 
			  mbstate_t *__restrict __ps) __THROW; 
#endif	

/* The following functions are extensions found in X/Open CAE.  */ 
#ifdef __USE_XOPEN 


   characters (or fewer if S ends before this) in S.  */ 
extern int wcswidth (__const wchar_t *__s, size_t __n) __THROW; 
#endif	

   representation.  */ 
extern double wcstod (__const wchar_t *__restrict __nptr, 
		      wchar_t **__restrict __endptr) __THROW; 
 
#ifdef __USE_ISOC99 


#endif /* C99 */ 
 
 


   representation.  */ 
extern long int wcstol (__const wchar_t *__restrict __nptr, 
			wchar_t **__restrict __endptr, int __base) __THROW; 
 


   representation.  */ 
extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr, 
				  wchar_t **__restrict __endptr, int __base) 
     __THROW; 
 
#if defined __USE_ISOC99 || (defined __GNUC__ && defined __USE_GNU) 


   representation.  */ 
__extension__ 
extern long long int wcstoll (__const wchar_t *__restrict __nptr, 
			      wchar_t **__restrict __endptr, int __base) 
     __THROW; 
 


   representation.  */ 
__extension__ 
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr, 
					wchar_t **__restrict __endptr, 
					int __base) __THROW; 
#endif 

   representation.  */ 
__extension__ 
extern long long int wcstoq (__const wchar_t *__restrict __nptr, 
			     wchar_t **__restrict __endptr, int __base) 
     __THROW; 
 


   representation.  */ 
__extension__ 
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr, 
				       wchar_t **__restrict __endptr, 
				       int __base) __THROW; 
#endif 

   This is a proof-of-concept implementation.  */ 
 


   (almost) opaque type for the user level programs.  */ 
# include <xlocale.h> 
 


   use as an additional parameter.  */ 
extern long int wcstol_l (__const wchar_t *__restrict __nptr, 
			  wchar_t **__restrict __endptr, int __base, 
			  __locale_t __loc) __THROW; 
 
extern unsigned long int wcstoul_l (__const wchar_t *__restrict __nptr, 
				    wchar_t **__restrict __endptr, 
				    int __base, __locale_t __loc) __THROW; 
 
__extension__ 
extern long long int wcstoll_l (__const wchar_t *__restrict __nptr, 
				wchar_t **__restrict __endptr, 
				int __base, __locale_t __loc) __THROW; 
 
__extension__ 
extern unsigned long long int wcstoull_l (__const wchar_t *__restrict __nptr, 
					  wchar_t **__restrict __endptr, 
					  int __base, __locale_t __loc) 
     __THROW; 
 
extern double wcstod_l (__const wchar_t *__restrict __nptr, 
			wchar_t **__restrict __endptr, __locale_t __loc) 
     __THROW; 
 
extern float wcstof_l (__const wchar_t *__restrict __nptr, 
		       wchar_t **__restrict __endptr, __locale_t __loc) 
     __THROW; 
 
extern long double wcstold_l (__const wchar_t *__restrict __nptr, 
			      wchar_t **__restrict __endptr, 
			      __locale_t __loc) __THROW; 
#endif 

   saying whether or not to parse locale-dependent number grouping.  */ 
extern double __wcstod_internal (__const wchar_t *__restrict __nptr, 
				 wchar_t **__restrict __endptr, int __group) 
     __THROW; 
extern float __wcstof_internal (__const wchar_t *__restrict __nptr, 
				wchar_t **__restrict __endptr, int __group) 
     __THROW; 
extern long double __wcstold_internal (__const wchar_t *__restrict __nptr, 
				       wchar_t **__restrict __endptr, 
				       int __group) __THROW; 
 
#if !defined __wcstol_internal_defined \ 
    && defined __OPTIMIZE__ && __GNUC__ >= 2 
extern long int __wcstol_internal (__const wchar_t *__restrict __nptr, 
				   wchar_t **__restrict __endptr, 
				   int __base, int __group) __THROW; 
# define __wcstol_internal_defined	1 
#endif 
#if !defined __wcstoul_internal_defined \ 
    && defined __OPTIMIZE__ && __GNUC__ >= 2 
extern unsigned long int __wcstoul_internal (__const wchar_t *__restrict __npt, 
					     wchar_t **__restrict __endptr, 
					     int __base, int __group) __THROW; 
# define __wcstoul_internal_defined	1 
#endif 
#if !defined __wcstoll_internal_defined \ 
    && defined __OPTIMIZE__ && __GNUC__ >= 2 
__extension__ 
extern long long int __wcstoll_internal (__const wchar_t *__restrict __nptr, 
					 wchar_t **__restrict __endptr, 
					 int __base, int __group) __THROW; 
# define __wcstoll_internal_defined	1 
#endif 
#if !defined __wcstoull_internal_defined \ 
    && defined __OPTIMIZE__ && __GNUC__ >= 2 
__extension__ 
extern unsigned long long int __wcstoull_internal (__const wchar_t * 
						   __restrict __nptr, 
						   wchar_t ** 
						   __restrict __endptr, 
						   int __base, 
						   int __group) __THROW; 
# define __wcstoull_internal_defined	1 
#endif 
 
 
#if defined __OPTIMIZE__ && __GNUC__ >= 2 


# endif /* Use GNU.  */ 
#endif 

   DEST.  */ 
extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) __THROW; 
 


   the last character written into DEST.  */ 
extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, size_t __n) 
     __THROW; 
#endif	

/* Wide character I/O functions.  */ 
 
#ifdef	__USE_GNU 


   a wide character string.  */ 
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __THROW; 
#endif 
 
#if defined __USE_ISOC99 || defined __USE_UNIX98 
__BEGIN_NAMESPACE_C99 
 


   marked with __THROW.  */ 
extern int fwprintf (__FILE *__restrict __stream, 
		     __const wchar_t *__restrict __format, ...) 
     

   marked with __THROW.  */ 
extern int wprintf (__const wchar_t *__restrict __format, ...) 
     

/* Write formatted output of at most N characters to S.  */ 
extern int swprintf (wchar_t *__restrict __s, size_t __n, 
		     __const wchar_t *__restrict __format, ...) 
     __THROW 

   marked with __THROW.  */ 
extern int vfwprintf (__FILE *__restrict __s, 
		      __const wchar_t *__restrict __format, 
		      __gnuc_va_list __arg) 
     

   marked with __THROW.  */ 
extern int vwprintf (__const wchar_t *__restrict __format, 
		     __gnuc_va_list __arg) 
     

   list ARG.  */ 
extern int vswprintf (wchar_t *__restrict __s, size_t __n, 
		      __const wchar_t *__restrict __format, 
		      __gnuc_va_list __arg) 
     __THROW 

   marked with __THROW.  */ 
extern int fwscanf (__FILE *__restrict __stream, 
		    __const wchar_t *__restrict __format, ...) 
     

   marked with __THROW.  */ 
extern int wscanf (__const wchar_t *__restrict __format, ...) 
     

/* Read formatted input from S.  */ 
extern int swscanf (__const wchar_t *__restrict __s, 
		    __const wchar_t *__restrict __format, ...) 
     __THROW 

#endif /* Use ISO C99 and Unix98. */ 
 
#ifdef __USE_ISOC99 
__BEGIN_NAMESPACE_C99 
 


   marked with __THROW.  */ 
extern int vfwscanf (__FILE *__restrict __s, 
		     __const wchar_t *__restrict __format, 
		     __gnuc_va_list __arg) 
     

   marked with __THROW.  */ 
extern int vwscanf (__const wchar_t *__restrict __format, 
		    __gnuc_va_list __arg) 
     

/* Read formatted input from S into argument list ARG.  */ 
extern int vswscanf (__const wchar_t *__restrict __s, 
		     __const wchar_t *__restrict __format, 
		     __gnuc_va_list __arg) 
     __THROW 

#endif /* Use ISO C99. */ 
 
 
__BEGIN_NAMESPACE_C99 


   marked with __THROW.  */ 
extern wint_t fgetwc (__FILE *__stream); 
extern wint_t getwc (__FILE *__stream); 
 


   marked with __THROW.  */ 
extern wint_t getwchar (void); 
 
 


   marked with __THROW.  */ 
extern wint_t fputwc (wchar_t __wc, __FILE *__stream); 
extern wint_t putwc (wchar_t __wc, __FILE *__stream); 
 


   marked with __THROW.  */ 
extern wint_t putwchar (wchar_t __wc); 
 
 


   marked with __THROW.  */ 
extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n, 
			__FILE *__restrict __stream); 
 


   marked with __THROW.  */ 
extern int fputws (__const wchar_t *__restrict __ws, 
		   __FILE *__restrict __stream); 
 
 


   marked with __THROW.  */ 
extern wint_t ungetwc (wint_t __wc, __FILE *__stream); 
__END_NAMESPACE_C99 
 
 
#ifdef __USE_GNU 


   therefore not marked with __THROW.  */ 
extern wint_t getwc_unlocked (__FILE *__stream); 
extern wint_t getwchar_unlocked (void); 
 


   therefore not marked with __THROW.  */ 
extern wint_t fgetwc_unlocked (__FILE *__stream); 
 


   therefore not marked with __THROW.  */ 
extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream); 
 


   therefore not marked with __THROW.  */ 
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream); 
extern wint_t putwchar_unlocked (wchar_t __wc); 
 
 


   therefore not marked with __THROW.  */ 
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n, 
				 __FILE *__restrict __stream); 
 


   therefore not marked with __THROW.  */ 
extern int fputws_unlocked (__const wchar_t *__restrict __ws, 
			    __FILE *__restrict __stream); 
#endif 
 
 
__BEGIN_NAMESPACE_C99 


   of wide characters written, or 0 if it would exceed MAXSIZE.  */ 
extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize, 
			__const wchar_t *__restrict __format, 
			__const struct tm *__restrict __tp) __THROW; 
__END_NAMESPACE_C99 
 
# ifdef __USE_GNU 
# include <xlocale.h> 
 


   the provided locale and not the global locale.  */ 
extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize, 
			  __const wchar_t *__restrict __format, 
			  __const struct tm *__restrict __tp, 
			  __locale_t __loc) __THROW; 
# endif 
 


   do this nonsense only if really necessary.  */ 
#if defined __USE_UNIX98 && !defined __USE_GNU 
# define __need_iswxxx 
# include <wctype.h> 
#endif 
 


#endif	/* _WCHAR_H defined */ 
 
#endif 
 
 


/* Signed.  */ 
 


/* Unsigned.  */ 
typedef unsigned char		uint8_t; 
typedef unsigned short int	uint16_t; 
#ifndef __uint32_t_defined 
typedef unsigned int		uint32_t; 
# define __uint32_t_defined 
#endif 
#if __WORDSIZE == 64 
typedef unsigned long int	uint64_t; 
#else 
__extension__ 
typedef unsigned long long int	uint64_t; 
#endif 
 
 


/* Signed.  */ 
typedef signed char		int_least8_t; 
typedef short int		int_least16_t; 
typedef int			int_least32_t; 
#if __WORDSIZE == 64 
typedef long int		int_least64_t; 
#else 
__extension__ 
typedef long long int		int_least64_t; 
#endif 
 


/* Fast types.  */ 
 


/* Unsigned.  */ 
typedef unsigned char		uint_fast8_t; 
#if __WORDSIZE == 64 
typedef unsigned long int	uint_fast16_t; 
typedef unsigned long int	uint_fast32_t; 
typedef unsigned long int	uint_fast64_t; 
#else 
typedef unsigned int		uint_fast16_t; 
typedef unsigned int		uint_fast32_t; 
__extension__ 
typedef unsigned long long int	uint_fast64_t; 
#endif 
 
 


/* Largest integral types.  */ 
#if __WORDSIZE == 64 
typedef long int		intmax_t; 
typedef unsigned long int	uintmax_t; 
#else 
__extension__ 
typedef long long int		intmax_t; 
__extension__ 
typedef unsigned long long int	uintmax_t; 
#endif 
 
 


   macros should only be defined if explicitly requested.  */ 
#if !defined __cplusplus || defined __STDC_LIMIT_MACROS 
 
# if __WORDSIZE == 64 
#  define __INT64_C(c)	c ## L 
#  define __UINT64_C(c)	c ## UL 
# else 
#  define __INT64_C(c)	c ## LL 
#  define __UINT64_C(c)	c ## ULL 
# endif 
 


/* Minimum of signed integral types.  */ 
# define INT8_MIN		(-128) 
# define INT16_MIN		(-32767-1) 
# define INT32_MIN		(-2147483647-1) 
# define INT64_MIN		(-__INT64_C(9223372036854775807)-1) 


/* Maximum of unsigned integral types.  */ 
# define UINT8_MAX		(255) 
# define UINT16_MAX		(65535) 
# define UINT32_MAX		(4294967295U) 
# define UINT64_MAX		(__UINT64_C(18446744073709551615)) 
 
 


/* Maximum of signed integral types having a minimum size.  */ 
# define INT_LEAST8_MAX		(127) 
# define INT_LEAST16_MAX	(32767) 
# define INT_LEAST32_MAX	(2147483647) 
# define INT_LEAST64_MAX	(__INT64_C(9223372036854775807)) 
 


/* Minimum of fast signed integral types having a minimum size.  */ 
# define INT_FAST8_MIN		(-128) 
# if __WORDSIZE == 64 
#  define INT_FAST16_MIN	(-9223372036854775807L-1) 
#  define INT_FAST32_MIN	(-9223372036854775807L-1) 
# else 
#  define INT_FAST16_MIN	(-2147483647-1) 
#  define INT_FAST32_MIN	(-2147483647-1) 
# endif 
# define INT_FAST64_MIN		(-__INT64_C(9223372036854775807)-1) 


/* Maximum of fast unsigned integral types having a minimum size.  */ 
# define UINT_FAST8_MAX		(255) 
# if __WORDSIZE == 64 
#  define UINT_FAST16_MAX	(18446744073709551615UL) 
#  define UINT_FAST32_MAX	(18446744073709551615UL) 
# else 
#  define UINT_FAST16_MAX	(4294967295U) 
#  define UINT_FAST32_MAX	(4294967295U) 
# endif 
# define UINT_FAST64_MAX	(__UINT64_C(18446744073709551615)) 
 
 


/* Minimum for largest signed integral type.  */ 
# define INTMAX_MIN		(-__INT64_C(9223372036854775807)-1) 


/* Maximum for largest unsigned integral type.  */ 
# define UINTMAX_MAX		(__UINT64_C(18446744073709551615)) 
 
 


/* Limits of `ptrdiff_t' type.  */ 
# if __WORDSIZE == 64 
#  define PTRDIFF_MIN		(-9223372036854775807L-1) 
#  define PTRDIFF_MAX		(9223372036854775807L) 
# else 
#  define PTRDIFF_MIN		(-2147483647-1) 
#  define PTRDIFF_MAX		(2147483647) 
# endif 
 


/* Limit of `size_t' type.  */ 
# if __WORDSIZE == 64 
#  define SIZE_MAX		(18446744073709551615UL) 
# else 
#  define SIZE_MAX		(4294967295U) 
# endif 
 


/* These constants might also be defined in <wchar.h>.  */ 
#  define WCHAR_MIN		__WCHAR_MIN 
#  define WCHAR_MAX		__WCHAR_MAX 
# endif 
 


#endif	/* C++ && limit macros */ 
 
 


   should only be defined if explicitly requested.  */ 
#if !defined __cplusplus || defined __STDC_CONSTANT_MACROS 
 


/* Unsigned.  */ 
# define UINT8_C(c)	c 
# define UINT16_C(c)	c 
# define UINT32_C(c)	c ## U 
# if __WORDSIZE == 64 
#  define UINT64_C(c)	c ## UL 
# else 
#  define UINT64_C(c)	c ## ULL 
# endif 
 


#endif	/* C++ && constant macros */ 
 
#endif 
 


   02111-1307 USA.  */ 
 
#ifndef	_SYS_SOCKET_H 
#define	_SYS_SOCKET_H	1 
 
 
__BEGIN_DECLS 
 


   02111-1307 USA.  */ 
 
#ifndef _SYS_UIO_H 
 
 
 
__BEGIN_DECLS 
 


   __THROW.  */ 
extern ssize_t readv (int __fd, __const struct iovec *__iovec, int __count); 
 


   __THROW.  */ 
extern ssize_t writev (int __fd, __const struct iovec *__iovec, int __count); 
 
__END_DECLS 
 
#endif 
 
#define	__need_size_t 
 
 


   `struct msghdr', and `struct linger' types.  */ 
 
#ifdef __USE_BSD 


   format in the grotty old 4.3 `talk' protocol.  */ 
struct osockaddr 
  { 
    unsigned short int sa_family; 
    unsigned char sa_data[14]; 
  }; 
#endif 
 


   `shutdown'.  */ 
enum 
{ 
  SHUT_RD = 0,		

  SHUT_WR,		/* No more transmissions.  */ 
  SHUT_RDWR		

   old-style declaration, too.  */ 
#if defined __cplusplus || !__GNUC_PREREQ (2, 7) || !defined __USE_GNU 
# define __SOCKADDR_ARG		struct sockaddr *__restrict 
# define __CONST_SOCKADDR_ARG	__const struct sockaddr * 
#else 


   These are all the ones I found on NetBSD and Linux.  */ 
# define __SOCKADDR_ALLTYPES \ 
  __SOCKADDR_ONETYPE (sockaddr) \ 
  __SOCKADDR_ONETYPE (sockaddr_at) \ 
  __SOCKADDR_ONETYPE (sockaddr_ax25) \ 
  __SOCKADDR_ONETYPE (sockaddr_dl) \ 
  __SOCKADDR_ONETYPE (sockaddr_eon) \ 
  __SOCKADDR_ONETYPE (sockaddr_in) \ 
  __SOCKADDR_ONETYPE (sockaddr_in6) \ 
  __SOCKADDR_ONETYPE (sockaddr_inarp) \ 
  __SOCKADDR_ONETYPE (sockaddr_ipx) \ 
  __SOCKADDR_ONETYPE (sockaddr_iso) \ 
  __SOCKADDR_ONETYPE (sockaddr_ns) \ 
  __SOCKADDR_ONETYPE (sockaddr_un) \ 
  __SOCKADDR_ONETYPE (sockaddr_x25) 
 
# define __SOCKADDR_ONETYPE(type) struct type *__restrict __##type##__; 
typedef union { __SOCKADDR_ALLTYPES 
	      } __SOCKADDR_ARG __attribute__ ((__transparent_union__)); 
# undef __SOCKADDR_ONETYPE 
# define __SOCKADDR_ONETYPE(type) __const struct type *__restrict __##type##__; 
typedef union { __SOCKADDR_ALLTYPES 
	      } __CONST_SOCKADDR_ARG __attribute__ ((__transparent_union__)); 
# undef __SOCKADDR_ONETYPE 
#endif 
 
 


   Returns a file descriptor for the new socket, or -1 for errors.  */ 
extern int socket (int __domain, int __type, int __protocol) __THROW; 
 


   one will be chosen automatically.  Returns 0 on success, -1 for errors.  */ 
extern int socketpair (int __domain, int __type, int __protocol, 
		       int __fds[2]) __THROW; 
 


/* Put the local address of FD into *ADDR and its length in *LEN.  */ 
extern int getsockname (int __fd, __SOCKADDR_ARG __addr, 
			socklen_t *__restrict __len) __THROW; 
 


   __THROW.  */ 
extern int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len); 
 


   (which is *LEN bytes long), and its actual length into *LEN.  */ 
extern int getpeername (int __fd, __SOCKADDR_ARG __addr, 
			socklen_t *__restrict __len) __THROW; 
 
 


   __THROW.  */ 
extern ssize_t send (int __fd, __const void *__buf, size_t __n, int __flags); 
 


   __THROW.  */ 
extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags); 
 


   __THROW.  */ 
extern ssize_t sendto (int __fd, __const void *__buf, size_t __n, 
		       int __flags, __CONST_SOCKADDR_ARG __addr, 
		       socklen_t __addr_len); 
 


   __THROW.  */ 
extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n, 
			 int __flags, __SOCKADDR_ARG __addr, 
			 socklen_t *__restrict __addr_len); 
 
 


   __THROW.  */ 
extern ssize_t sendmsg (int __fd, __const struct msghdr *__message, 
			int __flags); 
 


   __THROW.  */ 
extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags); 
 
 


   actual length.  Returns 0 on success, -1 for errors.  */ 
extern int getsockopt (int __fd, int __level, int __optname, 
		       void *__restrict __optval, 
		       socklen_t *__restrict __optlen) __THROW; 
 


   Returns 0 on success, -1 for errors.  */ 
extern int setsockopt (int __fd, int __level, int __optname, 
		       __const void *__optval, socklen_t __optlen) __THROW; 
 
 


   Returns 0 on success, -1 for errors.  */ 
extern int listen (int __fd, int __n) __THROW; 
 


   __THROW.  */ 
extern int accept (int __fd, __SOCKADDR_ARG __addr, 
		   socklen_t *__restrict __addr_len); 
 


   Returns 0 on success, -1 for errors.  */ 
extern int shutdown (int __fd, int __how) __THROW; 
 
 
#ifdef __USE_XOPEN2K 


   or -1 for errors (setting errno).  */ 
extern int isfdtype (int __fd, int __fdtype) __THROW; 
#endif 
 
 


#endif /* sys/socket.h */ 
 
 
 
__BEGIN_DECLS 
 


    IPPROTO_IP = 0,	   /* Dummy protocol for TCP.  */ 
    IPPROTO_HOPOPTS = 0,   

    IPPROTO_ICMP = 1,	   /* Internet Control Message Protocol.  */ 
    IPPROTO_IGMP = 2,	   

    IPPROTO_IPIP = 4,	   /* IPIP tunnels (older KA9Q tunnels use 94).  */ 
    IPPROTO_TCP = 6,	   

    IPPROTO_EGP = 8,	   /* Exterior Gateway Protocol.  */ 
    IPPROTO_PUP = 12,	   

    IPPROTO_UDP = 17,	   /* User Datagram Protocol.  */ 
    IPPROTO_IDP = 22,	   

    IPPROTO_TP = 29,	   /* SO Transport Protocol Class 4.  */ 
    IPPROTO_IPV6 = 41,     

    IPPROTO_ROUTING = 43,  /* IPv6 routing header.  */ 
    IPPROTO_FRAGMENT = 44, 

    IPPROTO_RSVP = 46,	   /* Reservation Protocol.  */ 
    IPPROTO_GRE = 47,	   

    IPPROTO_ESP = 50,      /* encapsulating security payload.  */ 
    IPPROTO_AH = 51,       

    IPPROTO_ICMPV6 = 58,   /* ICMPv6.  */ 
    IPPROTO_NONE = 59,     

    IPPROTO_DSTOPTS = 60,  /* IPv6 destination options.  */ 
    IPPROTO_MTP = 92,	   

    IPPROTO_ENCAP = 98,	   /* Encapsulation Header.  */ 
    IPPROTO_PIM = 103,	   

    IPPROTO_COMP = 108,	   /* Compression Header Protocol.  */ 
    IPPROTO_SCTP = 132,	   

    IPPROTO_RAW = 255,	   /* Raw IP packets.  */ 
    IPPROTO_MAX 
  }; 
 
 


/* Standard well-known ports.  */ 
enum 
  { 
    IPPORT_ECHO = 7,		

    IPPORT_DISCARD = 9,		/* Discard transmissions service.  */ 
    IPPORT_SYSTAT = 11,		

    IPPORT_DAYTIME = 13,	/* Time of day service.  */ 
    IPPORT_NETSTAT = 15,	

    IPPORT_FTP = 21,		/* File Transfer Protocol.  */ 
    IPPORT_TELNET = 23,		

    IPPORT_SMTP = 25,		/* Simple Mail Transfer Protocol.  */ 
    IPPORT_TIMESERVER = 37,	

    IPPORT_NAMESERVER = 42,	/* Domain Name Service.  */ 
    IPPORT_WHOIS = 43,		

    IPPORT_TFTP = 69,		/* Trivial File Transfer Protocol.  */ 
    IPPORT_RJE = 77, 
    IPPORT_FINGER = 79,		

    IPPORT_SUPDUP = 95,		/* SUPDUP protocol.  */ 
 
 
    IPPORT_EXECSERVER = 512,	

    IPPORT_LOGINSERVER = 513,	/* rlogind service.  */ 
    IPPORT_CMDSERVER = 514, 
    IPPORT_EFSSERVER = 520, 
 
    

    /* Ports less than this value are reserved for privileged processes.  */ 
    IPPORT_RESERVED = 1024, 
 
    

/* Internet address.  */ 
typedef uint32_t in_addr_t; 
struct in_addr 
  { 
    in_addr_t s_addr; 
  }; 
 
 


   the subnet mask, not these masks.  */ 
 
#define	IN_CLASSA(a)		((((in_addr_t)(a)) & 0x80000000) == 0) 
#define	IN_CLASSA_NET		0xff000000 
#define	IN_CLASSA_NSHIFT	24 
#define	IN_CLASSA_HOST		(0xffffffff & ~IN_CLASSA_NET) 
#define	IN_CLASSA_MAX		128 
 
#define	IN_CLASSB(a)		((((in_addr_t)(a)) & 0xc0000000) == 0x80000000) 
#define	IN_CLASSB_NET		0xffff0000 
#define	IN_CLASSB_NSHIFT	16 
#define	IN_CLASSB_HOST		(0xffffffff & ~IN_CLASSB_NET) 
#define	IN_CLASSB_MAX		65536 
 
#define	IN_CLASSC(a)		((((in_addr_t)(a)) & 0xe0000000) == 0xc0000000) 
#define	IN_CLASSC_NET		0xffffff00 
#define	IN_CLASSC_NSHIFT	8 
#define	IN_CLASSC_HOST		(0xffffffff & ~IN_CLASSC_NET) 
 
#define	IN_CLASSD(a)		((((in_addr_t)(a)) & 0xf0000000) == 0xe0000000) 
#define	IN_MULTICAST(a)		IN_CLASSD(a) 
 
#define	IN_EXPERIMENTAL(a)	((((in_addr_t)(a)) & 0xe0000000) == 0xe0000000) 
#define	IN_BADCLASS(a)		((((in_addr_t)(a)) & 0xf0000000) == 0xf0000000) 
 


/* Address to send to all hosts.  */ 
#define	INADDR_BROADCAST	((in_addr_t) 0xffffffff) 


/* Network number for local host loopback.  */ 
#define	IN_LOOPBACKNET		127 


# define INADDR_LOOPBACK	((in_addr_t) 0x7f000001) /* Inet 127.0.0.1.  */ 
#endif 
 


#define INADDR_ALLHOSTS_GROUP	((in_addr_t) 0xe0000001) 

#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff) 

/* IPv6 address */ 
struct in6_addr 
  { 
    union 
      { 
	uint8_t	u6_addr8[16]; 
	uint16_t u6_addr16[8]; 
	uint32_t u6_addr32[4]; 
      } in6_u; 
  }; 
 
extern const struct in6_addr in6addr_any;        

extern const struct in6_addr in6addr_loopback;   /* ::1 */ 
 
 


/* Structure describing an Internet socket address.  */ 
struct sockaddr_in 
  { 
    __SOCKADDR_COMMON (sin_); 
    in_port_t sin_port;			

    struct in_addr sin_addr;		/* Internet address.  */ 
 
    

/* Ditto, for IPv6.  */ 
struct sockaddr_in6 
  { 
    __SOCKADDR_COMMON (sin6_); 
    in_port_t sin6_port;	

    uint32_t sin6_flowinfo;	/* IPv6 flow information */ 
    struct in6_addr sin6_addr;	

    uint32_t sin6_scope_id;	/* IPv6 scope-id */ 
  }; 
 
 


    /* IP multicast address of group.  */ 
    struct in_addr imr_multiaddr; 
 
    

    /* IP multicast address of group.  */ 
    struct in_addr imr_multiaddr; 
 
    

    /* IP address of interface.  */ 
    struct in_addr imr_sourceaddr; 
  }; 
 


    /* IPv6 multicast address of group */ 
    struct in6_addr ipv6mr_multiaddr; 
 
    

/* Multicast group request.  */ 
struct group_req 
  { 
    

    /* Group address.  */ 
    struct sockaddr_storage gr_group; 
  }; 
 
struct group_source_req 
  { 
    

    /* Group address.  */ 
    struct sockaddr_storage gsr_group; 
 
    

/* Full-state filter operations.  */ 
struct ip_msfilter 
  { 
    

    /* Local IP address of interface.  */ 
    struct in_addr imsf_interface; 
 
    

    /* Number of source addresses.  */ 
    uint32_t imsf_numsrc; 
    

    /* Interface index.  */ 
    uint32_t gf_interface; 
 
    

    /* Filter mode.  */ 
    uint32_t gf_fmode; 
 
    

    /* Source addresses.  */ 
    struct sockaddr_storage gf_slist[1]; 
}; 
 
				   - sizeof (struct sockaddr_storage)	      \ 
				   + ((numsrc)				      \ 
				      * sizeof (struct sockaddr_storage))) 
 
 


   may have different representations but the values are always the same.  */ 
 
extern uint32_t ntohl (uint32_t __netlong) __THROW __attribute__ ((__const__)); 
extern uint16_t ntohs (uint16_t __netshort) 
     __THROW __attribute__ ((__const__)); 
extern uint32_t htonl (uint32_t __hostlong) 
     __THROW __attribute__ ((__const__)); 
extern uint16_t htons (uint16_t __hostshort) 
     __THROW __attribute__ ((__const__)); 
 


   02111-1307 USA.  */ 
 
#ifndef	_ENDIAN_H 
#define	_ENDIAN_H	1 
 
 


   and proceeding to the byte with the highest address at the right.  */ 
 
#define	__LITTLE_ENDIAN	1234 
#define	__BIG_ENDIAN	4321 
#define	__PDP_ENDIAN	3412 
 


   values.  */ 
#ifndef __FLOAT_WORD_ORDER 
# define __FLOAT_WORD_ORDER __BYTE_ORDER 
#endif 
 
#ifdef	__USE_BSD 
# define LITTLE_ENDIAN	__LITTLE_ENDIAN 
# define BIG_ENDIAN	__BIG_ENDIAN 
# define PDP_ENDIAN	__PDP_ENDIAN 
# define BYTE_ORDER	__BYTE_ORDER 
#endif 
 
#if __BYTE_ORDER == __LITTLE_ENDIAN 
# define __LONG_LONG_PAIR(HI, LO) LO, HI 
#elif __BYTE_ORDER == __BIG_ENDIAN 
# define __LONG_LONG_PAIR(HI, LO) HI, LO 
#endif 
 
#endif	
 
 


   often can be inlined.  */ 
# if __BYTE_ORDER == __BIG_ENDIAN 


   so these functions are all just identity.  */ 
# define ntohl(x)	(x) 
# define ntohs(x)	(x) 
# define htonl(x)	(x) 
# define htons(x)	(x) 
# else 
#  if __BYTE_ORDER == __LITTLE_ENDIAN 
#   define ntohl(x)	__bswap_32 (x) 
#   define ntohs(x)	__bswap_16 (x) 
#   define htonl(x)	__bswap_32 (x) 
#   define htons(x)	__bswap_16 (x) 
#  endif 
# endif 
#endif 
 
	(((__const uint32_t *) (a))[0] == 0				      \ 
	 && ((__const uint32_t *) (a))[1] == 0				      \ 
	 && ((__const uint32_t *) (a))[2] == 0				      \ 
	 && ((__const uint32_t *) (a))[3] == 0) 
 
	(((__const uint32_t *) (a))[0] == 0				      \ 
	 && ((__const uint32_t *) (a))[1] == 0				      \ 
	 && ((__const uint32_t *) (a))[2] == 0				      \ 
	 && ((__const uint32_t *) (a))[3] == htonl (1)) 
 
 
	((((__const uint32_t *) (a))[0] & htonl (0xffc00000))		      \ 
	 == htonl (0xfe800000)) 
 
	((((__const uint32_t *) (a))[0] & htonl (0xffc00000))		      \ 
	 == htonl (0xfec00000)) 
 
	((((__const uint32_t *) (a))[0] == 0)				      \ 
	 && (((__const uint32_t *) (a))[1] == 0)			      \ 
	 && (((__const uint32_t *) (a))[2] == htonl (0xffff))) 
 
	((((__const uint32_t *) (a))[0] == 0)				      \ 
	 && (((__const uint32_t *) (a))[1] == 0)			      \ 
	 && (((__const uint32_t *) (a))[2] == 0)			      \ 
	 && (ntohl (((__const uint32_t *) (a))[3]) > 1)) 
 
	((((__const uint32_t *) (a))[0] == ((__const uint32_t *) (b))[0])     \ 
	 && (((__const uint32_t *) (a))[1] == ((__const uint32_t *) (b))[1])  \ 
	 && (((__const uint32_t *) (a))[2] == ((__const uint32_t *) (b))[2])  \ 
	 && (((__const uint32_t *) (a))[3] == ((__const uint32_t *) (b))[3])) 
 


/* The IPv6 version of this function.  */ 
extern int bindresvport6 (int __sockfd, struct sockaddr_in6 *__sock_in) 
     __THROW; 
 
 
	(IN6_IS_ADDR_MULTICAST(a)					      \ 
	 && ((((__const uint8_t *) (a))[1] & 0xf) == 0x1)) 
 
	(IN6_IS_ADDR_MULTICAST(a)					      \ 
	 && ((((__const uint8_t *) (a))[1] & 0xf) == 0x2)) 
 
	(IN6_IS_ADDR_MULTICAST(a)					      \ 
	 && ((((__const uint8_t *) (a))[1] & 0xf) == 0x5)) 
 
	(IN6_IS_ADDR_MULTICAST(a)					      \ 
	 && ((((__const uint8_t *) (a))[1] & 0xf) == 0x8)) 
 
	(IN6_IS_ADDR_MULTICAST(a)					      \ 
	 && ((((__const uint8_t *) (a))[1] & 0xf) == 0xe)) 
 


    struct in6_addr ipi6_addr;	/* src/dst IPv6 address */ 
    unsigned int ipi6_ifindex;	

/* IPv6 MTU information.  */ 
struct ip6_mtuinfo 
  { 
    struct sockaddr_in6 ip6m_addr; 

    uint32_t ip6m_mtu;		   /* path MTU in host byte order */ 
  }; 
 
 
#ifdef __USE_GNU 


/* Hop-by-Hop and Destination Options Processing (RFC 3542).  */ 
extern int inet6_opt_init (void *__extbuf, socklen_t __extlen) __THROW; 
extern int inet6_opt_append (void *__extbuf, socklen_t __extlen, int __offset, 
			     uint8_t __type, socklen_t __len, uint8_t __align, 
			     void **__databufp) __THROW; 
extern int inet6_opt_finish (void *__extbuf, socklen_t __extlen, int __offset) 
     __THROW; 
extern int inet6_opt_set_val (void *__databuf, int __offset, void *__val, 
			      socklen_t __vallen) __THROW; 
extern int inet6_opt_next (void *__extbuf, socklen_t __extlen, int __offset, 
			   uint8_t *__typep, socklen_t *__lenp, 
			   void **__databufp) __THROW; 
extern int inet6_opt_find (void *__extbuf, socklen_t __extlen, int __offset, 
			   uint8_t __type, socklen_t *__lenp, 
			   void **__databufp) __THROW; 
extern int inet6_opt_get_val (void *__databuf, int __offset, void *__val, 
			      socklen_t __vallen) __THROW; 
 
 


/* Multicast source filter support.  */ 
 


/* Set IPv4 source filter.  */ 
extern int setipv4sourcefilter (int __s, struct in_addr __interface_addr, 
				struct in_addr __group, uint32_t __fmode, 
				uint32_t __numsrc, 
				__const struct in_addr *__slist) 
     __THROW; 
 
 


/* Set source filter.  */ 
extern int setsourcefilter (int __s, uint32_t __interface_addr, 
			    __const struct sockaddr *__group, 
			    socklen_t __grouplen, uint32_t __fmode, 
			    uint32_t __numsrc, 
			    __const struct sockaddr_storage *__slist) __THROW; 
#endif	

#endif	/* netinet/in.h */ 
 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef	_STDLIB_H 
 
 


/* XPG requires a few symbols from <sys/wait.h> being defined.  */ 
# include <bits/waitflags.h> 
# include <bits/waitstatus.h> 
 
# ifdef __USE_BSD 
 


   as well as POSIX.1 use of `int' for the status word.  */ 
 
#  if defined __GNUC__ && !defined __cplusplus 
#   define __WAIT_INT(status)						      \ 
  (__extension__ ({ union { __typeof(status) __in; int __i; } __u;	      \ 
		    __u.__in = (status); __u.__i; })) 
#  else 
#   define __WAIT_INT(status)	(*(int *) &(status)) 
#  endif 
 


   the actual function definitions.  */ 
 
#  if !defined __GNUC__ || __GNUC__ < 2 || defined __cplusplus 
#   define __WAIT_STATUS	void * 
#   define __WAIT_STATUS_DEFN	void * 
#  else 


# else /* Don't use BSD.  */ 
 
#  define __WAIT_INT(status)	(status) 
#  define __WAIT_STATUS		int * 
#  define __WAIT_STATUS_DEFN	int * 
 
# endif 

/* Define the macros <sys/wait.h> also would define this way.  */ 
# define WEXITSTATUS(status)	__WEXITSTATUS(__WAIT_INT(status)) 
# define WTERMSIG(status)	__WTERMSIG(__WAIT_INT(status)) 
# define WSTOPSIG(status)	__WSTOPSIG(__WAIT_INT(status)) 
# define WIFEXITED(status)	__WIFEXITED(__WAIT_INT(status)) 
# define WIFSIGNALED(status)	__WIFSIGNALED(__WAIT_INT(status)) 
# define WIFSTOPPED(status)	__WIFSTOPPED(__WAIT_INT(status)) 
# ifdef __WIFCONTINUED 
#  define WIFCONTINUED(status)	__WIFCONTINUED(__WAIT_INT(status)) 
# endif 
#endif	

/* Returned by `div'.  */ 
typedef struct 
  { 
    int quot;			

    int rem;			/* Remainder.  */ 
  } div_t; 
 


    long int quot;		/* Quotient.  */ 
    long int rem;		

/* Returned by `lldiv'.  */ 
__extension__ typedef struct 
  { 
    long long int quot;		

    long long int rem;		/* Remainder.  */ 
  } lldiv_t; 
# define __lldiv_t_defined	1 
__END_NAMESPACE_C99 
#endif 
 
 


   Changes from this to the outside world should be done in `_exit'.  */ 
#define	EXIT_FAILURE	1	

#define	EXIT_SUCCESS	0	/* Successful exit status.  */ 
 
 


/* Convert a string to a floating-point number.  */ 
extern double atof (__const char *__nptr) 
     __THROW __attribute_pure__ __nonnull ((1)) __wur; 


/* Convert a string to a long integer.  */ 
extern long int atol (__const char *__nptr) 
     __THROW __attribute_pure__ __nonnull ((1)) __wur; 
__END_NAMESPACE_STD 
 
#if defined __USE_ISOC99 || (defined __GLIBC_HAVE_LONG_LONG && defined __USE_MISC) 
__BEGIN_NAMESPACE_C99 


/* Convert a string to a floating-point number.  */ 
extern double strtod (__const char *__restrict __nptr, 
		      char **__restrict __endptr) 
     __THROW __nonnull ((1)) __wur; 
__END_NAMESPACE_STD 
 
#ifdef	__USE_ISOC99 
__BEGIN_NAMESPACE_C99 


/* Convert a string to a long integer.  */ 
extern long int strtol (__const char *__restrict __nptr, 
			char **__restrict __endptr, int __base) 
     __THROW __nonnull ((1)) __wur; 


/* Convert a string to a quadword integer.  */ 
__extension__ 
extern long long int strtoq (__const char *__restrict __nptr, 
			     char **__restrict __endptr, int __base) 
     __THROW __nonnull ((1)) __wur; 


#endif /* GCC and use BSD.  */ 
 
#if defined __USE_ISOC99 || (defined __GLIBC_HAVE_LONG_LONG && defined __USE_MISC) 
__BEGIN_NAMESPACE_C99 


/* Convert a string to an unsigned quadword integer.  */ 
__extension__ 
extern unsigned long long int strtoull (__const char *__restrict __nptr, 
					char **__restrict __endptr, int __base) 
     __THROW __nonnull ((1)) __wur; 
__END_NAMESPACE_C99 
#endif 

   This is a proof-of-concept implementation.  */ 
 


   (almost) opaque type for the user level programs.  */ 
# include <xlocale.h> 
 


   use as an additional parameter.  */ 
extern long int strtol_l (__const char *__restrict __nptr, 
			  char **__restrict __endptr, int __base, 
			  __locale_t __loc) __THROW __nonnull ((1, 4)) __wur; 
 
extern unsigned long int strtoul_l (__const char *__restrict __nptr, 
				    char **__restrict __endptr, 
				    int __base, __locale_t __loc) 
     __THROW __nonnull ((1, 4)) __wur; 
 
__extension__ 
extern long long int strtoll_l (__const char *__restrict __nptr, 
				char **__restrict __endptr, int __base, 
				__locale_t __loc) 
     __THROW __nonnull ((1, 4)) __wur; 
 
__extension__ 
extern unsigned long long int strtoull_l (__const char *__restrict __nptr, 
					  char **__restrict __endptr, 
					  int __base, __locale_t __loc) 
     __THROW __nonnull ((1, 4)) __wur; 
 
extern double strtod_l (__const char *__restrict __nptr, 
			char **__restrict __endptr, __locale_t __loc) 
     __THROW __nonnull ((1, 3)) __wur; 
 
extern float strtof_l (__const char *__restrict __nptr, 
		       char **__restrict __endptr, __locale_t __loc) 
     __THROW __nonnull ((1, 3)) __wur; 
 
extern long double strtold_l (__const char *__restrict __nptr, 
			      char **__restrict __endptr, 
			      __locale_t __loc) 
     __THROW __nonnull ((1, 3)) __wur; 
#endif 

   saying whether or not to parse locale-dependent number grouping.  */ 
 
extern double __strtod_internal (__const char *__restrict __nptr, 
				 char **__restrict __endptr, int __group) 
     __THROW __nonnull ((1)) __wur; 
extern float __strtof_internal (__const char *__restrict __nptr, 
				char **__restrict __endptr, int __group) 
     __THROW __nonnull ((1)) __wur; 
extern long double __strtold_internal (__const char *__restrict __nptr, 
				       char **__restrict __endptr, 
				       int __group) 
     __THROW __nonnull ((1)) __wur; 
#ifndef __strtol_internal_defined 
extern long int __strtol_internal (__const char *__restrict __nptr, 
				   char **__restrict __endptr, 
				   int __base, int __group) 
     __THROW __nonnull ((1)) __wur; 
# define __strtol_internal_defined	1 
#endif 
#ifndef __strtoul_internal_defined 
extern unsigned long int __strtoul_internal (__const char *__restrict __nptr, 
					     char **__restrict __endptr, 
					     int __base, int __group) 
     __THROW __nonnull ((1)) __wur; 
# define __strtoul_internal_defined	1 
#endif 
#if defined __GNUC__ || defined __USE_ISOC99 
# ifndef __strtoll_internal_defined 
__extension__ 
extern long long int __strtoll_internal (__const char *__restrict __nptr, 
					 char **__restrict __endptr, 
					 int __base, int __group) 
     __THROW __nonnull ((1)) __wur; 
#  define __strtoll_internal_defined	1 
# endif 
# ifndef __strtoull_internal_defined 
__extension__ 
extern unsigned long long int __strtoull_internal (__const char * 
						   __restrict __nptr, 
						   char **__restrict __endptr, 
						   int __base, int __group) 
     __THROW __nonnull ((1)) __wur; 
#  define __strtoull_internal_defined	1 
# endif 
#endif 

/* Define inline functions which call the internal entry points.  */ 
 
__BEGIN_NAMESPACE_STD 
extern __inline double 
__NTH (strtod (__const char *__restrict __nptr, char **__restrict __endptr)) 
{ 
  return __strtod_internal (__nptr, __endptr, 0); 
} 
extern __inline long int 
__NTH (strtol (__const char *__restrict __nptr, char **__restrict __endptr, 
	       int __base)) 
{ 
  return __strtol_internal (__nptr, __endptr, __base, 0); 
} 
extern __inline unsigned long int 
__NTH (strtoul (__const char *__restrict __nptr, char **__restrict __endptr, 
		int __base)) 
{ 
  return __strtoul_internal (__nptr, __endptr, __base, 0); 
} 
__END_NAMESPACE_STD 
 
# ifdef __USE_ISOC99 
__BEGIN_NAMESPACE_C99 
extern __inline float 
__NTH (strtof (__const char *__restrict __nptr, char **__restrict __endptr)) 
{ 
  return __strtof_internal (__nptr, __endptr, 0); 
} 
#  ifndef __LDBL_COMPAT 
extern __inline long double 
__NTH (strtold (__const char *__restrict __nptr, char **__restrict __endptr)) 
{ 
  return __strtold_internal (__nptr, __endptr, 0); 
} 
#  endif 
__END_NAMESPACE_C99 
# endif 
 
# ifdef __USE_BSD 
__extension__ extern __inline long long int 
__NTH (strtoq (__const char *__restrict __nptr, char **__restrict __endptr, 
	       int __base)) 
{ 
  return __strtoll_internal (__nptr, __endptr, __base, 0); 
} 
__extension__ extern __inline unsigned long long int 
__NTH (strtouq (__const char *__restrict __nptr, char **__restrict __endptr, 
		int __base)) 
{ 
  return __strtoull_internal (__nptr, __endptr, __base, 0); 
} 
# endif 
 
# if defined __USE_MISC || defined __USE_ISOC99 
__BEGIN_NAMESPACE_C99 
__extension__ extern __inline long long int 
__NTH (strtoll (__const char *__restrict __nptr, char **__restrict __endptr, 
		int __base)) 
{ 
  return __strtoll_internal (__nptr, __endptr, __base, 0); 
} 
__extension__ extern __inline unsigned long long int 
__NTH (strtoull (__const char * __restrict __nptr, char **__restrict __endptr, 
		 int __base)) 
{ 
  return __strtoull_internal (__nptr, __endptr, __base, 0); 
} 
__END_NAMESPACE_C99 
# endif 
 
__BEGIN_NAMESPACE_STD 
extern __inline double 
__NTH (atof (__const char *__nptr)) 
{ 
  return strtod (__nptr, (char **) NULL); 
} 
extern __inline int 
__NTH (atoi (__const char *__nptr)) 
{ 
  return (int) strtol (__nptr, (char **) NULL, 10); 
} 
extern __inline long int 
__NTH (atol (__const char *__nptr)) 
{ 
  return strtol (__nptr, (char **) NULL, 10); 
} 
__END_NAMESPACE_STD 
 
# if defined __USE_MISC || defined __USE_ISOC99 
__BEGIN_NAMESPACE_C99 
__extension__ extern __inline long long int 
__NTH (atoll (__const char *__nptr)) 
{ 
  return strtoll (__nptr, (char **) NULL, 10); 
} 
__END_NAMESPACE_C99 
# endif 
#endif 

   next call.  */ 
extern char *l64a (long int __n) __THROW __wur; 
 


#endif	/* Use SVID || extended X/Open.  */ 
 
#if defined __USE_SVID || defined __USE_XOPEN_EXTENDED || defined __USE_BSD 
# include <sys/types.h>	

   We provide both interfaces to the same random number generator.  */ 


/* Seed the random number generator with the given number.  */ 
extern void srandom (unsigned int __seed) __THROW; 
 


   cause an error and values greater than 256 will be rounded down.  */ 
extern char *initstate (unsigned int __seed, char *__statebuf, 
			size_t __statelen) __THROW __nonnull ((2)); 
 


   which should have been previously initialized by `initstate'.  */ 
extern char *setstate (char *__statebuf) __THROW __nonnull ((1)); 
 
 
# ifdef __USE_MISC 


   state, rather than global state variables.  */ 
 
struct random_data 
  { 
    int32_t *fptr;		

    int32_t *rptr;		/* Rear pointer.  */ 
    int32_t *state;		

    int rand_type;		/* Type of random number generator.  */ 
    int rand_deg;		

    int rand_sep;		/* Distance between front and rear.  */ 
    int32_t *end_ptr;		

# endif	/* Use misc.  */ 
#endif	

/* Return a random integer between 0 and RAND_MAX inclusive.  */ 
extern int rand (void) __THROW; 


/* Reentrant interface according to POSIX.1.  */ 
extern int rand_r (unsigned int *__seed) __THROW; 
#endif 
 
 
#if defined __USE_SVID || defined __USE_XOPEN 


/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */ 
extern double drand48 (void) __THROW; 
extern double erand48 (unsigned short int __xsubi[3]) __THROW __nonnull ((1)); 
 


/* Return signed, long integers in [-2^31,2^31).  */ 
extern long int mrand48 (void) __THROW; 
extern long int jrand48 (unsigned short int __xsubi[3]) 
     __THROW __nonnull ((1)); 
 


   have to allocate objects of this type.  */ 
struct drand48_data 
  { 
    unsigned short int __x[3];	

    unsigned short int __old_x[3]; /* Old state.  */ 
    unsigned short int __c;	

    unsigned short int __init;	/* Flag for initializing.  */ 
    unsigned long long int __a;	

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */ 
extern int drand48_r (struct drand48_data *__restrict __buffer, 
		      double *__restrict __result) __THROW __nonnull ((1, 2)); 
extern int erand48_r (unsigned short int __xsubi[3], 
		      struct drand48_data *__restrict __buffer, 
		      double *__restrict __result) __THROW __nonnull ((1, 2)); 
 


/* Return signed, long integers in [-2^31,2^31).  */ 
extern int mrand48_r (struct drand48_data *__restrict __buffer, 
		      long int *__restrict __result) 
     __THROW __nonnull ((1, 2)); 
extern int jrand48_r (unsigned short int __xsubi[3], 
		      struct drand48_data *__restrict __buffer, 
		      long int *__restrict __result) 
     __THROW __nonnull ((1, 2)); 
 


# endif	/* Use misc.  */ 
#endif	

#endif /* don't just need malloc and calloc */ 
 
#ifndef __malloc_and_calloc_defined 
# define __malloc_and_calloc_defined 
__BEGIN_NAMESPACE_STD 


/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */ 
extern void *calloc (size_t __nmemb, size_t __size) 
     __THROW __attribute_malloc__ __wur; 
__END_NAMESPACE_STD 
#endif 
 
#ifndef __need_malloc_and_calloc 
__BEGIN_NAMESPACE_STD 


   in PTR, making the new block SIZE bytes long.  */ 
extern void *realloc (void *__ptr, size_t __size) 
     __THROW __attribute_malloc__ __attribute_warn_unused_result__; 


/* Free a block.  An alias for `free'.	(Sun Unices).  */ 
extern void cfree (void *__ptr) __THROW; 
#endif 

#endif /* Use GNU, BSD, or misc.  */ 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


/* Allocate memory of SIZE bytes with an alignment of ALIGNMENT.  */ 
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size) 
     __THROW __nonnull ((1)) __wur; 
#endif 
 
__BEGIN_NAMESPACE_STD 


/* Register a function to be called when `exit' is called.  */ 
extern int atexit (void (*__func) (void)) __THROW __nonnull ((1)); 
__END_NAMESPACE_STD 
 
#ifdef	__USE_MISC 


   given to `exit' and the given argument.  */ 
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg) 
     __THROW __nonnull ((1)); 
#endif 
 
__BEGIN_NAMESPACE_STD 


   perform stdio cleanup, and terminate program execution with STATUS.  */ 
extern void exit (int __status) __THROW __attribute__ ((__noreturn__)); 
__END_NAMESPACE_STD 
 
#ifdef __USE_ISOC99 
__BEGIN_NAMESPACE_C99 


   functions registered with `atexit' or `on_exit'.  */ 
extern void _Exit (int __status) __THROW __attribute__ ((__noreturn__)); 
__END_NAMESPACE_C99 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   programs is running with SUID or SGID enabled.  */ 
extern char *__secure_getenv (__const char *__name) 
     __THROW __nonnull ((1)) __wur; 
 
#if defined __USE_SVID || defined __USE_XOPEN 


   If there is no `=', remove NAME from the environment.  */ 
extern int putenv (char *__string) __THROW __nonnull ((1)); 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN2K 


   If REPLACE is nonzero, overwrite an existing value.  */ 
extern int setenv (__const char *__name, __const char *__value, int __replace) 
     __THROW __nonnull ((2)); 
 


   for Fortran 77) requires this function.  */ 
extern int clearenv (void) __THROW; 
#endif 
 
 
#if defined __USE_MISC || defined __USE_XOPEN_EXTENDED 


   Returns TEMPLATE, or a null pointer if it cannot get a unique file name.  */ 
extern char *mktemp (char *__template) __THROW __nonnull ((1)) __wur; 
 


   marked with __THROW.  */ 
# ifndef __USE_FILE_OFFSET64 
extern int mkstemp (char *__template) __nonnull ((1)) __wur; 
# else 
#  ifdef __REDIRECT 
extern int __REDIRECT (mkstemp, (char *__template), mkstemp64) 
     __nonnull ((1)) __wur; 
#  else 
#   define mkstemp mkstemp64 
#  endif 
# endif 
# ifdef __USE_LARGEFILE64 
extern int mkstemp64 (char *__template) __nonnull ((1)) __wur; 
# endif 
#endif 
 
#ifdef __USE_BSD 


   The directory is created mode 700.  */ 
extern char *mkdtemp (char *__template) __THROW __nonnull ((1)) __wur; 
#endif 
 
 
__BEGIN_NAMESPACE_STD 


   __THROW.  */ 
extern int system (__const char *__command) __wur; 
__END_NAMESPACE_STD 
 
 
#ifdef	__USE_GNU 


   symlink to a nonexistent file.  */ 
extern char *canonicalize_file_name (__const char *__name) 
     __THROW __nonnull ((1)) __wur; 
#endif 
 
#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED 


   returns the name in RESOLVED.  */ 
extern char *realpath (__const char *__restrict __name, 
		       char *__restrict __resolved) __THROW __wur; 
#endif 
 
 


   of SIZE bytes each, using COMPAR to perform the comparisons.  */ 
extern void *bsearch (__const void *__key, __const void *__base, 
		      size_t __nmemb, size_t __size, __compar_fn_t __compar) 
     __nonnull ((1, 2, 5)) __wur; 
 


   using COMPAR to perform the comparisons.  */ 
extern void qsort (void *__base, size_t __nmemb, size_t __size, 
		   __compar_fn_t __compar) __nonnull ((1, 4)); 
 
 


   of the value of NUMER over DENOM. */ 


   valid only until another call to the same function.  */ 
 


   with the sign of the number.  */ 
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt, 
		   int *__restrict __sign) __THROW __nonnull ((3, 4)) __wur; 
 


   the number.  */ 
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt, 
		   int *__restrict __sign) __THROW __nonnull ((3, 4)) __wur; 
 


   be written to BUF.  */ 
extern char *gcvt (double __value, int __ndigit, char *__buf) 
     __THROW __nonnull ((3)) __wur; 
 
 
# ifdef __USE_MISC 


   buffers.  */ 
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt, 
		   int *__restrict __sign, char *__restrict __buf, 
		   size_t __len) __THROW __nonnull ((3, 4, 5)); 
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt, 
		   int *__restrict __sign, char *__restrict __buf, 
		   size_t __len) __THROW __nonnull ((3, 4, 5)); 
 
extern int qecvt_r (long double __value, int __ndigit, 
		    int *__restrict __decpt, int *__restrict __sign, 
		    char *__restrict __buf, size_t __len) 
     __THROW __nonnull ((3, 4, 5)); 
extern int qfcvt_r (long double __value, int __ndigit, 
		    int *__restrict __decpt, int *__restrict __sign, 
		    char *__restrict __buf, size_t __len) 
     __THROW __nonnull ((3, 4, 5)); 
# endif	

#endif	/* use MISC || use X/Open Unix */ 
 
 
__BEGIN_NAMESPACE_STD 


   in S, which is no longer than N.  */ 
extern int mblen (__const char *__s, size_t __n) __THROW __wur; 


   putting its `wchar_t' representation in *PWC.  */ 
extern int mbtowc (wchar_t *__restrict __pwc, 
		   __const char *__restrict __s, size_t __n) __THROW __wur; 


   by WCHAR in S, returning its length.  */ 
extern int wctomb (char *__s, wchar_t __wchar) __THROW __wur; 
 
 


/* Convert a wide char string to multibyte string.  */ 
extern size_t wcstombs (char *__restrict __s, 
			__const wchar_t *__restrict __pwcs, size_t __n) 
     __THROW; 
__END_NAMESPACE_STD 
 
 
#ifdef __USE_SVID 


   negative, and -1 if not matching.  */ 
extern int rpmatch (__const char *__response) __THROW __nonnull ((1)) __wur; 
#endif 
 
 
#ifdef __USE_XOPEN_EXTENDED 


   token or at the terminating NUL character.  */ 
extern int getsubopt (char **__restrict __optionp, 
		      char *__const *__restrict __tokens, 
		      char **__restrict __valuep) 
     __THROW __nonnull ((1, 2, 3)) __wur; 
#endif 
 
 
#ifdef __USE_XOPEN 


/* X/Open pseudo terminal handling.  */ 
 
#ifdef __USE_XOPEN2K 


   perform an operation on the associated slave:  */ 
 


   Call after grantpt().  */ 
extern int unlockpt (int __fd) __THROW; 
 


   The returned storage is good until the next call to this function.  */ 
extern char *ptsname (int __fd) __THROW __wur; 
#endif 
 
#ifdef __USE_GNU 


   Return 0 on success, otherwise an error number.  */ 
extern int ptsname_r (int __fd, char *__buf, size_t __buflen) 
     __THROW __nonnull ((2)); 
 


   three, but may be less than NELEM), or -1 if an error occurred.  */ 
extern int getloadavg (double __loadavg[], int __nelem) 
     __THROW __nonnull ((1)); 
#endif 
 
 


#endif /* don't just need malloc and calloc */ 
#undef __need_malloc_and_calloc 
 
__END_DECLS 
 
#endif 
 
 


 */ 


/* Define if there is no uint32_t in system headers. */ 


 */ 
#if GSSRPC__FAKE_UINT32 
#if (UINT_MAX == 0xffffffffUL) && (INT_MAX == 0x7fffffffL) \ 
	&& (INT_MIN == -INT_MAX-1) 
typedef int		int32_t; 
typedef unsigned int	uint32_t; 
#else 
#if (ULONG_MAX == 0xffffffffUL) && (LONG_MAX == 0x7fffffffL) \ 
	&& (LONG_MIN == -LONG_MAX-1) 
typedef long		int32_t; 
typedef unsigned long	uint32_t; 
#else 
#if (USHRT_MAX == 0xffffffffUL) && (SHRT_MAX == 0x7fffffffL) \ 
	&& (SHRT_MIN == -SHRT_MAX-1) 
typedef short		int32_t; 
typedef unsigned short	uint32_t; 
#else 
#error "Can't fake up uint32_t." 
#endif 
#endif 
#endif 
#endif 

/* Define if we need to fake up some BSD type aliases. */ 
#ifndef GSSRPC__BSD_TYPEALIASES	

/* #undef GSSRPC__BSD_TYPEALIASES */ 
#endif 
#if GSSRPC__BSD_TYPEALIASES 
typedef unsigned char	u_char; 
typedef unsigned short	u_short; 
typedef unsigned int	u_int; 
typedef unsigned long	u_long; 
#endif 
 
typedef uint32_t	rpcprog_t; 
typedef uint32_t	rpcvers_t; 
typedef uint32_t	rpcprot_t; 
typedef uint32_t	rpcproc_t; 
typedef uint32_t	rpcport_t; 
typedef int32_t		rpc_inline_t; 
 


/* XXX namespace */ 
#ifndef 0 
#	define 0 0 
#endif 
 


 */ 
 
#if 0 
#include <netdb.h> 

		    */ 
#endif 
 
#ifndef INADDR_LOOPBACK 
#endif 
#ifndef MAXHOSTNAMELEN 
#endif 
 
GSSRPC__END_DECLS 
 


 */ 
 
#ifndef GSSRPC_RENAME_H 
 


/* auth_gss.c */ 
 
 


/* auth_gssapi.c */ 
 
 


/* auth_unix.h */ 
 
 


/* XXX do we need to rename the struct? */ 
 


/* pmap_prot.h */ 
 
 


/* rpc.h */ 
 
 
#if 0 
#endif 
 


/* svc.h */ 
 
 
 
 
 
 
 
 
 
 


/* svc_auth_gss.c */ 
 
 
 


/* svc_auth_none.c */ 
 
 


#endif /* !defined(GSSRPC_RENAME_H) */ 
 
 
#endif 
 
 
__BEGIN_DECLS 
 
#ifndef _ISbit 


   machine's byte order.  */ 
 
# include <endian.h> 
# if __BYTE_ORDER == __BIG_ENDIAN 
#  define _ISbit(bit)	(1 << (bit)) 
# else 

  _ISupper = _ISbit (0),	/* UPPERCASE.  */ 
  _ISlower = _ISbit (1),	

  _ISalpha = _ISbit (2),	/* Alphabetic.  */ 
  _ISdigit = _ISbit (3),	

  _ISxdigit = _ISbit (4),	/* Hexadecimal numeric.  */ 
  _ISspace = _ISbit (5),	

  _ISprint = _ISbit (6),	/* Printing.  */ 
  _ISgraph = _ISbit (7),	

  _ISblank = _ISbit (8),	/* Blank (usually SPC and TAB).  */ 
  _IScntrl = _ISbit (9),	

  _ISpunct = _ISbit (10),	/* Punctuation.  */ 
  _ISalnum = _ISbit (11)	

#endif /* ! _ISbit  */ 
 


   the arrays are also used for multi-byte character sets.  */ 
extern __const unsigned short int **__ctype_b_loc (void) 
     __attribute__ ((__const)); 
extern __const __int32_t **__ctype_tolower_loc (void) 
     __attribute__ ((__const)); 
extern __const __int32_t **__ctype_toupper_loc (void) 
     __attribute__ ((__const)); 
 
  ((*__ctype_b_loc ())[(int) (c)] & (unsigned short int) type) 
 
#define	__isascii(c)	(((c) & ~0x7f) == 0)	

#define	__toascii(c)	((c) & 0x7f)		/* Mask off high bits.  */ 
 
#define	__exctype(name)	extern int name (int) __THROW 
 
__BEGIN_NAMESPACE_STD 
 


   For the meaning of the characteristic names, see the `enum' above.  */ 
__exctype (isalnum); 
__exctype (isalpha); 
__exctype (iscntrl); 
__exctype (isdigit); 
__exctype (islower); 
__exctype (isgraph); 
__exctype (isprint); 
__exctype (ispunct); 
__exctype (isspace); 
__exctype (isupper); 
__exctype (isxdigit); 
 
 


/* Return the uppercase version of C.  */ 
extern int toupper (int __c) __THROW; 
 
__END_NAMESPACE_STD 
 
 


/* Test C for a set of character classes according to MASK.  */ 
extern int isctype (int __c, int __mask) __THROW; 
#endif 
 
#if defined __USE_SVID || defined __USE_MISC || defined __USE_XOPEN 
 


   (i.e., is no more than 7 bits wide).  */ 
extern int isascii (int __c) __THROW; 
 


   (i.e., the low-order 7 bits of C).  */ 
extern int toascii (int __c) __THROW; 
 


   check the argument for being in the range of a `char'.  */ 
__exctype (_toupper); 
__exctype (_tolower); 
#endif 

/* This code is needed for the optimized mapping functions.  */ 
  (__extension__							      \ 
   ({ int __res;							      \ 
      if (sizeof (c) > 1)						      \ 
	{								      \ 
	  if (__builtin_constant_p (c))					      \ 
	    {								      \ 
	      int __c = (c);						      \ 
	      __res = __c < -128 || __c > 255 ? __c : (a)[__c];		      \ 
	    }								      \ 
	  else								      \ 
	    __res = f args;						      \ 
	}								      \ 
      else								      \ 
	__res = (a)[(int) (c)];						      \ 
      __res; })) 
 
#if !defined 1 && !defined __cplusplus 
# define isalnum(c)	__isctype((c), _ISalnum) 
# define isalpha(c)	__isctype((c), _ISalpha) 
# define iscntrl(c)	__isctype((c), _IScntrl) 
# define isdigit(c)	__isctype((c), _ISdigit) 
# define islower(c)	__isctype((c), _ISlower) 
# define isgraph(c)	__isctype((c), _ISgraph) 
# define isprint(c)	__isctype((c), _ISprint) 
# define ispunct(c)	__isctype((c), _ISpunct) 
# define isspace(c)	__isctype((c), _ISspace) 
# define isupper(c)	__isctype((c), _ISupper) 
# define isxdigit(c)	__isctype((c), _ISxdigit) 
 
# ifdef __USE_ISOC99 
#  define isblank(c)	__isctype((c), _ISblank) 
# endif 
 
# ifdef __USE_EXTERN_INLINES 
extern __inline int 
__NTH (tolower (int __c)) 
{ 
  return __c >= -128 && __c < 256 ? (*__ctype_tolower_loc ())[__c] : __c; 
} 
 
extern __inline int 
__NTH (toupper (int __c)) 
{ 
  return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc ())[__c] : __c; 
} 
# endif 
 
# if __GNUC__ >= 2 && defined __OPTIMIZE__ && !defined __cplusplus 
#  define tolower(c)	__tobody (c, tolower, *__ctype_tolower_loc (), (c)) 
#  define toupper(c)	__tobody (c, toupper, *__ctype_toupper_loc (), (c)) 
# endif 

#endif /* Not __NO_CTYPE.  */ 
 
 
#ifdef __USE_GNU 


   This is a proof-of-concept implementation.  */ 
 


   (almost) opaque type for the user level programs.  */ 
# include <xlocale.h> 
 


   take as an argument a handle for the locale which shall be used.  */ 
#  define __isctype_l(c, type, locale) \ 
  ((locale)->__ctype_b[(int) (c)] & (unsigned short int) type) 
 
# define __exctype_l(name) 						      \ 
  extern int name (int, __locale_t) __THROW 
 


   For the meaning of the characteristic names, see the `enum' above.  */ 
__exctype_l (isalnum_l); 
__exctype_l (isalpha_l); 
__exctype_l (iscntrl_l); 
__exctype_l (isdigit_l); 
__exctype_l (islower_l); 
__exctype_l (isgraph_l); 
__exctype_l (isprint_l); 
__exctype_l (ispunct_l); 
__exctype_l (isspace_l); 
__exctype_l (isupper_l); 
__exctype_l (isxdigit_l); 
 
__exctype_l (isblank_l); 
 
 


/* Return the uppercase version of C.  */ 
extern int __toupper_l (int __c, __locale_t __l) __THROW; 
extern int toupper_l (int __c, __locale_t __l) __THROW; 
 
# if __GNUC__ >= 2 && defined __OPTIMIZE__ && !defined __cplusplus 
#  define __tolower_l(c, locale) \ 
  __tobody (c, __tolower_l, (locale)->__ctype_tolower, (c, locale)) 
#  define __toupper_l(c, locale) \ 
  __tobody (c, __toupper_l, (locale)->__ctype_toupper, (c, locale)) 
#  define tolower_l(c, locale)	__tolower_l ((c), (locale)) 
#  define toupper_l(c, locale)	__toupper_l ((c), (locale)) 
# endif	

# endif /* Not __NO_CTYPE.  */ 
 
#endif 

#endif /* ctype.h  */ 
 
 
namespace std { 
  using ::isalnum; 
  using ::isdigit; 
  using ::isprint; 
  using ::isupper; 
  using ::tolower; 
  using ::isalpha; 
  using ::isgraph; 
  using ::ispunct; 
  using ::isxdigit; 
  using ::toupper; 
  using ::iscntrl; 
  using ::islower; 
  using ::isspace; 
} 
 
#endif #endif // CCTYPE_HEADER 
 
#include <bits/stringfwd.h> 	// String support -*- C++ -*- 
 
// Copyright (C) 2001, 2002 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 21 Strings library 
// 
 


 */ 
 
#ifndef _STRINGFWD_H 
 
#pragma GCC system_header 
 
 
namespace std 
{ 
  template<typename _Alloc> 
    class allocator; 
 
  template<class _CharT> 
    struct char_traits; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT>, 
           typename _Alloc = allocator<_CharT> > 
    class basic_string; 
 
  template<> struct char_traits<char>; 
 
  typedef basic_string<char>    string; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> struct char_traits<wchar_t>; 
 
  typedef basic_string<wchar_t> wstring; 
#endif 
} } // namespace std 
 
#endif	#endif	// 1 
 
// Position types -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2003, 2004 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.4.1 - Types 
// ISO C++ 14882: 27.4.3 - Template class fpos 
// 
 


 */ 
 
#ifndef _GLIBCXX_POSTYPES_H 
 
#pragma GCC system_header 
 
#include <cwchar> // This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CWCHAR_HEADER 
 
 
namespace std { 
  using ::mbstate_t; 
  using ::wint_t; 
  using ::size_t; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::btowc; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::getwchar; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::ungetwc; 
#endif 
  using ::wcscpy; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wcsrtombs; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wmemchr; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::fgetwc; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::mbrlen; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::vfwprintf; 
#endif 
#endif 
  using ::wcscspn; 
  using ::wcsspn; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wmemcmp; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::fgetws; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::mbrtowc; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::vswprintf; 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::wcsftime; 
#endif 
  using ::wcsstr; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wmemcpy; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::fputwc; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::mbsinit; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::vwprintf; 
#endif 
#endif 
  using ::wcslen; 
  using ::wcstod; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wmemmove; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::fputws; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::mbsrtowcs; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wcrtomb; 
#endif 
  using ::wcsncat; 
  using ::wcstok; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wmemset; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
#if !(defined(__DECCXX_VER) && __DECCXX_VER <= 60290024) 
  using ::fwide; 
#endif 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::putwc; 
#endif 
  using ::wcscat; 
  using ::wcsncmp; 
  using ::wcstol; 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wprintf; 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::fwprintf; 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::putwchar; 
#endif 
  using ::wcschr; 
  using ::wcsncpy; 
  using ::wcstoul; 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wscanf; 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::fwscanf; 
#endif 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::swprintf; 
#endif 
#endif 
  using ::wcscmp; 
  using ::wcspbrk; 
  using ::wcsxfrm; 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
  using ::getwc; 
#endif 
#if !(defined(__linux) && defined(__DECCXX_VER) && __DECCXX_VER <= 60390005) 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::swscanf; 
#endif 
#endif 
  using ::wcscoll; 
  using ::wcsrchr; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wctob; 
#endif 
} 
 
#endif #endif // CWCHAR_HEADER 
 
 
#ifdef 1 
#include <stdint.h> #endif 
 
namespace std 
{ 
    // The types streamoff, streampos and wstreampos and the class 
    // template fpos<> are described in clauses 21.1.2, 21.1.3, 27.1.2, 
    // 27.2, 27.4.1, 27.4.3 and D.6. Despite all this verbage, the 
    // behaviour of these types is mostly implementation defined or 
    // unspecified. The behaviour in this implementation is as noted 
    // below. 
 
  
  
  */   
#ifdef _GLIBCXX_HAVE_INT64_T 
  typedef int64_t       streamoff; 
#else 
  typedef long long     streamoff; 
#endif 
 
    /// Integral type for I/O operation counts and buffer sizes. 
  typedef ptrdiff_t	streamsize;   typedef ptrdiff_t	streamsize; // Signed integral type 
 
  template<typename _StateT> 
    class fpos; 
 
  

   */ 
  template<typename _StateT> 
    class fpos 
    { 
    private: 
      streamoff	                _M_off; 
      _StateT			_M_state; 
 
    public: 
            // The standard doesn't require that fpos objects can be default 
            // constructed. This implementation provides a default 
            // constructor that initializes the offset to 0 and default 
            // constructs the state. 
      fpos() 
      : _M_off(0), _M_state() { } 
 
            // The standard requires that fpos objects can be constructed 
            // from streamoff objects using the constructor syntax, and 
            // fails to give any meaningful semantics. In this 
            // implementation implicit conversion is also allowed, and this 
            // constructor stores the streamoff as the offset and default 
            // constructs the state. 
            /// Construct position from offset. 
      fpos(streamoff __off) 
      : _M_off(__off), _M_state() { } 
 
            /// Convert to streamoff. 
      operator streamoff() const { return _M_off; } 
 
            /// Remember the value of @a st. 
      void 
      state(_StateT __st) 
      { _M_state = __st; } 
 
            /// Return the last set value of @a st. 
      _StateT 
      state() const 
      { return _M_state; } 
 
            // The standard only requires that operator== must be an 
            // equivalence relation. In this implementation two fpos<StateT> 
            // objects belong to the same equivalence class if the contained 
            // offsets compare equal. 
            /// Test if equivalent to another position. 
      bool 
      operator==(const fpos& __other) const 
      { return _M_off == __other._M_off; } 
 
            /// Test if not equivalent to another position. 
      bool 
      operator!=(const fpos& __other) const 
      { return _M_off != __other._M_off; } 
 
            // The standard requires that this operator must be defined, but 
            // gives no semantics. In this implemenation it just adds it's 
            // argument to the stored offset and returns *this. 
            /// Add offset to this position. 
      fpos& 
      operator+=(streamoff __off) 
      { 
	_M_off += __off; 
	return *this; 
      } 
 
            // The standard requires that this operator must be defined, but 
            // gives no semantics. In this implemenation it just subtracts 
            // it's argument from the stored offset and returns *this. 
            /// Subtract offset from this position. 
      fpos& 
      operator-=(streamoff __off) 
      { 
	_M_off -= __off; 
	return *this; 
      } 
 
            // The standard requires that this operator must be defined, but 
            // defines it's semantics only in terms of operator-. In this 
            // implementation it constructs a copy of *this, adds the 
            // argument to that copy using operator+= and then returns the 
            // copy. 
            /// Add position and offset. 
      fpos 
      operator+(streamoff __off) const 
      { 
	fpos __pos(*this); 
	__pos += __off; 
	return __pos; 
      } 
 
            // The standard requires that this operator must be defined, but 
            // defines it's semantics only in terms of operator+. In this 
            // implementation it constructs a copy of *this, subtracts the 
            // argument from that copy using operator-= and then returns the 
            // copy. 
            /// Subtract offset from position. 
      fpos 
      operator-(streamoff __off) const 
      { 
	fpos __pos(*this); 
	__pos -= __off; 
	return __pos; 
      } 
 
            // The standard requires that this operator must be defined, but 
            // defines it's semantics only in terms of operator+. In this 
            // implementation it returns the difference between the offset 
            // stored in *this and in the argument. 
            /// Subtract position to return offset. 
      streamoff 
      operator-(const fpos& __other) const 
      { return _M_off - __other._M_off; } 
    }; 
 
    // Clauses 21.1.3.1 and 21.1.3.2 describe streampos and wstreampos 
    // as implementation defined types, but clause 27.2 requires that 
    // they must both be typedefs for fpos<mbstate_t> 
    /// File position for char streams. 
  typedef fpos<mbstate_t> streampos; 
    /// File position for wchar_t streams. 
  typedef fpos<mbstate_t> wstreampos; 
} } // namespace std 
 
#endif 
 
// Function-Based Exception Support -*- C++ -*- 
 
// Copyright (C) 2001, 2004, 2005 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
// 
// ISO C++ 14882: 19.1  Exception classes 
// 
 
#ifndef _FUNCTEXCEPT_H 
 
// -fno-exceptions Support -*- C++ -*- 
 
// Copyright (C) 2001, 2003 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 19.1  Exception classes 
// 
 
#ifndef _EXCEPTION_DEFINES_H 
 
#ifndef __EXCEPTIONS 
// Iff -fno-exceptions, transform error handling code to work without it. 
# define try      if (true) 
# define catch(X) if (false) 
# define __throw_exception_again 
#else 
// Else proceed normally. 
# define __throw_exception_again throw 
#endif 
 
#endif 
 
 
namespace std 
{ 
    // Helper for exception objects in <except> 
  void 
  __throw_bad_exception(void) __attribute__((__noreturn__)); 
 
    // Helper for exception objects in <new> 
  void 
  __throw_bad_alloc(void) __attribute__((__noreturn__)); 
 
    // Helper for exception objects in <typeinfo> 
  void 
  __throw_bad_cast(void) __attribute__((__noreturn__)); 
 
  void 
  __throw_bad_typeid(void) __attribute__((__noreturn__)); 
 
    // Helpers for exception objects in <stdexcept> 
  void 
  __throw_logic_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_domain_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_invalid_argument(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_length_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_out_of_range(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_runtime_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_range_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_overflow_error(const char*) __attribute__((__noreturn__)); 
 
  void 
  __throw_underflow_error(const char*) __attribute__((__noreturn__)); 
 
    // Helpers for exception objects in basic_ios 
  void 
  __throw_ios_failure(const char*) __attribute__((__noreturn__)); 
} } // namespace std 
 
#endif 
 
 
namespace std  
{ 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_ios; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_streambuf; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_istream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_ostream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_iostream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT>, 
	    typename _Alloc = allocator<_CharT> > 
    class basic_stringbuf; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT>, 
	   typename _Alloc = allocator<_CharT> > 
    class basic_istringstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT>, 
	   typename _Alloc = allocator<_CharT> > 
    class basic_ostringstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT>, 
	   typename _Alloc = allocator<_CharT> > 
    class basic_stringstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_filebuf; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_ifstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_ofstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class basic_fstream; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class istreambuf_iterator; 
 
  template<typename _CharT, typename _Traits = char_traits<_CharT> > 
    class ostreambuf_iterator; 
 
    // _GLIBCXX_RESOLVE_LIB_DEFECTS 
    // Not included.   (??? Apparently no LWG number?) 
  class ios_base;  
 
  

  */ 
  typedef basic_ios<char> 		ios;		  typedef basic_ios<char> 		ios;		///< @isiosfwd 
  typedef basic_streambuf<char> 	streambuf;	  typedef basic_streambuf<char> 	streambuf;	///< @isiosfwd 
  typedef basic_istream<char> 		istream;	  typedef basic_istream<char> 		istream;	///< @isiosfwd 
  typedef basic_ostream<char> 		ostream;	  typedef basic_ostream<char> 		ostream;	///< @isiosfwd 
  typedef basic_iostream<char> 		iostream;	  typedef basic_iostream<char> 		iostream;	///< @isiosfwd 
  typedef basic_stringbuf<char> 	stringbuf;	  typedef basic_stringbuf<char> 	stringbuf;	///< @isiosfwd 
  typedef basic_istringstream<char> 	istringstream;	  typedef basic_istringstream<char> 	istringstream;	///< @isiosfwd 
  typedef basic_ostringstream<char> 	ostringstream;	  typedef basic_ostringstream<char> 	ostringstream;	///< @isiosfwd 
  typedef basic_stringstream<char> 	stringstream;	  typedef basic_stringstream<char> 	stringstream;	///< @isiosfwd 
  typedef basic_filebuf<char> 		filebuf;	  typedef basic_filebuf<char> 		filebuf;	///< @isiosfwd 
  typedef basic_ifstream<char> 		ifstream;	  typedef basic_ifstream<char> 		ifstream;	///< @isiosfwd 
  typedef basic_ofstream<char> 		ofstream;	  typedef basic_ofstream<char> 		ofstream;	///< @isiosfwd 
  typedef basic_fstream<char> 		fstream;	  typedef basic_fstream<char> 		fstream;	///< @isiosfwd 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  typedef basic_ios<wchar_t> 		wios;		  typedef basic_ios<wchar_t> 		wios;		///< @isiosfwd 
  typedef basic_streambuf<wchar_t> 	wstreambuf;	  typedef basic_streambuf<wchar_t> 	wstreambuf;	///< @isiosfwd 
  typedef basic_istream<wchar_t> 	wistream;	  typedef basic_istream<wchar_t> 	wistream;	///< @isiosfwd 
  typedef basic_ostream<wchar_t> 	wostream;	  typedef basic_ostream<wchar_t> 	wostream;	///< @isiosfwd 
  typedef basic_iostream<wchar_t> 	wiostream;	  typedef basic_iostream<wchar_t> 	wiostream;	///< @isiosfwd 
  typedef basic_stringbuf<wchar_t> 	wstringbuf;	  typedef basic_stringbuf<wchar_t> 	wstringbuf;	///< @isiosfwd 
  typedef basic_istringstream<wchar_t> 	wistringstream;	  typedef basic_istringstream<wchar_t> 	wistringstream;	///< @isiosfwd 
  typedef basic_ostringstream<wchar_t> 	wostringstream;	  typedef basic_ostringstream<wchar_t> 	wostringstream;	///< @isiosfwd 
  typedef basic_stringstream<wchar_t> 	wstringstream;	  typedef basic_stringstream<wchar_t> 	wstringstream;	///< @isiosfwd 
  typedef basic_filebuf<wchar_t> 	wfilebuf;	  typedef basic_filebuf<wchar_t> 	wfilebuf;	///< @isiosfwd 
  typedef basic_ifstream<wchar_t> 	wifstream;	  typedef basic_ifstream<wchar_t> 	wifstream;	///< @isiosfwd 
  typedef basic_ofstream<wchar_t> 	wofstream;	  typedef basic_ofstream<wchar_t> 	wofstream;	///< @isiosfwd 
  typedef basic_fstream<wchar_t> 	wfstream;	  typedef basic_fstream<wchar_t> 	wfstream;	///< @isiosfwd 
#endif 
  

#endif /* 1 */ 
 
#include <exception> 		// Exception Handling support header for -*- C++ -*- 
 
// Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001, 2002 
// Free Software Foundation 
// 
// This file is part of GCC. 
// 
// GCC is free software; you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation; either version 2, or (at your option) 
// any later version. 
//  
// GCC is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
//  
// You should have received a copy of the GNU General Public License 
// along with GCC; see the file COPYING.  If not, write to 
// the Free Software Foundation, 51 Franklin Street, Fifth Floor, 
// Boston, MA 02110-1301, USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef __EXCEPTION__ 
 
#pragma GCC visibility push(default) 
 
extern "C++" { 
 
namespace std  
{ 
  

   */ 
  class exception  
  { 
  public: 
    exception() throw() { } 
    virtual ~exception() throw(); 
    

     *  of the current error.  */ 
    virtual const char* what() const throw(); 
  }; 
 
  

   *  %exception specification, one of these may be thrown.  */ 
  class bad_exception : public exception  
  { 
  public: 
    bad_exception() throw() { } 
        // This declaration is not useless: 
        // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118 
    virtual ~bad_exception() throw(); 
  }; 
 
    /// If you write a replacement %terminate handler, it must be of this type. 
  typedef void (*terminate_handler) (); 
    /// If you write a replacement %unexpected handler, it must be of this type. 
  typedef void (*unexpected_handler) (); 
 
    /// Takes a new handler function as an argument, returns the old function. 
  terminate_handler set_terminate(terminate_handler) throw(); 
  

   *  abandoned for any reason.  It can also be called by the user.  */ 
  void terminate() __attribute__ ((__noreturn__)); 
 
    /// Takes a new handler function as an argument, returns the old function. 
  unexpected_handler set_unexpected(unexpected_handler) throw(); 
  

   *  violates the function's %exception specification.  */ 
  void unexpected() __attribute__ ((__noreturn__)); 
 
  

   */ 
  bool uncaught_exception() throw(); 
} } // namespace std 
 
namespace __gnu_cxx 
{ 
  

  */ 
  void __verbose_terminate_handler (); 
} } // namespace __gnu_cxx 
   
} } // extern "C++" 
 
#pragma GCC visibility pop 
 
#endif 
 
#include <bits/char_traits.h> 	// Character Traits for use by standard string and iostream -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 21  Strings library 
// 
 


 */ 
 
#ifndef _CHAR_TRAITS_H 
 
#pragma GCC system_header 
 
#include <cstring>            #include <bits/stl_algobase.h>// Bits and pieces used in algorithms -*- C++ -*- 
 
// Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 


 */ 
 
#ifndef _ALGOBASE_H 
 
// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CLIMITS_HEADER 
 
 
#endif #endif // CLIMITS_HEADER 
 
// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CSTDLIB_HEADER 
 
 
namespace std { 
  using ::abort; 
  using ::atexit; 
  using ::exit; 
  using ::getenv; 
  using ::system; 
  using ::calloc; 
  using ::malloc; 
  using ::free; 
  using ::realloc; 
  using ::atol; 
  using ::mblen; 
  using ::strtod; 
  using ::wctomb; 
  using ::atof; 
  using ::mbstowcs; 
  using ::strtol; 
  using ::wcstombs; 
  using ::atoi; 
  using ::mbtowc; 
  using ::strtoul; 
  using ::bsearch; 
  using ::qsort; 
  using ::div_t; 
  using ::ldiv_t; 
  using ::abs; 
  using ::labs; 
  using ::srand; 
  using ::div; 
  using ::ldiv; 
  using ::rand; 
} 
 
#endif #endif // CSTDLIB_HEADER 
 
// Pair implementation -*- C++ -*- 
 
// Copyright (C) 2001, 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 


 */ 
 
#ifndef _PAIR_H 
 
namespace std 
{ 
    /// pair holds two objects of arbitrary type. 
  template<class _T1, class _T2> 
    struct pair 
    { 
      typedef _T1 first_type;          typedef _T1 first_type;    ///<  @c first_type is the first bound type 
      typedef _T2 second_type;         typedef _T2 second_type;   ///<  @c second_type is the second bound type 
 
      _T1 first;                       _T1 first;                 ///< @c first is a copy of the first object 
      _T2 second;                      _T2 second;                ///< @c second is a copy of the second object 
 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 265.  std::pair::pair() effects overly restrictive 
      

       *  respective default constructors.  */ 
      pair() 
      : first(), second() { } 
 
      

      /** There is also a templated copy ctor for the @c pair class itself.  */ 
      template<class _U1, class _U2> 
        pair(const pair<_U1, _U2>& __p) 
	: first(__p.first), second(__p.second) { } 
    }; 
 
    /// Two pairs of the same type are equal iff their members are equal. 
  template<class _T1, class _T2> 
    inline bool 
    operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return __x.first == __y.first && __x.second == __y.second; } 
 
    /// <http://gcc.gnu.org/onlinedocs/libstdc++/20_util/howto.html#pairlt> 
  template<class _T1, class _T2> 
    inline bool 
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return __x.first < __y.first 
	     || (!(__y.first < __x.first) && __x.second < __y.second); } 
 
    /// Uses @c operator== to find the result. 
  template<class _T1, class _T2> 
    inline bool 
    operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return !(__x == __y); } 
 
    /// Uses @c operator< to find the result. 
  template<class _T1, class _T2> 
    inline bool 
    operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return __y < __x; } 
 
    /// Uses @c operator< to find the result. 
  template<class _T1, class _T2> 
    inline bool 
    operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return !(__y < __x); } 
 
    /// Uses @c operator< to find the result. 
  template<class _T1, class _T2> 
    inline bool 
    operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) 
    { return !(__x < __y); } 
 
  

   */ 
    // _GLIBCXX_RESOLVE_LIB_DEFECTS 
    // 181.  make_pair() unintended behavior 
  template<class _T1, class _T2> 
    inline pair<_T1, _T2> 
    make_pair(_T1 __x, _T2 __y) 
    { return pair<_T1, _T2>(__x, __y); } 
} } // namespace std 
 
#endif 
 
// The  -*- C++ -*- type traits classes for internal use in libstdc++ 
 
// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// Written by Gabriel Dos Reis <dosreis@cmla.ens-cachan.fr> 
 


 */ 
 
#ifndef _CPP_TYPE_TRAITS_H 
 
#pragma GCC system_header 
 
 
// 
// This file provides some compile-time information about various types. 
// These representations were designed, on purpose, to be constant-expressions 
// and not types as found in <bits/type_traits.h>.  In particular, they 
// can be used in control structures and the optimizer hopefully will do 
// the obvious thing. 
// 
// Why integral expressions, and not functions nor types? 
// Firstly, these compile-time entities are used as template-arguments 
// so function return values won't work:  We need compile-time entities. 
// We're left with types and constant  integral expressions. 
// Secondly, from the point of view of ease of use, type-based compile-time 
// information is -not- *that* convenient.  On has to write lots of 
// overloaded functions and to hope that the compiler will select the right 
// one. As a net effect, the overall structure isn't very clear at first 
// glance. 
// Thirdly, partial ordering and overload resolution (of function templates) 
// is highly costly in terms of compiler-resource.  It is a Good Thing to 
// keep these resource consumption as least as possible. 
// 
// See valarray_array.h for a case use. 
// 
// -- Gaby (dosreis@cmla.ens-cachan.fr) 2000-03-06. 
// 
// Update 2005: types are also provided and <bits/type_traits.h> has been 
// removed. 
// 
 
// NB: g++ can not compile these if declared within the class 
// __is_pod itself. 
namespace __gnu_internal 
{ 
  typedef char __one; 
  typedef char __two[2]; 
 
  template<typename _Tp> 
  __one __test_type(int _Tp::*); 
  template<typename _Tp> 
  __two& __test_type(...); 
} } // namespace __gnu_internal 
 
// Forward declaration hack, should really include this from somewhere. 
namespace __gnu_cxx 
{ 
  template<typename _Iterator, typename _Container> 
    class __normal_iterator; 
} } // namespace __gnu_cxx 
 
struct __true_type { }; 
struct __false_type { }; 
 
namespace std 
{ 
  template<bool> 
    struct __truth_type 
    { typedef __false_type __type; }; 
 
  template<> 
    struct __truth_type<true> 
    { typedef __true_type __type; }; 
 
    // N.B. The conversions to bool are needed due to the issue 
    // explained in c++/19404. 
  template<class _Sp, class _Tp> 
    struct __traitor 
    { 
      enum { __value = bool(_Sp::__value) || bool(_Tp::__value) }; 
      typedef typename __truth_type<__value>::__type __type; 
    }; 
 
    // Compare for equality of types. 
  template<typename, typename> 
    struct __are_same 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
  template<typename _Tp> 
    struct __are_same<_Tp, _Tp> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // Define a nested type if some predicate holds. 
  template<typename, bool> 
    struct __enable_if 
    {  
    }; 
 
  template<typename _Tp> 
    struct __enable_if<_Tp, true> 
    { 
      typedef _Tp __type; 
    }; 
 
    // Holds if the template-argument is a void type. 
  template<typename _Tp> 
    struct __is_void 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
  template<> 
    struct __is_void<void> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // 
    // Integer types 
    // 
  template<typename _Tp> 
    struct __is_integer 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
    // Thirteen specializations (yes there are eleven standard integer 
    // types; 'long long' and 'unsigned long long' are supported as 
    // extensions) 
  template<> 
    struct __is_integer<bool> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<char> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<signed char> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<unsigned char> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
# ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    struct __is_integer<wchar_t> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
# endif 
 
  template<> 
    struct __is_integer<short> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<unsigned short> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<int> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<unsigned int> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<long> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<unsigned long> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<long long> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_integer<unsigned long long> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // 
    // Floating point types 
    // 
  template<typename _Tp> 
    struct __is_floating 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
    // three specializations (float, double and 'long double') 
  template<> 
    struct __is_floating<float> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_floating<double> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
  template<> 
    struct __is_floating<long double> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // 
    // Pointer types 
    // 
  template<typename _Tp> 
    struct __is_pointer 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
  template<typename _Tp> 
    struct __is_pointer<_Tp*> 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // 
    // Normal iterator type 
    // 
  template<typename _Tp> 
    struct __is_normal_iterator 
    { 
      enum { __value = 0 }; 
      typedef __false_type __type; 
    }; 
 
  template<typename _Iterator, typename _Container> 
    struct __is_normal_iterator< __gnu_cxx::__normal_iterator<_Iterator, 
							      _Container> > 
    { 
      enum { __value = 1 }; 
      typedef __true_type __type; 
    }; 
 
    // 
    // An arithmetic type is an integer type or a floating point type 
    // 
  template<typename _Tp> 
    struct __is_arithmetic 
    : public __traitor<__is_integer<_Tp>, __is_floating<_Tp> > 
    { }; 
 
    // 
    // A fundamental type is `void' or and arithmetic type 
    // 
  template<typename _Tp> 
    struct __is_fundamental 
    : public __traitor<__is_void<_Tp>, __is_arithmetic<_Tp> > 
    { }; 
 
    // 
    // A scalar type is an arithmetic type or a pointer type 
    //  
  template<typename _Tp> 
    struct __is_scalar 
    : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp> > 
    { }; 
 
    // 
    // For the immediate use, the following is a good approximation 
    // 
  template<typename _Tp> 
    struct __is_pod 
    { 
      enum 
	{ 
	  __value = (sizeof(__gnu_internal::__test_type<_Tp>(0)) 
		     != sizeof(__gnu_internal::__one)) 
	}; 
    }; 
 
    // 
    // A stripped-down version of std::tr1::is_empty 
    // 
  template<typename _Tp> 
    struct __is_empty 
    {  
    private: 
      template<typename> 
        struct __first { }; 
      template<typename _Up> 
        struct __second 
        : public _Up { }; 
            
    public: 
      enum 
	{ 
	  __value = sizeof(__first<_Tp>) == sizeof(__second<_Tp>) 
	}; 
    }; 
 
} } // namespace std 
 
#endif #endif //_CPP_TYPE_TRAITS_H 
 
// Types used in iterator implementation -*- C++ -*- 
 
// Copyright (C) 2001, 2002, 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 


 */ 
 
#ifndef _ITERATOR_BASE_TYPES_H 
 
#pragma GCC system_header 
 
namespace std 
{ 
    //@{ 
  

  */ 
    ///  Marking input iterators. 
  struct input_iterator_tag {}; 
    ///  Marking output iterators. 
  struct output_iterator_tag {}; 
    /// Forward iterators support a superset of input iterator operations. 
  struct forward_iterator_tag : public input_iterator_tag {}; 
    /// Bidirectional iterators support a superset of forward iterator 
    /// operations. 
  struct bidirectional_iterator_tag : public forward_iterator_tag {}; 
    /// Random-access iterators support a superset of bidirectional iterator 
    /// operations. 
  struct random_access_iterator_tag : public bidirectional_iterator_tag {}; 
    //@} 
 
 
  

  */ 
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t, 
           typename _Pointer = _Tp*, typename _Reference = _Tp&> 
    struct iterator 
    { 
            /// One of the @link iterator_tags tag types@endlink. 
      typedef _Category  iterator_category; 
            /// The type "pointed to" by the iterator. 
      typedef _Tp        value_type; 
            /// Distance between iterators is represented as this type. 
      typedef _Distance  difference_type; 
            /// This type represents a pointer-to-value_type. 
      typedef _Pointer   pointer; 
            /// This type represents a reference-to-value_type. 
      typedef _Reference reference; 
    }; 
 
  

  */ 
  template<typename _Iterator> 
    struct iterator_traits 
    { 
      typedef typename _Iterator::iterator_category iterator_category; 
      typedef typename _Iterator::value_type        value_type; 
      typedef typename _Iterator::difference_type   difference_type; 
      typedef typename _Iterator::pointer           pointer; 
      typedef typename _Iterator::reference         reference; 
    }; 
 
  template<typename _Tp> 
    struct iterator_traits<_Tp*> 
    { 
      typedef random_access_iterator_tag iterator_category; 
      typedef _Tp                         value_type; 
      typedef ptrdiff_t                   difference_type; 
      typedef _Tp*                        pointer; 
      typedef _Tp&                        reference; 
    }; 
 
  template<typename _Tp> 
    struct iterator_traits<const _Tp*> 
    { 
      typedef random_access_iterator_tag iterator_category; 
      typedef _Tp                         value_type; 
      typedef ptrdiff_t                   difference_type; 
      typedef const _Tp*                  pointer; 
      typedef const _Tp&                  reference; 
    }; 
 
  

  */ 
  template<typename _Iter> 
    inline typename iterator_traits<_Iter>::iterator_category 
    __iterator_category(const _Iter&) 
    { return typename iterator_traits<_Iter>::iterator_category(); } 
 
} } // namespace std 
 
#endif 
 
// Functions used by iterators -*- C++ -*- 
 
// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 


 */ 
 
#ifndef _ITERATOR_BASE_FUNCS_H 
 
#pragma GCC system_header 
// Concept-checking control -*- C++ -*- 
 
// Copyright (C) 2001 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef _CONCEPT_CHECK_H 
 
#pragma GCC system_header 
 
 
// All places in libstdc++-v3 where these are used, or /might/ be used, or 
// don't need to be used, or perhaps /should/ be used, are commented with 
// "concept requirements" (and maybe some more text).  So grep like crazy 
// if you're looking for additional places to use these. 
 
// Concept-checking code is off by default unless users turn it on via 
// configure options or editing c++config.h. 
 
#ifndef _GLIBCXX_CONCEPT_CHECKS 
 
 
#else #else // the checks are on 
 
// Copyright (C) 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// (C) Copyright Jeremy Siek 2000. Permission to copy, use, modify, 
// sell and distribute this software is granted provided this 
// copyright notice appears in all copies. This software is provided 
// "as is" without express or implied warranty, and with no claim as 
// to its suitability for any purpose. 
// 
 
// GCC Note:  based on version 1.12.0 of the Boost library. 
 


 */ 
 
#ifndef _BOOST_CONCEPT_CHECK_H 
 
#pragma GCC system_header 
 
#include <cstddef>                #include <bits/stl_iterator_base_types.h>    #include <utility>                            
 
namespace __gnu_cxx 
{ 
 
 
// When the C-C code is in use, we would like this function to do as little 
// as possible at runtime, use as few resources as possible, and hopefully 
// be elided out of existence... hmmm. 
template <class _Concept> 
inline void __function_requires() 
{ 
  void (_Concept::*__x)() __attribute__ ((__unused__)) = &_Concept::__constraints; 
} 
 
// No definition: if this is referenced, there's a problem with 
// the instantiating type not being one of the required integer types. 
// Unfortunately, this results in a link-time error, not a compile-time error. 
void __error_type_must_be_an_integer_type(); 
void __error_type_must_be_an_unsigned_integer_type(); 
void __error_type_must_be_a_signed_integer_type(); 
 
// ??? Should the "concept_checking*" structs begin with more than _ ? 
  typedef void (_ns::_concept <_type_var>::* _func##_type_var##_concept)(); \ 
  template <_func##_type_var##_concept _Tp1> \ 
  struct _concept_checking##_type_var##_concept { }; \ 
  typedef _concept_checking##_type_var##_concept< \ 
    &_ns::_concept <_type_var>::__constraints> \ 
    _concept_checking_typedef##_type_var##_concept 
 
  typedef void (_ns::_concept <_type_var1,_type_var2>::* _func##_type_var1##_type_var2##_concept)(); \ 
  template <_func##_type_var1##_type_var2##_concept _Tp1> \ 
  struct _concept_checking##_type_var1##_type_var2##_concept { }; \ 
  typedef _concept_checking##_type_var1##_type_var2##_concept< \ 
    &_ns::_concept <_type_var1,_type_var2>::__constraints> \ 
    _concept_checking_typedef##_type_var1##_type_var2##_concept 
 
  typedef void (_ns::_concept <_type_var1,_type_var2,_type_var3>::* _func##_type_var1##_type_var2##_type_var3##_concept)(); \ 
  template <_func##_type_var1##_type_var2##_type_var3##_concept _Tp1> \ 
  struct _concept_checking##_type_var1##_type_var2##_type_var3##_concept { }; \ 
  typedef _concept_checking##_type_var1##_type_var2##_type_var3##_concept< \ 
    &_ns::_concept <_type_var1,_type_var2,_type_var3>::__constraints>  \ 
  _concept_checking_typedef##_type_var1##_type_var2##_type_var3##_concept 
 
  typedef void (_ns::_concept <_type_var1,_type_var2,_type_var3,_type_var4>::* _func##_type_var1##_type_var2##_type_var3##_type_var4##_concept)(); \ 
  template <_func##_type_var1##_type_var2##_type_var3##_type_var4##_concept _Tp1> \ 
  struct _concept_checking##_type_var1##_type_var2##_type_var3##_type_var4##_concept { }; \ 
  typedef _concept_checking##_type_var1##_type_var2##_type_var3##_type_var4##_concept< \ 
  &_ns::_concept <_type_var1,_type_var2,_type_var3,_type_var4>::__constraints> \ 
    _concept_checking_typedef##_type_var1##_type_var2##_type_var3##_type_var4##_concept 
 
 
template <class _Tp1, class _Tp2> 
struct _Aux_require_same { }; 
 
template <class _Tp> 
struct _Aux_require_same<_Tp,_Tp> { typedef _Tp _Type; }; 
 
  template <class _Tp1, class _Tp2> 
  struct _SameTypeConcept 
  { 
    void __constraints() { 
      typedef typename _Aux_require_same<_Tp1, _Tp2>::_Type _Required; 
    } 
  }; 
 
  template <class _Tp> 
  struct _IntegerConcept { 
    void __constraints() { 
      __error_type_must_be_an_integer_type(); 
    } 
  }; 
  template <> struct _IntegerConcept<short> { void __constraints() {} }; 
  template <> struct _IntegerConcept<unsigned short> { void __constraints(){} }; 
  template <> struct _IntegerConcept<int> { void __constraints() {} }; 
  template <> struct _IntegerConcept<unsigned int> { void __constraints() {} }; 
  template <> struct _IntegerConcept<long> { void __constraints() {} }; 
  template <> struct _IntegerConcept<unsigned long> { void __constraints() {} }; 
  template <> struct _IntegerConcept<long long> { void __constraints() {} }; 
  template <> struct _IntegerConcept<unsigned long long> 
                                                { void __constraints() {} }; 
 
  template <class _Tp> 
  struct _SignedIntegerConcept { 
    void __constraints() { 
      __error_type_must_be_a_signed_integer_type(); 
    } 
  }; 
  template <> struct _SignedIntegerConcept<short> { void __constraints() {} }; 
  template <> struct _SignedIntegerConcept<int> { void __constraints() {} }; 
  template <> struct _SignedIntegerConcept<long> { void __constraints() {} }; 
  template <> struct _SignedIntegerConcept<long long> { void __constraints(){}}; 
 
  template <class _Tp> 
  struct _UnsignedIntegerConcept { 
    void __constraints() { 
      __error_type_must_be_an_unsigned_integer_type(); 
    } 
  }; 
  template <> struct _UnsignedIntegerConcept<unsigned short> 
    { void __constraints() {} }; 
  template <> struct _UnsignedIntegerConcept<unsigned int> 
    { void __constraints() {} }; 
  template <> struct _UnsignedIntegerConcept<unsigned long> 
    { void __constraints() {} }; 
  template <> struct _UnsignedIntegerConcept<unsigned long long> 
    { void __constraints() {} }; 
 
    //=========================================================================== 
    // Basic Concepts 
 
  template <class _Tp> 
  struct _DefaultConstructibleConcept 
  { 
    void __constraints() { 
      _Tp __a _IsUnused;                      _Tp __a _IsUnused;                // require default constructor 
    } 
  }; 
 
  template <class _Tp> 
  struct _AssignableConcept 
  { 
    void __constraints() { 
      __a = __a;                              __a = __a;                        // require assignment operator 
      __const_constraints(__a); 
    } 
    void __const_constraints(const _Tp& __b) { 
      __a = __b;                         __a = __b;                   // const required for argument to assignment 
    } 
    _Tp __a; 
        // possibly should be "Tp* a;" and then dereference "a" in constraint 
        // functions?  present way would require a default ctor, i think... 
  }; 
 
  template <class _Tp> 
  struct _CopyConstructibleConcept 
  { 
    void __constraints() { 
      _Tp __a(__b);                           _Tp __a(__b);                     // require copy constructor 
      _Tp* __ptr _IsUnused = &__a;            _Tp* __ptr __attribute__ ((__unused__)) = &__a;      // require address of operator 
      __const_constraints(__a); 
    } 
    void __const_constraints(const _Tp& __a) { 
      _Tp __c _IsUnused(__a);                 _Tp __c _IsUnused(__a);           // require const copy constructor 
      const _Tp* __ptr _IsUnused = &__a;       const _Tp* __ptr __attribute__ ((__unused__)) = &__a; // require const address of operator 
    } 
    _Tp __b; 
  }; 
 
    // The SGI STL version of Assignable requires copy constructor and operator= 
  template <class _Tp> 
  struct _SGIAssignableConcept 
  { 
    void __constraints() { 
      _Tp __b _IsUnused(__a); 
      __a = __a;                              __a = __a;                        // require assignment operator 
      __const_constraints(__a); 
    } 
    void __const_constraints(const _Tp& __b) { 
      _Tp __c _IsUnused(__b); 
      __a = __b;                    __a = __b;              // const required for argument to assignment 
    } 
    _Tp __a; 
  }; 
 
  template <class _From, class _To> 
  struct _ConvertibleConcept 
  { 
    void __constraints() { 
      _To __y __attribute__ ((__unused__)) = __x; 
    } 
    _From __x; 
  }; 
 
    // The C++ standard requirements for many concepts talk about return 
    // types that must be "convertible to bool".  The problem with this 
    // requirement is that it leaves the door open for evil proxies that 
    // define things like operator|| with strange return types.  Two 
    // possible solutions are: 
    // 1) require the return type to be exactly bool 
    // 2) stay with convertible to bool, and also 
    //    specify stuff about all the logical operators. 
    // For now we just test for convertible to bool. 
  template <class _Tp> 
  void __aux_require_boolean_expr(const _Tp& __t) { 
    bool __x __attribute__ ((__unused__)) = __t; 
  } 
 
// FIXME 
  template <class _Tp> 
  struct _EqualityComparableConcept 
  { 
    void __constraints() { 
      __aux_require_boolean_expr(__a == __b); 
    } 
    _Tp __a, __b; 
  }; 
 
  template <class _Tp> 
  struct _LessThanComparableConcept 
  { 
    void __constraints() { 
      __aux_require_boolean_expr(__a < __b); 
    } 
    _Tp __a, __b; 
  }; 
 
    // This is equivalent to SGI STL's LessThanComparable. 
  template <class _Tp> 
  struct _ComparableConcept 
  { 
    void __constraints() { 
      __aux_require_boolean_expr(__a < __b); 
      __aux_require_boolean_expr(__a > __b); 
      __aux_require_boolean_expr(__a <= __b); 
      __aux_require_boolean_expr(__a >= __b); 
    } 
    _Tp __a, __b; 
  }; 
 
  template <class _First, class _Second> \ 
  struct _NAME { \ 
    void __constraints() { (void)__constraints_(); } \ 
    bool __constraints_() {  \ 
      return  __a _OP __b; \ 
    } \ 
    _First __a; \ 
    _Second __b; \ 
  } 
 
  template <class _Ret, class _First, class _Second> \ 
  struct _NAME { \ 
    void __constraints() { (void)__constraints_(); } \ 
    _Ret __constraints_() {  \ 
      return __a _OP __b; \ 
    } \ 
    _First __a; \ 
    _Second __b; \ 
  } 
 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(==, _EqualOpConcept); 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(!=, _NotEqualOpConcept); 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<, _LessThanOpConcept); 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<=, _LessEqualOpConcept); 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>, _GreaterThanOpConcept); 
  _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>=, _GreaterEqualOpConcept); 
 
  _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT(+, _PlusOpConcept); 
  _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT(*, _TimesOpConcept); 
  _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT(/, _DivideOpConcept); 
  _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT(-, _SubtractOpConcept); 
  _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT(%, _ModOpConcept); 
 
#undef _GLIBCXX_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT 
#undef _GLIBCXX_DEFINE_BINARY_OPERATOR_CONSTRAINT 
 
    //=========================================================================== 
    // Function Object Concepts 
 
  template <class _Func, class _Return> 
  struct _GeneratorConcept 
  { 
    void __constraints() { 
      const _Return& __r _IsUnused = __f();      const _Return& __r __attribute__ ((__unused__)) = __f();// require operator() member function 
    } 
    _Func __f; 
  }; 
 
 
  template <class _Func> 
  struct _GeneratorConcept<_Func,void> 
  { 
    void __constraints() { 
      __f();                                  __f();                            // require operator() member function 
    } 
    _Func __f; 
  }; 
 
  template <class _Func, class _Return, class _Arg> 
  struct _UnaryFunctionConcept 
  { 
    void __constraints() { 
      __r = __f(__arg);                        __r = __f(__arg);                  // require operator() 
    } 
    _Func __f; 
    _Arg __arg; 
    _Return __r; 
  }; 
 
  template <class _Func, class _Arg> 
  struct _UnaryFunctionConcept<_Func, void, _Arg> { 
    void __constraints() { 
      __f(__arg);                             __f(__arg);                       // require operator() 
    } 
    _Func __f; 
    _Arg __arg; 
  }; 
 
  template <class _Func, class _Return, class _First, class _Second> 
  struct _BinaryFunctionConcept 
  { 
    void __constraints() { 
      __r = __f(__first, __second);           __r = __f(__first, __second);     // require operator() 
    } 
    _Func __f; 
    _First __first; 
    _Second __second; 
    _Return __r; 
  }; 
 
  template <class _Func, class _First, class _Second> 
  struct _BinaryFunctionConcept<_Func, void, _First, _Second> 
  { 
    void __constraints() { 
      __f(__first, __second);                 __f(__first, __second);           // require operator() 
    } 
    _Func __f; 
    _First __first; 
    _Second __second; 
  }; 
 
  template <class _Func, class _Arg> 
  struct _UnaryPredicateConcept 
  { 
    void __constraints() { 
      __aux_require_boolean_expr(__f(__arg));       __aux_require_boolean_expr(__f(__arg)); // require op() returning bool 
    } 
    _Func __f; 
    _Arg __arg; 
  }; 
 
  template <class _Func, class _First, class _Second> 
  struct _BinaryPredicateConcept 
  { 
    void __constraints() { 
      __aux_require_boolean_expr(__f(__a, __b));       __aux_require_boolean_expr(__f(__a, __b)); // require op() returning bool 
    } 
    _Func __f; 
    _First __a; 
    _Second __b; 
  }; 
 
    // use this when functor is used inside a container class like std::set 
  template <class _Func, class _First, class _Second> 
  struct _Const_BinaryPredicateConcept { 
    void __constraints() { 
      __const_constraints(__f); 
    } 
    void __const_constraints(const _Func& __fun) { 
      __function_requires<_BinaryPredicateConcept<_Func, _First, _Second> >(); 
            // operator() must be a const member function 
      __aux_require_boolean_expr(__fun(__a, __b)); 
    } 
    _Func __f; 
    _First __a; 
    _Second __b; 
  }; 
 
    //=========================================================================== 
    // Iterator Concepts 
 
  template <class _Tp> 
  struct _TrivialIteratorConcept 
  { 
    void __constraints() { 
//    __function_requires< _DefaultConstructibleConcept<_Tp> >(); 
      __function_requires< _AssignableConcept<_Tp> >(); 
      __function_requires< _EqualityComparableConcept<_Tp> >(); 
//      typedef typename std::iterator_traits<_Tp>::value_type _V; 
      (void)*__i;                             (void)*__i;                       // require dereference operator 
    } 
    _Tp __i; 
  }; 
 
  template <class _Tp> 
  struct _Mutable_TrivialIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _TrivialIteratorConcept<_Tp> >(); 
      *__i = *__j;                            *__i = *__j;                      // require dereference and assignment 
    } 
    _Tp __i, __j; 
  }; 
 
  template <class _Tp> 
  struct _InputIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _TrivialIteratorConcept<_Tp> >(); 
            // require iterator_traits typedef's 
      typedef typename std::iterator_traits<_Tp>::difference_type _Diff; 
//      __function_requires< _SignedIntegerConcept<_Diff> >(); 
      typedef typename std::iterator_traits<_Tp>::reference _Ref; 
      typedef typename std::iterator_traits<_Tp>::pointer _Pt; 
      typedef typename std::iterator_traits<_Tp>::iterator_category _Cat; 
      __function_requires< _ConvertibleConcept< 
        typename std::iterator_traits<_Tp>::iterator_category, 
        std::input_iterator_tag> >(); 
      ++__i;                                  ++__i;                            // require preincrement operator 
      __i++;                                  __i++;                            // require postincrement operator 
    } 
    _Tp __i; 
  }; 
 
  template <class _Tp, class _ValueT> 
  struct _OutputIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _AssignableConcept<_Tp> >(); 
      ++__i;                                  ++__i;                            // require preincrement operator 
      __i++;                                  __i++;                            // require postincrement operator 
      *__i++ = __t;                           *__i++ = __t;                     // require postincrement and assignment 
    } 
    _Tp __i; 
    _ValueT __t; 
  }; 
 
  template <class _Tp> 
  struct _ForwardIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _InputIteratorConcept<_Tp> >(); 
      __function_requires< _DefaultConstructibleConcept<_Tp> >(); 
      __function_requires< _ConvertibleConcept< 
        typename std::iterator_traits<_Tp>::iterator_category, 
        std::forward_iterator_tag> >(); 
      typedef typename std::iterator_traits<_Tp>::reference _Ref; 
      _Ref __r __attribute__ ((__unused__)) = *__i; 
    } 
    _Tp __i; 
  }; 
 
  template <class _Tp> 
  struct _Mutable_ForwardIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _ForwardIteratorConcept<_Tp> >(); 
      *__i++ = *__i;                          *__i++ = *__i;                    // require postincrement and assignment 
    } 
    _Tp __i; 
  }; 
 
  template <class _Tp> 
  struct _BidirectionalIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _ForwardIteratorConcept<_Tp> >(); 
      __function_requires< _ConvertibleConcept< 
        typename std::iterator_traits<_Tp>::iterator_category, 
        std::bidirectional_iterator_tag> >(); 
      --__i;                                  --__i;                            // require predecrement operator 
      __i--;                                  __i--;                            // require postdecrement operator 
    } 
    _Tp __i; 
  }; 
 
  template <class _Tp> 
  struct _Mutable_BidirectionalIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _BidirectionalIteratorConcept<_Tp> >(); 
      __function_requires< _Mutable_ForwardIteratorConcept<_Tp> >(); 
      *__i-- = *__i;                          *__i-- = *__i;                    // require postdecrement and assignment 
    } 
    _Tp __i; 
  }; 
 
 
  template <class _Tp> 
  struct _RandomAccessIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _BidirectionalIteratorConcept<_Tp> >(); 
      __function_requires< _ComparableConcept<_Tp> >(); 
      __function_requires< _ConvertibleConcept< 
        typename std::iterator_traits<_Tp>::iterator_category, 
        std::random_access_iterator_tag> >(); 
            // ??? We don't use _Ref, are we just checking for "referenceability"? 
      typedef typename std::iterator_traits<_Tp>::reference _Ref; 
 
      __i += __n;                             __i += __n;                       // require assignment addition operator 
      __i = __i + __n; __i = __n + __i;       __i = __i + __n; __i = __n + __i; // require addition with difference type 
      __i -= __n;                             __i -= __n;                       // require assignment subtraction op 
      __i = __i - __n;                        __i = __i - __n;                  // require subtraction with 
                                                                                //            difference type 
      __n = __i - __j;                        __n = __i - __j;                  // require difference operator 
      (void)__i[__n];                         (void)__i[__n];                   // require element access operator 
    } 
    _Tp __a, __b; 
    _Tp __i, __j; 
    typename std::iterator_traits<_Tp>::difference_type __n; 
  }; 
 
  template <class _Tp> 
  struct _Mutable_RandomAccessIteratorConcept 
  { 
    void __constraints() { 
      __function_requires< _RandomAccessIteratorConcept<_Tp> >(); 
      __function_requires< _Mutable_BidirectionalIteratorConcept<_Tp> >(); 
      __i[__n] = *__i;                        __i[__n] = *__i;                  // require element access and assignment 
    } 
    _Tp __i; 
    typename std::iterator_traits<_Tp>::difference_type __n; 
  }; 
 
    //=========================================================================== 
    // Container Concepts 
 
  template <class _Container> 
  struct _ContainerConcept 
  { 
    typedef typename _Container::value_type _Value_type; 
    typedef typename _Container::difference_type _Difference_type; 
    typedef typename _Container::size_type _Size_type; 
    typedef typename _Container::const_reference _Const_reference; 
    typedef typename _Container::const_pointer _Const_pointer; 
    typedef typename _Container::const_iterator _Const_iterator; 
 
    void __constraints() { 
      __function_requires< _InputIteratorConcept<_Const_iterator> >(); 
      __function_requires< _AssignableConcept<_Container> >(); 
      const _Container __c; 
      __i = __c.begin(); 
      __i = __c.end(); 
      __n = __c.size(); 
      __n = __c.max_size(); 
      __b = __c.empty(); 
    } 
    bool __b; 
    _Const_iterator __i; 
    _Size_type __n; 
  }; 
 
  template <class _Container> 
  struct _Mutable_ContainerConcept 
  { 
    typedef typename _Container::value_type _Value_type; 
    typedef typename _Container::reference _Reference; 
    typedef typename _Container::iterator _Iterator; 
    typedef typename _Container::pointer _Pointer; 
 
    void __constraints() { 
      __function_requires< _ContainerConcept<_Container> >(); 
      __function_requires< _AssignableConcept<_Value_type> >(); 
      __function_requires< _InputIteratorConcept<_Iterator> >(); 
 
      __i = __c.begin(); 
      __i = __c.end(); 
      __c.swap(__c2); 
    } 
    _Iterator __i; 
    _Container __c, __c2; 
  }; 
 
  template <class _ForwardContainer> 
  struct _ForwardContainerConcept 
  { 
    void __constraints() { 
      __function_requires< _ContainerConcept<_ForwardContainer> >(); 
      typedef typename _ForwardContainer::const_iterator _Const_iterator; 
      __function_requires< _ForwardIteratorConcept<_Const_iterator> >(); 
    } 
  }; 
 
  template <class _ForwardContainer> 
  struct _Mutable_ForwardContainerConcept 
  { 
    void __constraints() { 
      __function_requires< _ForwardContainerConcept<_ForwardContainer> >(); 
      __function_requires< _Mutable_ContainerConcept<_ForwardContainer> >(); 
      typedef typename _ForwardContainer::iterator _Iterator; 
      __function_requires< _Mutable_ForwardIteratorConcept<_Iterator> >(); 
    } 
  }; 
 
  template <class _ReversibleContainer> 
  struct _ReversibleContainerConcept 
  { 
    typedef typename _ReversibleContainer::const_iterator _Const_iterator; 
    typedef typename _ReversibleContainer::const_reverse_iterator 
      _Const_reverse_iterator; 
 
    void __constraints() { 
      __function_requires< _ForwardContainerConcept<_ReversibleContainer> >(); 
      __function_requires< _BidirectionalIteratorConcept<_Const_iterator> >(); 
      __function_requires< 
        _BidirectionalIteratorConcept<_Const_reverse_iterator> >(); 
 
      const _ReversibleContainer __c; 
      _Const_reverse_iterator __i = __c.rbegin(); 
      __i = __c.rend(); 
    } 
  }; 
 
  template <class _ReversibleContainer> 
  struct _Mutable_ReversibleContainerConcept 
  { 
    typedef typename _ReversibleContainer::iterator _Iterator; 
    typedef typename _ReversibleContainer::reverse_iterator _Reverse_iterator; 
 
    void __constraints() { 
      __function_requires<_ReversibleContainerConcept<_ReversibleContainer> >(); 
      __function_requires< 
        _Mutable_ForwardContainerConcept<_ReversibleContainer> >(); 
      __function_requires<_Mutable_BidirectionalIteratorConcept<_Iterator> >(); 
      __function_requires< 
        _Mutable_BidirectionalIteratorConcept<_Reverse_iterator> >(); 
 
      _Reverse_iterator __i = __c.rbegin(); 
      __i = __c.rend(); 
    } 
    _ReversibleContainer __c; 
  }; 
 
  template <class _RandomAccessContainer> 
  struct _RandomAccessContainerConcept 
  { 
    typedef typename _RandomAccessContainer::size_type _Size_type; 
    typedef typename _RandomAccessContainer::const_reference _Const_reference; 
    typedef typename _RandomAccessContainer::const_iterator _Const_iterator; 
    typedef typename _RandomAccessContainer::const_reverse_iterator 
      _Const_reverse_iterator; 
 
    void __constraints() { 
      __function_requires< 
        _ReversibleContainerConcept<_RandomAccessContainer> >(); 
      __function_requires< _RandomAccessIteratorConcept<_Const_iterator> >(); 
      __function_requires< 
        _RandomAccessIteratorConcept<_Const_reverse_iterator> >(); 
 
      const _RandomAccessContainer __c; 
      _Const_reference __r __attribute__ ((__unused__)) = __c[__n]; 
    } 
    _Size_type __n; 
  }; 
 
  template <class _RandomAccessContainer> 
  struct _Mutable_RandomAccessContainerConcept 
  { 
    typedef typename _RandomAccessContainer::size_type _Size_type; 
    typedef typename _RandomAccessContainer::reference _Reference; 
    typedef typename _RandomAccessContainer::iterator _Iterator; 
    typedef typename _RandomAccessContainer::reverse_iterator _Reverse_iterator; 
 
    void __constraints() { 
      __function_requires< 
        _RandomAccessContainerConcept<_RandomAccessContainer> >(); 
      __function_requires< 
        _Mutable_ReversibleContainerConcept<_RandomAccessContainer> >(); 
      __function_requires< _Mutable_RandomAccessIteratorConcept<_Iterator> >(); 
      __function_requires< 
        _Mutable_RandomAccessIteratorConcept<_Reverse_iterator> >(); 
 
      _Reference __r __attribute__ ((__unused__)) = __c[__i]; 
    } 
    _Size_type __i; 
    _RandomAccessContainer __c; 
  }; 
 
    // A Sequence is inherently mutable 
  template <class _Sequence> 
  struct _SequenceConcept 
  { 
    typedef typename _Sequence::reference _Reference; 
    typedef typename _Sequence::const_reference _Const_reference; 
 
    void __constraints() { 
            // Matt Austern's book puts DefaultConstructible here, the C++ 
            // standard places it in Container 
            //    function_requires< DefaultConstructible<Sequence> >(); 
      __function_requires< _Mutable_ForwardContainerConcept<_Sequence> >(); 
      __function_requires< _DefaultConstructibleConcept<_Sequence> >(); 
 
      _Sequence 
	__c _IsUnused(__n, __t), 
        __c2 _IsUnused(__first, __last); 
 
      __c.insert(__p, __t); 
      __c.insert(__p, __n, __t); 
      __c.insert(__p, __first, __last); 
 
      __c.erase(__p); 
      __c.erase(__p, __q); 
 
      _Reference __r __attribute__ ((__unused__)) = __c.front(); 
 
      __const_constraints(__c); 
    } 
    void __const_constraints(const _Sequence& __c) { 
      _Const_reference __r __attribute__ ((__unused__)) = __c.front(); 
    } 
    typename _Sequence::value_type __t; 
    typename _Sequence::size_type __n; 
    typename _Sequence::value_type *__first, *__last; 
    typename _Sequence::iterator __p, __q; 
  }; 
 
  template <class _FrontInsertionSequence> 
  struct _FrontInsertionSequenceConcept 
  { 
    void __constraints() { 
      __function_requires< _SequenceConcept<_FrontInsertionSequence> >(); 
 
      __c.push_front(__t); 
      __c.pop_front(); 
    } 
    _FrontInsertionSequence __c; 
    typename _FrontInsertionSequence::value_type __t; 
  }; 
 
  template <class _BackInsertionSequence> 
  struct _BackInsertionSequenceConcept 
  { 
    typedef typename _BackInsertionSequence::reference _Reference; 
    typedef typename _BackInsertionSequence::const_reference _Const_reference; 
 
    void __constraints() { 
      __function_requires< _SequenceConcept<_BackInsertionSequence> >(); 
 
      __c.push_back(__t); 
      __c.pop_back(); 
      _Reference __r __attribute__ ((__unused__)) = __c.back(); 
    } 
    void __const_constraints(const _BackInsertionSequence& __c) { 
      _Const_reference __r __attribute__ ((__unused__)) = __c.back(); 
    }; 
    _BackInsertionSequence __c; 
    typename _BackInsertionSequence::value_type __t; 
  }; 
 
  template <class _AssociativeContainer> 
  struct _AssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< _ForwardContainerConcept<_AssociativeContainer> >(); 
      __function_requires< 
        _DefaultConstructibleConcept<_AssociativeContainer> >(); 
 
      __i = __c.find(__k); 
      __r = __c.equal_range(__k); 
      __c.erase(__k); 
      __c.erase(__i); 
      __c.erase(__r.first, __r.second); 
      __const_constraints(__c); 
    } 
    void __const_constraints(const _AssociativeContainer& __c) { 
      __ci = __c.find(__k); 
      __n = __c.count(__k); 
      __cr = __c.equal_range(__k); 
    } 
    typedef typename _AssociativeContainer::iterator _Iterator; 
    typedef typename _AssociativeContainer::const_iterator _Const_iterator; 
 
    _AssociativeContainer __c; 
    _Iterator __i; 
    std::pair<_Iterator,_Iterator> __r; 
    _Const_iterator __ci; 
    std::pair<_Const_iterator,_Const_iterator> __cr; 
    typename _AssociativeContainer::key_type __k; 
    typename _AssociativeContainer::size_type __n; 
  }; 
 
  template <class _UniqueAssociativeContainer> 
  struct _UniqueAssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< 
        _AssociativeContainerConcept<_UniqueAssociativeContainer> >(); 
 
      _UniqueAssociativeContainer __c(__first, __last); 
 
      __pos_flag = __c.insert(__t); 
      __c.insert(__first, __last); 
    } 
    std::pair<typename _UniqueAssociativeContainer::iterator, bool> __pos_flag; 
    typename _UniqueAssociativeContainer::value_type __t; 
    typename _UniqueAssociativeContainer::value_type *__first, *__last; 
  }; 
 
  template <class _MultipleAssociativeContainer> 
  struct _MultipleAssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< 
        _AssociativeContainerConcept<_MultipleAssociativeContainer> >(); 
 
      _MultipleAssociativeContainer __c(__first, __last); 
 
      __pos = __c.insert(__t); 
      __c.insert(__first, __last); 
 
    } 
    typename _MultipleAssociativeContainer::iterator __pos; 
    typename _MultipleAssociativeContainer::value_type __t; 
    typename _MultipleAssociativeContainer::value_type *__first, *__last; 
  }; 
 
  template <class _SimpleAssociativeContainer> 
  struct _SimpleAssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< 
        _AssociativeContainerConcept<_SimpleAssociativeContainer> >(); 
      typedef typename _SimpleAssociativeContainer::key_type _Key_type; 
      typedef typename _SimpleAssociativeContainer::value_type _Value_type; 
      typedef typename _Aux_require_same<_Key_type, _Value_type>::_Type 
        _Required; 
    } 
  }; 
 
  template <class _SimpleAssociativeContainer> 
  struct _PairAssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< 
        _AssociativeContainerConcept<_SimpleAssociativeContainer> >(); 
      typedef typename _SimpleAssociativeContainer::key_type _Key_type; 
      typedef typename _SimpleAssociativeContainer::value_type _Value_type; 
      typedef typename _SimpleAssociativeContainer::mapped_type _Mapped_type; 
      typedef std::pair<const _Key_type, _Mapped_type> _Required_value_type; 
      typedef typename _Aux_require_same<_Value_type, 
        _Required_value_type>::_Type _Required; 
    } 
  }; 
 
  template <class _SortedAssociativeContainer> 
  struct _SortedAssociativeContainerConcept 
  { 
    void __constraints() { 
      __function_requires< 
        _AssociativeContainerConcept<_SortedAssociativeContainer> >(); 
      __function_requires< 
        _ReversibleContainerConcept<_SortedAssociativeContainer> >(); 
 
      _SortedAssociativeContainer 
        __c _IsUnused(__kc), 
        __c2 _IsUnused(__first, __last), 
        __c3 _IsUnused(__first, __last, __kc); 
 
      __p = __c.upper_bound(__k); 
      __p = __c.lower_bound(__k); 
      __r = __c.equal_range(__k); 
 
      __c.insert(__p, __t); 
    } 
    void __const_constraints(const _SortedAssociativeContainer& __c) { 
      __kc = __c.key_comp(); 
      __vc = __c.value_comp(); 
 
      __cp = __c.upper_bound(__k); 
      __cp = __c.lower_bound(__k); 
      __cr = __c.equal_range(__k); 
    } 
    typename _SortedAssociativeContainer::key_compare __kc; 
    typename _SortedAssociativeContainer::value_compare __vc; 
    typename _SortedAssociativeContainer::value_type __t; 
    typename _SortedAssociativeContainer::key_type __k; 
    typedef typename _SortedAssociativeContainer::iterator _Iterator; 
    typedef typename _SortedAssociativeContainer::const_iterator 
      _Const_iterator; 
 
    _Iterator __p; 
    _Const_iterator __cp; 
    std::pair<_Iterator,_Iterator> __r; 
    std::pair<_Const_iterator,_Const_iterator> __cr; 
    typename _SortedAssociativeContainer::value_type *__first, *__last; 
  }; 
 
    // HashedAssociativeContainer 
 
} } // namespace __gnu_cxx 
 
#undef __attribute__ ((__unused__)) 
 
#endif #endif // _GLIBCXX_BOOST_CONCEPT_CHECK 
 
 
 
 
// Note that the obvious and elegant approach of 
// 
//#define glibcxx_function_requires(C) boost::function_requires< boost::C >() 
// 
// won't work due to concept templates with more than one parameter, e.g., 
// BinaryPredicateConcept.  The preprocessor tries to split things up on 
// the commas in the template argument list.  We can't use an inner pair of 
// parenthesis to hide the commas, because "boost::(Temp<Foo,Bar>)" isn't 
// a valid instantiation pattern.  Thus, we steal a feature from C99. 
 
            __gnu_cxx::__function_requires< __gnu_cxx::__VA_ARGS__ >(); 
            _GLIBCXX_CLASS_REQUIRES(_a, __gnu_cxx, _C); 
            _GLIBCXX_CLASS_REQUIRES2(_a, _b, __gnu_cxx, _C); 
            _GLIBCXX_CLASS_REQUIRES3(_a, _b, _c, __gnu_cxx, _C); 
            _GLIBCXX_CLASS_REQUIRES4(_a, _b, _c, _d, __gnu_cxx, _C); 
 
#endif #endif // enable/disable 
 
#endif #endif // _GLIBCXX_CONCEPT_CHECK 
 
 
namespace std 
{ 
  template<typename _InputIterator> 
    inline typename iterator_traits<_InputIterator>::difference_type 
    __distance(_InputIterator __first, _InputIterator __last, 
               input_iterator_tag) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>) 
 
      typename iterator_traits<_InputIterator>::difference_type __n = 0; 
      while (__first != __last) 
	{ 
	  ++__first; 
	  ++__n; 
	} 
      return __n; 
    } 
 
  template<typename _RandomAccessIterator> 
    inline typename iterator_traits<_RandomAccessIterator>::difference_type 
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last, 
               random_access_iterator_tag) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_RandomAccessIteratorConcept< 
				  _RandomAccessIterator>) 
      return __last - __first; 
    } 
 
  

  */ 
  template<typename _InputIterator> 
    inline typename iterator_traits<_InputIterator>::difference_type 
    distance(_InputIterator __first, _InputIterator __last) 
    { 
            // concept requirements -- taken care of in __distance 
      return std::__distance(__first, __last, 
			     std::__iterator_category(__first)); 
    } 
 
  template<typename _InputIterator, typename _Distance> 
    inline void 
    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>) 
      while (__n--) 
	++__i; 
    } 
 
  template<typename _BidirectionalIterator, typename _Distance> 
    inline void 
    __advance(_BidirectionalIterator& __i, _Distance __n, 
              bidirectional_iterator_tag) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_BidirectionalIteratorConcept< 
				  _BidirectionalIterator>) 
      if (__n > 0) 
        while (__n--) 
	  ++__i; 
      else 
        while (__n++) 
	  --__i; 
    } 
 
  template<typename _RandomAccessIterator, typename _Distance> 
    inline void 
    __advance(_RandomAccessIterator& __i, _Distance __n, 
              random_access_iterator_tag) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_RandomAccessIteratorConcept< 
				  _RandomAccessIterator>) 
      __i += __n; 
    } 
 
  

  */ 
  template<typename _InputIterator, typename _Distance> 
    inline void 
    advance(_InputIterator& __i, _Distance __n) 
    { 
            // concept requirements -- taken care of in __advance 
      std::__advance(__i, __n, std::__iterator_category(__i)); 
    } 
} } // namespace std 
 
#endif 
 
// Iterators -*- C++ -*- 
 
// Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 


 */ 
 
#ifndef _ITERATOR_H 
 
 
namespace std 
{ 
    // 24.4.1 Reverse iterators 
  

  */ 
  template<typename _Iterator> 
    class reverse_iterator 
    : public iterator<typename iterator_traits<_Iterator>::iterator_category, 
		      typename iterator_traits<_Iterator>::value_type, 
		      typename iterator_traits<_Iterator>::difference_type, 
		      typename iterator_traits<_Iterator>::pointer, 
                      typename iterator_traits<_Iterator>::reference> 
    { 
    protected: 
      _Iterator current; 
 
    public: 
      typedef _Iterator					       iterator_type; 
      typedef typename iterator_traits<_Iterator>::difference_type 
							       difference_type; 
      typedef typename iterator_traits<_Iterator>::reference   reference; 
      typedef typename iterator_traits<_Iterator>::pointer     pointer; 
 
    public: 
      

      */ 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 235 No specification of default ctor for reverse_iterator 
      reverse_iterator() : current() { } 
 
      

      */ 
      explicit 
      reverse_iterator(iterator_type __x) : current(__x) { } 
 
      

      */ 
      reverse_iterator(const reverse_iterator& __x) 
      : current(__x.current) { } 
 
      

      */ 
      template<typename _Iter> 
        reverse_iterator(const reverse_iterator<_Iter>& __x) 
	: current(__x.base()) { } 
 
      

      */ 
      iterator_type 
      base() const 
      { return current; } 
 
      

      */ 
      reference 
      operator*() const 
      { 
	_Iterator __tmp = current; 
	return *--__tmp; 
      } 
 
      

      */ 
      pointer 
      operator->() const 
      { return &(operator*()); } 
 
      

      */ 
      reverse_iterator& 
      operator++() 
      { 
	--current; 
	return *this; 
      } 
 
      

      */ 
      reverse_iterator 
      operator++(int) 
      { 
	reverse_iterator __tmp = *this; 
	--current; 
	return __tmp; 
      } 
 
      

      */ 
      reverse_iterator& 
      operator--() 
      { 
	++current; 
	return *this; 
      } 
 
      

      */ 
      reverse_iterator 
      operator--(int) 
      { 
	reverse_iterator __tmp = *this; 
	++current; 
	return __tmp; 
      } 
 
      

      */ 
      reverse_iterator 
      operator+(difference_type __n) const 
      { return reverse_iterator(current - __n); } 
 
      

      */ 
      reverse_iterator& 
      operator+=(difference_type __n) 
      { 
	current -= __n; 
	return *this; 
      } 
 
      

      */ 
      reverse_iterator 
      operator-(difference_type __n) const 
      { return reverse_iterator(current + __n); } 
 
      

      */ 
      reverse_iterator& 
      operator-=(difference_type __n) 
      { 
	current += __n; 
	return *this; 
      } 
 
      

      */ 
      reference 
      operator[](difference_type __n) const 
      { return *(*this + __n); } 
    }; 
 
    //@{ 
  

  */ 
  template<typename _Iterator> 
    inline bool 
    operator==(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return __x.base() == __y.base(); } 
 
  template<typename _Iterator> 
    inline bool 
    operator<(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y.base() < __x.base(); } 
 
  template<typename _Iterator> 
    inline bool 
    operator!=(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return !(__x == __y); } 
 
  template<typename _Iterator> 
    inline bool 
    operator>(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y < __x; } 
 
  template<typename _Iterator> 
    inline bool 
    operator<=(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return !(__y < __x); } 
 
  template<typename _Iterator> 
    inline bool 
    operator>=(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return !(__x < __y); } 
 
  template<typename _Iterator> 
    inline typename reverse_iterator<_Iterator>::difference_type 
    operator-(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y.base() - __x.base(); } 
 
  template<typename _Iterator> 
    inline reverse_iterator<_Iterator> 
    operator+(typename reverse_iterator<_Iterator>::difference_type __n, 
	      const reverse_iterator<_Iterator>& __x) 
    { return reverse_iterator<_Iterator>(__x.base() - __n); } 
 
    // _GLIBCXX_RESOLVE_LIB_DEFECTS 
    // DR 280. Comparison of reverse_iterator to const reverse_iterator. 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator==(const reverse_iterator<_IteratorL>& __x, 
	       const reverse_iterator<_IteratorR>& __y) 
    { return __x.base() == __y.base(); } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator<(const reverse_iterator<_IteratorL>& __x, 
	      const reverse_iterator<_IteratorR>& __y) 
    { return __y.base() < __x.base(); } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator!=(const reverse_iterator<_IteratorL>& __x, 
	       const reverse_iterator<_IteratorR>& __y) 
    { return !(__x == __y); } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator>(const reverse_iterator<_IteratorL>& __x, 
	      const reverse_iterator<_IteratorR>& __y) 
    { return __y < __x; } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator<=(const reverse_iterator<_IteratorL>& __x, 
	       const reverse_iterator<_IteratorR>& __y) 
    { return !(__y < __x); } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline bool 
    operator>=(const reverse_iterator<_IteratorL>& __x, 
	       const reverse_iterator<_IteratorR>& __y) 
    { return !(__x < __y); } 
 
  template<typename _IteratorL, typename _IteratorR> 
    inline typename reverse_iterator<_IteratorL>::difference_type 
    operator-(const reverse_iterator<_IteratorL>& __x, 
	      const reverse_iterator<_IteratorR>& __y) 
    { return __y.base() - __x.base(); } 
    //@} 
 
    // 24.4.2.2.1 back_insert_iterator 
  

  */ 
  template<typename _Container> 
    class back_insert_iterator 
    : public iterator<output_iterator_tag, void, void, void, void> 
    { 
    protected: 
      _Container* container; 
 
    public: 
            /// A nested typedef for the type of whatever container you used. 
      typedef _Container          container_type; 
 
            /// The only way to create this %iterator is with a container. 
      explicit 
      back_insert_iterator(_Container& __x) : container(&__x) { } 
 
      

      */ 
      back_insert_iterator& 
      operator=(typename _Container::const_reference __value) 
      { 
	container->push_back(__value); 
	return *this; 
      } 
 
            /// Simply returns *this. 
      back_insert_iterator& 
      operator*() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      back_insert_iterator& 
      operator++() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      back_insert_iterator 
      operator++(int) 
      { return *this; } 
    }; 
 
  

  */ 
  template<typename _Container> 
    inline back_insert_iterator<_Container> 
    back_inserter(_Container& __x) 
    { return back_insert_iterator<_Container>(__x); } 
 
  

  */ 
  template<typename _Container> 
    class front_insert_iterator 
    : public iterator<output_iterator_tag, void, void, void, void> 
    { 
    protected: 
      _Container* container; 
 
    public: 
            /// A nested typedef for the type of whatever container you used. 
      typedef _Container          container_type; 
 
            /// The only way to create this %iterator is with a container. 
      explicit front_insert_iterator(_Container& __x) : container(&__x) { } 
 
      

      */ 
      front_insert_iterator& 
      operator=(typename _Container::const_reference __value) 
      { 
	container->push_front(__value); 
	return *this; 
      } 
 
            /// Simply returns *this. 
      front_insert_iterator& 
      operator*() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      front_insert_iterator& 
      operator++() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      front_insert_iterator 
      operator++(int) 
      { return *this; } 
    }; 
 
  

  */ 
  template<typename _Container> 
    inline front_insert_iterator<_Container> 
    front_inserter(_Container& __x) 
    { return front_insert_iterator<_Container>(__x); } 
 
  

  */ 
  template<typename _Container> 
    class insert_iterator 
    : public iterator<output_iterator_tag, void, void, void, void> 
    { 
    protected: 
      _Container* container; 
      typename _Container::iterator iter; 
 
    public: 
            /// A nested typedef for the type of whatever container you used. 
      typedef _Container          container_type; 
 
      

      */ 
      insert_iterator(_Container& __x, typename _Container::iterator __i) 
      : container(&__x), iter(__i) {} 
 
      

      */ 
      insert_iterator& 
      operator=(const typename _Container::const_reference __value) 
      { 
	iter = container->insert(iter, __value); 
	++iter; 
	return *this; 
      } 
 
            /// Simply returns *this. 
      insert_iterator& 
      operator*() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      insert_iterator& 
      operator++() 
      { return *this; } 
 
            /// Simply returns *this.  (This %iterator does not "move".) 
      insert_iterator& 
      operator++(int) 
      { return *this; } 
    }; 
 
  

  */ 
  template<typename _Container, typename _Iterator> 
    inline insert_iterator<_Container> 
    inserter(_Container& __x, _Iterator __i) 
    { 
      return insert_iterator<_Container>(__x, 
					 typename _Container::iterator(__i)); 
    } 
} } // namespace std 
 
namespace __gnu_cxx 
{ 
    // This iterator adapter is 'normal' in the sense that it does not 
    // change the semantics of any of the operators of its iterator 
    // parameter.  Its primary purpose is to convert an iterator that is 
    // not a class, e.g. a pointer, into an iterator that is a class. 
    // The _Container parameter exists solely so that different containers 
    // using this template can instantiate different types, even if the 
    // _Iterator parameter is the same. 
  using std::iterator_traits; 
  using std::iterator; 
  template<typename _Iterator, typename _Container> 
    class __normal_iterator 
    { 
    protected: 
      _Iterator _M_current; 
 
    public: 
      typedef typename iterator_traits<_Iterator>::iterator_category 
                                                             iterator_category; 
      typedef typename iterator_traits<_Iterator>::value_type  value_type; 
      typedef typename iterator_traits<_Iterator>::difference_type 
                                                             difference_type; 
      typedef typename iterator_traits<_Iterator>::reference reference; 
      typedef typename iterator_traits<_Iterator>::pointer   pointer; 
 
      __normal_iterator() : _M_current(_Iterator()) { } 
 
      explicit 
      __normal_iterator(const _Iterator& __i) : _M_current(__i) { } 
 
            // Allow iterator to const_iterator conversion 
      template<typename _Iter> 
        __normal_iterator(const __normal_iterator<_Iter, 
			  typename std::__enable_if<_Container, 
			  (std::__are_same<_Iter, 
			   typename _Container::pointer>::__value) 
			  >::__type>& __i) 
        : _M_current(__i.base()) { } 
 
            // Forward iterator requirements 
      reference 
      operator*() const 
      { return *_M_current; } 
 
      pointer 
      operator->() const 
      { return _M_current; } 
 
      __normal_iterator& 
      operator++() 
      { 
	++_M_current; 
	return *this; 
      } 
 
      __normal_iterator 
      operator++(int) 
      { return __normal_iterator(_M_current++); } 
 
            // Bidirectional iterator requirements 
      __normal_iterator& 
      operator--() 
      { 
	--_M_current; 
	return *this; 
      } 
 
      __normal_iterator 
      operator--(int) 
      { return __normal_iterator(_M_current--); } 
 
            // Random access iterator requirements 
      reference 
      operator[](const difference_type& __n) const 
      { return _M_current[__n]; } 
 
      __normal_iterator& 
      operator+=(const difference_type& __n) 
      { _M_current += __n; return *this; } 
 
      __normal_iterator 
      operator+(const difference_type& __n) const 
      { return __normal_iterator(_M_current + __n); } 
 
      __normal_iterator& 
      operator-=(const difference_type& __n) 
      { _M_current -= __n; return *this; } 
 
      __normal_iterator 
      operator-(const difference_type& __n) const 
      { return __normal_iterator(_M_current - __n); } 
 
      const _Iterator& 
      base() const 
      { return _M_current; } 
    }; 
 
    // Note: In what follows, the left- and right-hand-side iterators are 
    // allowed to vary in types (conceptually in cv-qualification) so that 
    // comparaison between cv-qualified and non-cv-qualified iterators be 
    // valid.  However, the greedy and unfriendly operators in std::rel_ops 
    // will make overload resolution ambiguous (when in scope) if we don't 
    // provide overloads whose operands are of the same type.  Can someone 
    // remind me what generic programming is about? -- Gaby 
 
    // Forward iterator requirements 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator==(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	       const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() == __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator==(const __normal_iterator<_Iterator, _Container>& __lhs, 
	       const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() == __rhs.base(); } 
 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	       const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() != __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator!=(const __normal_iterator<_Iterator, _Container>& __lhs, 
	       const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() != __rhs.base(); } 
 
    // Random access iterator requirements 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator<(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	      const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() < __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator<(const __normal_iterator<_Iterator, _Container>& __lhs, 
	      const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() < __rhs.base(); } 
 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator>(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	      const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() > __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator>(const __normal_iterator<_Iterator, _Container>& __lhs, 
	      const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() > __rhs.base(); } 
 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	       const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() <= __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator<=(const __normal_iterator<_Iterator, _Container>& __lhs, 
	       const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() <= __rhs.base(); } 
 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline bool 
    operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	       const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() >= __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline bool 
    operator>=(const __normal_iterator<_Iterator, _Container>& __lhs, 
	       const __normal_iterator<_Iterator, _Container>& __rhs) 
    { return __lhs.base() >= __rhs.base(); } 
 
    // _GLIBCXX_RESOLVE_LIB_DEFECTS 
    // According to the resolution of DR179 not only the various comparison 
    // operators but also operator- must accept mixed iterator/const_iterator 
    // parameters. 
  template<typename _IteratorL, typename _IteratorR, typename _Container> 
    inline typename __normal_iterator<_IteratorL, _Container>::difference_type 
    operator-(const __normal_iterator<_IteratorL, _Container>& __lhs, 
	      const __normal_iterator<_IteratorR, _Container>& __rhs) 
    { return __lhs.base() - __rhs.base(); } 
 
  template<typename _Iterator, typename _Container> 
    inline __normal_iterator<_Iterator, _Container> 
    operator+(typename __normal_iterator<_Iterator, _Container>::difference_type 
	      __n, const __normal_iterator<_Iterator, _Container>& __i) 
    { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); } 
} } // namespace __gnu_cxx 
 
#endif 
 
// Local Variables: 
// mode:C++ 
// End: 
 
#ifndef _SEPOL_DEBUG_H_ 
 
#ifndef _SEPOL_HANDLE_H_ 
 
struct sepol_handle; 
typedef struct sepol_handle sepol_handle_t; 
 


 * not disable dontaudits, 1 disables them */ 
void sepol_set_disable_dontaudit(sepol_handle_t * sh, int disable_dontaudit); 
 

 
 


/* End deprecated */ 
 
 
extern int sepol_msg_get_level(sepol_handle_t * handle); 
 
extern const char *sepol_msg_get_channel(sepol_handle_t * handle); 
 
extern const char *sepol_msg_get_fname(sepol_handle_t * handle); 
 


 * indicates that messaging should be suppressed */ 
extern void sepol_msg_set_callback(sepol_handle_t * handle, 
#ifdef __GNUC__ 
				   __attribute__ ((format(printf, 3, 4))) 
#endif 
				   void (*msg_callback) (void *varg, 
							 sepol_handle_t * 
							 handle, 
							 const char *fmt, ...), 
				   void *msg_callback_arg); 
#endif 
 
 
namespace std 
{ 
 
  

  */ 
  template<typename _Tp> 
    inline void 
    swap(_Tp& __a, _Tp& __b) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_SGIAssignableConcept<_Tp>) 
 
      _Tp __tmp = __a; 
      __a = __b; 
      __b = __tmp; 
    } 
 
    // See http://gcc.gnu.org/ml/libstdc++/2004-08/msg00167.html: in a 
    // nutshell, we are partially implementing the resolution of DR 187, 
    // when it's safe, i.e., the value_types are equal. 
  template<bool _BoolType> 
    struct __iter_swap 
    { 
      template<typename _ForwardIterator1, typename _ForwardIterator2> 
        static void 
        iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
        { 
          typedef typename iterator_traits<_ForwardIterator1>::value_type 
            _ValueType1; 
          _ValueType1 __tmp = *__a; 
          *__a = *__b; 
          *__b = __tmp;  
	} 
    }; 
 
  template<> 
    struct __iter_swap<true> 
    { 
      template<typename _ForwardIterator1, typename _ForwardIterator2> 
        static void  
        iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
        { 
          swap(*__a, *__b); 
        } 
    }; 
 
  

  */ 
  template<typename _ForwardIterator1, typename _ForwardIterator2> 
    inline void 
    iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
    { 
      typedef typename iterator_traits<_ForwardIterator1>::value_type 
	_ValueType1; 
      typedef typename iterator_traits<_ForwardIterator2>::value_type 
	_ValueType2; 
 
            // concept requirements 
      __glibcxx_function_requires(_Mutable_ForwardIteratorConcept< 
				  _ForwardIterator1>) 
      __glibcxx_function_requires(_Mutable_ForwardIteratorConcept< 
				  _ForwardIterator2>) 
      __glibcxx_function_requires(_ConvertibleConcept<_ValueType1, 
				  _ValueType2>) 
      __glibcxx_function_requires(_ConvertibleConcept<_ValueType2, 
				  _ValueType1>) 
 
      typedef typename iterator_traits<_ForwardIterator1>::reference 
	_ReferenceType1; 
      typedef typename iterator_traits<_ForwardIterator2>::reference 
	_ReferenceType2; 
      std::__iter_swap<__are_same<_ValueType1, _ValueType2>::__value && 
	__are_same<_ValueType1 &, _ReferenceType1>::__value && 
	__are_same<_ValueType2 &, _ReferenceType2>::__value>:: 
	iter_swap(__a, __b); 
    } 
 
  #undef min 
  #undef max 
 
  

  */ 
  template<typename _Tp> 
    inline const _Tp& 
    min(const _Tp& __a, const _Tp& __b) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_LessThanComparableConcept<_Tp>) 
            //return __b < __a ? __b : __a; 
      if (__b < __a) 
	return __b; 
      return __a; 
    } 
 
  

  */ 
  template<typename _Tp> 
    inline const _Tp& 
    max(const _Tp& __a, const _Tp& __b) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_LessThanComparableConcept<_Tp>) 
            //return  __a < __b ? __b : __a; 
      if (__a < __b) 
	return __b; 
      return __a; 
    } 
 
  

  */ 
  template<typename _Tp, typename _Compare> 
    inline const _Tp& 
    min(const _Tp& __a, const _Tp& __b, _Compare __comp) 
    { 
            //return __comp(__b, __a) ? __b : __a; 
      if (__comp(__b, __a)) 
	return __b; 
      return __a; 
    } 
 
  

  */ 
  template<typename _Tp, typename _Compare> 
    inline const _Tp& 
    max(const _Tp& __a, const _Tp& __b, _Compare __comp) 
    { 
            //return __comp(__a, __b) ? __b : __a; 
      if (__comp(__a, __b)) 
	return __b; 
      return __a; 
    } 
 
    // All of these auxiliary structs serve two purposes.  (1) Replace 
    // calls to copy with memmove whenever possible.  (Memmove, not memcpy, 
    // because the input and output ranges are permitted to overlap.) 
    // (2) If we're using random access iterators, then write the loop as 
    // a for loop with an explicit count. 
 
  template<bool, typename> 
    struct __copy 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy(_II __first, _II __last, _OI __result) 
        { 
	  for (; __first != __last; ++__result, ++__first) 
	    *__result = *__first; 
	  return __result; 
	} 
    }; 
 
  template<bool _BoolType> 
    struct __copy<_BoolType, random_access_iterator_tag> 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy(_II __first, _II __last, _OI __result) 
        {  
	  typedef typename iterator_traits<_II>::difference_type _Distance; 
	  for(_Distance __n = __last - __first; __n > 0; --__n) 
	    { 
	      *__result = *__first; 
	      ++__first; 
	      ++__result; 
	    } 
	  return __result; 
	} 
    }; 
 
  template<> 
    struct __copy<true, random_access_iterator_tag> 
    { 
      template<typename _Tp> 
        static _Tp* 
        copy(const _Tp* __first, const _Tp* __last, _Tp* __result) 
        {  
	  std::memmove(__result, __first, sizeof(_Tp) * (__last - __first)); 
	  return __result + (__last - __first); 
	} 
    }; 
 
  template<typename _II, typename _OI> 
    inline _OI 
    __copy_aux(_II __first, _II __last, _OI __result) 
    { 
      typedef typename iterator_traits<_II>::value_type _ValueTypeI; 
      typedef typename iterator_traits<_OI>::value_type _ValueTypeO; 
      typedef typename iterator_traits<_II>::iterator_category _Category; 
      const bool __simple = (__is_scalar<_ValueTypeI>::__value 
	                     && __is_pointer<_II>::__value 
	                     && __is_pointer<_OI>::__value 
			     && __are_same<_ValueTypeI, _ValueTypeO>::__value); 
 
      return std::__copy<__simple, _Category>::copy(__first, __last, __result); 
    } 
 
  template<bool, bool> 
    struct __copy_normal 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy_n(_II __first, _II __last, _OI __result) 
        { return std::__copy_aux(__first, __last, __result); } 
    }; 
 
  template<> 
    struct __copy_normal<true, false> 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy_n(_II __first, _II __last, _OI __result) 
        { return std::__copy_aux(__first.base(), __last.base(), __result); } 
    }; 
 
  template<> 
    struct __copy_normal<false, true> 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy_n(_II __first, _II __last, _OI __result) 
        { return _OI(std::__copy_aux(__first, __last, __result.base())); } 
    }; 
 
  template<> 
    struct __copy_normal<true, true> 
    { 
      template<typename _II, typename _OI> 
        static _OI 
        copy_n(_II __first, _II __last, _OI __result) 
        { return _OI(std::__copy_aux(__first.base(), __last.base(), 
				     __result.base())); } 
    }; 
 
  

  */ 
  template<typename _InputIterator, typename _OutputIterator> 
    inline _OutputIterator 
    copy(_InputIterator __first, _InputIterator __last, 
	 _OutputIterator __result) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>) 
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator, 
	    typename iterator_traits<_InputIterator>::value_type>) 
      __glibcxx_requires_valid_range(__first, __last); 
 
       const bool __in = __is_normal_iterator<_InputIterator>::__value; 
       const bool __out = __is_normal_iterator<_OutputIterator>::__value; 
       return std::__copy_normal<__in, __out>::copy_n(__first, __last, 
						      __result); 
    } 
   
  template<bool, typename> 
    struct __copy_backward 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b(_BI1 __first, _BI1 __last, _BI2 __result) 
        {  
	  while (__first != __last) 
	    *--__result = *--__last; 
	  return __result; 
	} 
    }; 
 
  template<bool _BoolType> 
    struct __copy_backward<_BoolType, random_access_iterator_tag> 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b(_BI1 __first, _BI1 __last, _BI2 __result) 
        {  
	  typename iterator_traits<_BI1>::difference_type __n; 
	  for (__n = __last - __first; __n > 0; --__n) 
	    *--__result = *--__last; 
	  return __result; 
	} 
    }; 
 
  template<> 
    struct __copy_backward<true, random_access_iterator_tag> 
    { 
      template<typename _Tp> 
        static _Tp* 
        copy_b(const _Tp* __first, const _Tp* __last, _Tp* __result) 
        {  
	  const ptrdiff_t _Num = __last - __first; 
	  std::memmove(__result - _Num, __first, sizeof(_Tp) * _Num); 
	  return __result - _Num; 
	} 
    }; 
 
  template<typename _BI1, typename _BI2> 
    inline _BI2 
    __copy_backward_aux(_BI1 __first, _BI1 __last, _BI2 __result) 
    { 
      typedef typename iterator_traits<_BI1>::value_type _ValueType1; 
      typedef typename iterator_traits<_BI2>::value_type _ValueType2; 
      typedef typename iterator_traits<_BI1>::iterator_category _Category; 
      const bool __simple = (__is_scalar<_ValueType1>::__value 
	                     && __is_pointer<_BI1>::__value 
	                     && __is_pointer<_BI2>::__value 
			     && __are_same<_ValueType1, _ValueType2>::__value); 
 
      return std::__copy_backward<__simple, _Category>::copy_b(__first, __last, 
							       __result); 
    } 
 
  template<bool, bool> 
    struct __copy_backward_normal 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b_n(_BI1 __first, _BI1 __last, _BI2 __result) 
        { return std::__copy_backward_aux(__first, __last, __result); } 
    }; 
 
  template<> 
    struct __copy_backward_normal<true, false> 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b_n(_BI1 __first, _BI1 __last, _BI2 __result) 
        { return std::__copy_backward_aux(__first.base(), __last.base(), 
					  __result); } 
    }; 
 
  template<> 
    struct __copy_backward_normal<false, true> 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b_n(_BI1 __first, _BI1 __last, _BI2 __result) 
        { return _BI2(std::__copy_backward_aux(__first, __last, 
					       __result.base())); } 
    }; 
 
  template<> 
    struct __copy_backward_normal<true, true> 
    { 
      template<typename _BI1, typename _BI2> 
        static _BI2 
        copy_b_n(_BI1 __first, _BI1 __last, _BI2 __result) 
        { return _BI2(std::__copy_backward_aux(__first.base(), __last.base(), 
					       __result.base())); } 
    }; 
 
  

  */ 
  template <typename _BI1, typename _BI2> 
    inline _BI2 
    copy_backward(_BI1 __first, _BI1 __last, _BI2 __result) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_BidirectionalIteratorConcept<_BI1>) 
      __glibcxx_function_requires(_Mutable_BidirectionalIteratorConcept<_BI2>) 
      __glibcxx_function_requires(_ConvertibleConcept< 
	    typename iterator_traits<_BI1>::value_type, 
	    typename iterator_traits<_BI2>::value_type>) 
      __glibcxx_requires_valid_range(__first, __last); 
 
      const bool __bi1 = __is_normal_iterator<_BI1>::__value; 
      const bool __bi2 = __is_normal_iterator<_BI2>::__value; 
      return std::__copy_backward_normal<__bi1, __bi2>::copy_b_n(__first, __last, 
								 __result); 
    } 
 
  template<bool> 
    struct __fill 
    { 
      template<typename _ForwardIterator, typename _Tp> 
        static void 
        fill(_ForwardIterator __first, _ForwardIterator __last, 
	     const _Tp& __value) 
        { 
	  for (; __first != __last; ++__first) 
	    *__first = __value; 
	} 
    }; 
 
  template<> 
    struct __fill<true> 
    { 
      template<typename _ForwardIterator, typename _Tp> 
        static void 
        fill(_ForwardIterator __first, _ForwardIterator __last, 
	     const _Tp& __value) 
        { 
	  const _Tp __tmp = __value; 
	  for (; __first != __last; ++__first) 
	    *__first = __tmp; 
	} 
    }; 
 
  

  */ 
  template<typename _ForwardIterator, typename _Tp> 
    void 
    fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_Mutable_ForwardIteratorConcept< 
				  _ForwardIterator>) 
      __glibcxx_requires_valid_range(__first, __last); 
 
      const bool __scalar = __is_scalar<_Tp>::__value; 
      std::__fill<__scalar>::fill(__first, __last, __value); 
    } 
 
    // Specialization: for one-byte types we can use memset. 
  inline void 
  fill(unsigned char* __first, unsigned char* __last, const unsigned char& __c) 
  { 
    __glibcxx_requires_valid_range(__first, __last); 
    const unsigned char __tmp = __c; 
    std::memset(__first, __tmp, __last - __first); 
  } 
 
  inline void 
  fill(signed char* __first, signed char* __last, const signed char& __c) 
  { 
    __glibcxx_requires_valid_range(__first, __last); 
    const signed char __tmp = __c; 
    std::memset(__first, static_cast<unsigned char>(__tmp), __last - __first); 
  } 
 
  inline void 
  fill(char* __first, char* __last, const char& __c) 
  { 
    __glibcxx_requires_valid_range(__first, __last); 
    const char __tmp = __c; 
    std::memset(__first, static_cast<unsigned char>(__tmp), __last - __first); 
  } 
 
  template<bool> 
    struct __fill_n 
    { 
      template<typename _OutputIterator, typename _Size, typename _Tp> 
        static _OutputIterator 
        fill_n(_OutputIterator __first, _Size __n, const _Tp& __value) 
        { 
	  for (; __n > 0; --__n, ++__first) 
	    *__first = __value; 
	  return __first; 
	} 
    }; 
 
  template<> 
    struct __fill_n<true> 
    { 
      template<typename _OutputIterator, typename _Size, typename _Tp> 
        static _OutputIterator 
        fill_n(_OutputIterator __first, _Size __n, const _Tp& __value) 
        { 
	  const _Tp __tmp = __value; 
	  for (; __n > 0; --__n, ++__first) 
	    *__first = __tmp; 
	  return __first;	   
	} 
    }; 
 
  

  */ 
  template<typename _OutputIterator, typename _Size, typename _Tp> 
    _OutputIterator 
    fill_n(_OutputIterator __first, _Size __n, const _Tp& __value) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator, _Tp>) 
 
      const bool __scalar = __is_scalar<_Tp>::__value; 
      return std::__fill_n<__scalar>::fill_n(__first, __n, __value); 
    } 
 
  template<typename _Size> 
    inline unsigned char* 
    fill_n(unsigned char* __first, _Size __n, const unsigned char& __c) 
    { 
      std::fill(__first, __first + __n, __c); 
      return __first + __n; 
    } 
 
  template<typename _Size> 
    inline signed char* 
    fill_n(char* __first, _Size __n, const signed char& __c) 
    { 
      std::fill(__first, __first + __n, __c); 
      return __first + __n; 
    } 
 
  template<typename _Size> 
    inline char* 
    fill_n(char* __first, _Size __n, const char& __c) 
    { 
      std::fill(__first, __first + __n, __c); 
      return __first + __n; 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2> 
    pair<_InputIterator1, _InputIterator2> 
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1, 
	     _InputIterator2 __first2) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_function_requires(_EqualOpConcept< 
	    typename iterator_traits<_InputIterator1>::value_type, 
	    typename iterator_traits<_InputIterator2>::value_type>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
 
      while (__first1 != __last1 && *__first1 == *__first2) 
        { 
	  ++__first1; 
	  ++__first2; 
        } 
      return pair<_InputIterator1, _InputIterator2>(__first1, __first2); 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2, 
	   typename _BinaryPredicate> 
    pair<_InputIterator1, _InputIterator2> 
    mismatch(_InputIterator1 __first1, _InputIterator1 __last1, 
	     _InputIterator2 __first2, _BinaryPredicate __binary_pred) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
 
      while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) 
        { 
	  ++__first1; 
	  ++__first2; 
        } 
      return pair<_InputIterator1, _InputIterator2>(__first1, __first2); 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2> 
    inline bool 
    equal(_InputIterator1 __first1, _InputIterator1 __last1, 
	  _InputIterator2 __first2) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_function_requires(_EqualOpConcept< 
	    typename iterator_traits<_InputIterator1>::value_type, 
	    typename iterator_traits<_InputIterator2>::value_type>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
       
      for (; __first1 != __last1; ++__first1, ++__first2) 
	if (!(*__first1 == *__first2)) 
	  return false; 
      return true; 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2, 
	   typename _BinaryPredicate> 
    inline bool 
    equal(_InputIterator1 __first1, _InputIterator1 __last1, 
	  _InputIterator2 __first2, 
	  _BinaryPredicate __binary_pred) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
 
      for (; __first1 != __last1; ++__first1, ++__first2) 
	if (!__binary_pred(*__first1, *__first2)) 
	  return false; 
      return true; 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2> 
    bool 
    lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1, 
			    _InputIterator2 __first2, _InputIterator2 __last2) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_function_requires(_LessThanOpConcept< 
	    typename iterator_traits<_InputIterator1>::value_type, 
	    typename iterator_traits<_InputIterator2>::value_type>) 
      __glibcxx_function_requires(_LessThanOpConcept< 
	    typename iterator_traits<_InputIterator2>::value_type, 
	    typename iterator_traits<_InputIterator1>::value_type>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
      __glibcxx_requires_valid_range(__first2, __last2); 
 
      for (; __first1 != __last1 && __first2 != __last2; 
	   ++__first1, ++__first2) 
	{ 
	  if (*__first1 < *__first2) 
	    return true; 
	  if (*__first2 < *__first1) 
	    return false; 
	} 
      return __first1 == __last1 && __first2 != __last2; 
    } 
 
  

  */ 
  template<typename _InputIterator1, typename _InputIterator2, 
	   typename _Compare> 
    bool 
    lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1, 
			    _InputIterator2 __first2, _InputIterator2 __last2, 
			    _Compare __comp) 
    { 
            // concept requirements 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>) 
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>) 
      __glibcxx_requires_valid_range(__first1, __last1); 
      __glibcxx_requires_valid_range(__first2, __last2); 
 
      for (; __first1 != __last1 && __first2 != __last2; 
	   ++__first1, ++__first2) 
	{ 
	  if (__comp(*__first1, *__first2)) 
	    return true; 
	  if (__comp(*__first2, *__first1)) 
	    return false; 
	} 
      return __first1 == __last1 && __first2 != __last2; 
    } 
 
  inline bool 
  lexicographical_compare(const unsigned char* __first1, 
			  const unsigned char* __last1, 
			  const unsigned char* __first2, 
			  const unsigned char* __last2) 
  { 
    __glibcxx_requires_valid_range(__first1, __last1); 
    __glibcxx_requires_valid_range(__first2, __last2); 
 
    const size_t __len1 = __last1 - __first1; 
    const size_t __len2 = __last2 - __first2; 
    const int __result = std::memcmp(__first1, __first2, 
				     std::min(__len1, __len2)); 
    return __result != 0 ? __result < 0 : __len1 < __len2; 
  } 
 
  inline bool 
  lexicographical_compare(const char* __first1, const char* __last1, 
			  const char* __first2, const char* __last2) 
  { 
    __glibcxx_requires_valid_range(__first1, __last1); 
    __glibcxx_requires_valid_range(__first2, __last2); 
 
#if CHAR_MAX == SCHAR_MAX 
    return std::lexicographical_compare((const signed char*) __first1, 
					(const signed char*) __last1, 
					(const signed char*) __first2, 
					(const signed char*) __last2); 
#else 

#endif /* CHAR_MAX == SCHAR_MAX */ 
  } 
 
} } // namespace std 
 
#endif 
 
#include <bits/postypes.h>     
namespace __gnu_cxx 
{ 
  

   *  while leaving __gnu_cxx::char_traits alone. */ 
  template <class _CharT> 
    struct _Char_types 
    { 
      typedef unsigned long   int_type; 
      typedef std::streampos  pos_type; 
      typedef std::streamoff  off_type; 
      typedef std::mbstate_t  state_type; 
    }; 
 
 
  

   */ 
  template<typename _CharT> 
    struct char_traits 
    { 
      typedef _CharT                                    char_type; 
      typedef typename _Char_types<_CharT>::int_type    int_type; 
      typedef typename _Char_types<_CharT>::pos_type    pos_type; 
      typedef typename _Char_types<_CharT>::off_type    off_type; 
      typedef typename _Char_types<_CharT>::state_type  state_type; 
 
      static void 
      assign(char_type& __c1, const char_type& __c2) 
      { __c1 = __c2; } 
 
      static bool 
      eq(const char_type& __c1, const char_type& __c2) 
      { return __c1 == __c2; } 
 
      static bool 
      lt(const char_type& __c1, const char_type& __c2) 
      { return __c1 < __c2; } 
 
      static int 
      compare(const char_type* __s1, const char_type* __s2, std::size_t __n); 
 
      static std::size_t 
      length(const char_type* __s); 
 
      static const char_type* 
      find(const char_type* __s, std::size_t __n, const char_type& __a); 
 
      static char_type* 
      move(char_type* __s1, const char_type* __s2, std::size_t __n); 
 
      static char_type* 
      copy(char_type* __s1, const char_type* __s2, std::size_t __n); 
 
      static char_type* 
      assign(char_type* __s, std::size_t __n, char_type __a); 
 
      static char_type 
      to_char_type(const int_type& __c) 
      { return static_cast<char_type>(__c); } 
 
      static int_type 
      to_int_type(const char_type& __c) 
      { return static_cast<int_type>(__c); } 
 
      static bool 
      eq_int_type(const int_type& __c1, const int_type& __c2) 
      { return __c1 == __c2; } 
 
      static int_type 
      eof() 
      { return static_cast<int_type>(EOF); } 
 
      static int_type 
      not_eof(const int_type& __c) 
      { return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type()); } 
    }; 
 
  template<typename _CharT> 
    int 
    char_traits<_CharT>:: 
    compare(const char_type* __s1, const char_type* __s2, std::size_t __n) 
    { 
      for (size_t __i = 0; __i < __n; ++__i) 
	if (lt(__s1[__i], __s2[__i])) 
	  return -1; 
	else if (lt(__s2[__i], __s1[__i])) 
	  return 1; 
      return 0; 
    } 
 
  template<typename _CharT> 
    std::size_t 
    char_traits<_CharT>:: 
    length(const char_type* __p) 
    { 
      std::size_t __i = 0; 
      while (!eq(__p[__i], char_type())) 
        ++__i; 
      return __i; 
    } 
 
  template<typename _CharT> 
    const typename char_traits<_CharT>::char_type* 
    char_traits<_CharT>:: 
    find(const char_type* __s, std::size_t __n, const char_type& __a) 
    { 
      for (std::size_t __i = 0; __i < __n; ++__i) 
        if (eq(__s[__i], __a)) 
          return __s + __i; 
      return 0; 
    } 
 
  template<typename _CharT> 
    typename char_traits<_CharT>::char_type* 
    char_traits<_CharT>:: 
    move(char_type* __s1, const char_type* __s2, std::size_t __n) 
    { 
      return static_cast<_CharT*>(std::memmove(__s1, __s2, 
					       __n * sizeof(char_type))); 
    } 
 
  template<typename _CharT> 
    typename char_traits<_CharT>::char_type* 
    char_traits<_CharT>:: 
    copy(char_type* __s1, const char_type* __s2, std::size_t __n) 
    { 
      std::copy(__s2, __s2 + __n, __s1); 
      return __s1; 
    } 
 
  template<typename _CharT> 
    typename char_traits<_CharT>::char_type* 
    char_traits<_CharT>:: 
    assign(char_type* __s, std::size_t __n, char_type __a) 
    { 
      std::fill_n(__s, __n, __a); 
      return __s; 
    } 
} 
 
namespace std 
{ 
    // 21.1 
  

  */ 
  template<class _CharT> 
    struct char_traits : public __gnu_cxx::char_traits<_CharT> 
    { }; 
 
 
    /// @brief  21.1.3.1  char_traits specializations 
  template<> 
    struct char_traits<char> 
    { 
      typedef char              char_type; 
      typedef int               int_type; 
      typedef streampos         pos_type; 
      typedef streamoff         off_type; 
      typedef mbstate_t         state_type; 
 
      static void 
      assign(char_type& __c1, const char_type& __c2) 
      { __c1 = __c2; } 
 
      static bool 
      eq(const char_type& __c1, const char_type& __c2) 
      { return __c1 == __c2; } 
 
      static bool 
      lt(const char_type& __c1, const char_type& __c2) 
      { return __c1 < __c2; } 
 
      static int 
      compare(const char_type* __s1, const char_type* __s2, size_t __n) 
      { return memcmp(__s1, __s2, __n); } 
 
      static size_t 
      length(const char_type* __s) 
      { return strlen(__s); } 
 
      static const char_type* 
      find(const char_type* __s, size_t __n, const char_type& __a) 
      { return static_cast<const char_type*>(memchr(__s, __a, __n)); } 
 
      static char_type* 
      move(char_type* __s1, const char_type* __s2, size_t __n) 
      { return static_cast<char_type*>(memmove(__s1, __s2, __n)); } 
 
      static char_type* 
      copy(char_type* __s1, const char_type* __s2, size_t __n) 
      { return static_cast<char_type*>(memcpy(__s1, __s2, __n)); } 
 
      static char_type* 
      assign(char_type* __s, size_t __n, char_type __a) 
      { return static_cast<char_type*>(memset(__s, __a, __n)); } 
 
      static char_type 
      to_char_type(const int_type& __c) 
      { return static_cast<char_type>(__c); } 
 
            // To keep both the byte 0xff and the eof symbol 0xffffffff 
            // from ending up as 0xffffffff. 
      static int_type 
      to_int_type(const char_type& __c) 
      { return static_cast<int_type>(static_cast<unsigned char>(__c)); } 
 
      static bool 
      eq_int_type(const int_type& __c1, const int_type& __c2) 
      { return __c1 == __c2; } 
 
      static int_type 
      eof() { return static_cast<int_type>(EOF); } 
 
      static int_type 
      not_eof(const int_type& __c) 
      { return (__c == eof()) ? 0 : __c; } 
  }; 
 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
    /// @brief  21.1.3.2  char_traits specializations 
  template<> 
    struct char_traits<wchar_t> 
    { 
      typedef wchar_t           char_type; 
      typedef wint_t            int_type; 
      typedef streamoff         off_type; 
      typedef wstreampos        pos_type; 
      typedef mbstate_t         state_type; 
 
      static void 
      assign(char_type& __c1, const char_type& __c2) 
      { __c1 = __c2; } 
 
      static bool 
      eq(const char_type& __c1, const char_type& __c2) 
      { return __c1 == __c2; } 
 
      static bool 
      lt(const char_type& __c1, const char_type& __c2) 
      { return __c1 < __c2; } 
 
      static int 
      compare(const char_type* __s1, const char_type* __s2, size_t __n) 
      { return wmemcmp(__s1, __s2, __n); } 
 
      static size_t 
      length(const char_type* __s) 
      { return wcslen(__s); } 
 
      static const char_type* 
      find(const char_type* __s, size_t __n, const char_type& __a) 
      { return wmemchr(__s, __a, __n); } 
 
      static char_type* 
      move(char_type* __s1, const char_type* __s2, size_t __n) 
      { return wmemmove(__s1, __s2, __n); } 
 
      static char_type* 
      copy(char_type* __s1, const char_type* __s2, size_t __n) 
      { return wmemcpy(__s1, __s2, __n); } 
 
      static char_type* 
      assign(char_type* __s, size_t __n, char_type __a) 
      { return wmemset(__s, __a, __n); } 
 
      static char_type 
      to_char_type(const int_type& __c) { return char_type(__c); } 
 
      static int_type 
      to_int_type(const char_type& __c) { return int_type(__c); } 
 
      static bool 
      eq_int_type(const int_type& __c1, const int_type& __c2) 
      { return __c1 == __c2; } 
 
      static int_type 
      eof() { return static_cast<int_type>(WEOF); } 
 
      static int_type 
      not_eof(const int_type& __c) 
      { return eq_int_type(__c, eof()) ? 0 : __c; } 
  }; 
#endif #endif //_GLIBCXX_USE_WCHAR_T 
 
} } // namespace std 
 
#endif 
 
#include <cstdio> 	#include <bits/localefwd.h>	// Locale support -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 22.1  Locales 
// 
 


 */ 
 
#ifndef _LOCALE_FWD_H 
 
#pragma GCC system_header 
 
#include <bits/c++locale.h>     #include <iosfwd>		 
namespace std 
{ 
    // 22.1.1 Locale 
  class locale; 
 
    // 22.1.3 Convenience interfaces 
  template<typename _CharT> 
    inline bool 
    isspace(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isprint(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    iscntrl(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isupper(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    islower(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isalpha(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isdigit(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    ispunct(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isxdigit(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isalnum(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline bool 
    isgraph(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline _CharT 
    toupper(_CharT, const locale&); 
 
  template<typename _CharT> 
    inline _CharT 
    tolower(_CharT, const locale&); 
 
    // 22.2.1 and 22.2.1.3 ctype 
  class ctype_base; 
  template<typename _CharT> 
    class ctype; 
  template<> class ctype<char>; 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> class ctype<wchar_t>; 
#endif 
  template<typename _CharT> 
    class ctype_byname; 
    // NB: Specialized for char and wchar_t in locale_facets.h. 
 
  class codecvt_base; 
  class __enc_traits; 
  template<typename _InternT, typename _ExternT, typename _StateT> 
    class codecvt; 
  template<> class codecvt<char, char, mbstate_t>; 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> class codecvt<wchar_t, char, mbstate_t>; 
#endif 
  template<typename _InternT, typename _ExternT, typename _StateT> 
    class codecvt_byname; 
 
    // 22.2.2 and 22.2.3 numeric 
_GLIBCXX_BEGIN_LDBL_NAMESPACE 
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> > 
    class num_get; 
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> > 
    class num_put; 
_GLIBCXX_END_LDBL_NAMESPACE 
  template<typename _CharT> class numpunct; 
  template<typename _CharT> class numpunct_byname; 
 
    // 22.2.4 collation 
  template<typename _CharT> 
    class collate; 
  template<typename _CharT> class 
    collate_byname; 
 
    // 22.2.5 date and time 
  class time_base; 
  template<typename _CharT, typename _InIter =  istreambuf_iterator<_CharT> > 
    class time_get; 
  template<typename _CharT, typename _InIter =  istreambuf_iterator<_CharT> > 
    class time_get_byname; 
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> > 
    class time_put; 
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> > 
    class time_put_byname; 
 
    // 22.2.6 money 
  class money_base; 
_GLIBCXX_BEGIN_LDBL_NAMESPACE 
  template<typename _CharT, typename _InIter =  istreambuf_iterator<_CharT> > 
    class money_get; 
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> > 
    class money_put; 
_GLIBCXX_END_LDBL_NAMESPACE 
  template<typename _CharT, bool _Intl = false> 
    class moneypunct; 
  template<typename _CharT, bool _Intl = false> 
    class moneypunct_byname; 
 
    // 22.2.7 message retrieval 
  class messages_base; 
  template<typename _CharT> 
    class messages; 
  template<typename _CharT> 
    class messages_byname; 
 
  template<typename _Facet> 
    bool 
    has_facet(const locale& __loc) throw(); 
 
  template<typename _Facet> 
    const _Facet& 
    use_facet(const locale& __loc); 
 
  template<typename _Facet> 
    inline const _Facet& 
    __check_facet(const _Facet* __f) 
    { 
      if (!__f) 
	__throw_bad_cast(); 
      return *__f; 
    } 
} } // namespace std 
 
#endif 
 
#include <bits/ios_base.h>	// Iostreams base classes -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.4  Iostreams base classes 
// 
 


 */ 
 
#ifndef _IOS_BASE_H 
 
#pragma GCC system_header 
 
// Low-level functions for atomic operations -*- C++ -*- 
 
// Copyright (C) 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef _GLIBCXX_ATOMICITY_H 
 
// Low-level type for atomic operations -*- C++ -*- 
 
// Copyright (C) 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
#ifndef _GLIBCXX_ATOMIC_WORD_H 
 
typedef int _Atomic_word; 
 
// Define these two macros using the appropriate memory barrier for the target. 
// The commented out versions below are the defaults. 
// See ia64/atomic_word.h for an alternative approach. 
 
// This one prevents loads from being hoisted across the barrier; 
// in other words, this is a Load-Load acquire barrier. 
// This is necessary iff TARGET_RELAXED_ORDERING is defined in tm.h.   
// #define _GLIBCXX_READ_MEM_BARRIER __asm __volatile ("":::"memory") 
 
// This one prevents stores from being sunk across the barrier; in other 
// words, a Store-Store release barrier. 
// #define _GLIBCXX_WRITE_MEM_BARRIER __asm __volatile ("":::"memory") 
 
#endif  
 
   
namespace __gnu_cxx 
{ 
  _Atomic_word  
  __attribute__ ((__unused__)) 
  __exchange_and_add(volatile _Atomic_word* __mem, int __val); 
 
  void 
  __attribute__ ((__unused__)) 
  __atomic_add(volatile _Atomic_word* __mem, int __val); 
} } // namespace __gnu_cxx 
 


   the compiler doesn't reorder memory accesses across the barriers.  */ 
#ifndef _GLIBCXX_READ_MEM_BARRIER 
#endif 
#ifndef _GLIBCXX_WRITE_MEM_BARRIER 
#endif 
 
#endif  
 
// Locale support -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 22.1  Locales 
// 
 


 */ 
 
#ifndef _LOCALE_CLASSES_H 
 
#pragma GCC system_header 
 
#include <cstring>		 
 
namespace std 
{ 
    // 22.1.1 Class locale 
  

  */ 
  class locale 
  { 
  public: 
        // Types: 
        /// Definition of locale::category. 
    typedef int	category; 
 
        // Forward decls and friends: 
    class facet; 
    class id; 
    class _Impl; 
 
    friend class facet; 
    friend class _Impl; 
 
    template<typename _Facet> 
      friend bool 
      has_facet(const locale&) throw(); 
 
    template<typename _Facet> 
      friend const _Facet& 
      use_facet(const locale&); 
 
    template<typename _Cache> 
      friend struct __use_cache; 
 
        //@{ 
    

    */ 
    static const category none		= 0; 
    static const category ctype		= 1L << 0; 
    static const category numeric	= 1L << 1; 
    static const category collate	= 1L << 2; 
    static const category time		= 1L << 3; 
    static const category monetary	= 1L << 4; 
    static const category messages	= 1L << 5; 
    static const category all		= (ctype | numeric | collate | 
					   time  | monetary | messages); 
        //@} 
 
        // Construct/copy/destroy: 
 
    

    */ 
    locale() throw(); 
 
    

    */ 
    locale(const locale& __other) throw(); 
 
    

    */ 
    explicit 
    locale(const char* __s); 
 
    

    */ 
    locale(const locale& __base, const char* __s, category __cat); 
 
    

    */ 
    locale(const locale& __base, const locale& __add, category __cat); 
 
    

    */ 
    template<typename _Facet> 
      locale(const locale& __other, _Facet* __f); 
 
        /// Locale destructor. 
    ~locale() throw(); 
 
    

    */ 
    const locale& 
    operator=(const locale& __other) throw(); 
 
    

    */ 
    template<typename _Facet> 
      locale 
      combine(const locale& __other) const; 
 
        // Locale operations: 
    

    */ 
    string 
    name() const; 
 
    

    */ 
    bool 
    operator==(const locale& __other) const throw (); 
 
    

    */ 
    inline bool 
    operator!=(const locale& __other) const throw () 
    { return !(this->operator==(__other));  } 
 
    

    */ 
    template<typename _Char, typename _Traits, typename _Alloc> 
      bool 
      operator()(const basic_string<_Char, _Traits, _Alloc>& __s1, 
		 const basic_string<_Char, _Traits, _Alloc>& __s2) const; 
 
        // Global locale objects: 
    

    */ 
    static locale 
    global(const locale&); 
 
    

    */ 
    static const locale& 
    classic(); 
 
  private: 
        // The (shared) implementation 
    _Impl*		_M_impl; 
 
        // The "C" reference locale 
    static _Impl*       _S_classic; 
 
        // Current global locale 
    static _Impl*	_S_global; 
 
        // Names of underlying locale categories. 
        // NB: locale::global() has to know how to modify all the 
        // underlying categories, not just the ones required by the C++ 
        // standard. 
    static const char* const* const _S_categories; 
 
        // Number of standard categories. For C++, these categories are 
        // collate, ctype, monetary, numeric, time, and messages. These 
        // directly correspond to ISO C99 macros LC_COLLATE, LC_CTYPE, 
        // LC_MONETARY, LC_NUMERIC, and LC_TIME. In addition, POSIX (IEEE 
        // 1003.1-2001) specifies LC_MESSAGES. 
        // In addition to the standard categories, the underlying 
        // operating system is allowed to define extra LC_* 
        // macros. For GNU systems, the following are also valid: 
        // LC_PAPER, LC_NAME, LC_ADDRESS, LC_TELEPHONE, LC_MEASUREMENT, 
        // and LC_IDENTIFICATION. 
    enum { _S_categories_size = 6 + 6 }; 
 
#ifdef 1 
    static __gthread_once_t _S_once; 
#endif 
 
    explicit 
    locale(_Impl*) throw(); 
 
    static void 
    _S_initialize(); 
 
    static void 
    _S_initialize_once(); 
 
    static category 
    _S_normalize_category(category); 
 
    void 
    _M_coalesce(const locale& __base, const locale& __add, category __cat); 
  }; 
 
 
    // 22.1.1.1.2  Class locale::facet 
  

  */ 
  class locale::facet 
  { 
  private: 
    friend class locale; 
    friend class locale::_Impl; 
 
    mutable _Atomic_word		_M_refcount; 
 
        // Contains data from the underlying "C" library for the classic locale. 
    static __c_locale                   _S_c_locale; 
 
        // String literal for the name of the classic locale. 
    static const char			_S_c_name[2]; 
 
#ifdef 1 
    static __gthread_once_t		_S_once; 
#endif 
 
    static void 
    _S_initialize_once(); 
 
  protected: 
    

    */ 
    explicit 
    facet(size_t __refs = 0) throw() : _M_refcount(__refs ? 1 : 0) 
    { } 
 
        /// Facet destructor. 
    virtual 
    ~facet(); 
 
    static void 
    _S_create_c_locale(__c_locale& __cloc, const char* __s, 
		       __c_locale __old = 0); 
 
    static __c_locale 
    _S_clone_c_locale(__c_locale& __cloc); 
 
    static void 
    _S_destroy_c_locale(__c_locale& __cloc); 
 
        // Returns data from the underlying "C" library data for the 
        // classic locale. 
    static __c_locale 
    _S_get_c_locale(); 
 
    static const char* 
    _S_get_c_name(); 
 
  private: 
    inline void 
    _M_add_reference() const throw() 
    { __gnu_cxx::__atomic_add(&_M_refcount, 1); } 
 
    inline void 
    _M_remove_reference() const throw() 
    { 
      if (__gnu_cxx::__exchange_and_add(&_M_refcount, -1) == 1) 
	{ 
	  try 
	    { delete this; } 
	  catch (...) 
	    { } 
	} 
    } 
 
    facet(const facet&);      facet(const facet&);  // Not defined. 
 
    facet& 
    operator=(const facet&);      operator=(const facet&);  // Not defined. 
  }; 
 
 
    // 22.1.1.1.3 Class locale::id 
  

  */ 
  class locale::id 
  { 
  private: 
    friend class locale; 
    friend class locale::_Impl; 
 
    template<typename _Facet> 
      friend const _Facet& 
      use_facet(const locale&); 
 
    template<typename _Facet> 
      friend bool 
      has_facet(const locale&) throw (); 
 
        // NB: There is no accessor for _M_index because it may be used 
        // before the constructor is run; the effect of calling a member 
        // function (even an inline) would be undefined. 
    mutable size_t		_M_index; 
 
        // Last id number assigned. 
    static _Atomic_word		_S_refcount; 
 
    void 
    operator=(const id&);      operator=(const id&);  // Not defined. 
 
    id(const id&);      id(const id&);  // Not defined. 
 
  public: 
        // NB: This class is always a static data member, and thus can be 
        // counted on to be zero-initialized. 
        /// Constructor. 
    id() { } 
 
    size_t 
    _M_id() const; 
  }; 
 
 
    // Implementation object for locale. 
  class locale::_Impl 
  { 
  public: 
        // Friends. 
    friend class locale; 
    friend class locale::facet; 
 
    template<typename _Facet> 
      friend bool 
      has_facet(const locale&) throw(); 
 
    template<typename _Facet> 
      friend const _Facet& 
      use_facet(const locale&); 
 
    template<typename _Cache> 
      friend struct __use_cache; 
 
  private: 
        // Data Members. 
    _Atomic_word			_M_refcount; 
    const facet**			_M_facets; 
    size_t				_M_facets_size; 
    const facet**			_M_caches; 
    char**				_M_names; 
    static const locale::id* const	_S_id_ctype[]; 
    static const locale::id* const	_S_id_numeric[]; 
    static const locale::id* const	_S_id_collate[]; 
    static const locale::id* const	_S_id_time[]; 
    static const locale::id* const	_S_id_monetary[]; 
    static const locale::id* const	_S_id_messages[]; 
    static const locale::id* const* const _S_facet_categories[]; 
 
    inline void 
    _M_add_reference() throw() 
    { __gnu_cxx::__atomic_add(&_M_refcount, 1); } 
 
    inline void 
    _M_remove_reference() throw() 
    { 
      if (__gnu_cxx::__exchange_and_add(&_M_refcount, -1) == 1) 
	{ 
	  try 
	    { delete this; } 
	  catch(...) 
	    { } 
	} 
    } 
 
    _Impl(const _Impl&, size_t); 
    _Impl(const char*, size_t); 
    _Impl(size_t) throw(); 
 
   ~_Impl() throw(); 
 
    _Impl(const _Impl&);      _Impl(const _Impl&);  // Not defined. 
 
    void 
    operator=(const _Impl&);      operator=(const _Impl&);  // Not defined. 
 
    inline bool 
    _M_check_same_name() 
    { 
      bool __ret = true; 
      if (_M_names[1]) 
		// We must actually compare all the _M_names: can be all equal! 
	for (size_t __i = 0; __ret && __i < _S_categories_size - 1; ++__i) 
	  __ret = std::strcmp(_M_names[__i], _M_names[__i + 1]) == 0; 
      return __ret; 
    } 
 
    void 
    _M_replace_categories(const _Impl*, category); 
 
    void 
    _M_replace_category(const _Impl*, const locale::id* const*); 
 
    void 
    _M_replace_facet(const _Impl*, const locale::id*); 
 
    void 
    _M_install_facet(const locale::id*, const facet*); 
 
    template<typename _Facet> 
      inline void 
      _M_init_facet(_Facet* __facet) 
      { _M_install_facet(&_Facet::id, __facet); } 
 
    void 
    _M_install_cache(const facet*, size_t); 
  }; 
 
  template<typename _Facet> 
    locale::locale(const locale& __other, _Facet* __f) 
    { 
      _M_impl = new _Impl(*__other._M_impl, 1); 
 
      try 
	{ _M_impl->_M_install_facet(&_Facet::id, __f); } 
      catch(...) 
	{ 
	  _M_impl->_M_remove_reference(); 
	  __throw_exception_again; 
	} 
      delete [] _M_impl->_M_names[0]; 
      _M_impl->_M_names[0] = 0;         _M_impl->_M_names[0] = 0;   // Unnamed. 
    } 
} } // namespace std 
 
#endif 
 
 
namespace std 
{ 
    // The following definitions of bitmask types are enums, not ints, 
    // as permitted (but not required) in the standard, in order to provide 
    // better type safety in iostream calls.  A side effect is that 
    // expressions involving them are no longer compile-time constants. 
  enum _Ios_Fmtflags  
    {  
      _S_boolalpha 	= 1L << 0, 
      _S_dec 		= 1L << 1, 
      _S_fixed 		= 1L << 2, 
      _S_hex 		= 1L << 3, 
      _S_internal 	= 1L << 4, 
      _S_left 		= 1L << 5, 
      _S_oct 		= 1L << 6, 
      _S_right 		= 1L << 7, 
      _S_scientific 	= 1L << 8, 
      _S_showbase 	= 1L << 9, 
      _S_showpoint 	= 1L << 10, 
      _S_showpos 	= 1L << 11, 
      _S_skipws 	= 1L << 12, 
      _S_unitbuf 	= 1L << 13, 
      _S_uppercase 	= 1L << 14, 
      _S_adjustfield 	= _S_left | _S_right | _S_internal, 
      _S_basefield 	= _S_dec | _S_oct | _S_hex, 
      _S_floatfield 	= _S_scientific | _S_fixed, 
      _S_ios_fmtflags_end = 1L << 16  
    }; 
 
  inline _Ios_Fmtflags 
  operator&(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
  { return _Ios_Fmtflags(static_cast<int>(__a) & static_cast<int>(__b)); } 
 
  inline _Ios_Fmtflags 
  operator|(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
  { return _Ios_Fmtflags(static_cast<int>(__a) | static_cast<int>(__b)); } 
 
  inline _Ios_Fmtflags 
  operator^(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
  { return _Ios_Fmtflags(static_cast<int>(__a) ^ static_cast<int>(__b)); } 
 
  inline _Ios_Fmtflags& 
  operator|=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b) 
  { return __a = __a | __b; } 
 
  inline _Ios_Fmtflags& 
  operator&=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b) 
  { return __a = __a & __b; } 
 
  inline _Ios_Fmtflags& 
  operator^=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b) 
  { return __a = __a ^ __b; } 
 
  inline _Ios_Fmtflags 
  operator~(_Ios_Fmtflags __a) 
  { return _Ios_Fmtflags(~static_cast<int>(__a)); } 
 
 
  enum _Ios_Openmode  
    {  
      _S_app 		= 1L << 0, 
      _S_ate 		= 1L << 1, 
      _S_bin 		= 1L << 2, 
      _S_in 		= 1L << 3, 
      _S_out 		= 1L << 4, 
      _S_trunc 		= 1L << 5, 
      _S_ios_openmode_end = 1L << 16  
    }; 
 
  inline _Ios_Openmode 
  operator&(_Ios_Openmode __a, _Ios_Openmode __b) 
  { return _Ios_Openmode(static_cast<int>(__a) & static_cast<int>(__b)); } 
 
  inline _Ios_Openmode 
  operator|(_Ios_Openmode __a, _Ios_Openmode __b) 
  { return _Ios_Openmode(static_cast<int>(__a) | static_cast<int>(__b)); } 
 
  inline _Ios_Openmode 
  operator^(_Ios_Openmode __a, _Ios_Openmode __b) 
  { return _Ios_Openmode(static_cast<int>(__a) ^ static_cast<int>(__b)); } 
 
  inline _Ios_Openmode& 
  operator|=(_Ios_Openmode& __a, _Ios_Openmode __b) 
  { return __a = __a | __b; } 
 
  inline _Ios_Openmode& 
  operator&=(_Ios_Openmode& __a, _Ios_Openmode __b) 
  { return __a = __a & __b; } 
 
  inline _Ios_Openmode& 
  operator^=(_Ios_Openmode& __a, _Ios_Openmode __b) 
  { return __a = __a ^ __b; } 
 
  inline _Ios_Openmode 
  operator~(_Ios_Openmode __a) 
  { return _Ios_Openmode(~static_cast<int>(__a)); } 
 
 
  enum _Ios_Iostate 
    {  
      _S_goodbit 		= 0, 
      _S_badbit 		= 1L << 0, 
      _S_eofbit 		= 1L << 1, 
      _S_failbit		= 1L << 2, 
      _S_ios_iostate_end = 1L << 16  
    }; 
 
  inline _Ios_Iostate 
  operator&(_Ios_Iostate __a, _Ios_Iostate __b) 
  { return _Ios_Iostate(static_cast<int>(__a) & static_cast<int>(__b)); } 
 
  inline _Ios_Iostate 
  operator|(_Ios_Iostate __a, _Ios_Iostate __b) 
  { return _Ios_Iostate(static_cast<int>(__a) | static_cast<int>(__b)); } 
 
  inline _Ios_Iostate 
  operator^(_Ios_Iostate __a, _Ios_Iostate __b) 
  { return _Ios_Iostate(static_cast<int>(__a) ^ static_cast<int>(__b)); } 
 
  inline _Ios_Iostate& 
  operator|=(_Ios_Iostate& __a, _Ios_Iostate __b) 
  { return __a = __a | __b; } 
 
  inline _Ios_Iostate& 
  operator&=(_Ios_Iostate& __a, _Ios_Iostate __b) 
  { return __a = __a & __b; } 
 
  inline _Ios_Iostate& 
  operator^=(_Ios_Iostate& __a, _Ios_Iostate __b) 
  { return __a = __a ^ __b; } 
 
  inline _Ios_Iostate 
  operator~(_Ios_Iostate __a) 
  { return _Ios_Iostate(~static_cast<int>(__a)); } 
 
  enum _Ios_Seekdir  
    {  
      _S_beg = 0, 
      _S_cur = SEEK_CUR, 
      _S_end = SEEK_END, 
      _S_ios_seekdir_end = 1L << 16  
    }; 
 
    // 27.4.2  Class ios_base 
  

  */ 
  class ios_base 
  { 
  public: 
 
        // 27.4.2.1.1  Class ios_base::failure 
        /// These are thrown to indicate problems.  Doc me. 
    class failure : public exception 
    { 
    public: 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 48.  Use of non-existent exception constructor 
      explicit 
      failure(const string& __str) throw(); 
 
            // This declaration is not useless: 
            // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118 
      virtual 
      ~failure() throw(); 
 
      virtual const char* 
      what() const throw(); 
 
    private: 
      string _M_msg; 
    }; 
 
        // 27.4.2.1.2  Type ios_base::fmtflags 
    

    */ 
    typedef _Ios_Fmtflags fmtflags; 
 
        /// Insert/extract @c bool in alphabetic rather than numeric format. 
    static const fmtflags boolalpha =   _S_boolalpha; 
 
        /// Converts integer input or generates integer output in decimal base. 
    static const fmtflags dec =         _S_dec; 
 
        /// Generate floating-point output in fixed-point notation. 
    static const fmtflags fixed =       _S_fixed; 
 
        /// Converts integer input or generates integer output in hexadecimal base. 
    static const fmtflags hex =         _S_hex; 
 
        /// Adds fill characters at a designated internal point in certain 
        /// generated output, or identical to @c right if no such point is 
        /// designated. 
    static const fmtflags internal =    _S_internal; 
 
        /// Adds fill characters on the right (final positions) of certain 
        /// generated output.  (I.e., the thing you print is flush left.) 
    static const fmtflags left =        _S_left; 
 
        /// Converts integer input or generates integer output in octal base. 
    static const fmtflags oct =         _S_oct; 
 
        /// Adds fill characters on the left (initial positions) of certain 
        /// generated output.  (I.e., the thing you print is flush right.) 
    static const fmtflags right =       _S_right; 
 
        /// Generates floating-point output in scientific notation. 
    static const fmtflags scientific =  _S_scientific; 
 
        /// Generates a prefix indicating the numeric base of generated integer 
        /// output. 
    static const fmtflags showbase =    _S_showbase; 
 
        /// Generates a decimal-point character unconditionally in generated 
        /// floating-point output. 
    static const fmtflags showpoint =   _S_showpoint; 
 
        /// Generates a + sign in non-negative generated numeric output. 
    static const fmtflags showpos =     _S_showpos; 
 
        /// Skips leading white space before certain input operations. 
    static const fmtflags skipws =      _S_skipws; 
 
        /// Flushes output after each output operation. 
    static const fmtflags unitbuf =     _S_unitbuf; 
 
        /// Replaces certain lowercase letters with their uppercase equivalents 
        /// in generated output. 
    static const fmtflags uppercase =   _S_uppercase; 
 
        /// A mask of left|right|internal.  Useful for the 2-arg form of @c setf. 
    static const fmtflags adjustfield = _S_adjustfield; 
 
        /// A mask of dec|oct|hex.  Useful for the 2-arg form of @c setf. 
    static const fmtflags basefield =   _S_basefield; 
 
        /// A mask of scientific|fixed.  Useful for the 2-arg form of @c setf. 
    static const fmtflags floatfield =  _S_floatfield; 
 
        // 27.4.2.1.3  Type ios_base::iostate 
    

    */ 
    typedef _Ios_Iostate iostate; 
 
        /// Indicates a loss of integrity in an input or output sequence (such 
        /// as an irrecoverable read error from a file). 
    static const iostate badbit =	_S_badbit; 
 
        /// Indicates that an input operation reached the end of an input sequence. 
    static const iostate eofbit =	_S_eofbit; 
 
        /// Indicates that an input operation failed to read the expected 
        /// characters, or that an output operation failed to generate the 
        /// desired characters. 
    static const iostate failbit =	_S_failbit; 
 
        /// Indicates all is well. 
    static const iostate goodbit =	_S_goodbit; 
 
        // 27.4.2.1.4  Type ios_base::openmode 
    

    */ 
    typedef _Ios_Openmode openmode; 
 
        /// Seek to end before each write. 
    static const openmode app =		_S_app; 
 
        /// Open and seek to end immediately after opening. 
    static const openmode ate =		_S_ate; 
 
        /// Perform input and output in binary mode (as opposed to text mode). 
        /// This is probably not what you think it is; see 
        /// http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#3 and 
        /// http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#7 for more. 
    static const openmode binary =	_S_bin; 
 
        /// Open for input.  Default for @c ifstream and fstream. 
    static const openmode in =		_S_in; 
 
        /// Open for output.  Default for @c ofstream and fstream. 
    static const openmode out =		_S_out; 
 
        /// Open for input.  Default for @c ofstream. 
    static const openmode trunc =	_S_trunc; 
 
        // 27.4.2.1.5  Type ios_base::seekdir 
    

    */ 
    typedef _Ios_Seekdir seekdir; 
 
        /// Request a seek relative to the beginning of the stream. 
    static const seekdir beg =		_S_beg; 
 
        /// Request a seek relative to the current position within the sequence. 
    static const seekdir cur =		_S_cur; 
 
        /// Request a seek relative to the current end of the sequence. 
    static const seekdir end =		_S_end; 
 
        // Annex D.6 
    typedef int io_state; 
    typedef int open_mode; 
    typedef int seek_dir; 
 
    typedef std::streampos streampos; 
    typedef std::streamoff streamoff; 
 
        // Callbacks; 
    

    */ 
    enum event 
    { 
      erase_event, 
      imbue_event, 
      copyfmt_event 
    }; 
 
    

    */ 
    typedef void (*event_callback) (event, ios_base&, int); 
 
    

    */ 
    void 
    register_callback(event_callback __fn, int __index); 
 
  protected: 
        //@{ 
    

    */ 
    streamsize		_M_precision; 
    streamsize		_M_width; 
    fmtflags		_M_flags; 
    iostate		_M_exception; 
    iostate		_M_streambuf_state; 
        //@} 
 
        // 27.4.2.6  Members for callbacks 
        // 27.4.2.6  ios_base callbacks 
    struct _Callback_list 
    { 
            // Data Members 
      _Callback_list*		_M_next; 
      ios_base::event_callback	_M_fn; 
      int			_M_index; 
      _Atomic_word		_M_refcount;        _Atomic_word		_M_refcount;  // 0 means one reference. 
 
      _Callback_list(ios_base::event_callback __fn, int __index, 
		     _Callback_list* __cb) 
      : _M_next(__cb), _M_fn(__fn), _M_index(__index), _M_refcount(0) { } 
 
      void 
      _M_add_reference() { __gnu_cxx::__atomic_add(&_M_refcount, 1); } 
 
            // 0 => OK to delete. 
      int 
      _M_remove_reference()  
      { return __gnu_cxx::__exchange_and_add(&_M_refcount, -1); } 
    }; 
 
     _Callback_list*	_M_callbacks; 
 
    void 
    _M_call_callbacks(event __ev) throw(); 
 
    void 
    _M_dispose_callbacks(void); 
 
        // 27.4.2.5  Members for iword/pword storage 
    struct _Words 
    { 
      void*	_M_pword; 
      long	_M_iword; 
      _Words() : _M_pword(0), _M_iword(0) { } 
    }; 
 
        // Only for failed iword/pword calls. 
    _Words		_M_word_zero; 
 
        // Guaranteed storage. 
        // The first 5 iword and pword slots are reserved for internal use. 
    enum { _S_local_word_size = 8 }; 
    _Words		_M_local_word[_S_local_word_size]; 
 
        // Allocated storage. 
    int			_M_word_size; 
    _Words*		_M_word; 
 
    _Words& 
    _M_grow_words(int __index, bool __iword); 
 
        // Members for locale and locale caching. 
    locale		_M_ios_locale; 
 
    void 
    _M_init(); 
 
  public: 
 
        // 27.4.2.1.6  Class ios_base::Init 
        // Used to initialize standard streams. In theory, g++ could use 
        // -finit-priority to order this stuff correctly without going 
        // through these machinations. 
    class Init 
    { 
      friend class ios_base; 
    public: 
      Init(); 
      ~Init(); 
 
    private: 
      static _Atomic_word	_S_refcount; 
      static bool		_S_synced_with_stdio; 
    }; 
 
        // [27.4.2.2] fmtflags state functions 
    

    */ 
    inline fmtflags 
    flags() const { return _M_flags; } 
 
    

    */ 
    inline fmtflags 
    flags(fmtflags __fmtfl) 
    { 
      fmtflags __old = _M_flags; 
      _M_flags = __fmtfl; 
      return __old; 
    } 
 
    

    */ 
    inline fmtflags 
    setf(fmtflags __fmtfl) 
    { 
      fmtflags __old = _M_flags; 
      _M_flags |= __fmtfl; 
      return __old; 
    } 
 
    

    */ 
    inline fmtflags 
    setf(fmtflags __fmtfl, fmtflags __mask) 
    { 
      fmtflags __old = _M_flags; 
      _M_flags &= ~__mask; 
      _M_flags |= (__fmtfl & __mask); 
      return __old; 
    } 
 
    

    */ 
    inline void 
    unsetf(fmtflags __mask) { _M_flags &= ~__mask; } 
 
    

    */ 
    inline streamsize 
    precision() const { return _M_precision; } 
 
    

    */ 
    inline streamsize 
    precision(streamsize __prec) 
    { 
      streamsize __old = _M_precision; 
      _M_precision = __prec; 
      return __old; 
    } 
 
    

    */ 
    inline streamsize 
    width() const { return _M_width; } 
 
    

    */ 
    inline streamsize 
    width(streamsize __wide) 
    { 
      streamsize __old = _M_width; 
      _M_width = __wide; 
      return __old; 
    } 
 
        // [27.4.2.4] ios_base static members 
    

    */ 
    static bool 
    sync_with_stdio(bool __sync = true); 
 
        // [27.4.2.3] ios_base locale functions 
    

    */ 
    locale 
    imbue(const locale& __loc); 
 
    

    */ 
    inline locale 
    getloc() const { return _M_ios_locale; } 
 
    

    */ 
    inline const locale& 
    _M_getloc() const { return _M_ios_locale; } 
 
        // [27.4.2.5] ios_base storage functions 
    

    */ 
    static int 
    xalloc() throw(); 
 
    

    */ 
    inline long& 
    iword(int __ix) 
    { 
      _Words& __word = (__ix < _M_word_size) 
			? _M_word[__ix] : _M_grow_words(__ix, true); 
      return __word._M_iword; 
    } 
 
    

    */ 
    inline void*& 
    pword(int __ix) 
    { 
      _Words& __word = (__ix < _M_word_size) 
			? _M_word[__ix] : _M_grow_words(__ix, false); 
      return __word._M_pword; 
    } 
 
        // Destructor 
    

    */ 
    virtual ~ios_base(); 
 
  protected: 
    ios_base(); 
 
    // _GLIBCXX_RESOLVE_LIB_DEFECTS 
    // 50.  Copy constructor and assignment operator of ios_base 
  private: 
    ios_base(const ios_base&); 
 
    ios_base& 
    operator=(const ios_base&); 
  }; 
 
    // [27.4.5.1] fmtflags manipulators 
    /// Calls base.setf(ios_base::boolalpha). 
  inline ios_base& 
  boolalpha(ios_base& __base) 
  { 
    __base.setf(ios_base::boolalpha); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::boolalpha). 
  inline ios_base& 
  noboolalpha(ios_base& __base) 
  { 
    __base.unsetf(ios_base::boolalpha); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::showbase). 
  inline ios_base& 
  showbase(ios_base& __base) 
  { 
    __base.setf(ios_base::showbase); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::showbase). 
  inline ios_base& 
  noshowbase(ios_base& __base) 
  { 
    __base.unsetf(ios_base::showbase); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::showpoint). 
  inline ios_base& 
  showpoint(ios_base& __base) 
  { 
    __base.setf(ios_base::showpoint); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::showpoint). 
  inline ios_base& 
  noshowpoint(ios_base& __base) 
  { 
    __base.unsetf(ios_base::showpoint); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::showpos). 
  inline ios_base& 
  showpos(ios_base& __base) 
  { 
    __base.setf(ios_base::showpos); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::showpos). 
  inline ios_base& 
  noshowpos(ios_base& __base) 
  { 
    __base.unsetf(ios_base::showpos); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::skipws). 
  inline ios_base& 
  skipws(ios_base& __base) 
  { 
    __base.setf(ios_base::skipws); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::skipws). 
  inline ios_base& 
  noskipws(ios_base& __base) 
  { 
    __base.unsetf(ios_base::skipws); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::uppercase). 
  inline ios_base& 
  uppercase(ios_base& __base) 
  { 
    __base.setf(ios_base::uppercase); 
    return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::uppercase). 
  inline ios_base& 
  nouppercase(ios_base& __base) 
  { 
    __base.unsetf(ios_base::uppercase); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::unitbuf). 
  inline ios_base& 
  unitbuf(ios_base& __base) 
  { 
     __base.setf(ios_base::unitbuf); 
     return __base; 
  } 
 
    /// Calls base.unsetf(ios_base::unitbuf). 
  inline ios_base& 
  nounitbuf(ios_base& __base) 
  { 
     __base.unsetf(ios_base::unitbuf); 
     return __base; 
  } 
 
    // [27.4.5.2] adjustfield anipulators 
    /// Calls base.setf(ios_base::internal, ios_base::adjustfield). 
  inline ios_base& 
  internal(ios_base& __base) 
  { 
     __base.setf(ios_base::internal, ios_base::adjustfield); 
     return __base; 
  } 
 
    /// Calls base.setf(ios_base::left, ios_base::adjustfield). 
  inline ios_base& 
  left(ios_base& __base) 
  { 
    __base.setf(ios_base::left, ios_base::adjustfield); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::right, ios_base::adjustfield). 
  inline ios_base& 
  right(ios_base& __base) 
  { 
    __base.setf(ios_base::right, ios_base::adjustfield); 
    return __base; 
  } 
 
    // [27.4.5.3] basefield anipulators 
    /// Calls base.setf(ios_base::dec, ios_base::basefield). 
  inline ios_base& 
  dec(ios_base& __base) 
  { 
    __base.setf(ios_base::dec, ios_base::basefield); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::hex, ios_base::basefield). 
  inline ios_base& 
  hex(ios_base& __base) 
  { 
    __base.setf(ios_base::hex, ios_base::basefield); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::oct, ios_base::basefield). 
  inline ios_base& 
  oct(ios_base& __base) 
  { 
    __base.setf(ios_base::oct, ios_base::basefield); 
    return __base; 
  } 
 
    // [27.4.5.4] floatfield anipulators 
    /// Calls base.setf(ios_base::fixed, ios_base::floatfield). 
  inline ios_base& 
  fixed(ios_base& __base) 
  { 
    __base.setf(ios_base::fixed, ios_base::floatfield); 
    return __base; 
  } 
 
    /// Calls base.setf(ios_base::scientific, ios_base::floatfield). 
  inline ios_base& 
  scientific(ios_base& __base) 
  { 
    __base.setf(ios_base::scientific, ios_base::floatfield); 
    return __base; 
  } 
} } // namespace std 
 
#endif 
 
 
// Iostreams base classes -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003, 2004 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef _BASIC_IOS_H 
 
#pragma GCC system_header 
 
// Streambuf iterators 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef _STREAMBUF_ITERATOR_H 
 
#pragma GCC system_header 
 
 
// NB: Should specialize copy, find algorithms for streambuf iterators. 
 
namespace std 
{ 
    // 24.5.3 Template class istreambuf_iterator 
    /// Provides input iterator semantics for streambufs. 
  template<typename _CharT, typename _Traits> 
    class istreambuf_iterator 
    : public iterator<input_iterator_tag, _CharT, typename _Traits::off_type, 
		      _CharT*, _CharT&> 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT					char_type; 
      typedef _Traits					traits_type; 
      typedef typename _Traits::int_type		int_type; 
      typedef basic_streambuf<_CharT, _Traits>		streambuf_type; 
      typedef basic_istream<_CharT, _Traits>		istream_type; 
            //@} 
 
    private: 
            // 24.5.3 istreambuf_iterator 
            // p 1 
            // If the end of stream is reached (streambuf_type::sgetc() 
            // returns traits_type::eof()), the iterator becomes equal to 
            // the "end of stream" iterator value. 
            // NB: This implementation assumes the "end of stream" value 
            // is EOF, or -1. 
      mutable streambuf_type*	_M_sbuf; 
      mutable int_type		_M_c; 
 
    public: 
            ///  Construct end of input stream iterator. 
      istreambuf_iterator() throw() 
      : _M_sbuf(0), _M_c(traits_type::eof()) { } 
 
            ///  Construct start of input stream iterator. 
      istreambuf_iterator(istream_type& __s) throw() 
      : _M_sbuf(__s.rdbuf()), _M_c(traits_type::eof()) { } 
 
            ///  Construct start of streambuf iterator. 
      istreambuf_iterator(streambuf_type* __s) throw() 
      : _M_sbuf(__s), _M_c(traits_type::eof()) { } 
 
            ///  Return the current character pointed to by iterator.  This returns 
            ///  streambuf.sgetc().  It cannot be assigned.  NB: The result of 
            ///  operator*() on an end of stream is undefined. 
      char_type 
      operator*() const 
      { 
#ifdef _GLIBCXX_DEBUG_PEDANTIC 
		// Dereferencing a past-the-end istreambuf_iterator is a 
		// libstdc++ extension 
	__glibcxx_requires_cond(!_M_at_eof(), 
				_M_message(__gnu_debug::__msg_deref_istreambuf) 
				._M_iterator(*this)); 
#endif 
	return traits_type::to_char_type(_M_get()); 
      } 
 
            /// Advance the iterator.  Calls streambuf.sbumpc(). 
      istreambuf_iterator& 
      operator++() 
      { 
	__glibcxx_requires_cond(!_M_at_eof(), 
				_M_message(__gnu_debug::__msg_inc_istreambuf) 
				._M_iterator(*this)); 
	if (_M_sbuf) 
	  { 
	    _M_sbuf->sbumpc(); 
	    _M_c = traits_type::eof(); 
	  } 
	return *this; 
      } 
 
            /// Advance the iterator.  Calls streambuf.sbumpc(). 
      istreambuf_iterator 
      operator++(int) 
      { 
	__glibcxx_requires_cond(!_M_at_eof(), 
				_M_message(__gnu_debug::__msg_inc_istreambuf) 
				._M_iterator(*this)); 
 
	istreambuf_iterator __old = *this; 
	if (_M_sbuf) 
	  { 
	    __old._M_c = _M_sbuf->sbumpc(); 
	    _M_c = traits_type::eof(); 
	  } 
	return __old; 
      } 
 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 110 istreambuf_iterator::equal not const 
            // NB: there is also number 111 (NAD, Future) pending on this function. 
            /// Return true both iterators are end or both are not end. 
      bool 
      equal(const istreambuf_iterator& __b) const 
      { 
	const bool __thiseof = _M_at_eof(); 
	const bool __beof = __b._M_at_eof(); 
	return (__thiseof && __beof || (!__thiseof && !__beof)); 
      } 
 
    private: 
      int_type 
      _M_get() const 
      { 
	const int_type __eof = traits_type::eof(); 
	int_type __ret = __eof; 
	if (_M_sbuf) 
	  { 
	    if (!traits_type::eq_int_type(_M_c, __eof)) 
	      __ret = _M_c; 
	    else if (!traits_type::eq_int_type((__ret = _M_sbuf->sgetc()), 
					       __eof)) 
	      _M_c = __ret; 
	    else 
	      _M_sbuf = 0; 
	  } 
	return __ret; 
      } 
 
      bool 
      _M_at_eof() const 
      { 
	const int_type __eof = traits_type::eof(); 
	return traits_type::eq_int_type(_M_get(), __eof); 
      } 
    }; 
 
  template<typename _CharT, typename _Traits> 
    inline bool 
    operator==(const istreambuf_iterator<_CharT, _Traits>& __a, 
	       const istreambuf_iterator<_CharT, _Traits>& __b) 
    { return __a.equal(__b); } 
 
  template<typename _CharT, typename _Traits> 
    inline bool 
    operator!=(const istreambuf_iterator<_CharT, _Traits>& __a, 
	       const istreambuf_iterator<_CharT, _Traits>& __b) 
    { return !__a.equal(__b); } 
 
    /// Provides output iterator semantics for streambufs. 
  template<typename _CharT, typename _Traits> 
    class ostreambuf_iterator 
    : public iterator<output_iterator_tag, void, void, void, void> 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT                           char_type; 
      typedef _Traits                          traits_type; 
      typedef basic_streambuf<_CharT, _Traits> streambuf_type; 
      typedef basic_ostream<_CharT, _Traits>   ostream_type; 
            //@} 
 
    private: 
      streambuf_type*	_M_sbuf; 
      bool		_M_failed; 
 
    public: 
            ///  Construct output iterator from ostream. 
      ostreambuf_iterator(ostream_type& __s) throw () 
      : _M_sbuf(__s.rdbuf()), _M_failed(!_M_sbuf) { } 
 
            ///  Construct output iterator from streambuf. 
      ostreambuf_iterator(streambuf_type* __s) throw () 
      : _M_sbuf(__s), _M_failed(!_M_sbuf) { } 
 
            ///  Write character to streambuf.  Calls streambuf.sputc(). 
      ostreambuf_iterator& 
      operator=(_CharT __c) 
      { 
	if (!_M_failed && 
	    _Traits::eq_int_type(_M_sbuf->sputc(__c), _Traits::eof())) 
	  _M_failed = true; 
	return *this; 
      } 
 
            /// Return *this. 
      ostreambuf_iterator& 
      operator*() 
      { return *this; } 
 
            /// Return *this. 
      ostreambuf_iterator& 
      operator++(int) 
      { return *this; } 
 
            /// Return *this. 
      ostreambuf_iterator& 
      operator++() 
      { return *this; } 
 
            /// Return true if previous operator=() failed. 
      bool 
      failed() const throw() 
      { return _M_failed; } 
 
      ostreambuf_iterator& 
      _M_put(const _CharT* __ws, streamsize __len) 
      { 
	if (__builtin_expect(!_M_failed, true) 
	    && __builtin_expect(this->_M_sbuf->sputn(__ws, __len) != __len, 
				false)) 
	  _M_failed = true; 
	return *this; 
      } 
    }; 
} } // namespace std 
#endif 
 
// Locale support -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 22.1  Locales 
// 
 


 */ 
 
#ifndef _LOCALE_FACETS_H 
 
#pragma GCC system_header 
 
#include <ctime>	// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CTIME_HEADER 
 
 
namespace std { 
  using ::size_t; 
  using ::clock_t; 
  using ::time_t; 
  using ::tm; 
  using ::asctime; 
  using ::clock; 
  using ::difftime; 
  using ::localtime; 
  using ::strftime; 
  using ::ctime; 
  using ::gmtime; 
  using ::mktime; 
  using ::time; 
} 
 
#endif #endif // CTIME_HEADER 
 
#include <cwctype>	// This file is automatically generated. Do not edit. 
// ['../../libs/compatibility/generate_cpp_c_headers.py'] 
// Wed Jul 23 12:11:19 2003 ('GMTST', 'GMTST') 
 
#ifndef __CWCTYPE_HEADER 
 


   02111-1307 USA.  */ 
 


 */ 
 
#ifndef _WCTYPE_H 
 
 
#ifndef __need_iswxxx 
# define _WCTYPE_H	1 
 


   there.  So define it ourselves if it remains undefined.  */ 
# define __need_wint_t 
# include <stddef.h> 
# ifndef _WINT_T 


   member of the extended character set.  */ 
#  define _WINT_T 
typedef unsigned int wint_t; 
# else 
#  ifdef __USE_ISOC99 
__USING_NAMESPACE_C99(wint_t) 
#  endif 
# endif 
 


   to any member of the extended character set.  */ 
# ifndef WEOF 
#  define WEOF (0xffffffffu) 
# endif 
#endif 
#undef __need_iswxxx 
 
 


   in the Unix98 compatibility mode.  */ 
#ifndef __iswxxx_defined 
# define __iswxxx_defined	1 
 
__BEGIN_NAMESPACE_C99 


   character classifications.  */ 
typedef unsigned long int wctype_t; 
__END_NAMESPACE_C99 
 
# ifndef _ISwbit 


   machine's byte order.  */ 
 
#  include <endian.h> 
#  if __BYTE_ORDER == __BIG_ENDIAN 
#   define _ISwbit(bit)	(1 << (bit)) 
#  else 

  __ISwupper = 0,			/* UPPERCASE.  */ 
  __ISwlower = 1,			

  __ISwalpha = 2,			/* Alphabetic.  */ 
  __ISwdigit = 3,			

  __ISwxdigit = 4,			/* Hexadecimal numeric.  */ 
  __ISwspace = 5,			

  __ISwprint = 6,			/* Printing.  */ 
  __ISwgraph = 7,			

  __ISwblank = 8,			/* Blank (usually SPC and TAB).  */ 
  __ISwcntrl = 9,			

  __ISwpunct = 10,			/* Punctuation.  */ 
  __ISwalnum = 11,			

  _ISwupper = _ISwbit (__ISwupper),	/* UPPERCASE.  */ 
  _ISwlower = _ISwbit (__ISwlower),	

  _ISwalpha = _ISwbit (__ISwalpha),	/* Alphabetic.  */ 
  _ISwdigit = _ISwbit (__ISwdigit),	

  _ISwxdigit = _ISwbit (__ISwxdigit),	/* Hexadecimal numeric.  */ 
  _ISwspace = _ISwbit (__ISwspace),	

  _ISwprint = _ISwbit (__ISwprint),	/* Printing.  */ 
  _ISwgraph = _ISwbit (__ISwgraph),	

  _ISwblank = _ISwbit (__ISwblank),	/* Blank (usually SPC and TAB).  */ 
  _ISwcntrl = _ISwbit (__ISwcntrl),	

  _ISwpunct = _ISwbit (__ISwpunct),	/* Punctuation.  */ 
  _ISwalnum = _ISwbit (__ISwalnum)	

# endif /* Not _ISwbit  */ 
 
 
__BEGIN_DECLS 
 
__BEGIN_NAMESPACE_C99 


 */ 
 


   true.  */ 
extern int iswalnum (wint_t __wc) __THROW; 
 


   `iswpunct', or `iswspace' is true.  */ 
extern int iswalpha (wint_t __wc) __THROW; 
 


   character.  */ 
extern int iswdigit (wint_t __wc) __THROW; 
 


   `iswspace' is false.  */ 
extern int iswgraph (wint_t __wc) __THROW; 
 


   none of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */ 
extern int iswlower (wint_t __wc) __THROW; 
 


   nor `iswalnum' is true.  */ 
extern int iswpunct (wint_t __wc) __THROW; 
 


   `iswpunct' is true.  */ 
extern int iswspace (wint_t __wc) __THROW; 
 


   of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */ 
extern int iswupper (wint_t __wc) __THROW; 
 


   in the previous subclause.  */ 
extern int iswxdigit (wint_t __wc) __THROW; 
 


   which `iswalnum' is false.  */ 
# ifdef __USE_ISOC99 
extern int iswblank (wint_t __wc) __THROW; 
# endif 
 


 */ 
 


   by the string argument PROPERTY.  */ 
extern wctype_t wctype (__const char *__property) __THROW; 
 


   DESC.  */ 
extern int iswctype (wint_t __wc, wctype_t __desc) __THROW; 
__END_NAMESPACE_C99 
 
 


 */ 
 
__BEGIN_NAMESPACE_C99 


   character mappings.  */ 
typedef __const __int32_t *wctrans_t; 
__END_NAMESPACE_C99 
#ifdef __USE_GNU 
__USING_NAMESPACE_C99(wctrans_t) 
#endif 
 
__BEGIN_NAMESPACE_C99 


/* Converts an lowercase letter to the corresponding uppercase letter.  */ 
extern wint_t towupper (wint_t __wc) __THROW; 
__END_NAMESPACE_C99 
 
__END_DECLS 
 
#endif	

   <wcsmbs.h> header.  */ 
#ifdef _WCTYPE_H 
 


 */ 
 
__BEGIN_DECLS 
 
__BEGIN_NAMESPACE_C99 


   identified by the string argument PROPERTY.  */ 
extern wctrans_t wctrans (__const char *__property) __THROW; 
 


/* Declare the interface to extended locale model.  */ 
#  include <xlocale.h> 
 


   true.  */ 
extern int iswalnum_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   `iswpunct', or `iswspace' is true.  */ 
extern int iswalpha_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   character.  */ 
extern int iswdigit_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   `iswspace' is false.  */ 
extern int iswgraph_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   none of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */ 
extern int iswlower_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   nor `iswalnum' is true.  */ 
extern int iswpunct_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   `iswpunct' is true.  */ 
extern int iswspace_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   of `iswcntrl', `iswdigit', `iswpunct', or `iswspace' is true.  */ 
extern int iswupper_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   in the previous subclause.  */ 
extern int iswxdigit_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   which `iswalnum' is false.  */ 
extern int iswblank_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   by the string argument PROPERTY.  */ 
extern wctype_t wctype_l (__const char *__property, __locale_t __locale) 
     __THROW; 
 


   DESC.  */ 
extern int iswctype_l (wint_t __wc, wctype_t __desc, __locale_t __locale) 
     __THROW; 
 
 


 */ 
 


/* Converts an lowercase letter to the corresponding uppercase letter.  */ 
extern wint_t towupper_l (wint_t __wc, __locale_t __locale) __THROW; 
 


   identified by the string argument PROPERTY.  */ 
extern wctrans_t wctrans_l (__const char *__property, __locale_t __locale) 
     __THROW; 
 


# endif /* Use GNU.  */ 
 
__END_DECLS 
 
#endif	

#endif /* wctype.h  */ 
 
 
namespace std { 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wctrans_t; 
#endif 
  using ::wctype_t; 
  using ::wint_t; 
  using ::iswalnum; 
  using ::iswctype; 
  using ::iswlower; 
  using ::iswspace; 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::towctrans; 
#endif 
#if !(defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 740) 
  using ::wctrans; 
#endif 
  using ::iswalpha; 
  using ::iswdigit; 
  using ::iswprint; 
  using ::iswupper; 
  using ::towlower; 
  using ::wctype; 
  using ::iswcntrl; 
  using ::iswgraph; 
  using ::iswpunct; 
  using ::iswxdigit; 
  using ::towupper; 
} 
 
#endif #endif // CWCTYPE_HEADER 
 
#include <bits/ios_base.h>   
namespace std 
{ 
    // NB: Don't instantiate required wchar_t facets if no wchar_t support. 
#ifdef _GLIBCXX_USE_WCHAR_T 
# define  _GLIBCXX_NUM_FACETS 28 
#else 
# define  _GLIBCXX_NUM_FACETS 14 
#endif 
 
    // Convert string to numeric value of type _Tv and store results. 
    // NB: This is specialized for all required types, there is no 
    // generic definition. 
  template<typename _Tv> 
    void 
    __convert_to_v(const char* __in, _Tv& __out, ios_base::iostate& __err, 
		   const __c_locale& __cloc); 
 
    // Explicit specializations for required types. 
  template<> 
    void 
    __convert_to_v(const char*, float&, ios_base::iostate&, 
		   const __c_locale&); 
 
  template<> 
    void 
    __convert_to_v(const char*, double&, ios_base::iostate&, 
		   const __c_locale&); 
 
  template<> 
    void 
    __convert_to_v(const char*, long double&, ios_base::iostate&, 
		   const __c_locale&); 
 
    // NB: __pad is a struct, rather than a function, so it can be 
    // partially-specialized. 
  template<typename _CharT, typename _Traits> 
    struct __pad 
    { 
      static void 
      _S_pad(ios_base& __io, _CharT __fill, _CharT* __news, 
	     const _CharT* __olds, const streamsize __newlen, 
	     const streamsize __oldlen, const bool __num); 
    }; 
 
    // Used by both numeric and monetary facets. 
    // Inserts "group separator" characters into an array of characters. 
    // It's recursive, one iteration per group.  It moves the characters 
    // in the buffer this way: "xxxx12345" -> "12,345xxx".  Call this 
    // only with __glen != 0. 
  template<typename _CharT> 
    _CharT* 
    __add_grouping(_CharT* __s, _CharT __sep, 
		   const char* __gbeg, size_t __gsize, 
		   const _CharT* __first, const _CharT* __last); 
 
    // This template permits specializing facet output code for 
    // ostreambuf_iterator.  For ostreambuf_iterator, sputn is 
    // significantly more efficient than incrementing iterators. 
  template<typename _CharT> 
    inline 
    ostreambuf_iterator<_CharT> 
    __write(ostreambuf_iterator<_CharT> __s, const _CharT* __ws, int __len) 
    { 
      __s._M_put(__ws, __len); 
      return __s; 
    } 
 
    // This is the unspecialized form of the template. 
  template<typename _CharT, typename _OutIter> 
    inline 
    _OutIter 
    __write(_OutIter __s, const _CharT* __ws, int __len) 
    { 
      for (int __j = 0; __j < __len; __j++, ++__s) 
	*__s = __ws[__j]; 
      return __s; 
    } 
 
 
    // 22.2.1.1  Template class ctype 
    // Include host and configuration specific ctype enums for ctype_base. 
  #include <bits/ctype_base.h> 
 
    // Common base for ctype<_CharT>. 
  

  */ 
  template<typename _CharT> 
    class __ctype_abstract_base : public locale::facet, public ctype_base 
    { 
    public: 
            // Types: 
            /// Typedef for the template parameter 
      typedef _CharT char_type; 
 
      

      */ 
      bool 
      is(mask __m, char_type __c) const 
      { return this->do_is(__m, __c); } 
 
      

      */ 
      const char_type* 
      is(const char_type *__lo, const char_type *__hi, mask *__vec) const 
      { return this->do_is(__lo, __hi, __vec); } 
 
      

      */ 
      const char_type* 
      scan_is(mask __m, const char_type* __lo, const char_type* __hi) const 
      { return this->do_scan_is(__m, __lo, __hi); } 
 
      

      */ 
      const char_type* 
      scan_not(mask __m, const char_type* __lo, const char_type* __hi) const 
      { return this->do_scan_not(__m, __lo, __hi); } 
 
      

      */ 
      char_type 
      toupper(char_type __c) const 
      { return this->do_toupper(__c); } 
 
      

      */ 
      const char_type* 
      toupper(char_type *__lo, const char_type* __hi) const 
      { return this->do_toupper(__lo, __hi); } 
 
      

      */ 
      char_type 
      tolower(char_type __c) const 
      { return this->do_tolower(__c); } 
 
      

      */ 
      const char_type* 
      tolower(char_type* __lo, const char_type* __hi) const 
      { return this->do_tolower(__lo, __hi); } 
 
      

      */ 
      char_type 
      widen(char __c) const 
      { return this->do_widen(__c); } 
 
      

      */ 
      const char* 
      widen(const char* __lo, const char* __hi, char_type* __to) const 
      { return this->do_widen(__lo, __hi, __to); } 
 
      

      */ 
      char 
      narrow(char_type __c, char __dfault) const 
      { return this->do_narrow(__c, __dfault); } 
 
      

      */ 
      const char_type* 
      narrow(const char_type* __lo, const char_type* __hi, 
	      char __dfault, char *__to) const 
      { return this->do_narrow(__lo, __hi, __dfault, __to); } 
 
    protected: 
      explicit 
      __ctype_abstract_base(size_t __refs = 0): facet(__refs) { } 
 
      virtual 
      ~__ctype_abstract_base() { } 
 
      

      */ 
      virtual bool 
      do_is(mask __m, char_type __c) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_is(const char_type* __lo, const char_type* __hi, 
	    mask* __vec) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_scan_is(mask __m, const char_type* __lo, 
		 const char_type* __hi) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_scan_not(mask __m, const char_type* __lo, 
		  const char_type* __hi) const = 0; 
 
      

      */ 
      virtual char_type 
      do_toupper(char_type) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_toupper(char_type* __lo, const char_type* __hi) const = 0; 
 
      

      */ 
      virtual char_type 
      do_tolower(char_type) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_tolower(char_type* __lo, const char_type* __hi) const = 0; 
 
      

      */ 
      virtual char_type 
      do_widen(char) const = 0; 
 
      

      */ 
      virtual const char* 
      do_widen(const char* __lo, const char* __hi, 
	       char_type* __dest) const = 0; 
 
      

      */ 
      virtual char 
      do_narrow(char_type, char __dfault) const = 0; 
 
      

      */ 
      virtual const char_type* 
      do_narrow(const char_type* __lo, const char_type* __hi, 
		char __dfault, char* __dest) const = 0; 
    }; 
 
    // NB: Generic, mostly useless implementation. 
  

  */ 
  template<typename _CharT> 
    class ctype : public __ctype_abstract_base<_CharT> 
    { 
    public: 
            // Types: 
      typedef _CharT			char_type; 
      typedef typename __ctype_abstract_base<_CharT>::mask mask; 
 
            /// The facet id for ctype<char_type> 
      static locale::id			id; 
 
      explicit 
      ctype(size_t __refs = 0) : __ctype_abstract_base<_CharT>(__refs) { } 
 
   protected: 
      virtual 
      ~ctype(); 
 
      virtual bool 
      do_is(mask __m, char_type __c) const; 
 
      virtual const char_type* 
      do_is(const char_type* __lo, const char_type* __hi, mask* __vec) const; 
 
      virtual const char_type* 
      do_scan_is(mask __m, const char_type* __lo, const char_type* __hi) const; 
 
      virtual const char_type* 
      do_scan_not(mask __m, const char_type* __lo, 
		  const char_type* __hi) const; 
 
      virtual char_type 
      do_toupper(char_type __c) const; 
 
      virtual const char_type* 
      do_toupper(char_type* __lo, const char_type* __hi) const; 
 
      virtual char_type 
      do_tolower(char_type __c) const; 
 
      virtual const char_type* 
      do_tolower(char_type* __lo, const char_type* __hi) const; 
 
      virtual char_type 
      do_widen(char __c) const; 
 
      virtual const char* 
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const; 
 
      virtual char 
      do_narrow(char_type, char __dfault) const; 
 
      virtual const char_type* 
      do_narrow(const char_type* __lo, const char_type* __hi, 
		char __dfault, char* __dest) const; 
    }; 
 
  template<typename _CharT> 
    locale::id ctype<_CharT>::id; 
 
    // 22.2.1.3  ctype<char> specialization. 
  

  */ 
  template<> 
    class ctype<char> : public locale::facet, public ctype_base 
    { 
    public: 
            // Types: 
            /// Typedef for the template parameter char. 
      typedef char		char_type; 
 
    protected: 
            // Data Members: 
      __c_locale		_M_c_locale_ctype; 
      bool			_M_del; 
      __to_type			_M_toupper; 
      __to_type			_M_tolower; 
      const mask*		_M_table; 
      mutable char		_M_widen_ok; 
      mutable char		_M_widen[1 + static_cast<unsigned char>(-1)]; 
      mutable char		_M_narrow[1 + static_cast<unsigned char>(-1)]; 
      mutable char		_M_narrow_ok;	      mutable char		_M_narrow_ok;	// 0 uninitialized, 1 init, 
												// 2 memcpy can't be used 
 
    public: 
            /// The facet id for ctype<char> 
      static locale::id        id; 
            /// The size of the mask table.  It is SCHAR_MAX + 1. 
      static const size_t      table_size = 1 + static_cast<unsigned char>(-1); 
 
      

      */ 
      explicit 
      ctype(const mask* __table = 0, bool __del = false, size_t __refs = 0); 
 
      

      */ 
      explicit 
      ctype(__c_locale __cloc, const mask* __table = 0, bool __del = false, 
	    size_t __refs = 0); 
 
      

      */ 
      inline bool 
      is(mask __m, char __c) const; 
 
      

      */ 
      inline const char* 
      is(const char* __lo, const char* __hi, mask* __vec) const; 
 
      

      */ 
      inline const char* 
      scan_is(mask __m, const char* __lo, const char* __hi) const; 
 
      

      */ 
      inline const char* 
      scan_not(mask __m, const char* __lo, const char* __hi) const; 
 
      

      */ 
      char_type 
      toupper(char_type __c) const 
      { return this->do_toupper(__c); } 
 
      

      */ 
      const char_type* 
      toupper(char_type *__lo, const char_type* __hi) const 
      { return this->do_toupper(__lo, __hi); } 
 
      

      */ 
      char_type 
      tolower(char_type __c) const 
      { return this->do_tolower(__c); } 
 
      

      */ 
      const char_type* 
      tolower(char_type* __lo, const char_type* __hi) const 
      { return this->do_tolower(__lo, __hi); } 
 
      

      */ 
      char_type 
      widen(char __c) const 
      { 
	if (_M_widen_ok) 
	  return _M_widen[static_cast<unsigned char>(__c)]; 
	this->_M_widen_init(); 
	return this->do_widen(__c); 
      } 
 
      

      */ 
      const char* 
      widen(const char* __lo, const char* __hi, char_type* __to) const 
      { 
	if (_M_widen_ok == 1) 
	  { 
	    memcpy(__to, __lo, __hi - __lo); 
	    return __hi; 
	  } 
	if (!_M_widen_ok) 
	  _M_widen_init(); 
	return this->do_widen(__lo, __hi, __to); 
      } 
 
      

      */ 
      char 
      narrow(char_type __c, char __dfault) const 
      { 
	if (_M_narrow[static_cast<unsigned char>(__c)]) 
	  return _M_narrow[static_cast<unsigned char>(__c)]; 
	const char __t = do_narrow(__c, __dfault); 
	if (__t != __dfault) 
	  _M_narrow[static_cast<unsigned char>(__c)] = __t; 
	return __t; 
      } 
 
      

      */ 
      const char_type* 
      narrow(const char_type* __lo, const char_type* __hi, 
	     char __dfault, char *__to) const 
      { 
	if (__builtin_expect(_M_narrow_ok == 1, true)) 
	  { 
	    memcpy(__to, __lo, __hi - __lo); 
	    return __hi; 
	  } 
	if (!_M_narrow_ok) 
	  _M_narrow_init(); 
	return this->do_narrow(__lo, __hi, __dfault, __to); 
      } 
 
    protected: 
            /// Returns a pointer to the mask table provided to the constructor, or 
            /// the default from classic_table() if none was provided. 
      const mask* 
      table() const throw() 
      { return _M_table; } 
 
            /// Returns a pointer to the C locale mask table. 
      static const mask* 
      classic_table() throw(); 
 
      

      */ 
      virtual 
      ~ctype(); 
 
      

      */ 
      virtual char_type 
      do_toupper(char_type) const; 
 
      

      */ 
      virtual const char_type* 
      do_toupper(char_type* __lo, const char_type* __hi) const; 
 
      

      */ 
      virtual char_type 
      do_tolower(char_type) const; 
 
      

      */ 
      virtual const char_type* 
      do_tolower(char_type* __lo, const char_type* __hi) const; 
 
      

      */ 
      virtual char_type 
      do_widen(char __c) const 
      { return __c; } 
 
      

      */ 
      virtual const char* 
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const 
      { 
	memcpy(__dest, __lo, __hi - __lo); 
	return __hi; 
      } 
 
      

      */ 
      virtual char 
      do_narrow(char_type __c, char) const 
      { return __c; } 
 
      

      */ 
      virtual const char_type* 
      do_narrow(const char_type* __lo, const char_type* __hi, 
		char, char* __dest) const 
      { 
	memcpy(__dest, __lo, __hi - __lo); 
	return __hi; 
      } 
 
    private: 
 
      void _M_widen_init() const 
      { 
	char __tmp[sizeof(_M_widen)]; 
	for (size_t __i = 0; __i < sizeof(_M_widen); ++__i) 
	  __tmp[__i] = __i; 
	do_widen(__tmp, __tmp + sizeof(__tmp), _M_widen); 
 
	_M_widen_ok = 1; 
		// Set _M_widen_ok to 2 if memcpy can't be used. 
	if (memcmp(__tmp, _M_widen, sizeof(_M_widen))) 
	  _M_widen_ok = 2; 
      } 
 
            // Fill in the narrowing cache and flag whether all values are 
            // valid or not.  _M_narrow_ok is set to 2 if memcpy can't 
            // be used. 
      void _M_narrow_init() const 
      { 
	char __tmp[sizeof(_M_narrow)]; 
	for (size_t __i = 0; __i < sizeof(_M_narrow); ++__i) 
	  __tmp[__i] = __i; 
	do_narrow(__tmp, __tmp + sizeof(__tmp), 0, _M_narrow); 
 
	_M_narrow_ok = 1; 
	if (memcmp(__tmp, _M_narrow, sizeof(_M_narrow))) 
	  _M_narrow_ok = 2; 
	else 
	  { 
	    	    // Deal with the special case of zero: renarrow with a 
	    	    // different default and compare. 
	    char __c; 
	    do_narrow(__tmp, __tmp + 1, 1, &__c); 
	    if (__c == 1) 
	      _M_narrow_ok = 2; 
	  } 
      } 
    }; 
 
  template<> 
    const ctype<char>& 
    use_facet<ctype<char> >(const locale& __loc); 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
    // 22.2.1.3  ctype<wchar_t> specialization 
  

  */ 
  template<> 
    class ctype<wchar_t> : public __ctype_abstract_base<wchar_t> 
    { 
    public: 
            // Types: 
            /// Typedef for the template parameter wchar_t. 
      typedef wchar_t		char_type; 
      typedef wctype_t		__wmask_type; 
 
    protected: 
      __c_locale		_M_c_locale_ctype; 
 
            // Pre-computed narrowed and widened chars. 
      bool                      _M_narrow_ok; 
      char                      _M_narrow[128]; 
      wint_t                    _M_widen[1 + static_cast<unsigned char>(-1)]; 
 
            // Pre-computed elements for do_is. 
      mask                      _M_bit[16]; 
      __wmask_type              _M_wmask[16]; 
 
    public: 
            // Data Members: 
            /// The facet id for ctype<wchar_t> 
      static locale::id		id; 
 
      

      */ 
      explicit 
      ctype(size_t __refs = 0); 
 
      

      */ 
      explicit 
      ctype(__c_locale __cloc, size_t __refs = 0); 
 
    protected: 
      __wmask_type 
      _M_convert_to_wmask(const mask __m) const; 
 
            /// Destructor 
      virtual 
      ~ctype(); 
 
      

      */ 
      virtual bool 
      do_is(mask __m, char_type __c) const; 
 
      

      */ 
      virtual const char_type* 
      do_is(const char_type* __lo, const char_type* __hi, mask* __vec) const; 
 
      

      */ 
      virtual const char_type* 
      do_scan_is(mask __m, const char_type* __lo, const char_type* __hi) const; 
 
      

      */ 
      virtual const char_type* 
      do_scan_not(mask __m, const char_type* __lo, 
		  const char_type* __hi) const; 
 
      

      */ 
      virtual char_type 
      do_toupper(char_type) const; 
 
      

      */ 
      virtual const char_type* 
      do_toupper(char_type* __lo, const char_type* __hi) const; 
 
      

      */ 
      virtual char_type 
      do_tolower(char_type) const; 
 
      

      */ 
      virtual const char_type* 
      do_tolower(char_type* __lo, const char_type* __hi) const; 
 
      

      */ 
      virtual char_type 
      do_widen(char) const; 
 
      

      */ 
      virtual const char* 
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const; 
 
      

      */ 
      virtual char 
      do_narrow(char_type, char __dfault) const; 
 
      

      */ 
      virtual const char_type* 
      do_narrow(const char_type* __lo, const char_type* __hi, 
		char __dfault, char* __dest) const; 
 
            // For use at construction time only. 
      void 
      _M_initialize_ctype(); 
    }; 
 
  template<> 
    const ctype<wchar_t>& 
    use_facet<ctype<wchar_t> >(const locale& __loc); 
#endif #endif //_GLIBCXX_USE_WCHAR_T 
 
    // Include host and configuration specific ctype inlines. 
  #include <bits/ctype_inline.h> 
 
    /// @brief  class ctype_byname [22.2.1.2]. 
  template<typename _CharT> 
    class ctype_byname : public ctype<_CharT> 
    { 
    public: 
      typedef _CharT		char_type; 
 
      explicit 
      ctype_byname(const char* __s, size_t __refs = 0); 
 
    protected: 
      virtual 
      ~ctype_byname() { }; 
    }; 
 
    /// 22.2.1.4  Class ctype_byname specializations. 
  template<> 
    ctype_byname<char>::ctype_byname(const char*, size_t refs); 
 
  template<> 
    ctype_byname<wchar_t>::ctype_byname(const char*, size_t refs); 
 
    // 22.2.1.5  Template class codecvt 
  #include <bits/codecvt.h> 
 
    // 22.2.2  The numeric category. 
  class __num_base 
  { 
  public: 
        // NB: Code depends on the order of _S_atoms_out elements. 
        // Below are the indices into _S_atoms_out. 
    enum 
      { 
        _S_ominus, 
        _S_oplus, 
        _S_ox, 
        _S_oX, 
        _S_odigits, 
        _S_odigits_end = _S_odigits + 16, 
        _S_oudigits = _S_odigits_end, 
        _S_oudigits_end = _S_oudigits + 16, 
        _S_oe = _S_odigits + 14,          _S_oe = _S_odigits + 14,  // For scientific notation, 'e' 
        _S_oE = _S_oudigits + 14,         _S_oE = _S_oudigits + 14, // For scientific notation, 'E' 
	_S_oend = _S_oudigits_end 
      }; 
 
        // A list of valid numeric literals for output.  This array 
        // contains chars that will be passed through the current locale's 
        // ctype<_CharT>.widen() and then used to render numbers. 
        // For the standard "C" locale, this is 
        // "-+xX0123456789abcdef0123456789ABCDEF". 
    static const char* _S_atoms_out; 
 
        // String literal of acceptable (narrow) input, for num_get. 
        // "-+xX0123456789abcdefABCDEF" 
    static const char* _S_atoms_in; 
 
    enum 
    { 
      _S_iminus, 
      _S_iplus, 
      _S_ix, 
      _S_iX, 
      _S_izero, 
      _S_ie = _S_izero + 14, 
      _S_iE = _S_izero + 20, 
      _S_iend = 26 
    }; 
 
        // num_put 
        // Construct and return valid scanf format for floating point types. 
    static void 
    _S_format_float(const ios_base& __io, char* __fptr, char __mod); 
  }; 
 
  template<typename _CharT> 
    struct __numpunct_cache : public locale::facet 
    { 
      const char*			_M_grouping; 
      size_t                            _M_grouping_size; 
      bool				_M_use_grouping; 
      const _CharT*			_M_truename; 
      size_t                            _M_truename_size; 
      const _CharT*			_M_falsename; 
      size_t                            _M_falsename_size; 
      _CharT				_M_decimal_point; 
      _CharT				_M_thousands_sep; 
 
            // A list of valid numeric literals for output: in the standard 
            // "C" locale, this is "-+xX0123456789abcdef0123456789ABCDEF". 
            // This array contains the chars after having been passed 
            // through the current locale's ctype<_CharT>.widen(). 
      _CharT				_M_atoms_out[__num_base::_S_oend]; 
 
            // A list of valid numeric literals for input: in the standard 
            // "C" locale, this is "-+xX0123456789abcdefABCDEF" 
            // This array contains the chars after having been passed 
            // through the current locale's ctype<_CharT>.widen(). 
      _CharT				_M_atoms_in[__num_base::_S_iend]; 
 
      bool				_M_allocated; 
 
      __numpunct_cache(size_t __refs = 0) : facet(__refs), 
      _M_grouping(NULL), _M_grouping_size(0), _M_use_grouping(false), 
      _M_truename(NULL), _M_truename_size(0), _M_falsename(NULL), 
      _M_falsename_size(0), _M_decimal_point(_CharT()), 
      _M_thousands_sep(_CharT()), _M_allocated(false) 
      { } 
 
      ~__numpunct_cache(); 
 
      void 
      _M_cache(const locale& __loc); 
 
    private: 
      __numpunct_cache& 
      operator=(const __numpunct_cache&); 
       
      explicit 
      __numpunct_cache(const __numpunct_cache&); 
    }; 
 
  template<typename _CharT> 
    __numpunct_cache<_CharT>::~__numpunct_cache() 
    { 
      if (_M_allocated) 
	{ 
	  delete [] _M_grouping; 
	  delete [] _M_truename; 
	  delete [] _M_falsename; 
	} 
    } 
 
  

  */ 
  template<typename _CharT> 
    class numpunct : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
      typedef __numpunct_cache<_CharT>  __cache_type; 
 
    protected: 
      __cache_type*			_M_data; 
 
    public: 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

       */ 
      explicit 
      numpunct(size_t __refs = 0) : facet(__refs), _M_data(NULL) 
      { _M_initialize_numpunct(); } 
 
      

       */ 
      explicit 
      numpunct(__cache_type* __cache, size_t __refs = 0) 
      : facet(__refs), _M_data(__cache) 
      { _M_initialize_numpunct(); } 
 
      

       */ 
      explicit 
      numpunct(__c_locale __cloc, size_t __refs = 0) 
      : facet(__refs), _M_data(NULL) 
      { _M_initialize_numpunct(__cloc); } 
 
      

      */ 
      char_type 
      decimal_point() const 
      { return this->do_decimal_point(); } 
 
      

      */ 
      char_type 
      thousands_sep() const 
      { return this->do_thousands_sep(); } 
 
      

      */ 
      string 
      grouping() const 
      { return this->do_grouping(); } 
 
      

      */ 
      string_type 
      truename() const 
      { return this->do_truename(); } 
 
      

      */ 
      string_type 
      falsename() const 
      { return this->do_falsename(); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~numpunct(); 
 
      

      */ 
      virtual char_type 
      do_decimal_point() const 
      { return _M_data->_M_decimal_point; } 
 
      

      */ 
      virtual char_type 
      do_thousands_sep() const 
      { return _M_data->_M_thousands_sep; } 
 
      

      */ 
      virtual string 
      do_grouping() const 
      { return _M_data->_M_grouping; } 
 
      

      */ 
      virtual string_type 
      do_truename() const 
      { return _M_data->_M_truename; } 
 
      

      */ 
      virtual string_type 
      do_falsename() const 
      { return _M_data->_M_falsename; } 
 
            // For use at construction time only. 
      void 
      _M_initialize_numpunct(__c_locale __cloc = NULL); 
    }; 
 
  template<typename _CharT> 
    locale::id numpunct<_CharT>::id; 
 
  template<> 
    numpunct<char>::~numpunct(); 
 
  template<> 
    void 
    numpunct<char>::_M_initialize_numpunct(__c_locale __cloc); 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    numpunct<wchar_t>::~numpunct(); 
 
  template<> 
    void 
    numpunct<wchar_t>::_M_initialize_numpunct(__c_locale __cloc); 
#endif 
 
    /// @brief  class numpunct_byname [22.2.3.2]. 
  template<typename _CharT> 
    class numpunct_byname : public numpunct<_CharT> 
    { 
    public: 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
 
      explicit 
      numpunct_byname(const char* __s, size_t __refs = 0) 
      : numpunct<_CharT>(__refs) 
      { 
	if (std::strcmp(__s, "C") != 0 && std::strcmp(__s, "POSIX") != 0) 
	  { 
	    __c_locale __tmp; 
	    this->_S_create_c_locale(__tmp, __s); 
	    this->_M_initialize_numpunct(__tmp); 
	    this->_S_destroy_c_locale(__tmp); 
	  } 
      } 
 
    protected: 
      virtual 
      ~numpunct_byname() { } 
    }; 
 
_GLIBCXX_BEGIN_LDBL_NAMESPACE 
  

  */ 
  template<typename _CharT, typename _InIter> 
    class num_get : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef _InIter			iter_type; 
            //@} 
 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      num_get(size_t __refs = 0) : facet(__refs) { } 
 
      

      */ 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, bool& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
            //@{ 
      

      */ 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, long& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, unsigned short& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, unsigned int& __v)   const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, unsigned long& __v)  const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, long long& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, unsigned long long& __v)  const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
#endif 
            //@} 
 
            //@{ 
      

      */ 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, float& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, double& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, long double& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
            //@} 
 
      

      */ 
      iter_type 
      get(iter_type __in, iter_type __end, ios_base& __io, 
	  ios_base::iostate& __err, void*& __v) const 
      { return this->do_get(__in, __end, __io, __err, __v); } 
 
    protected: 
            /// Destructor. 
      virtual ~num_get() { } 
 
      iter_type 
      _M_extract_float(iter_type, iter_type, ios_base&, ios_base::iostate&, 
		       string& __xtrc) const; 
 
      template<typename _ValueT> 
        iter_type 
        _M_extract_int(iter_type, iter_type, ios_base&, ios_base::iostate&, 
		       _ValueT& __v) const; 
 
            //@{ 
      

      */ 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, bool&) const; 
 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, long&) const; 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	      unsigned short&) const; 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     unsigned int&) const; 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     unsigned long&) const; 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     long long&) const; 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     unsigned long long&) const; 
#endif 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     float&) const; 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     double&) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      __do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	       double&) const; 
#else 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     long double&) const; 
#endif 
 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     void*&) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err, 
	     long double&) const; 
#endif 
            //@} 
    }; 
 
  template<typename _CharT, typename _InIter> 
    locale::id num_get<_CharT, _InIter>::id; 
 
 
  

  */ 
  template<typename _CharT, typename _OutIter> 
    class num_put : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT		char_type; 
      typedef _OutIter		iter_type; 
            //@} 
 
            /// Numpunct facet id. 
      static locale::id		id; 
 
      

      */ 
      explicit 
      num_put(size_t __refs = 0) : facet(__refs) { } 
 
      

      */ 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, bool __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
            //@{ 
      

      */ 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, long __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, 
	  unsigned long __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, long long __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, 
	  unsigned long long __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
#endif 
            //@} 
 
            //@{ 
      

      */ 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, double __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, 
	  long double __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
            //@} 
 
      

      */ 
      iter_type 
      put(iter_type __s, ios_base& __f, char_type __fill, 
	  const void* __v) const 
      { return this->do_put(__s, __f, __fill, __v); } 
 
    protected: 
      template<typename _ValueT> 
        iter_type 
        _M_insert_float(iter_type, ios_base& __io, char_type __fill, 
			char __mod, _ValueT __v) const; 
 
      void 
      _M_group_float(const char* __grouping, size_t __grouping_size, 
		     char_type __sep, const char_type* __p, char_type* __new, 
		     char_type* __cs, int& __len) const; 
 
      template<typename _ValueT> 
        iter_type 
        _M_insert_int(iter_type, ios_base& __io, char_type __fill, 
		      _ValueT __v) const; 
 
      void 
      _M_group_int(const char* __grouping, size_t __grouping_size, 
		   char_type __sep, ios_base& __io, char_type* __new, 
		   char_type* __cs, int& __len) const; 
 
      void 
      _M_pad(char_type __fill, streamsize __w, ios_base& __io, 
	     char_type* __new, const char_type* __cs, int& __len) const; 
 
            /// Destructor. 
      virtual 
      ~num_put() { }; 
 
            //@{ 
      

      */ 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, bool __v) const; 
 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, long __v) const; 
 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, unsigned long) const; 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, long long __v) const; 
 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, unsigned long long) const; 
#endif 
 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, double __v) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      __do_put(iter_type, ios_base&, char_type __fill, double __v) const; 
#else 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, long double __v) const; 
#endif 
 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, const void* __v) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      do_put(iter_type, ios_base&, char_type __fill, long double __v) const; 
#endif 
            //@} 
    }; 
 
  template <typename _CharT, typename _OutIter> 
    locale::id num_put<_CharT, _OutIter>::id; 
 
_GLIBCXX_END_LDBL_NAMESPACE 
 
  

  */ 
  template<typename _CharT> 
    class collate : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
 
    protected: 
            // Underlying "C" library locale information saved from 
            // initialization, needed by collate_byname as well. 
      __c_locale			_M_c_locale_collate; 
 
    public: 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      collate(size_t __refs = 0) 
      : facet(__refs), _M_c_locale_collate(_S_get_c_locale()) 
      { } 
 
      

      */ 
      explicit 
      collate(__c_locale __cloc, size_t __refs = 0) 
      : facet(__refs), _M_c_locale_collate(_S_clone_c_locale(__cloc)) 
      { } 
 
      

      */ 
      int 
      compare(const _CharT* __lo1, const _CharT* __hi1, 
	      const _CharT* __lo2, const _CharT* __hi2) const 
      { return this->do_compare(__lo1, __hi1, __lo2, __hi2); } 
 
      

      */ 
      string_type 
      transform(const _CharT* __lo, const _CharT* __hi) const 
      { return this->do_transform(__lo, __hi); } 
 
      

      */ 
      long 
      hash(const _CharT* __lo, const _CharT* __hi) const 
      { return this->do_hash(__lo, __hi); } 
 
            // Used to abstract out _CharT bits in virtual member functions, below. 
      int 
      _M_compare(const _CharT*, const _CharT*) const; 
 
      size_t 
      _M_transform(_CharT*, const _CharT*, size_t) const; 
 
  protected: 
            /// Destructor. 
      virtual 
      ~collate() 
      { _S_destroy_c_locale(_M_c_locale_collate); } 
 
      

      */ 
      virtual int 
      do_compare(const _CharT* __lo1, const _CharT* __hi1, 
		 const _CharT* __lo2, const _CharT* __hi2) const; 
 
      

      */ 
      virtual string_type 
      do_transform(const _CharT* __lo, const _CharT* __hi) const; 
 
      

      */ 
      virtual long 
      do_hash(const _CharT* __lo, const _CharT* __hi) const; 
    }; 
 
  template<typename _CharT> 
    locale::id collate<_CharT>::id; 
 
    // Specializations. 
  template<> 
    int 
    collate<char>::_M_compare(const char*, const char*) const; 
 
  template<> 
    size_t 
    collate<char>::_M_transform(char*, const char*, size_t) const; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    int 
    collate<wchar_t>::_M_compare(const wchar_t*, const wchar_t*) const; 
 
  template<> 
    size_t 
    collate<wchar_t>::_M_transform(wchar_t*, const wchar_t*, size_t) const; 
#endif 
 
    /// @brief  class collate_byname [22.2.4.2]. 
  template<typename _CharT> 
    class collate_byname : public collate<_CharT> 
    { 
    public: 
            //@{ 
            /// Public typedefs 
      typedef _CharT               char_type; 
      typedef basic_string<_CharT> string_type; 
            //@} 
 
      explicit 
      collate_byname(const char* __s, size_t __refs = 0) 
      : collate<_CharT>(__refs) 
      { 
	if (std::strcmp(__s, "C") != 0 && std::strcmp(__s, "POSIX") != 0) 
	  { 
	    this->_S_destroy_c_locale(this->_M_c_locale_collate); 
	    this->_S_create_c_locale(this->_M_c_locale_collate, __s); 
	  } 
      } 
 
    protected: 
      virtual 
      ~collate_byname() { } 
    }; 
 
 
  

  */ 
  class time_base 
  { 
  public: 
    enum dateorder { no_order, dmy, mdy, ymd, ydm }; 
  }; 
 
  template<typename _CharT> 
    struct __timepunct_cache : public locale::facet 
    { 
            // List of all known timezones, with GMT first. 
      static const _CharT*		_S_timezones[14]; 
 
      const _CharT*			_M_date_format; 
      const _CharT*			_M_date_era_format; 
      const _CharT*			_M_time_format; 
      const _CharT*			_M_time_era_format; 
      const _CharT*			_M_date_time_format; 
      const _CharT*			_M_date_time_era_format; 
      const _CharT*			_M_am; 
      const _CharT*			_M_pm; 
      const _CharT*			_M_am_pm_format; 
 
            // Day names, starting with "C"'s Sunday. 
      const _CharT*			_M_day1; 
      const _CharT*			_M_day2; 
      const _CharT*			_M_day3; 
      const _CharT*			_M_day4; 
      const _CharT*			_M_day5; 
      const _CharT*			_M_day6; 
      const _CharT*			_M_day7; 
 
            // Abbreviated day names, starting with "C"'s Sun. 
      const _CharT*			_M_aday1; 
      const _CharT*			_M_aday2; 
      const _CharT*			_M_aday3; 
      const _CharT*			_M_aday4; 
      const _CharT*			_M_aday5; 
      const _CharT*			_M_aday6; 
      const _CharT*			_M_aday7; 
 
            // Month names, starting with "C"'s January. 
      const _CharT*			_M_month01; 
      const _CharT*			_M_month02; 
      const _CharT*			_M_month03; 
      const _CharT*			_M_month04; 
      const _CharT*			_M_month05; 
      const _CharT*			_M_month06; 
      const _CharT*			_M_month07; 
      const _CharT*			_M_month08; 
      const _CharT*			_M_month09; 
      const _CharT*			_M_month10; 
      const _CharT*			_M_month11; 
      const _CharT*			_M_month12; 
 
            // Abbreviated month names, starting with "C"'s Jan. 
      const _CharT*			_M_amonth01; 
      const _CharT*			_M_amonth02; 
      const _CharT*			_M_amonth03; 
      const _CharT*			_M_amonth04; 
      const _CharT*			_M_amonth05; 
      const _CharT*			_M_amonth06; 
      const _CharT*			_M_amonth07; 
      const _CharT*			_M_amonth08; 
      const _CharT*			_M_amonth09; 
      const _CharT*			_M_amonth10; 
      const _CharT*			_M_amonth11; 
      const _CharT*			_M_amonth12; 
 
      bool				_M_allocated; 
 
      __timepunct_cache(size_t __refs = 0) : facet(__refs), 
      _M_date_format(NULL), _M_date_era_format(NULL), _M_time_format(NULL), 
      _M_time_era_format(NULL), _M_date_time_format(NULL), 
      _M_date_time_era_format(NULL), _M_am(NULL), _M_pm(NULL), 
      _M_am_pm_format(NULL), _M_day1(NULL), _M_day2(NULL), _M_day3(NULL), 
      _M_day4(NULL), _M_day5(NULL), _M_day6(NULL), _M_day7(NULL), 
      _M_aday1(NULL), _M_aday2(NULL), _M_aday3(NULL), _M_aday4(NULL), 
      _M_aday5(NULL), _M_aday6(NULL), _M_aday7(NULL), _M_month01(NULL), 
      _M_month02(NULL), _M_month03(NULL), _M_month04(NULL), _M_month05(NULL), 
      _M_month06(NULL), _M_month07(NULL), _M_month08(NULL), _M_month09(NULL), 
      _M_month10(NULL), _M_month11(NULL), _M_month12(NULL), _M_amonth01(NULL), 
      _M_amonth02(NULL), _M_amonth03(NULL), _M_amonth04(NULL), 
      _M_amonth05(NULL), _M_amonth06(NULL), _M_amonth07(NULL), 
      _M_amonth08(NULL), _M_amonth09(NULL), _M_amonth10(NULL), 
      _M_amonth11(NULL), _M_amonth12(NULL), _M_allocated(false) 
      { } 
 
      ~__timepunct_cache(); 
 
      void 
      _M_cache(const locale& __loc); 
 
    private: 
      __timepunct_cache& 
      operator=(const __timepunct_cache&); 
       
      explicit 
      __timepunct_cache(const __timepunct_cache&); 
    }; 
 
  template<typename _CharT> 
    __timepunct_cache<_CharT>::~__timepunct_cache() 
    { 
      if (_M_allocated) 
	{ 
	  	  // Unused. 
	} 
    } 
 
    // Specializations. 
  template<> 
    const char* 
    __timepunct_cache<char>::_S_timezones[14]; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    const wchar_t* 
    __timepunct_cache<wchar_t>::_S_timezones[14]; 
#endif 
 
    // Generic. 
  template<typename _CharT> 
    const _CharT* __timepunct_cache<_CharT>::_S_timezones[14]; 
 
  template<typename _CharT> 
    class __timepunct : public locale::facet 
    { 
    public: 
            // Types: 
      typedef _CharT			__char_type; 
      typedef basic_string<_CharT>	__string_type; 
      typedef __timepunct_cache<_CharT>	__cache_type; 
 
    protected: 
      __cache_type*			_M_data; 
      __c_locale			_M_c_locale_timepunct; 
      const char*			_M_name_timepunct; 
 
    public: 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      explicit 
      __timepunct(size_t __refs = 0); 
 
      explicit 
      __timepunct(__cache_type* __cache, size_t __refs = 0); 
 
      

      */ 
      explicit 
      __timepunct(__c_locale __cloc, const char* __s, size_t __refs = 0); 
 
            // FIXME: for error checking purposes _M_put should return the return 
            // value of strftime/wcsftime. 
      void 
      _M_put(_CharT* __s, size_t __maxlen, const _CharT* __format, 
	     const tm* __tm) const; 
 
      void 
      _M_date_formats(const _CharT** __date) const 
      { 
		// Always have default first. 
	__date[0] = _M_data->_M_date_format; 
	__date[1] = _M_data->_M_date_era_format; 
      } 
 
      void 
      _M_time_formats(const _CharT** __time) const 
      { 
		// Always have default first. 
	__time[0] = _M_data->_M_time_format; 
	__time[1] = _M_data->_M_time_era_format; 
      } 
 
      void 
      _M_date_time_formats(const _CharT** __dt) const 
      { 
		// Always have default first. 
	__dt[0] = _M_data->_M_date_time_format; 
	__dt[1] = _M_data->_M_date_time_era_format; 
      } 
 
      void 
      _M_am_pm_format(const _CharT* __ampm) const 
      { __ampm = _M_data->_M_am_pm_format; } 
 
      void 
      _M_am_pm(const _CharT** __ampm) const 
      { 
	__ampm[0] = _M_data->_M_am; 
	__ampm[1] = _M_data->_M_pm; 
      } 
 
      void 
      _M_days(const _CharT** __days) const 
      { 
	__days[0] = _M_data->_M_day1; 
	__days[1] = _M_data->_M_day2; 
	__days[2] = _M_data->_M_day3; 
	__days[3] = _M_data->_M_day4; 
	__days[4] = _M_data->_M_day5; 
	__days[5] = _M_data->_M_day6; 
	__days[6] = _M_data->_M_day7; 
      } 
 
      void 
      _M_days_abbreviated(const _CharT** __days) const 
      { 
	__days[0] = _M_data->_M_aday1; 
	__days[1] = _M_data->_M_aday2; 
	__days[2] = _M_data->_M_aday3; 
	__days[3] = _M_data->_M_aday4; 
	__days[4] = _M_data->_M_aday5; 
	__days[5] = _M_data->_M_aday6; 
	__days[6] = _M_data->_M_aday7; 
      } 
 
      void 
      _M_months(const _CharT** __months) const 
      { 
	__months[0] = _M_data->_M_month01; 
	__months[1] = _M_data->_M_month02; 
	__months[2] = _M_data->_M_month03; 
	__months[3] = _M_data->_M_month04; 
	__months[4] = _M_data->_M_month05; 
	__months[5] = _M_data->_M_month06; 
	__months[6] = _M_data->_M_month07; 
	__months[7] = _M_data->_M_month08; 
	__months[8] = _M_data->_M_month09; 
	__months[9] = _M_data->_M_month10; 
	__months[10] = _M_data->_M_month11; 
	__months[11] = _M_data->_M_month12; 
      } 
 
      void 
      _M_months_abbreviated(const _CharT** __months) const 
      { 
	__months[0] = _M_data->_M_amonth01; 
	__months[1] = _M_data->_M_amonth02; 
	__months[2] = _M_data->_M_amonth03; 
	__months[3] = _M_data->_M_amonth04; 
	__months[4] = _M_data->_M_amonth05; 
	__months[5] = _M_data->_M_amonth06; 
	__months[6] = _M_data->_M_amonth07; 
	__months[7] = _M_data->_M_amonth08; 
	__months[8] = _M_data->_M_amonth09; 
	__months[9] = _M_data->_M_amonth10; 
	__months[10] = _M_data->_M_amonth11; 
	__months[11] = _M_data->_M_amonth12; 
      } 
 
    protected: 
      virtual 
      ~__timepunct(); 
 
            // For use at construction time only. 
      void 
      _M_initialize_timepunct(__c_locale __cloc = NULL); 
    }; 
 
  template<typename _CharT> 
    locale::id __timepunct<_CharT>::id; 
 
    // Specializations. 
  template<> 
    void 
    __timepunct<char>::_M_initialize_timepunct(__c_locale __cloc); 
 
  template<> 
    void 
    __timepunct<char>::_M_put(char*, size_t, const char*, const tm*) const; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    void 
    __timepunct<wchar_t>::_M_initialize_timepunct(__c_locale __cloc); 
 
  template<> 
    void 
    __timepunct<wchar_t>::_M_put(wchar_t*, size_t, const wchar_t*, 
				 const tm*) const; 
#endif 
 
    // Include host and configuration specific timepunct functions. 
  #include <bits/time_members.h> 
 
  

  */ 
  template<typename _CharT, typename _InIter> 
    class time_get : public locale::facet, public time_base 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef _InIter			iter_type; 
            //@} 
      typedef basic_string<_CharT>	__string_type; 
 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      time_get(size_t __refs = 0) 
      : facet (__refs) { } 
 
      

      */ 
      dateorder 
      date_order()  const 
      { return this->do_date_order(); } 
 
      

      */ 
      iter_type 
      get_time(iter_type __beg, iter_type __end, ios_base& __io, 
	       ios_base::iostate& __err, tm* __tm)  const 
      { return this->do_get_time(__beg, __end, __io, __err, __tm); } 
 
      

      */ 
      iter_type 
      get_date(iter_type __beg, iter_type __end, ios_base& __io, 
	       ios_base::iostate& __err, tm* __tm)  const 
      { return this->do_get_date(__beg, __end, __io, __err, __tm); } 
 
      

      */ 
      iter_type 
      get_weekday(iter_type __beg, iter_type __end, ios_base& __io, 
		  ios_base::iostate& __err, tm* __tm) const 
      { return this->do_get_weekday(__beg, __end, __io, __err, __tm); } 
 
      

      */ 
      iter_type 
      get_monthname(iter_type __beg, iter_type __end, ios_base& __io, 
		    ios_base::iostate& __err, tm* __tm) const 
      { return this->do_get_monthname(__beg, __end, __io, __err, __tm); } 
 
      

      */ 
      iter_type 
      get_year(iter_type __beg, iter_type __end, ios_base& __io, 
	       ios_base::iostate& __err, tm* __tm) const 
      { return this->do_get_year(__beg, __end, __io, __err, __tm); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~time_get() { } 
 
      

      */ 
      virtual dateorder 
      do_date_order() const; 
 
      

      */ 
      virtual iter_type 
      do_get_time(iter_type __beg, iter_type __end, ios_base& __io, 
		  ios_base::iostate& __err, tm* __tm) const; 
 
      

      */ 
      virtual iter_type 
      do_get_date(iter_type __beg, iter_type __end, ios_base& __io, 
		  ios_base::iostate& __err, tm* __tm) const; 
 
      

      */ 
      virtual iter_type 
      do_get_weekday(iter_type __beg, iter_type __end, ios_base&, 
		     ios_base::iostate& __err, tm* __tm) const; 
 
      

      */ 
      virtual iter_type 
      do_get_monthname(iter_type __beg, iter_type __end, ios_base&, 
		       ios_base::iostate& __err, tm* __tm) const; 
 
      

      */ 
      virtual iter_type 
      do_get_year(iter_type __beg, iter_type __end, ios_base& __io, 
		  ios_base::iostate& __err, tm* __tm) const; 
 
            // Extract numeric component of length __len. 
      iter_type 
      _M_extract_num(iter_type __beg, iter_type __end, int& __member, 
		     int __min, int __max, size_t __len, 
		     ios_base& __io, ios_base::iostate& __err) const; 
 
            // Extract day or month name, or any unique array of string 
            // literals in a const _CharT* array. 
      iter_type 
      _M_extract_name(iter_type __beg, iter_type __end, int& __member, 
		      const _CharT** __names, size_t __indexlen, 
		      ios_base& __io, ios_base::iostate& __err) const; 
 
            // Extract on a component-by-component basis, via __format argument. 
      iter_type 
      _M_extract_via_format(iter_type __beg, iter_type __end, ios_base& __io, 
			    ios_base::iostate& __err, tm* __tm, 
			    const _CharT* __format) const; 
    }; 
 
  template<typename _CharT, typename _InIter> 
    locale::id time_get<_CharT, _InIter>::id; 
 
    /// @brief  class time_get_byname [22.2.5.2]. 
  template<typename _CharT, typename _InIter> 
    class time_get_byname : public time_get<_CharT, _InIter> 
    { 
    public: 
            // Types: 
      typedef _CharT			char_type; 
      typedef _InIter			iter_type; 
 
      explicit 
      time_get_byname(const char*, size_t __refs = 0) 
      : time_get<_CharT, _InIter>(__refs) { } 
 
    protected: 
      virtual 
      ~time_get_byname() { } 
    }; 
 
  

  */ 
  template<typename _CharT, typename _OutIter> 
    class time_put : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef _OutIter			iter_type; 
            //@} 
 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      time_put(size_t __refs = 0) 
      : facet(__refs) { } 
 
      

       */ 
      iter_type 
      put(iter_type __s, ios_base& __io, char_type __fill, const tm* __tm, 
	  const _CharT* __beg, const _CharT* __end) const; 
 
      

       */ 
      iter_type 
      put(iter_type __s, ios_base& __io, char_type __fill, 
	  const tm* __tm, char __format, char __mod = 0) const 
      { return this->do_put(__s, __io, __fill, __tm, __format, __mod); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~time_put() 
      { } 
 
      

       */ 
      virtual iter_type 
      do_put(iter_type __s, ios_base& __io, char_type __fill, const tm* __tm, 
	     char __format, char __mod) const; 
    }; 
 
  template<typename _CharT, typename _OutIter> 
    locale::id time_put<_CharT, _OutIter>::id; 
 
    /// @brief  class time_put_byname [22.2.5.4]. 
  template<typename _CharT, typename _OutIter> 
    class time_put_byname : public time_put<_CharT, _OutIter> 
    { 
    public: 
            // Types: 
      typedef _CharT			char_type; 
      typedef _OutIter			iter_type; 
 
      explicit 
      time_put_byname(const char*, size_t __refs = 0) 
      : time_put<_CharT, _OutIter>(__refs) 
      { }; 
 
    protected: 
      virtual 
      ~time_put_byname() { } 
    }; 
 
 
  

  */ 
  class money_base 
  { 
  public: 
    enum part { none, space, symbol, sign, value }; 
    struct pattern { char field[4]; }; 
 
    static const pattern _S_default_pattern; 
 
    enum 
    { 
      _S_minus, 
      _S_zero, 
      _S_end = 11 
    }; 
 
        // String literal of acceptable (narrow) input/output, for 
        // money_get/money_put. "-0123456789" 
    static const char* _S_atoms; 
 
        // Construct and return valid pattern consisting of some combination of: 
        // space none symbol sign value 
    static pattern 
    _S_construct_pattern(char __precedes, char __space, char __posn); 
  }; 
 
  template<typename _CharT, bool _Intl> 
    struct __moneypunct_cache : public locale::facet 
    { 
      const char*			_M_grouping; 
      size_t                            _M_grouping_size; 
      bool				_M_use_grouping; 
      _CharT				_M_decimal_point; 
      _CharT				_M_thousands_sep; 
      const _CharT*			_M_curr_symbol; 
      size_t                            _M_curr_symbol_size; 
      const _CharT*			_M_positive_sign; 
      size_t                            _M_positive_sign_size; 
      const _CharT*			_M_negative_sign; 
      size_t                            _M_negative_sign_size; 
      int				_M_frac_digits; 
      money_base::pattern		_M_pos_format; 
      money_base::pattern	        _M_neg_format; 
 
            // A list of valid numeric literals for input and output: in the standard 
            // "C" locale, this is "-0123456789". This array contains the chars after 
            // having been passed through the current locale's ctype<_CharT>.widen(). 
      _CharT				_M_atoms[money_base::_S_end]; 
 
      bool				_M_allocated; 
 
      __moneypunct_cache(size_t __refs = 0) : facet(__refs), 
      _M_grouping(NULL), _M_grouping_size(0), _M_use_grouping(false), 
      _M_decimal_point(_CharT()), _M_thousands_sep(_CharT()), 
      _M_curr_symbol(NULL), _M_curr_symbol_size(0), 
      _M_positive_sign(NULL), _M_positive_sign_size(0), 
      _M_negative_sign(NULL), _M_negative_sign_size(0), 
      _M_frac_digits(0), 
      _M_pos_format(money_base::pattern()), 
      _M_neg_format(money_base::pattern()), _M_allocated(false) 
      { } 
 
      ~__moneypunct_cache(); 
 
      void 
      _M_cache(const locale& __loc); 
 
    private: 
      __moneypunct_cache& 
      operator=(const __moneypunct_cache&); 
       
      explicit 
      __moneypunct_cache(const __moneypunct_cache&); 
    }; 
 
  template<typename _CharT, bool _Intl> 
    __moneypunct_cache<_CharT, _Intl>::~__moneypunct_cache() 
    { 
      if (_M_allocated) 
	{ 
	  delete [] _M_grouping; 
	  delete [] _M_curr_symbol; 
	  delete [] _M_positive_sign; 
	  delete [] _M_negative_sign; 
	} 
    } 
 
  

  */ 
  template<typename _CharT, bool _Intl> 
    class moneypunct : public locale::facet, public money_base 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
      typedef __moneypunct_cache<_CharT, _Intl>     __cache_type; 
 
    private: 
      __cache_type*			_M_data; 
 
    public: 
            /// This value is provided by the standard, but no reason for its 
            /// existence. 
      static const bool			intl = _Intl; 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      moneypunct(size_t __refs = 0) : facet(__refs), _M_data(NULL) 
      { _M_initialize_moneypunct(); } 
 
      

      */ 
      explicit 
      moneypunct(__cache_type* __cache, size_t __refs = 0) 
      : facet(__refs), _M_data(__cache) 
      { _M_initialize_moneypunct(); } 
 
      

      */ 
      explicit 
      moneypunct(__c_locale __cloc, const char* __s, size_t __refs = 0) 
      : facet(__refs), _M_data(NULL) 
      { _M_initialize_moneypunct(__cloc, __s); } 
 
      

      */ 
      char_type 
      decimal_point() const 
      { return this->do_decimal_point(); } 
 
      

      */ 
      char_type 
      thousands_sep() const 
      { return this->do_thousands_sep(); } 
 
      

      */ 
      string 
      grouping() const 
      { return this->do_grouping(); } 
 
      

      */ 
      string_type 
      curr_symbol() const 
      { return this->do_curr_symbol(); } 
 
      

      */ 
      string_type 
      positive_sign() const 
      { return this->do_positive_sign(); } 
 
      

      */ 
      string_type 
      negative_sign() const 
      { return this->do_negative_sign(); } 
 
      

      */ 
      int 
      frac_digits() const 
      { return this->do_frac_digits(); } 
 
            //@{ 
      

      */ 
      pattern 
      pos_format() const 
      { return this->do_pos_format(); } 
 
      pattern 
      neg_format() const 
      { return this->do_neg_format(); } 
            //@} 
 
    protected: 
            /// Destructor. 
      virtual 
      ~moneypunct(); 
 
      

      */ 
      virtual char_type 
      do_decimal_point() const 
      { return _M_data->_M_decimal_point; } 
 
      

      */ 
      virtual char_type 
      do_thousands_sep() const 
      { return _M_data->_M_thousands_sep; } 
 
      

      */ 
      virtual string 
      do_grouping() const 
      { return _M_data->_M_grouping; } 
 
      

      */ 
      virtual string_type 
      do_curr_symbol()   const 
      { return _M_data->_M_curr_symbol; } 
 
      

      */ 
      virtual string_type 
      do_positive_sign() const 
      { return _M_data->_M_positive_sign; } 
 
      

      */ 
      virtual string_type 
      do_negative_sign() const 
      { return _M_data->_M_negative_sign; } 
 
      

      */ 
      virtual int 
      do_frac_digits() const 
      { return _M_data->_M_frac_digits; } 
 
      

      */ 
      virtual pattern 
      do_pos_format() const 
      { return _M_data->_M_pos_format; } 
 
      

      */ 
      virtual pattern 
      do_neg_format() const 
      { return _M_data->_M_neg_format; } 
 
            // For use at construction time only. 
       void 
       _M_initialize_moneypunct(__c_locale __cloc = NULL, 
				const char* __name = NULL); 
    }; 
 
  template<typename _CharT, bool _Intl> 
    locale::id moneypunct<_CharT, _Intl>::id; 
 
  template<typename _CharT, bool _Intl> 
    const bool moneypunct<_CharT, _Intl>::intl; 
 
  template<> 
    moneypunct<char, true>::~moneypunct(); 
 
  template<> 
    moneypunct<char, false>::~moneypunct(); 
 
  template<> 
    void 
    moneypunct<char, true>::_M_initialize_moneypunct(__c_locale, const char*); 
 
  template<> 
    void 
    moneypunct<char, false>::_M_initialize_moneypunct(__c_locale, const char*); 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    moneypunct<wchar_t, true>::~moneypunct(); 
 
  template<> 
    moneypunct<wchar_t, false>::~moneypunct(); 
 
  template<> 
    void 
    moneypunct<wchar_t, true>::_M_initialize_moneypunct(__c_locale, 
							const char*); 
 
  template<> 
    void 
    moneypunct<wchar_t, false>::_M_initialize_moneypunct(__c_locale, 
							 const char*); 
#endif 
 
    /// @brief  class moneypunct_byname [22.2.6.4]. 
  template<typename _CharT, bool _Intl> 
    class moneypunct_byname : public moneypunct<_CharT, _Intl> 
    { 
    public: 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
 
      static const bool intl = _Intl; 
 
      explicit 
      moneypunct_byname(const char* __s, size_t __refs = 0) 
      : moneypunct<_CharT, _Intl>(__refs) 
      { 
	if (std::strcmp(__s, "C") != 0 && std::strcmp(__s, "POSIX") != 0) 
	  { 
	    __c_locale __tmp; 
	    this->_S_create_c_locale(__tmp, __s); 
	    this->_M_initialize_moneypunct(__tmp); 
	    this->_S_destroy_c_locale(__tmp); 
	  } 
      } 
 
    protected: 
      virtual 
      ~moneypunct_byname() { } 
    }; 
 
  template<typename _CharT, bool _Intl> 
    const bool moneypunct_byname<_CharT, _Intl>::intl; 
 
_GLIBCXX_BEGIN_LDBL_NAMESPACE 
  

  */ 
  template<typename _CharT, typename _InIter> 
    class money_get : public locale::facet 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef _InIter			iter_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      money_get(size_t __refs = 0) : facet(__refs) { } 
 
      

       */ 
      iter_type 
      get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	  ios_base::iostate& __err, long double& __units) const 
      { return this->do_get(__s, __end, __intl, __io, __err, __units); } 
 
      

       */ 
      iter_type 
      get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	  ios_base::iostate& __err, string_type& __digits) const 
      { return this->do_get(__s, __end, __intl, __io, __err, __digits); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~money_get() { } 
 
      

       */ 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      __do_get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	       ios_base::iostate& __err, double& __units) const; 
#else 
      virtual iter_type 
      do_get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	     ios_base::iostate& __err, long double& __units) const; 
#endif 
 
      

       */ 
      virtual iter_type 
      do_get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	     ios_base::iostate& __err, string_type& __digits) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      do_get(iter_type __s, iter_type __end, bool __intl, ios_base& __io, 
	     ios_base::iostate& __err, long double& __units) const; 
#endif 
 
      template<bool _Intl> 
        iter_type 
        _M_extract(iter_type __s, iter_type __end, ios_base& __io, 
		   ios_base::iostate& __err, string& __digits) const;      
    }; 
 
  template<typename _CharT, typename _InIter> 
    locale::id money_get<_CharT, _InIter>::id; 
 
  

  */ 
  template<typename _CharT, typename _OutIter> 
    class money_put : public locale::facet 
    { 
    public: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef _OutIter			iter_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      money_put(size_t __refs = 0) : facet(__refs) { } 
 
      

       */ 
      iter_type 
      put(iter_type __s, bool __intl, ios_base& __io, 
	  char_type __fill, long double __units) const 
      { return this->do_put(__s, __intl, __io, __fill, __units); } 
 
      

       */ 
      iter_type 
      put(iter_type __s, bool __intl, ios_base& __io, 
	  char_type __fill, const string_type& __digits) const 
      { return this->do_put(__s, __intl, __io, __fill, __digits); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~money_put() { } 
 
      

       */ 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      __do_put(iter_type __s, bool __intl, ios_base& __io, char_type __fill, 
	       double __units) const; 
#else 
      virtual iter_type 
      do_put(iter_type __s, bool __intl, ios_base& __io, char_type __fill, 
	     long double __units) const; 
#endif 
 
      

       */ 
      virtual iter_type 
      do_put(iter_type __s, bool __intl, ios_base& __io, char_type __fill, 
	     const string_type& __digits) const; 
 
            // XXX GLIBCXX_ABI Deprecated 
#if defined _GLIBCXX_LONG_DOUBLE_COMPAT && defined __LONG_DOUBLE_128__ 
      virtual iter_type 
      do_put(iter_type __s, bool __intl, ios_base& __io, char_type __fill, 
	     long double __units) const; 
#endif 
 
      template<bool _Intl> 
        iter_type 
        _M_insert(iter_type __s, ios_base& __io, char_type __fill, 
		  const string_type& __digits) const; 
    }; 
 
  template<typename _CharT, typename _OutIter> 
    locale::id money_put<_CharT, _OutIter>::id; 
 
_GLIBCXX_END_LDBL_NAMESPACE 
 
  

   */ 
  struct messages_base 
  { 
    typedef int catalog; 
  }; 
 
  

  */ 
  template<typename _CharT> 
    class messages : public locale::facet, public messages_base 
    { 
    public: 
            // Types: 
            //@{ 
            /// Public typedefs 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
            //@} 
 
    protected: 
            // Underlying "C" library locale information saved from 
            // initialization, needed by messages_byname as well. 
      __c_locale			_M_c_locale_messages; 
      const char*			_M_name_messages; 
 
    public: 
            /// Numpunct facet id. 
      static locale::id			id; 
 
      

      */ 
      explicit 
      messages(size_t __refs = 0); 
 
            // Non-standard. 
      

       */ 
      explicit 
      messages(__c_locale __cloc, const char* __s, size_t __refs = 0); 
 
      

      */ 
      catalog 
      open(const basic_string<char>& __s, const locale& __loc) const 
      { return this->do_open(__s, __loc); } 
 
            // Non-standard and unorthodox, yet effective. 
      

      */ 
      catalog 
      open(const basic_string<char>&, const locale&, const char*) const; 
 
      

      */ 
      string_type 
      get(catalog __c, int __set, int __msgid, const string_type& __s) const 
      { return this->do_get(__c, __set, __msgid, __s); } 
 
      

      */ 
      void 
      close(catalog __c) const 
      { return this->do_close(__c); } 
 
    protected: 
            /// Destructor. 
      virtual 
      ~messages(); 
 
      

      */ 
      virtual catalog 
      do_open(const basic_string<char>&, const locale&) const; 
 
      

      */ 
      virtual string_type 
      do_get(catalog, int, int, const string_type& __dfault) const; 
 
      

      */ 
      virtual void 
      do_close(catalog) const; 
 
            // Returns a locale and codeset-converted string, given a char* message. 
      char* 
      _M_convert_to_char(const string_type& __msg) const 
      { 
		// XXX 
	return reinterpret_cast<char*>(const_cast<_CharT*>(__msg.c_str())); 
      } 
 
            // Returns a locale and codeset-converted string, given a char* message. 
      string_type 
      _M_convert_from_char(char*) const 
      { 
#if 0 
		// Length of message string without terminating null. 
	size_t __len = char_traits<char>::length(__msg) - 1; 
 
		// "everybody can easily convert the string using 
		// mbsrtowcs/wcsrtombs or with iconv()" 
 
		// Convert char* to _CharT in locale used to open catalog. 
		// XXX need additional template parameter on messages class for this.. 
		// typedef typename codecvt<char, _CharT, _StateT> __codecvt_type; 
	typedef typename codecvt<char, _CharT, mbstate_t> __codecvt_type; 
 
	__codecvt_type::state_type __state; 
		// XXX may need to initialize state. 
		//initialize_state(__state._M_init()); 
 
	char* __from_next; 
		// XXX what size for this string? 
	_CharT* __to = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 
	const __codecvt_type& __cvt = use_facet<__codecvt_type>(_M_locale_conv); 
	__cvt.out(__state, __msg, __msg + __len, __from_next, 
		  __to, __to + __len + 1, __to_next); 
	return string_type(__to); 
#endif 
#if 0 
	typedef ctype<_CharT> __ctype_type; 
		// const __ctype_type& __cvt = use_facet<__ctype_type>(_M_locale_msg); 
	const __ctype_type& __cvt = use_facet<__ctype_type>(locale()); 
		// XXX Again, proper length of converted string an issue here. 
		// For now, assume the converted length is not larger. 
	_CharT* __dest = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 
	__cvt.widen(__msg, __msg + __len, __dest); 
	return basic_string<_CharT>(__dest); 
#endif 
	return string_type(); 
      } 
     }; 
 
  template<typename _CharT> 
    locale::id messages<_CharT>::id; 
 
    // Specializations for required instantiations. 
  template<> 
    string 
    messages<char>::do_get(catalog, int, int, const string&) const; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<> 
    wstring 
    messages<wchar_t>::do_get(catalog, int, int, const wstring&) const; 
#endif 
 
      /// @brief class messages_byname [22.2.7.2]. 
   template<typename _CharT> 
    class messages_byname : public messages<_CharT> 
    { 
    public: 
      typedef _CharT			char_type; 
      typedef basic_string<_CharT>	string_type; 
 
      explicit 
      messages_byname(const char* __s, size_t __refs = 0); 
 
    protected: 
      virtual 
      ~messages_byname() 
      { } 
    }; 
 
    // Include host and configuration specific messages functions. 
  #include <bits/messages_members.h> 
 
 
    // Subclause convenience interfaces, inlines. 
    // NB: These are inline because, when used in a loop, some compilers 
    // can hoist the body out of the loop; then it's just as fast as the 
    // C is*() function. 
 
    /// Convenience interface to ctype.is(ctype_base::space, __c). 
  template<typename _CharT> 
    inline bool 
    isspace(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::space, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::print, __c). 
  template<typename _CharT> 
    inline bool 
    isprint(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::print, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::cntrl, __c). 
  template<typename _CharT> 
    inline bool 
    iscntrl(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::cntrl, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::upper, __c). 
  template<typename _CharT> 
    inline bool 
    isupper(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::upper, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::lower, __c). 
  template<typename _CharT> 
    inline bool  
    islower(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::lower, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::alpha, __c). 
  template<typename _CharT> 
    inline bool 
    isalpha(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::alpha, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::digit, __c). 
  template<typename _CharT> 
    inline bool 
    isdigit(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::digit, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::punct, __c). 
  template<typename _CharT> 
    inline bool 
    ispunct(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::punct, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::xdigit, __c). 
  template<typename _CharT> 
    inline bool 
    isxdigit(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::xdigit, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::alnum, __c). 
  template<typename _CharT> 
    inline bool 
    isalnum(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::alnum, __c); } 
 
    /// Convenience interface to ctype.is(ctype_base::graph, __c). 
  template<typename _CharT> 
    inline bool 
    isgraph(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::graph, __c); } 
 
    /// Convenience interface to ctype.toupper(__c). 
  template<typename _CharT> 
    inline _CharT 
    toupper(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).toupper(__c); } 
 
    /// Convenience interface to ctype.tolower(__c). 
  template<typename _CharT> 
    inline _CharT 
    tolower(_CharT __c, const locale& __loc) 
    { return use_facet<ctype<_CharT> >(__loc).tolower(__c); } 
} } // namespace std 
 
#endif 
 
 
namespace std 
{ 
    // 27.4.5  Template class basic_ios 
  

  */ 
  template<typename _CharT, typename _Traits> 
    class basic_ios : public ios_base 
    { 
    public: 
            //@{ 
      

      */ 
      typedef _CharT                                 char_type; 
      typedef typename _Traits::int_type             int_type; 
      typedef typename _Traits::pos_type             pos_type; 
      typedef typename _Traits::off_type             off_type; 
      typedef _Traits                                traits_type; 
            //@} 
 
            //@{ 
      

      */ 
      typedef ctype<_CharT>                          __ctype_type; 
      typedef num_put<_CharT, ostreambuf_iterator<_CharT, _Traits> > 
						     __num_put_type; 
      typedef num_get<_CharT, istreambuf_iterator<_CharT, _Traits> > 
						     __num_get_type; 
            //@} 
 
            // Data members: 
    protected: 
      basic_ostream<_CharT, _Traits>*                _M_tie; 
      mutable char_type                              _M_fill; 
      mutable bool                                   _M_fill_init; 
      basic_streambuf<_CharT, _Traits>*              _M_streambuf; 
 
            // Cached use_facet<ctype>, which is based on the current locale info. 
      const __ctype_type*                            _M_ctype; 
            // For ostream. 
      const __num_put_type*                          _M_num_put; 
            // For istream. 
      const __num_get_type*                          _M_num_get; 
 
    public: 
            //@{ 
      

      */ 
      operator void*() const 
      { return this->fail() ? 0 : const_cast<basic_ios*>(this); } 
 
      bool 
      operator!() const 
      { return this->fail(); } 
            //@} 
 
      

      */ 
      iostate 
      rdstate() const 
      { return _M_streambuf_state; } 
 
      

      */ 
      void 
      clear(iostate __state = goodbit); 
 
      

      */ 
      void 
      setstate(iostate __state) 
      { this->clear(this->rdstate() | __state); } 
 
            // Flip the internal state on for the proper state bits, then re 
            // throws the propagated exception if bit also set in 
            // exceptions(). 
      void 
      _M_setstate(iostate __state) 
      { 
		// 27.6.1.2.1 Common requirements. 
		// Turn this on without causing an ios::failure to be thrown. 
	_M_streambuf_state |= __state; 
	if (this->exceptions() & __state) 
	  __throw_exception_again; 
      } 
 
      

      */ 
      bool 
      good() const 
      { return this->rdstate() == 0; } 
 
      

      */ 
      bool 
      eof() const 
      { return (this->rdstate() & eofbit) != 0; } 
 
      

      */ 
      bool 
      fail() const 
      { return (this->rdstate() & (badbit | failbit)) != 0; } 
 
      

      */ 
      bool 
      bad() const 
      { return (this->rdstate() & badbit) != 0; } 
 
      

      */ 
      iostate 
      exceptions() const 
      { return _M_exception; } 
 
      

      */ 
      void 
      exceptions(iostate __except) 
      { 
        _M_exception = __except; 
        this->clear(_M_streambuf_state); 
      } 
 
            // Constructor/destructor: 
      

      */ 
      explicit 
      basic_ios(basic_streambuf<_CharT, _Traits>* __sb) 
      : ios_base(), _M_tie(0), _M_fill(), _M_fill_init(false), _M_streambuf(0), 
      _M_ctype(0), _M_num_put(0), _M_num_get(0) 
      { this->init(__sb); } 
 
      

      */ 
      virtual 
      ~basic_ios() { } 
 
            // Members: 
      

      */ 
      basic_ostream<_CharT, _Traits>* 
      tie() const 
      { return _M_tie; } 
 
      

      */ 
      basic_ostream<_CharT, _Traits>* 
      tie(basic_ostream<_CharT, _Traits>* __tiestr) 
      { 
        basic_ostream<_CharT, _Traits>* __old = _M_tie; 
        _M_tie = __tiestr; 
        return __old; 
      } 
 
      

      */ 
      basic_streambuf<_CharT, _Traits>* 
      rdbuf() const 
      { return _M_streambuf; } 
 
      

      */ 
      basic_streambuf<_CharT, _Traits>* 
      rdbuf(basic_streambuf<_CharT, _Traits>* __sb); 
 
      

      */ 
      basic_ios& 
      copyfmt(const basic_ios& __rhs); 
 
      

      */ 
      char_type 
      fill() const 
      { 
	if (!_M_fill_init) 
	  { 
	    _M_fill = this->widen(' '); 
	    _M_fill_init = true; 
	  } 
	return _M_fill; 
      } 
 
      

      */ 
      char_type 
      fill(char_type __ch) 
      { 
	char_type __old = this->fill(); 
	_M_fill = __ch; 
	return __old; 
      } 
 
            // Locales: 
      

      */ 
      locale 
      imbue(const locale& __loc); 
 
      

      */ 
      char 
      narrow(char_type __c, char __dfault) const; 
 
      

      */ 
      char_type 
      widen(char __c) const; 
 
    protected: 
            // 27.4.5.1  basic_ios constructors 
      

      */ 
      basic_ios() 
      : ios_base(), _M_tie(0), _M_fill(char_type()), _M_fill_init(false),  
      _M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0) 
      { } 
 
      

      */ 
      void 
      init(basic_streambuf<_CharT, _Traits>* __sb); 
 
      void 
      _M_cache_locale(const locale& __loc); 
    }; 
} } // namespace std 
 
#ifndef _GLIBCXX_EXPORT_TEMPLATE 
// basic_ios member functions -*- C++ -*- 
 
// Copyright (C) 1999, 2001, 2002, 2003, 2004 Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 


 */ 
 
#ifndef _BASIC_IOS_TCC 
 
#pragma GCC system_header 
 
namespace std 
{ 
  template<typename _CharT, typename _Traits> 
    void 
    basic_ios<_CharT, _Traits>::clear(iostate __state) 
    { 
      if (this->rdbuf()) 
	_M_streambuf_state = __state; 
      else 
	  _M_streambuf_state = __state | badbit; 
      if (this->exceptions() & this->rdstate()) 
	__throw_ios_failure(__N("basic_ios::clear")); 
    } 
 
  template<typename _CharT, typename _Traits> 
    basic_streambuf<_CharT, _Traits>* 
    basic_ios<_CharT, _Traits>::rdbuf(basic_streambuf<_CharT, _Traits>* __sb) 
    { 
      basic_streambuf<_CharT, _Traits>* __old = _M_streambuf; 
      _M_streambuf = __sb; 
      this->clear(); 
      return __old; 
    } 
 
  template<typename _CharT, typename _Traits> 
    basic_ios<_CharT, _Traits>& 
    basic_ios<_CharT, _Traits>::copyfmt(const basic_ios& __rhs) 
    { 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 292. effects of a.copyfmt (a) 
      if (this != &__rhs) 
	{ 
	  	  // Per 27.1.1, do not call imbue, yet must trash all caches 
	  	  // associated with imbue() 
 
	  	  // Alloc any new word array first, so if it fails we have "rollback". 
	  _Words* __words = (__rhs._M_word_size <= _S_local_word_size) ? 
	                     _M_local_word : new _Words[__rhs._M_word_size]; 
 
	  	  // Bump refs before doing callbacks, for safety. 
	  _Callback_list* __cb = __rhs._M_callbacks; 
	  if (__cb) 
	    __cb->_M_add_reference(); 
	  _M_call_callbacks(erase_event); 
	  if (_M_word != _M_local_word) 
	    { 
	      delete [] _M_word; 
	      _M_word = 0; 
	    } 
	  _M_dispose_callbacks(); 
 
	  	  // NB: Don't want any added during above. 
	  _M_callbacks = __cb; 
	  for (int __i = 0; __i < __rhs._M_word_size; ++__i) 
	    __words[__i] = __rhs._M_word[__i]; 
	  _M_word = __words; 
	  _M_word_size = __rhs._M_word_size; 
 
	  this->flags(__rhs.flags()); 
	  this->width(__rhs.width()); 
	  this->precision(__rhs.precision()); 
	  this->tie(__rhs.tie()); 
	  this->fill(__rhs.fill()); 
	  _M_ios_locale = __rhs.getloc(); 
	  _M_cache_locale(_M_ios_locale); 
 
	  _M_call_callbacks(copyfmt_event); 
 
	  	  // The next is required to be the last assignment. 
	  this->exceptions(__rhs.exceptions()); 
	} 
      return *this; 
    } 
 
  template<typename _CharT, typename _Traits> 
    char 
    basic_ios<_CharT, _Traits>::narrow(char_type __c, char __dfault) const 
    { return __check_facet(_M_ctype).narrow(__c, __dfault); } 
 
  template<typename _CharT, typename _Traits> 
    _CharT 
    basic_ios<_CharT, _Traits>::widen(char __c) const 
    { return __check_facet(_M_ctype).widen(__c); } 
 
    // Locales: 
  template<typename _CharT, typename _Traits> 
    locale 
    basic_ios<_CharT, _Traits>::imbue(const locale& __loc) 
    { 
      locale __old(this->getloc()); 
      ios_base::imbue(__loc); 
      _M_cache_locale(__loc); 
      if (this->rdbuf() != 0) 
	this->rdbuf()->pubimbue(__loc); 
      return __old; 
    } 
 
  template<typename _CharT, typename _Traits> 
    void 
    basic_ios<_CharT, _Traits>::init(basic_streambuf<_CharT, _Traits>* __sb) 
    { 
            // NB: This may be called more than once on the same object. 
      ios_base::_M_init(); 
 
            // Cache locale data and specific facets used by iostreams. 
      _M_cache_locale(_M_ios_locale); 
 
            // NB: The 27.4.4.1 Postconditions Table specifies requirements 
            // after basic_ios::init() has been called. As part of this, 
            // fill() must return widen(' ') any time after init() has been 
            // called, which needs an imbued ctype facet of char_type to 
            // return without throwing an exception. Unfortunately, 
            // ctype<char_type> is not necessarily a required facet, so 
            // streams with char_type != [char, wchar_t] will not have it by 
            // default. Because of this, the correct value for _M_fill is 
            // constructed on the first call of fill(). That way, 
            // unformatted input and output with non-required basic_ios 
            // instantiations is possible even without imbuing the expected 
            // ctype<char_type> facet. 
      _M_fill = _CharT(); 
      _M_fill_init = false; 
 
      _M_tie = 0; 
      _M_exception = goodbit; 
      _M_streambuf = __sb; 
      _M_streambuf_state = __sb ? goodbit : badbit; 
    } 
 
  template<typename _CharT, typename _Traits> 
    void 
    basic_ios<_CharT, _Traits>::_M_cache_locale(const locale& __loc) 
    { 
      if (__builtin_expect(has_facet<__ctype_type>(__loc), true)) 
	_M_ctype = &use_facet<__ctype_type>(__loc); 
      else 
	_M_ctype = 0; 
 
      if (__builtin_expect(has_facet<__num_put_type>(__loc), true)) 
	_M_num_put = &use_facet<__num_put_type>(__loc); 
      else 
	_M_num_put = 0; 
 
      if (__builtin_expect(has_facet<__num_get_type>(__loc), true)) 
	_M_num_get = &use_facet<__num_get_type>(__loc); 
      else 
	_M_num_get = 0; 
    } 
 
    // Inhibit implicit instantiations for required instantiations, 
    // which are defined via explicit instantiations elsewhere. 
    // NB:  This syntax is a GNU extension. 
#if _GLIBCXX_EXTERN_TEMPLATE 
  extern template class basic_ios<char>; 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  extern template class basic_ios<wchar_t>; 
#endif 
#endif 
} } // namespace std 
 
#endif 
 
#endif 
 
#endif 
 
 
#endif	
 
 
namespace std 
{ 
    // [27.6.2.1] Template class basic_ostream 
  

  */ 
  template<typename _CharT, typename _Traits> 
    class basic_ostream : virtual public basic_ios<_CharT, _Traits> 
    { 
    public: 
            // Types (inherited from basic_ios (27.4.4)): 
      typedef _CharT                     		char_type; 
      typedef typename _Traits::int_type 		int_type; 
      typedef typename _Traits::pos_type 		pos_type; 
      typedef typename _Traits::off_type 		off_type; 
      typedef _Traits                    		traits_type; 
       
            // Non-standard Types: 
      typedef basic_streambuf<_CharT, _Traits> 		__streambuf_type; 
      typedef basic_ios<_CharT, _Traits>		__ios_type; 
      typedef basic_ostream<_CharT, _Traits>		__ostream_type; 
      typedef num_put<_CharT, ostreambuf_iterator<_CharT, _Traits> >         
      							__num_put_type; 
      typedef ctype<_CharT>           			__ctype_type; 
 
      template<typename _CharT2, typename _Traits2> 
        friend basic_ostream<_CharT2, _Traits2>& 
        operator<<(basic_ostream<_CharT2, _Traits2>&, _CharT2); 
  
      template<typename _Traits2> 
        friend basic_ostream<char, _Traits2>& 
        operator<<(basic_ostream<char, _Traits2>&, char); 
  
      template<typename _CharT2, typename _Traits2> 
        friend basic_ostream<_CharT2, _Traits2>& 
        operator<<(basic_ostream<_CharT2, _Traits2>&, const _CharT2*); 
  
      template<typename _Traits2> 
        friend basic_ostream<char, _Traits2>& 
        operator<<(basic_ostream<char, _Traits2>&, const char*); 
  
      template<typename _CharT2, typename _Traits2> 
        friend basic_ostream<_CharT2, _Traits2>& 
        operator<<(basic_ostream<_CharT2, _Traits2>&, const char*); 
 
            // [27.6.2.2] constructor/destructor 
      

      */ 
      explicit  
      basic_ostream(__streambuf_type* __sb) 
      { this->init(__sb); } 
 
      

      */ 
      virtual  
      ~basic_ostream() { } 
 
            // [27.6.2.3] prefix/suffix 
      class sentry; 
      friend class sentry; 
       
            // [27.6.2.5] formatted output 
            // [27.6.2.5.3]  basic_ostream::operator<< 
            //@{ 
      

      */ 
      inline __ostream_type& 
      operator<<(__ostream_type& (*__pf)(__ostream_type&)); 
       
      inline __ostream_type& 
      operator<<(__ios_type& (*__pf)(__ios_type&)); 
       
      inline __ostream_type& 
      operator<<(ios_base& (*__pf) (ios_base&)); 
            //@} 
 
            // [27.6.2.5.2] arithmetic inserters 
      

      */ 
            //@{ 
      

      */ 
      __ostream_type&  
      operator<<(long __n); 
       
      __ostream_type&  
      operator<<(unsigned long __n); 
 
      __ostream_type&  
      operator<<(bool __n); 
 
      __ostream_type&  
      operator<<(short __n); 
 
      __ostream_type&  
      operator<<(unsigned short __n); 
 
      __ostream_type&  
      operator<<(int __n); 
 
      __ostream_type&  
      operator<<(unsigned int __n); 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      __ostream_type&  
      operator<<(long long __n); 
 
      __ostream_type&  
      operator<<(unsigned long long __n); 
#endif 
 
      __ostream_type&  
      operator<<(double __f); 
 
      __ostream_type&  
      operator<<(float __f); 
 
      __ostream_type&  
      operator<<(long double __f); 
 
      __ostream_type&  
      operator<<(const void* __p); 
 
      

      */ 
      __ostream_type&  
      operator<<(__streambuf_type* __sb); 
            //@} 
 
            // [27.6.2.6] unformatted output functions 
      

      */ 
            //@{ 
      

      */ 
      __ostream_type&  
      put(char_type __c); 
 
            // Core write functionality, without sentry. 
      void 
      _M_write(const char_type* __s, streamsize __n) 
      { 
	streamsize __put = this->rdbuf()->sputn(__s, __n); 
	if (__put != __n) 
	  this->setstate(ios_base::badbit); 
      } 
 
      

      */ 
      __ostream_type&  
      write(const char_type* __s, streamsize __n); 
            //@} 
 
      

      */ 
      __ostream_type&  
      flush(); 
 
            // [27.6.2.4] seek members 
      

      */ 
      pos_type  
      tellp(); 
 
      

      */ 
      __ostream_type&  
      seekp(pos_type); 
 
      

      */ 
       __ostream_type&  
      seekp(off_type, ios_base::seekdir); 
       
    protected: 
      explicit  
      basic_ostream() { } 
    }; 
 
  

  */ 
  template <typename _CharT, typename _Traits> 
    class basic_ostream<_CharT, _Traits>::sentry 
    { 
            // Data Members: 
      bool 				_M_ok; 
      basic_ostream<_CharT,_Traits>& 	_M_os; 
       
    public: 
      

      */ 
      explicit 
      sentry(basic_ostream<_CharT,_Traits>& __os); 
 
      

      */ 
      ~sentry() 
      { 
		// XXX MT 
	if (_M_os.flags() & ios_base::unitbuf && !uncaught_exception()) 
	  { 
	    	    // Can't call flush directly or else will get into recursive lock. 
	    if (_M_os.rdbuf() && _M_os.rdbuf()->pubsync() == -1) 
	      _M_os.setstate(ios_base::badbit); 
	  } 
      } 
 
      

      */ 
      operator bool() const 
      { return _M_ok; } 
    }; 
 
    // [27.6.2.5.4] character insertion templates 
    //@{ 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>& 
    operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c); 
 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>& 
    operator<<(basic_ostream<_CharT, _Traits>& __out, char __c) 
    { return (__out << __out.widen(__c)); } 
 
    // Specialization 
  template <class _Traits>  
    basic_ostream<char, _Traits>& 
    operator<<(basic_ostream<char, _Traits>& __out, char __c); 
 
    // Signed and unsigned 
  template<class _Traits> 
    basic_ostream<char, _Traits>& 
    operator<<(basic_ostream<char, _Traits>& __out, signed char __c) 
    { return (__out << static_cast<char>(__c)); } 
   
  template<class _Traits> 
    basic_ostream<char, _Traits>& 
    operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c) 
    { return (__out << static_cast<char>(__c)); } 
    //@} 
   
    //@{ 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>& 
    operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s); 
 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits> & 
    operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s); 
 
    // Partial specializationss 
  template<class _Traits> 
    basic_ostream<char, _Traits>& 
    operator<<(basic_ostream<char, _Traits>& __out, const char* __s); 
  
    // Signed and unsigned 
  template<class _Traits> 
    basic_ostream<char, _Traits>& 
    operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s) 
    { return (__out << reinterpret_cast<const char*>(__s)); } 
 
  template<class _Traits> 
    basic_ostream<char, _Traits> & 
    operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s) 
    { return (__out << reinterpret_cast<const char*>(__s)); } 
    //@} 
 
    // [27.6.2.7] standard basic_ostream manipulators 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>&  
    endl(basic_ostream<_CharT, _Traits>& __os) 
    { return flush(__os.put(__os.widen('\n'))); } 
 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>&  
    ends(basic_ostream<_CharT, _Traits>& __os) 
    { return __os.put(_CharT()); } 
   
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_ostream<_CharT, _Traits>&  
    flush(basic_ostream<_CharT, _Traits>& __os) 
    { return __os.flush(); } 
 
} } // namespace std 
 
#ifndef _GLIBCXX_EXPORT_TEMPLATE 
# include <bits/ostream.tcc> 
#endif 
 
#endif	
 
// Input streams -*- C++ -*- 
 
// Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003, 2004, 2005 
// Free Software Foundation, Inc. 
// 
// This file is part of the GNU ISO C++ Library.  This library is free 
// software; you can redistribute it and/or modify it under the 
// terms of the GNU General Public License as published by the 
// Free Software Foundation; either version 2, or (at your option) 
// any later version. 
 
// This library is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
 
// You should have received a copy of the GNU General Public License along 
// with this library; see the file COPYING.  If not, write to the Free 
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, 
// USA. 
 
// As a special exception, you may use this file as part of a free software 
// library without restriction.  Specifically, if other files instantiate 
// templates or use macros or inline functions from this file, or you compile 
// this file and link it with other files to produce an executable, this 
// file does not by itself cause the resulting executable to be covered by 
// the GNU General Public License.  This exception does not however 
// invalidate any other reasons why the executable file might be covered by 
// the GNU General Public License. 
 
// 
// ISO C++ 14882: 27.6.1  Input streams 
// 
 


 */ 
 
#ifndef _GLIBCXX_ISTREAM 
 
#pragma GCC system_header 
 
#include <limits>  
 
namespace std 
{ 
    // [27.6.1.1] Template class basic_istream 
  

  */ 
  template<typename _CharT, typename _Traits> 
    class basic_istream : virtual public basic_ios<_CharT, _Traits> 
    { 
    public: 
            // Types (inherited from basic_ios (27.4.4)): 
      typedef _CharT                     		char_type; 
      typedef typename _Traits::int_type 		int_type; 
      typedef typename _Traits::pos_type 		pos_type; 
      typedef typename _Traits::off_type 		off_type; 
      typedef _Traits                    		traits_type; 
       
            // Non-standard Types: 
      typedef basic_streambuf<_CharT, _Traits> 		__streambuf_type; 
      typedef basic_ios<_CharT, _Traits>		__ios_type; 
      typedef basic_istream<_CharT, _Traits>		__istream_type; 
      typedef num_get<_CharT, istreambuf_iterator<_CharT, _Traits> >         
 							__num_get_type; 
      typedef ctype<_CharT>           			__ctype_type; 
 
      template<typename _CharT2, typename _Traits2> 
        friend basic_istream<_CharT2, _Traits2>& 
        operator>>(basic_istream<_CharT2, _Traits2>&, _CharT2&); 
  
      template<typename _CharT2, typename _Traits2> 
        friend basic_istream<_CharT2, _Traits2>& 
        operator>>(basic_istream<_CharT2, _Traits2>&, _CharT2*); 
  
    protected: 
            // Data Members: 
      

      */ 
      streamsize 		_M_gcount; 
 
    public: 
            // [27.6.1.1.1] constructor/destructor 
      

      */ 
      explicit  
      basic_istream(__streambuf_type* __sb): _M_gcount(streamsize(0)) 
      { this->init(__sb); } 
 
      

      */ 
      virtual  
      ~basic_istream()  
      { _M_gcount = streamsize(0); } 
 
            // [27.6.1.1.2] prefix/suffix 
      class sentry; 
      friend class sentry; 
 
            // [27.6.1.2] formatted input 
            // [27.6.1.2.3] basic_istream::operator>> 
            //@{ 
      

      */ 
      inline __istream_type& 
      operator>>(__istream_type& (*__pf)(__istream_type&)); 
 
      inline __istream_type& 
      operator>>(__ios_type& (*__pf)(__ios_type&)); 
 
      inline __istream_type& 
      operator>>(ios_base& (*__pf)(ios_base&)); 
            //@} 
       
            // [27.6.1.2.2] arithmetic extractors 
      

      */ 
            //@{ 
      

      */ 
      __istream_type&  
      operator>>(bool& __n); 
       
      __istream_type&  
      operator>>(short& __n); 
       
      __istream_type&  
      operator>>(unsigned short& __n); 
 
      __istream_type&  
      operator>>(int& __n); 
       
      __istream_type&  
      operator>>(unsigned int& __n); 
 
      __istream_type&  
      operator>>(long& __n); 
       
      __istream_type&  
      operator>>(unsigned long& __n); 
 
#ifdef _GLIBCXX_USE_LONG_LONG 
      __istream_type&  
      operator>>(long long& __n); 
 
      __istream_type&  
      operator>>(unsigned long long& __n); 
#endif 
 
      __istream_type&  
      operator>>(float& __f); 
 
      __istream_type&  
      operator>>(double& __f); 
 
      __istream_type&  
      operator>>(long double& __f); 
 
      __istream_type&  
      operator>>(void*& __p); 
 
      

      */ 
      __istream_type&  
      operator>>(__streambuf_type* __sb); 
            //@} 
       
            // [27.6.1.3] unformatted input 
      

      */ 
      inline streamsize  
      gcount() const  
      { return _M_gcount; } 
       
      

      */ 
            //@{ 
      

      */ 
      int_type  
      get(); 
 
      

      */ 
      __istream_type&  
      get(char_type& __c); 
 
      

      */ 
      __istream_type&  
      get(char_type* __s, streamsize __n, char_type __delim); 
 
      

      */ 
      inline __istream_type&  
      get(char_type* __s, streamsize __n) 
      { return this->get(__s, __n, this->widen('\n')); } 
 
      

      */ 
      __istream_type& 
      get(__streambuf_type& __sb, char_type __delim); 
 
      

      */ 
      inline __istream_type& 
      get(__streambuf_type& __sb) 
      { return this->get(__sb, this->widen('\n')); } 
 
      

      */ 
      __istream_type&  
      getline(char_type* __s, streamsize __n, char_type __delim); 
 
      

      */ 
      inline __istream_type&  
      getline(char_type* __s, streamsize __n) 
      { return this->getline(__s, __n, this->widen('\n')); } 
 
      

      */ 
      __istream_type&  
      ignore(); 
 
      __istream_type&  
      ignore(streamsize __n); 
 
      __istream_type&  
      ignore(streamsize __n, int_type __delim); 
       
      

      */ 
      int_type  
      peek(); 
       
      

      */ 
      __istream_type&  
      read(char_type* __s, streamsize __n); 
 
      

      */ 
      streamsize  
      readsome(char_type* __s, streamsize __n); 
       
      

      */ 
      __istream_type&  
      putback(char_type __c); 
 
      

      */ 
      __istream_type&  
      unget(); 
 
      

      */ 
      int  
      sync(); 
 
      

      */ 
      pos_type  
      tellg(); 
 
      

      */ 
      __istream_type&  
      seekg(pos_type); 
 
      

      */ 
      __istream_type&  
      seekg(off_type, ios_base::seekdir); 
            //@} 
 
    protected: 
      explicit  
      basic_istream(): _M_gcount(streamsize(0)) { } 
    }; 
 
    // Explicit specialization declarations, defined in src/istream.cc. 
  template<>  
    basic_istream<char>&  
    basic_istream<char>:: 
    getline(char_type* __s, streamsize __n, char_type __delim); 
   
  template<> 
    basic_istream<char>& 
    basic_istream<char>:: 
    ignore(streamsize __n); 
   
  template<> 
    basic_istream<char>& 
    basic_istream<char>:: 
    ignore(streamsize __n, int_type __delim); 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  template<>  
    basic_istream<wchar_t>&  
    basic_istream<wchar_t>:: 
    getline(char_type* __s, streamsize __n, char_type __delim); 
 
  template<> 
    basic_istream<wchar_t>& 
    basic_istream<wchar_t>:: 
    ignore(streamsize __n); 
   
  template<> 
    basic_istream<wchar_t>& 
    basic_istream<wchar_t>:: 
    ignore(streamsize __n, int_type __delim); 
#endif 
 
  

  */ 
  template<typename _CharT, typename _Traits> 
    class basic_istream<_CharT, _Traits>::sentry 
    { 
    public: 
            /// Easy access to dependant types. 
      typedef _Traits 					traits_type; 
      typedef basic_streambuf<_CharT, _Traits> 		__streambuf_type; 
      typedef basic_istream<_CharT, _Traits> 		__istream_type; 
      typedef typename __istream_type::__ctype_type 	__ctype_type; 
      typedef typename _Traits::int_type		__int_type; 
 
      

      */ 
      explicit  
      sentry(basic_istream<_CharT, _Traits>& __is, bool __noskipws = false); 
 
      

      */ 
      operator bool() const { return _M_ok; } 
 
    private: 
      bool _M_ok; 
    }; 
 
    // [27.6.1.2.3] character extraction templates 
    //@{ 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_istream<_CharT, _Traits>& 
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT& __c); 
 
  template<class _Traits> 
    basic_istream<char, _Traits>& 
    operator>>(basic_istream<char, _Traits>& __in, unsigned char& __c) 
    { return (__in >> reinterpret_cast<char&>(__c)); } 
 
  template<class _Traits> 
    basic_istream<char, _Traits>& 
    operator>>(basic_istream<char, _Traits>& __in, signed char& __c) 
    { return (__in >> reinterpret_cast<char&>(__c)); } 
    //@} 
 
    //@{ 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_istream<_CharT, _Traits>& 
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT* __s); 
 
    // Explicit specialization declaration, defined in src/istream.cc. 
  template<> 
    basic_istream<char>& 
    operator>>(basic_istream<char>& __in, char* __s); 
 
  template<class _Traits> 
    basic_istream<char, _Traits>& 
    operator>>(basic_istream<char, _Traits>& __in, unsigned char* __s) 
    { return (__in >> reinterpret_cast<char*>(__s)); } 
 
  template<class _Traits> 
    basic_istream<char, _Traits>& 
    operator>>(basic_istream<char, _Traits>& __in, signed char* __s) 
    { return (__in >> reinterpret_cast<char*>(__s)); } 
    //@} 
 
    // 27.6.1.5 Template class basic_iostream 
  

  */ 
  template<typename _CharT, typename _Traits> 
    class basic_iostream 
    : public basic_istream<_CharT, _Traits>,  
      public basic_ostream<_CharT, _Traits> 
    { 
    public: 
            // _GLIBCXX_RESOLVE_LIB_DEFECTS 
            // 271. basic_iostream missing typedefs 
            // Types (inherited): 
      typedef _CharT                     		char_type; 
      typedef typename _Traits::int_type 		int_type; 
      typedef typename _Traits::pos_type 		pos_type; 
      typedef typename _Traits::off_type 		off_type; 
      typedef _Traits                    		traits_type; 
 
            // Non-standard Types: 
      typedef basic_istream<_CharT, _Traits>		__istream_type; 
      typedef basic_ostream<_CharT, _Traits>		__ostream_type; 
 
      

      */ 
      explicit  
      basic_iostream(basic_streambuf<_CharT, _Traits>* __sb) 
      : __istream_type(), __ostream_type() 
      { this->init(__sb); } 
 
      

      */ 
      virtual  
      ~basic_iostream() { } 
 
    protected: 
      explicit  
      basic_iostream() : __istream_type(), __ostream_type() 
      { } 
    }; 
 
    // [27.6.1.4] standard basic_istream manipulators 
  

  */ 
  template<typename _CharT, typename _Traits> 
    basic_istream<_CharT, _Traits>&  
    ws(basic_istream<_CharT, _Traits>& __is); 
} } // namespace std 
 
#ifndef _GLIBCXX_EXPORT_TEMPLATE 
# include <bits/istream.tcc> 
#endif 
 
#endif	
 
 
namespace std  
{ 
  

  */ 
    //@{ 
  extern istream cin;		  extern istream cin;		///< Linked to standard input 
  extern ostream cout;		  extern ostream cout;		///< Linked to standard output 
  extern ostream cerr;		  extern ostream cerr;		///< Linked to standard error (unbuffered) 
  extern ostream clog;		  extern ostream clog;		///< Linked to standard error (buffered) 
 
#ifdef _GLIBCXX_USE_WCHAR_T 
  extern wistream wcin;		  extern wistream wcin;		///< Linked to standard input 
  extern wostream wcout;	  extern wostream wcout;	///< Linked to standard output 
  extern wostream wcerr;	  extern wostream wcerr;	///< Linked to standard error (unbuffered) 
  extern wostream wclog;	  extern wostream wclog;	///< Linked to standard error (buffered) 
#endif 
    //@} 
 
    // For construction of filebuffers for cout, cin, cerr, clog et. al. 
  static ios_base::Init __ioinit; 
} } // namespace std 
 
#endif 
 
using namespace std; 
 
class Custom 
{ 
 
private: 
    string sentence; 
    int number; 
 
 
public: 
 
Custom() 
:sentence(""),number(0) 
{} 
 
Custom(string s) 
:sentence(s),number(0) 
{} 
 
Custom(int n) 
:sentence(""),number(n) 
{} 
 
Custom(string s, int n) 
:sentence(s),number(n) 
{} 
 
 
}; 
 
using namespace std; 
 
    //main functioin 
int main() 
{ 
    

    */ 
    string s = "Program terminated";

     */ 
    cout << "Hello World " << s << endl; 
 
    cout << 1000 << endl; 
 
    cout << "WONGWORLD!" << "WONGWORLD!" << " " << "WONGWORLD!" << endl; 
    cout << xx << endl; 
 
 
    return 0;    return 0;//exit program 
} 
 
