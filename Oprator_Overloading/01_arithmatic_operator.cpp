 // 01_arithmatic_operator.cpp

/*
   arithmatic operator - 산술 연산자
   (+), (-), (*), (/), (%), (+=), (-=), (*=), (/=), (%=)
*/

#include<iostream>
using namespace std;

// #define C1
#define C2

#ifdef C1

class Won
{
public:
	Won(int value)
		:value(value)
	{

	}
	int GetValue() const
	{
		return value;
	}

	// 보통 들어오는 인자값의 이름을 이렇게 정함
	// lhs - 좌항 : left hand side
	// rhs - 우항 : right hand side

	friend int operator+(const Won& lhs, Won& rhs);

private:
	int value;
};

int operator+(const Won& lhs, Won& rhs)
{
	//return lhs.GetValue() + rhs.GetValue();
	return lhs.value() + rhs.value();
}

int operator-(const Won& lhs, Won& rhs)
{
	// 리턴값에 맞은 적절한 생성자강 있을시 가능하다.
	return lhs.GetValue() - rhs.GetValue();
}

int main() {
	Won l(100), r(500);

	int result = l + r;
	cout << result << endl;

	Won result2(l - r);
	cout << result2.GetValue() << endl;
}

#endif 

#ifdef C2

class Won
{
public:
	Won(int value)
		:value(value)
	{

	}

	int GetValue() const
	{
		return value;
	}
	// l + r -> l.operator(r)
	int operator+(const Won& rhs) const
	{
		return value + rhs.value;
	}

private:
	int value;
};

int main() {
	Won l(100), r(500);

	int result = l + r;
	cout << result << endl;

	l.operator+(r);

	//Won result2(l - r);
	//cout << result2.GetValue() << endl;
}

#endif 