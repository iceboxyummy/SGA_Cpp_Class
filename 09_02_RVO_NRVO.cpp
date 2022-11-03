 //	09_02_RVO_NRVO.	cpp

/*
	RVO - Return Value Optimization) : � �Լ��� ��ü�� ��ȯ�ؾ� �� ���, �ʿ����� ���� �ӽ� ��ü�� �������� �ʵ��� ����ȭ �ϴ� ��
	 - Debug, Rlease ���� ����
	 - ��ȯ ��ü�� �������� ������ ���� ��� ����ȭ�ȴ�.
	 - �������� ���� ��� ����ȭ ���� �ʾ����� NRVO�� �߰��Ǿ� �����ϰ� �Ǿ���.

	 NRVO(Named Return Value Optimization) : RVO�� ���� ������� ����ȭ�� �����Ѵ�.
	  - Debug������ ����ȭ x, Rlease ������ ����ȭ o
*/

#include<iostream>
using namespace std;

class Test
{
public:
	Test(int value) : value1(value), value2(count++)
	{
		cout << " constructor : " << this->value1 << "," << this->value2 << endl;
	}

	Test(const Test& rhs) : value1(rhs.value1), value2(count++)
	{
		cout << " copy constructor : " << this->value1 << "," << this->value2 << endl;
	}

	~Test()
	{
		cout << " destructor : " << this->value1 << "," << this->value2 << endl;
	}

public:
	static int count;

private:
	int value1;
	int value2;
};

int Test::count = 1;

// Debug, Release : �ӽð�ü ���� x
Test MakeRVO(int value)
{
	return Test(value); // RVO -> ��ȯ ��ü�� �̸��� ���� �Ͽ� 
}

// Debug : �ӽð�ü ���� x, Release : �ӽð�ü ���� ��
Test MakeNRVO(int value)
{
	return Test(value); // NRVO -> ��ȯ ��ü�� �̸���  �ִ� �Ͽ� 
}

int main() {
	
	cout << "-----------RVO-----------" << endl;
	Test t1 = MakeRVO(1);

	cout << "----------NRVO-----------" << endl;
	Test t2 = MakeNRVO(2);

	cout << "-----------End-----------" << endl;

	return 0;
}