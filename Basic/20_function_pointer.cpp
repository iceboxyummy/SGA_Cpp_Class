// 20_function_pointer.cpp

#include <iostream>
#include <functional> // 함수 포인터를 쉽게 쓸 수 있게 해주는 라이브러리

using namespace std;

bool func(const int& x)
{
	return x > 0;
}

// 함수의 이름부분이 타입 부분이 된다.
typedef bool(*func_ptr)(const int&);

// using
using func_type = bool(*)(const int&);

int main() {

	bool (*pf)(const int&) = func;

	func_ptr f = func;

	func_type f2 = func;

	// 반환값과 매개변수만 넣어주면 된다. 함수 포인터와 동작 원리가 비슷하다.
	std::function<bool(const int&)>f3 = func;

	return 0;
}