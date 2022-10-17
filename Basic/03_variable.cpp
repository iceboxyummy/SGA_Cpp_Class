 // 03_variable.cpp

#include<iostream>
#include<numeric>

int main() {
	// Initialization

	int x = 10;		// copy
	int y(10);		// direct
	int z{ 10 };	// uniform : ����ȯ�� ������� �ʴ´�. -> �����ϴ�.

	int a = 1.1;		// warning : ������ �ս�
	// int b{ 1.1 };	// error : ���� �߸�
	char c = 500;		// warning
	// char d{ 500 };	// error 

	int e = 0, f(1), g{ 2 };

	// limits : ������ �ڷ����� �Ѱ谪�� ������ �ִ� Ŭ����
	// <> : temlpate
	std::cout << std::numeric_limits<short>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl << std::endl;

	// casting
	float k = 10.123f;
	std::cout << k << std::endl;
	std::cout << (int)k << std::endl; // c ctyle �ʹ� ������ -> ������� �ڷ��������� ����ȯ�� ����
	std::cout << int(k) << std::endl; // c++ style

	std::cout << static_cast<int>(k) << std::endl; // c++ style

	// const vs constexpr 

	// const : �޴� ���� ���� �������̳� ��Ÿ�� �� ���� �����ȴ�.

	const int c1 = 123;

	int i1 = 10;
	const int c2 = i1;

	int arr_1[c1];
	// int arr_2[c2]; // error : �ʱ�ȭ ���� ������ �޾� ��Ÿ�Ӷ� ���� ��������.

	/* 
		constexpr : ������Ÿ�Ӷ� ���� ��������.
		 ->�����϶� �� �� ���� ���� ���� �� ����.
		 - ��ũ�ο� ���������� ������� �����ϴ�.
	 */

	constexpr float pi1 = 3.1415921f;
	float pi2 = 3.141592f;
	// constexpr float pi3 = pi2; // error : ������ ������ ������ �� �� ���� �ȵȴ�.

	return 0;
}

