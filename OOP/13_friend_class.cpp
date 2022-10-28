 // 13_friend_class.cpp

/*
	friend : �ܺο��� Ŭ������ ������ ����� ������ �� �ְ� ���ִ� Ű����
	 - ������ �����ϰ� ���� �ʿ��� �����Ѵ�. -> �ܹ���
	 - friend�� ����� ���� �ʴ´�.
*/

#include <iostream>
using namespace std;
#define FRIEND_GLOBAL_FUNTION

#ifdef FRIEND_GLOBAL_FUNTION
/*
	���� �Լ����� �����ϴ� ���
*/

class A
{
private:
	int value = 1;

private:
	// 1.
	// friend Ű���带 ����ϸ� ���� �Լ����� ������ ����� ���ٰ���
	friend void do_something1(const A& a);

	// 2.
	// �Լ��� ���Ǻθ� �ٷ� �ۼ����� (�ۿ� �����ϴ� �Ͱ� �������� ����.)
	// ���ο� �����ص� �����Լ� ���
	friend void do_something2(const A& a)
	{
		// friend Ű���带 ����� ������ ����� ���ٰ���
		cout << a.value << endl;
	}

};

 // 1.
void do_something1(const A& a)
{
	// friend Ű���带 ����� ������ ����� ���ٰ���
	cout << a.value << endl;
}

int main()
{
	A a;
	do_something1(a);

	return 0;
}

#endif

#ifdef FRIEND_CLASS

#endif  