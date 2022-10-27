 // 07_this_pointer_and_chaining_member_functions.cpp

#include<iostream>
using namespace std;

//#define THIS_POINTER
#define CHAINING

#ifdef THIS_POINTER

//this pointer : 멤버 함수를 호출한 객체를 구별하기 위헤 기본적으로 포함되는 해당 객체의 포인터
class Test
{
public:
	Test(){}
	~Test(){}

	// this : 실체화된 인스턴스의 포인터
	int /*this call*/ GetA()
	{
		// this의 주소는 멤버 함수를 호출한 인스턴스
		cout << this << endl;

		return a;
	}

	// void SetA(const int& a) { a = a; } // name hiding 매개변수가 우선시 된다.
	void SetA(const int& a) { this->a = a; } // this포인터를 사용하여 중복문제 해결 가능

private:
	int a;
	int b;
	int c;
};

int main() {
	Test test1;
	test1.GetA();

	Test test2;
	test2.GetA();

	cout << &test1<< "," << &test2 << endl;
}
#endif

#ifdef CHAINING
/*
	chaining member function
	 - 자신을 연쇄적으로 호출하는 함수
*/

class Calc
{
public:
	Calc(int value): value(value){}

	// 1.
	/*
	void Add(int value) { this->value += value; }
	void Sub(int value) { this->value -= value; }
	void Mul(int value) { this->value *= value; }
	void Div(int value) { this->value /= value; }
	void Mod(int value) { this->value %= value; } */

	// 2. 반환값이 Calc&(자신)

	Calc& Add(int value) { this->value += value; return *this; }
	Calc& Sub(int value) { this->value -= value; return *this; }
	Calc& Mul(int value) { this->value *= value; return *this; }
	Calc& Div(int value) { this->value /= value; return *this; }
	Calc& Mod(int value) { this->value %= value; return *this; }

private:
	int value;
};

int main()
{
	// 1.
	Calc calc(10);
	calc.Add(5);
	calc.Div(2);
	calc.Mul(3);
	calc.Mod(5);
	calc.Sub(2);

	// 2.
	calc.Add(5).Div(2).Mul(3).Mod(5).Sub(2);

	// 3.
	Calc(10).Add(5).Div(2).Mul(3).Mod(5).Sub(2);

	return 0;
}
#endif