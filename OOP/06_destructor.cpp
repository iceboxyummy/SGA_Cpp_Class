 // 06_destructor.cpp

/*
	destructor(�Ҹ���) : �ν��Ͻ��� �Ҹ��Ҷ� ȣ��Ǵ� �Լ�
	 - �Ҹ�� �ʿ��� �۾��� ó���Ѵ�.
	 - �����ε��� �ȵǱ� ������ �ϳ��� ����
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

	// ~ : tilde (not ������ �ǹ�)
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

	~IntArray() // �Ҹ��ڰ� ȣ��Ǹ鼭 �޸𸮸� ����
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