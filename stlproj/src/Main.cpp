#include "vector.h"
#include "pointer.h"

//C Stuff(MSVC)
#include <stdio.h>

class Test
{
public:
	Test() {}
	~Test() {}

	float x, y, z = 0.0f;

protected:
	

private:
};

class Testing : Test
{
public:
	Testing() { }
	~Testing() { }

protected:


private:
};

class Class
{
public:
	Class() { }
	~Class() { }

protected:


private:
};

int main()
{
	std::vector<const char*> m_Test;
	m_Test.push_back( "Test\n" );
	m_Test.push_back( "Yes\n" );
	m_Test.push_back( "Epic\n" );
	m_Test.push_back( "Test\n" );
	m_Test.push_back( "Yes\n" );
	m_Test.push_back( "Epic\n" );
	m_Test.push_back( "Test\n" );
	m_Test.push_back( "Yes\n" );
	m_Test.push_back( "Epic\n" );
	m_Test.push_back( "Test\n" );
	m_Test.push_back( "Yes\n" );
	m_Test.push_back( "Epic\n" );
	m_Test.push_back( "Test\n" );
	m_Test.push_back( "Yes\n" );
	m_Test.push_back( "Epic\n" );

	for ( size_t i = 0; i < m_Test.size(); i++ )
	{
		printf( "%s", m_Test[ i ] );
	}

	printf( "is_pointer_v\n" );

	static_assert( std::IsPointerV<Test*> );
	//static_assert( std::IsPointerV<Test> );

	printf( "is_base_of_v\n" );

	static_assert( std::IsBaseOfV<Test, Testing> );
	//static_assert( std::IsBaseOf<Test, Class> );

	printf( "is_same_v\n" );

	static_assert( std::IsSameV<Test, Test> );
	//static_assert( std::IsSameV<Test, Testing> );
}