 // 14_dynamic_memory_allocation.cpp

#include <iostream>

int main() {
	int* ptr1 = new int; // ���� �Ҵ�
	delete ptr1;		 // ���� ����

	int* ptr2 = new int(7); // �ʱⰪ ���ð���
	delete ptr2;

	int* ptr3 = new int(7); // ������ �ʱ�ȭ�� �����ϴ�.
	delete ptr3;

	// new�� �Ҵ� ���н� nullptr�� �������� �ʰ� ���ܸ� �߻���Ų��.
	// std::nothrow�� ����� ��쿡�� nullptr�� ��ȯ���ش�.
	int* ptr4 = new(std::nothrow) int{ 7 };

	if (ptr4 == nullptr)
		std::cout << "Error!";

	if (ptr4 != nullptr)
		delete ptr4;

	// �迭 ���� ����
	int* arr = new int[10]{ 1,2,3,4 };
	delete[] arr; // []�� �־��־�� �Ѵ�.

	// ������ �迭�� 2���� �����ͷ� �޾ƺ���
	int** ptr_arr = new int* [5];

	ptr_arr[0] = new int[10];
	ptr_arr[1] = new int[10];
	ptr_arr[2] = new int[10];
	ptr_arr[3] = new int[10];
	ptr_arr[4] = new int[10];

	for (int i = 0; i < 5; i++)
		delete[] ptr_arr[i];

	delete[] ptr_arr;
	return 0;
}

/*
	#include<string.h>
	
	struct Test
	{
		int a;
		int b;
		std::string str;
	};
	
	int main() {
		{
			Test* test = new Test;
	
			test->a = 10;
			test->b = 20;
			test->str = "Hello!!";
	
			std::cout << test->a << std::endl;
			std::cout << test->b << std::endl;
			std::cout << test->str<< std::endl;
	
			return 0;
		} 
	}
*/