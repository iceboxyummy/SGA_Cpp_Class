 // 14_dynamic_memory_allocation.cpp

#include <iostream>

int main() {
	int* ptr1 = new int; // 동적 할당
	delete ptr1;		 // 동적 해제

	int* ptr2 = new int(7); // 초기값 세팅가능
	delete ptr2;

	int* ptr3 = new int(7); // 유니폼 초기화도 가능하다.
	delete ptr3;

	// new는 할당 실패시 nullptr을 리턴하지 않고 예외를 발생시킨다.
	// std::nothrow를 사용할 경우에는 nullptr를 반환해준다.
	int* ptr4 = new(std::nothrow) int{ 7 };

	if (ptr4 == nullptr)
		std::cout << "Error!";

	if (ptr4 != nullptr)
		delete ptr4;

	// 배열 형태 선언
	int* arr = new int[10]{ 1,2,3,4 };
	delete[] arr; // []를 넣어주어야 한다.

	// 포인터 배열을 2차원 포인터로 받아보자
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