 // 16_range_based_for_loop.cpp

#include<iostream>

int main() {
	using namespace std;

	int fibonacci[]{ 0,1,1,2,3,5,8,13,21,34,55,89 };

	for (int i = 0; i < sizeof(fibonacci) / sizeof(int); i++)
		cout << fibonacci[i] << endl;
	cout << endl;

	// 연속된 데이터를 처음부터 끝까지 접근하며 동일한 작업을 처리

	for (const auto& number : fibonacci) // 범위기반 for loop
		cout << number << endl;

	for (const auto& number : { 0,1,1,2,3,5,8,13,21,34,55,89 }) 
		cout << number << endl;

	int* test = new int[10];

	// for(auto t : test) // error : 범위를 확인할 수 없는 자료형은 불가능하다.

	struct tt
	{
		int arr1[10];
		float a;
		int arr2[10];

		int* begin()
		{
			return arr2;
		}

		int* end()
		{
			return &arr2[9] + 1;
		}
	};

	tt t1;
	for (auto a : t1)
		cout << a << endl;

	return 0;
}