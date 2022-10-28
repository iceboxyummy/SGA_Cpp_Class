 // 10_static_member_varible.cpp

/*
	Static member variable : Ŭ���� ���ο��� �ϳ��� �����ϴ�, Ŭ������ ��� ��ü�� �����ϴ� ����
	 - ������ Ŭ���� ���ο���, �ʱ�ȭ�� �ҽ�����(.cpp)���� ���־���Ѵ�.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	int value = 1;

	// static int count = 10;
	static int count;
	// static �������� ������ �� �޸𸮰� �����Ǿ�� �Ѵ�.
	// �׷��� class ����� ���� -> ���⼭�� ���� ���� �ǰ� �ʱ�ȭ�� ���� �ʴ´�.

	// const Ű���带 �߰��� ��쿡�� ����
	static const int test = 10;

private:
};

// define in cpp -> ��� ���Ͽ��� �ʱ�ȭ�� ��� error �� ���� �� ����

int Test::count = 10;

class Math
{
public:
	static constexpr double PI = 3.14;
};

int main()
{
	Math::PI;

	Test t1, t2;

	t1.value = 20;
	t2.value = 30;

	cout << &t1.value << "," << t1.value << endl;
	cout << &t2.value << "," << t2.value << endl;

	t1.count = 20;
	t2.count = 30;

	cout << &t1.count << "," << t1.count << endl;
	cout << &t2.count << "," << t2.count << endl;

	cout << &Test::count << "," << Test::count << endl;

	return 0;
}