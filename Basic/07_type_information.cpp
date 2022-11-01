// 07_type_information.cpp

/*
	RTTI(Run Time Type Information) : 런타임 중에 실시간으로 데이터 타입에 대한 정보를 얻는 기능
	 - 해당 기능이 켜저있어야 실시간으로 데이터 확인가능
	 - dynamic_cast시에도 필요하다
	 - 런타임때 자료형을 계산하는거라 느리다.
*/

#include<iostream>
#include<typeinfo>

//int add(int a, int b) { return a + b; }
//float add(float a, float b) { return a + b; }
//short add(short a, short b) { return a + b; }

template<typename T>

T add(T a, T b)
{
	std::cout << "a : " << typeid(a).name() << std::endl;
	std::cout << "b : " << typeid(b).name() << std::endl;

	return a + b;
}

int main()
{
	auto a = add(10, 20);
	std::cout << add(10.0f, 20.0f);

	return 0;
}