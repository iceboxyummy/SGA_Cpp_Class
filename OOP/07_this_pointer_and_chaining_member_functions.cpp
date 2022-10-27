 // 07_this_pointer_and_chaining_member_functions.cpp

#include<iostream>
using namespace std;

//#define THIS_POINTER
#define CHAINING

#ifdef THIS_POINTER

//this pointer : ��� �Լ��� ȣ���� ��ü�� �����ϱ� ���� �⺻������ ���ԵǴ� �ش� ��ü�� ������
class Test
{
public:
	Test(){}
	~Test(){}

	// this : ��üȭ�� �ν��Ͻ��� ������
	int /*this call*/ GetA()
	{
		// this�� �ּҴ� ��� �Լ��� ȣ���� �ν��Ͻ�
		cout << this << endl;

		return a;
	}

	// void SetA(const int& a) { a = a; } // name hiding �Ű������� �켱�� �ȴ�.
	void SetA(const int& a) { this->a = a; } // this�����͸� ����Ͽ� �ߺ����� �ذ� ����

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
	 - �ڽ��� ���������� ȣ���ϴ� �Լ�
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

	// 2. ��ȯ���� Calc&(�ڽ�)

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