 // 17_array.cpp

#include <iostream>
#include <array>

int main() {
	using namespace std;
	
	int arr1[] = { 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	// int arr3[](1, 2, 3, 4, 5); // error

	/*
		STL : Standard Template Libraries
		손쉽게 사용가능 하도록 만든 라이브러리
	*/

	std::array<int, 5> arr4; // int가 5개인 메모리 생성
	std::array<int, 5> arr5{ 1,2,3,4,5 }; // 초기화도 가능

	cout << arr5[0] << endl;
	cout << arr5[1] << endl;
	cout << arr5.at(0) << endl;
	cout << arr5.at(1) << endl;
	cout << arr5.size() << endl;

	return 0;
}