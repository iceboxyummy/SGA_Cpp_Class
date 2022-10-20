 // 15_reference_variable.cpp

/*
    L-value -> copy, R-value ->mave

	L-value &  : ���߿� �ٽ� ������ ������ ��
	R-value && : ���� ������ ������ �Ұ����� ��
*/

#include <iostream>

// �� ���۷����� ���α׷����� �ǵ��� �� �� �ִ�.
int Test1(int& a) // a�� �ܺο� ������ ������ ǥ���ϰ� ������ �ʿ伺�� ǥ��
{
	return a;
}

int Test2(int&& a) // a�� �ۿ��� �������� ������ ǥ�� -> ������ �ʿ䰡 ����.
{
	return a;
}


int main()
{
	int val = 5;

	int& r = val; // �ڷ��� ���� ���� & -> L-value Reference;
	 // val == r value�� r�� ����. ���ϰ� ����ϱ� ���� ������ ���� ��
	 // ���������δ� ������, ����ó�� ����ϸ�ȴ�.

	r = 10;

	std::cout << val << std::endl;

	// int& r2 = 10; // L-value�� ���� �� �ִ�.
	const int& r2 = 10; // const�� ���̸� ����

	int&& rr = 10; // R-value reference

	return 0;
}