#include "08_calc.h"
#include<iostream>

// 멤버 함수이기 때문에 해당 함수가 어디 클래스 소속인지를 명시해주어야한다. -> ::
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