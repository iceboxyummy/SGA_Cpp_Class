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

template<class T> // 모든 포인터타입에 대해 특수화를 하기 위해 명시한다.
class A<T*> // 포인터에 대한 특수화
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