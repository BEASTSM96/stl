
#include <iostream>
#include "vector.h"

class Test
{
public:
	Test() {}
	~Test() {}

	float x, y, z = 0.0f;

protected:
	

private:
};

int main() 
{
	std::vector<std::string> m_Test;
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

	printf( "%s", m_Test[ 55 ].c_str());

	for ( size_t i = 0; i < m_Test.size(); i++ )
	{
		printf( "%s", m_Test[ i ].c_str() );
	}

	std::cin.get();

} 