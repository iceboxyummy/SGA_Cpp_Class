 // 19_default_paprmeter.cpp
#include <iostream>

void print(int x = 7) // 아무것도 입력 안할 때 기본값으로 7이 나오게 한다.
{
	std::cout << x << std::endl;
}

// 주의점 1 : 항상 마지막부터 넣어야 한다.
void print(int x, int y= 7)
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}

// 주의점 2 : 수정할 값이 뒤에 있다면 앞의 값도 대입해주어야 한다.
void test(int x = 10, int y = 10, int z = 10) {	}

int main() {

	print(); // 기본 설정값인 7로 호출된다.
	test(10, 10, 3); // 뒤에 있는 값을 수정하고 싶다면 앞의 값도 넣어주어야 한다.

	// 주의점 3 : ambiguos
    // print(10); => print(int x=7)인지 print(int x, int y=7)인지 모호하다. => defalt parameter 와 오버로드는 동시에 쓰지 않는게 좋다.
	
	return 0;
}