 // 19_default_paprmeter.cpp
#include <iostream>

void print(int x = 7) // �ƹ��͵� �Է� ���� �� �⺻������ 7�� ������ �Ѵ�.
{
	std::cout << x << std::endl;
}

// ������ 1 : �׻� ���������� �־�� �Ѵ�.
void print(int x, int y= 7)
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}

// ������ 2 : ������ ���� �ڿ� �ִٸ� ���� ���� �������־�� �Ѵ�.
void test(int x = 10, int y = 10, int z = 10) {	}

int main() {

	print(); // �⺻ �������� 7�� ȣ��ȴ�.
	test(10, 10, 3); // �ڿ� �ִ� ���� �����ϰ� �ʹٸ� ���� ���� �־��־�� �Ѵ�.

	// ������ 3 : ambiguos
    // print(10); => print(int x=7)���� print(int x, int y=7)���� ��ȣ�ϴ�. => defalt parameter �� �����ε�� ���ÿ� ���� �ʴ°� ����.
	
	return 0;
}