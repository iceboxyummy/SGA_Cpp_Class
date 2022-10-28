 // 10_static_member_varible.cpp

/*
	Static member variable : 클래스 내부에서 하나만 존재하는, 클래스의 모든 객체가 공유하는 변수
	 - 선언은 클래스 내부에서, 초기화는 소스파일(.cpp)에서 해주어야한다.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	int value = 1;

	// static int count = 10;
	static int count;
	// static 변수들은 컴파일 때 메모리가 생성되어야 한다.
	// 그러나 class 상상의 개념 -> 여기서는 그저 선언만 되고 초기화가 되지 않는다.

	// const 키워드를 추가할 경우에는 가능
	static const int test = 10;

private:
};

// define in cpp -> 헤더 파일에서 초기화할 경우 error 가 생길 수 있음

int Test::count = 10;

class Math
{
public:
	static constexpr double PI = 3.14;
};

int main()
{
	Math::PI;

	Test t1, t2;

	t1.value = 20;
	t2.value = 30;

	cout << &t1.value << "," << t1.value << endl;
	cout << &t2.value << "," << t2.value << endl;

	t1.count = 20;
	t2.count = 30;

	cout << &t1.count << "," << t1.count << endl;
	cout << &t2.count << "," << t2.count << endl;

	cout << &Test::count << "," << Test::count << endl;

	return 0;
}