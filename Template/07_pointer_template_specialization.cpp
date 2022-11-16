 // 07_pointer_template_specialization.cpp

#include<iostream>
using namespace std;

template<class T>
class A 
{
public:
	A(const T& value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}
private:
	T value;
};

template<class T> // ��� ������Ÿ�Կ� ���� Ư��ȭ�� �ϱ� ���� ����Ѵ�.
class A<T*> // �����Ϳ� ���� Ư��ȭ
{
public:
	A(const T* value)
		:value(value)
	{}

	void Print()
	{
		cout << *value << endl;
	}

private:
	T* value;
};

int main() {
	A<int> a_int(123);
	a_int.Print();

	int temp = 456;
	A<int*> a_int_ptr(&temp);
	a_int_ptr.Print();

	return 0;
}