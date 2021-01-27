#pragma once

#include "core.h"

#ifdef STL_USE_STD_NAMESPACE
namespace std {
#endif // STL_USE_STD_NAMESPACE

#ifdef STL_USE_NAMESPACE
namespace beast::std {
#endif

#ifdef STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE
#error STL_USE_NAMESPACE and STL_USE_STD_NAMESPACE can not be defined at the same time.
#endif // STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE

//used the MSVC for ref'ing
//is pointer
//we can't use is_pointer_v as it will fail to compile 
//TODO: ^^^
#ifdef STL_USE_STD_NAMESPACE
template<class>
inline constexpr bool IsPointerV = false;
template<class T>
inline constexpr bool IsPointerV<T*> = true;
template<class T>
inline constexpr bool IsPointerV<T* const volatile> = true;
template<class T>
inline constexpr bool IsPointerV<T*const> = true;
template<class T>
inline constexpr bool IsPointerV<T*volatile> = true;
#endif // STL_USE_STD_NAMESPACE
#ifdef STL_USE_NAMESPACE
template<class>
inline constexpr bool is_pointer_v = false;
template<class T>
inline constexpr bool is_pointer_v<T*> = true;
template<class T>
inline constexpr bool is_pointer_v<T* const volatile> = true;
template<class T>
inline constexpr bool is_pointer_v<T* const> = true;
template<class T>
inline constexpr bool is_pointer_v<T* volatile> = true;
#endif // STL_USE_NAMESPACE

//used the MSVC for ref'ing
//is base of
#ifdef STL_USE_STD_NAMESPACE
template<class Base, class Derived>
inline constexpr bool IsBaseOfV = __is_base_of( Base, Derived );
#endif // STL_USE_STD_NAMESPACE
#ifdef STL_USE_NAMESPACE
template<class Base, class Derived>
inline constexpr bool is_base_of_v = __is_base_of( Base, Derived );
#endif // STL_USE_STD_NAMESPACE
//is same
#ifdef STL_USE_STD_NAMESPACE
template<class, class>
inline constexpr bool IsSameV = false;
template<class T>
inline constexpr bool IsSameV<T, T> = true;
#endif
#ifdef STL_USE_NAMESPACE
template<class, class>
inline constexpr bool is_same_v = false;
template<class T>
inline constexpr bool is_same_v<T, T> = true;
#endif

#ifdef STL_USE_NAMESPACE
}
#endif

#ifdef STL_USE_STD_NAMESPACE
}
#endif // STL_USE_STD_NAMESPACE