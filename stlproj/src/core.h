#pragma once

#include "base.h"
#include <stdio.h>

#ifdef _STL_COMPILER_PREPROCESSOR_

#if defined( _WINDOWS_ ) || defined( _WIN64 )
#define _STL_INTERNAL_BREAKDEBUG_() __debugbreak();
#elif __linux__
#include <signal.h>
#define _STL_INTERNAL_BREAKDEBUG_() raise(SIGTRAP);
#endif

#ifndef _STL_INTERNAL_ASSERT_
#define  _STL_INTERNAL_ASSERT_(cond, msg) if (!(cond)) { printf( "Assertion Failed: Message: %s, File %s, Line %i, Assertion on-hit time: %s ", msg, __FILE__, __LINE__, __TIME__ ); _STL_INTERNAL_BREAKDEBUG_(); }
#endif // !_STL_INTERNAL_ASSERT_

#define _STL_ASSERT_(cond, msg) _STL_INTERNAL_ASSERT_(cond, msg)

#ifdef STL_USE_STD_NAMESPACE
namespace std {
#endif // STL_USE_STD_NAMESPACE

#ifdef STL_USE_NAMESPACE
namespace beast::std {
#endif

#ifdef STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE
#error STL_USE_NAMESPACE and STL_USE_STD_NAMESPACE can not be defined at the same time.
#endif // STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE

typedef nullptr_t nullptr_t;

#ifdef STL_USE_NAMESPACE
}
#endif

#ifdef STL_USE_STD_NAMESPACE
}
#endif // STL_USE_STD_NAMESPACE

#endif // _STL_COMPILER_PREPROCESSOR_