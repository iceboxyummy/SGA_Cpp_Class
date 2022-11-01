 // 01_arithmatic_operator.cpp

/*
   arithmatic operator - ��� ������
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

	// ���� ������ ���ڰ��� �̸��� �̷��� ����
	// lhs - ���� : left hand side
	// rhs - ���� : right hand side

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
	// ���ϰ��� ���� ������ �����ڰ� ������ �����ϴ�.
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