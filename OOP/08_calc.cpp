#include "08_calc.h"
#include<iostream>

// ��� �Լ��̱� ������ �ش� �Լ��� ��� Ŭ���� �Ҽ������� ������־���Ѵ�. -> ::
inline void Calc::Add(int value) { this->value += value; }
inline void Calc::Sub(int value) { this->value -= value; }
inline void Calc::Mul(int value) { this->value *= value; }
inline void Calc::Div(int value) { this->value /= value; }
inline void Calc::Mod(int value) { this->value %= value; }

inline void Calc::Print()
{
	using namespace std;
	cout << value << endl;
}

void Calc::Test()
{
}

void Test(int a)
{
}