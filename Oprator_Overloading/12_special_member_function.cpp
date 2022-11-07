 // 12_special_member_function.cpp

/*
   special member function - Ư�� ��� �Լ�
   - �ڵ����� �ۼ��Ǵ� �Լ� 6������ ���Ѵ�.
   - �� �Լ��� ��������� �ۼ����� ���� ��� �ڵ����� �ۼ��� �ȴ�.
   - �� ����/�Լ����� Ư�� ���ǿ� ���� �ڵ� �ۼ��� ���� ���� �� �ִ�.

   �޼��� ����
   default constructor - �⺻ ������
   - �ۼ��� �����ڰ� �ϳ��� ���� �� �ۼ��ȴ�.
   - �ƹ��� ����� ����.

   destructor - �Ҹ���
   - �Ҹ��ڸ� �ۼ����� ���� ��� �ڵ� �ۼ��ȴ�.

   copy constructor/assigment operator - ���� ������/���� ������
   - �� �� �ϳ��� �ۼ� �Ǿ� ���� ���, �ٸ� �ϳ��� �ۼ��� ���� �ʴ´�.
   - move constructor/assigment operator�� �ϳ��� �ۼ��Ǿ� �ִٸ� �ۼ��� ���� �ʴ´�.

   move constructor/assigment operator - �̵� ������/���� ������
   - �� �� �ϳ��� �ۼ� �Ǿ� ���� ���, �ٸ� �ϳ��� �ۼ��� ���� �ʴ´�.
   - copy constructor/assigment operator�� �ϳ��� �ۼ��Ǿ� �ִٸ� �ۼ��� ���� �ʴ´�.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	// constructor
	Test()
		:value(++count)
	{
		cout << "default constructor" << endl;
	}

	Test(const Test& t)
		:value(++count)
	{
		cout << "copy constructor" << endl;
	}

	Test(Test&& t) noexcept
		:value(++count)
	{
		cout << "move constructor" << endl;
	}

	// assignment
	Test& operator = (const Test& t)
	{
		cout << "copy assignment" << endl;
		return *this;
	}

	Test& operator = (Test& t)
	{
		cout << "move assignment" << endl;
		return *this;
	}

	// destructor
	~Test()
	{
		cout << "destructor : " << value << endl;
	}

public:
	static int count;

private:
	int value;
};

int Test::count = 0;

int main() {
	cout << "1###########################" << endl;
	Test t1; // �⺻ ������

	cout << "2###########################" << endl;
	Test t2 = t1; // ���� �ܰ迡���� =�� ������ �ǹ� x, ���� ������ ȣ��
	Test t3(t1);

	cout << "3###########################" << endl;
	Test t4=move(t1); // �̵� ������ ȣ��
	Test t5(move(t1));

	cout << "4###########################" << endl;
	t1 = t2; // ���� ���� ������

	cout << "5###########################" << endl;
	t1 = move(t2); // �̵� ���� ������

	cout << "6###########################" << endl;

	return 0;
}