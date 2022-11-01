 // 04_namespace.cpp

/*
	namespace(이름공간) : 정의된 객체에 대해 소속을 정해주는 것
	- std::cout, std::cin 여기서 std가 cout, cin의 이름 공간
	- 이름이 같아도 이름 공간이 다르다면 다른 객체로 인식
	- 변수나 함수의 중복문제를 해결가능

	선언
	namespace 공간의이름
	{
		멤버
	}

	접근법
	공간이름::멤버
*/

#include<iostream>
using namespace std;

namespace my_namespace_1
{
	int a; // my_namespace_1::a
	void do_something() {} // my_namespace_1::do_something()

	namespace DIDI // 중첩
	{
		namespace TITI // 중첩
		{
			namespace RURU // 중첩
			{
				int c; // my_namespace_1::DIDI::TITI::RURU::c
			}
		}
	}
}

// 분리해서 사용해도 같은 이름 공간에 들어간다.
namespace my_namespace_1
{
	int hello;
}

// c++ 17에서는 가능
namespace my_namespace_1::DIDI::TITI::RURU
{
	int test;
}

namespace my_namespace_2
{
	int a;
	void do_something() {}
}

// using namespace 해당 지역에서 이용할 이름공간 => 해당 이름공간을 선언한 영역내에서 사용하지 않고도 접근 가능

using namespace std;

int main()
{
	// 소속된 이름공간이 달라 중복된 이름의 변수, 함수 사용가능 -> 중복문제 해결
	my_namespace_1::a;
	my_namespace_2::a;

	my_namespace_1::DIDI::TITI::RURU::c;

	// 해당 소속을 적어주어야만 접근 가능
	//cout << a << endl; // error : 선언되지않음

	// 전역에 선언하게 되면 모호성이 생길 확률이 높으므로 블록안에 선언하는게 좋다.
	{
		using namespace my_namespace_1;
		using namespace my_namespace_2;

		//a = 10; // ambiguos : 모호성
		hello;

		my_namespace_2::a;

	}

	return 0;
}
