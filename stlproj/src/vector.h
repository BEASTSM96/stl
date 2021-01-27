#pragma once

#include "core.h"
//TEMP MSVC
#include <type_traits>

#ifdef STL_USE_STD_NAMESPACE
namespace std {
#endif // STL_USE_STD_NAMESPACE

#ifdef STL_USE_NAMESPACE
namespace beast::std {
#endif

#ifdef STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE
#error STL_USE_NAMESPACE and STL_USE_STD_NAMESPACE can not be defined at the same time.
#endif // STL_USE_NAMESPACE && STL_USE_STD_NAMESPACE

template<typename T>
class vector
{
public:

	vector()
	{
		ReAlloc( 2 );
	}

	~vector()
	{
		clear();
		delete[] m_Data;
	}

public:

	void clear()
	{
		/*
		for( size_t i = 0; i < m_Size; i++ )
			m_Size[ i ].~T();

		m_Size = 0;
		*/
	}

	//vector operators & get object at index
	const T& operator[](size_t index) const
	{
		if ( index >= m_Size )
		{
			_STL_ASSERT_( false, "vector out of range!" );
		}
		return m_Data[ index ];
	}

	T& operator[]( size_t index )
	{
		if( index >= m_Size )
		{
			_STL_ASSERT_( false, "vector out of range!" );
		}
		return m_Data[ index ];
	}

	T& at( size_t index )
	{
		if( index >= m_Size )
		{
			_STL_ASSERT_( false, "vector out of range!" );
		}
		return m_Data[ index ];
	}

	const T& at( size_t index ) const
	{
		if( index >= m_Size )
		{
			_STL_ASSERT_( false, "vector out of range!" );
		}
		return m_Data[ index ];
	}

	//push & emplace back, and maybe pop back
	void push_back( const T& value )
	{
		if( m_Size >= m_Capacity )
			ReAlloc( m_Capacity + m_Capacity / 2 );

		m_Data[ m_Size ] = std::move( value );
		m_Size++;
	}

	void push_back(T&& value) 
	{
		if( m_Size >= m_Capacity )
			ReAlloc( m_Capacity + m_Capacity / 2 );

		m_Data[ m_Size ] = std::move( value );
		m_Size++;
	}

	template<typename... Args>
	T& emplace_back(Args&&... args)
	{
		if( m_Size >= m_Capacity )
			ReAlloc( m_Capacity + m_Capacity / 2 );

		m_Data[ m_Size ] = T( std::forward<Args>( args )... );
	}

	void pop_back() 
	{
		if ( m_Size > 0 )
		{
			m_Size--;
			m_Data[ m_Size ].~T();
		}
	}

	//size
	size_t size() const	{ return m_Size; }

private:

	void ReAlloc( size_t newCapacity ) 
	{
		T* newBlock = new T[ newCapacity ];

		if( newCapacity < m_Size )
			m_Size = newCapacity;

		for( size_t i = 0; i < m_Size; i++ )
			//TODO: Make a 'move' func!
			newBlock[ i ] = std::move( m_Data[ i ] ); 

		// if we have one element
		if (m_Size == 0)
		{
			m_First = newBlock;
		}
		if ( m_Size == 1)
		{
			m_Last = m_First - m_Size;
		}

		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:

	T* m_Data = nullptr;
	T* m_Last = nullptr;
	T* m_First = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
};

#ifdef STL_USE_NAMESPACE
}
#endif

#ifdef STL_USE_STD_NAMESPACE
}
#endif // STL_USE_STD_NAMESPACE