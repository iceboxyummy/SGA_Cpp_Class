 // 06_destructor.cpp

/*
	destructor(소멸자) : 인스턴스가 소멸할때 호출되는 함수
	 - 소멸시 필요한 작업을 처리한다.
	 - 오버로딩이 안되기 때문에 하나만 존재
*/

#include<iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Constructor!!" << endl;
	}

	// ~ : tilde (not 부정의 의미)
	~Test()
	{
		cout << "Destructor!!" << endl;
	}

private:
};

class IntArray
{
public:
	IntArray(const int& in_length)
	{
		length = in_length;
		arr = new int[length];
		cout << "Constructor!!" << endl;
	}

	~IntArray() // 소멸자가 호출되면서 메모리를 해제
	{
		delete[] arr;
		cout << "Destructor!!" << endl;
	}

private:
	int* arr = nullptr;
	int length = 0;
};

int main()
{
	cout << "################# 1" << endl;
	{
	cout << "################# 2" << endl;
		Test test;
	cout << "################# 3" << endl;
	}
	cout << "################# 4" << endl;

	return 0;
}