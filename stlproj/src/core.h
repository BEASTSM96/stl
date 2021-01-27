#pragma once

#include "base.h"

#ifdef _STL_COMPILER_PREPROCESSOR_

#ifndef _STL_INTERNAL_ASSERT_
#define  _STL_INTERNAL_ASSERT_(cond, msg) if (!(cond)) { printf( "Assertion Failed: Message: %s, File %s, Line %i, Assertion on-hit time: %s ", msg, __FILE__, __LINE__, __TIME__ ); __debugbreak(); }
#endif // !_STL_INTERNAL_ASSERT_


#define _STL_ASSERT_(cond, msg) _STL_INTERNAL_ASSERT_(cond, msg)

#endif // _STL_COMPILER_PREPROCESSOR_