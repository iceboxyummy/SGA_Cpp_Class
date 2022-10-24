 // 18_function_overloading.cpp

 // function overloading : 함수의 이름을 적재(중복)해서 사용하는 것, 매개변수로만 구분이 가능하다.

#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; } // (1)
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// int add(int a, int b) { return a + b + 10; } 매개변수가 같은함수(1)가 있다.
// void add(int a, int b) { return; } 반환값으로는 구분이 안된다.

using interger = int;
// int add(interger a, interger b) { return a + b; } 컴파일러가 보기에는 (1)과 같다.

float add(float a, float b) { return a + b; }

void output(unsigned int value){}
void output(float value){}

int main(){

	auto result1 = add(10, 20);
	auto result2 = add(10.0f, 20.0f);

	// output(1); // ambiguos
	// output(1.0);
	// output('c');

	return 0;
}