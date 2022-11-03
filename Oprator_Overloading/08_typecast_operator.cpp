 // 08_typecast_operator.cpp

#include<iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value) {}

	operator int()
	{
		return value;
	}

private:
	int value;
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
public:
	Point(float x, float y, float z)
		: x(x),y(y),z(z)
	{}

	operator float*()
	{
		// 데이터가 연속적으로 되어있어 x를 넘기면 x, y, z를 포인터 연산으로 순서대로 접근가능
		return &x;
	}

private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

// 내부적으로 배열을 매개변수로 받을때는 포인터 형태로 받는다.
void PrintPoint(float points[3]) // float* points
	{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
	}

int main() {

	Won w(10);
	
	// int 형변환을 오버로딩하여 암시적으로 캐스팅되도록 함
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);

	PrintPoint(p);
	return 0; 
}
