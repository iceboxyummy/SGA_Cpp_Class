 // 03_template_and_non_type_parameter.cpp

#include<iostream>
#include<array>
using namespace std;

// non-type parameter : �ڷ����� �ƴ� ���ø� �Ű����� => ���ø� �Ű����� ���� �ڷ����� �ƴ� ���� �־��ش�.

template<typename T, unsigned int SIZE>
class MyArray
{
public:
	T arr1[10]; // �����Ҵ� (����� �� �� �ִ�.)
	T arr2[SIZE]; // ���ø� ��üȭ ����(������ Ÿ��)�� ���� ���� ������ �����ϴ�.
};

int maun() {
	MyArray<int, 15> arr1;
	MyArray<float, 20> arr2;
	
	// array stl �� ���°� ����.
	array<int, 10>stl_arr;

	return 0;
}