 // 13_pointer.cpp

#include <iostream>

int main()
{
	int* ptr = nullptr;      //C++에서는 NULL 대신 nullptr 사용
	int* ptr2(nullptr);
	int* ptr3{ nullptr };

	const char* str = "Test";

	return 0;
}