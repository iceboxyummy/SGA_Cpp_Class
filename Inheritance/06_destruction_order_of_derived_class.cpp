 // 06_destruction_order_of_derived_class.cpp

#include<iostream>
using namespace std;

class A
{
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }

private:
	int a;
};

class B : public A
{
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }

private:
	double b;
};

int main() {
	// 생성자는 기본 클래스 먼저 소멸자는 파생 클래스 먼저
	// 먼저 생성된 객체는 더 많은 관계를 맺고 있을 가능성이 있어 생성의 역순으로 삭제하는게 안전하다.

	B b;

	/*
		 패딩 : 클래스나 구조체의 패딩바이트를 추가하여 CPU가 접근하기 용이하게 해주는 기법
		  - CPU가 데이터를 읽을 때 자료형이 잘려 데이터에 두 번 접근하는 것을 방지한다.
		  - 일반적으로 가장 큰 멤버 변수 중 사이즈가 가장 큰 변수의 크기에 맞추어 패딩을 한다.
		  
		  ㅁ -> 패딩바이트

		  a a a a ㅁ ㅁ ㅁ ㅁ b b b b b b b b
	*/
	sizeof(B);

	class P1
	{
		char c;
		short s1;
		short s2;
	};

	// c ㅁ s1 s1 s2 s2
	sizeof(P1);

	class P2
	{
		char c;
		short s;
		int i;
		double d;
	};

	// c s s i i i i ㅁ d d d d d d d d
	sizeof(P2);

	return 0;
}