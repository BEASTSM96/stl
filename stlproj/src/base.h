#pragma once

#ifndef _STL_COMPILER_PREPROCESSOR_
#define _STL_COMPILER_PREPROCESSOR_
#endif

//_HAS_CXX XX
//hard code it for now...
#define _STL_CXX_VER_ 201705L
#if _STL_CXX_VER_ == 201703L
#define _HAS_CXX17_ _STL_CXX_VER_
#elif _STL_CXX_VER_ == 201705L
#define _HAS_CXX20_ _STL_CXX_VER_
#endif
