 // 18_function_overloading.cpp

 // function overloading : �Լ��� �̸��� ����(�ߺ�)�ؼ� ����ϴ� ��, �Ű������θ� ������ �����ϴ�.

#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; } // (1)
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// int add(int a, int b) { return a + b + 10; } �Ű������� �����Լ�(1)�� �ִ�.
// void add(int a, int b) { return; } ��ȯ�����δ� ������ �ȵȴ�.

using interger = int;
// int add(interger a, interger b) { return a + b; } �����Ϸ��� ���⿡�� (1)�� ����.

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