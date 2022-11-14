 // 03_template_and_non_type_parameter.cpp

#include<iostream>
#include<array>
using namespace std;

// non-type parameter : 자료형이 아닌 템플릿 매개변수 => 템플릿 매개변수 값을 자료형이 아닌 값을 넣어준다.

template<typename T, unsigned int SIZE>
class MyArray
{
public:
	T arr1[10]; // 정적할당 (상수만 들어갈 수 있다.)
	T arr2[SIZE]; // 템플릿 구체화 시점(컴파일 타임)에 값이 들어가기 때문에 가능하다.
};

int maun() {
	MyArray<int, 15> arr1;
	MyArray<float, 20> arr2;
	
	// array stl 과 형태가 같다.
	array<int, 10>stl_arr;

	return 0;
}