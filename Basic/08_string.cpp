 // 08_string.cpp

#include <iostream>
#include <string>

int main() {
	using namespace std;

	// 포인터로 받으면 문자열 상수의 주소를 받기때문에 수정이 안된다.
	// c와 달리 c++에서는 const를 붙이지 않으면 받지 못하도록 변경되었다.
	const char* test = "Hello";
	char my_str[] = "Hello, C++";

	// string : 문자열을 다루기 쉽게 해주는 객체
	string str = "Hello, C++!";

	// 길이 반환
	cout << str.size() << endl;
	cout << str.length() << endl;

	// 변수처럼 초기화 가능
	string a("Hello, ");
	string b("C++!! ");

	// + 연산 가능
	string c = a + b;

	c += ", good!!";
	cout << c << endl;

	// 배열처럼 사용가능
	cout << c[3] << endl;

	return 0;
}
