 // 04_namespace.cpp

/*
	namespace(�̸�����) : ���ǵ� ��ü�� ���� �Ҽ��� �����ִ� ��
	- std::cout, std::cin ���⼭ std�� cout, cin�� �̸� ����
	- �̸��� ���Ƶ� �̸� ������ �ٸ��ٸ� �ٸ� ��ü�� �ν�
	- ������ �Լ��� �ߺ������� �ذᰡ��

	����
	namespace �������̸�
	{
		���
	}

	���ٹ�
	�����̸�::���
*/

#include<iostream>
using namespace std;

namespace my_namespace_1
{
	int a; // my_namespace_1::a
	void do_something() {} // my_namespace_1::do_something()

	namespace DIDI // ��ø
	{
		namespace TITI // ��ø
		{
			namespace RURU // ��ø
			{
				int c; // my_namespace_1::DIDI::TITI::RURU::c
			}
		}
	}
}

// �и��ؼ� ����ص� ���� �̸� ������ ����.
namespace my_namespace_1
{
	int hello;
}

// c++ 17������ ����
namespace my_namespace_1::DIDI::TITI::RURU
{
	int test;
}

namespace my_namespace_2
{
	int a;
	void do_something() {}
}

// using namespace �ش� �������� �̿��� �̸����� => �ش� �̸������� ������ ���������� ������� �ʰ� ���� ����

using namespace std;

int main()
{
	// �Ҽӵ� �̸������� �޶� �ߺ��� �̸��� ����, �Լ� ��밡�� -> �ߺ����� �ذ�
	my_namespace_1::a;
	my_namespace_2::a;

	my_namespace_1::DIDI::TITI::RURU::c;

	// �ش� �Ҽ��� �����־�߸� ���� ����
	//cout << a << endl; // error : �����������

	// ������ �����ϰ� �Ǹ� ��ȣ���� ���� Ȯ���� �����Ƿ� ��Ͼȿ� �����ϴ°� ����.
	{
		using namespace my_namespace_1;
		using namespace my_namespace_2;

		//a = 10; // ambiguos : ��ȣ��
		hello;

		my_namespace_2::a;

	}

	return 0;
}
