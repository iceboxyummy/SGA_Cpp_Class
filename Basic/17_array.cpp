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
		�ս��� ��밡�� �ϵ��� ���� ���̺귯��
	*/

	std::array<int, 5> arr4; // int�� 5���� �޸� ����
	std::array<int, 5> arr5{ 1,2,3,4,5 }; // �ʱ�ȭ�� ����

	cout << arr5[0] << endl;
	cout << arr5[1] << endl;
	cout << arr5.at(0) << endl;
	cout << arr5.at(1) << endl;
	cout << arr5.size() << endl;

	return 0;
}