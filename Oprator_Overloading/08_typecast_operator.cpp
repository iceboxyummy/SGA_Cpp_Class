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
		// �����Ͱ� ���������� �Ǿ��־� x�� �ѱ�� x, y, z�� ������ �������� ������� ���ٰ���
		return &x;
	}

private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

// ���������� �迭�� �Ű������� �������� ������ ���·� �޴´�.
void PrintPoint(float points[3]) // float* points
	{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
	}

int main() {

	Won w(10);
	
	// int ����ȯ�� �����ε��Ͽ� �Ͻ������� ĳ���õǵ��� ��
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);

	PrintPoint(p);
	return 0;
}