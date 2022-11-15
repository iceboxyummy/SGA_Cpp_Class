 // 05_class_template_specialization.cpp

#include<iostream>
using namespace std;

template<class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() 
	{

	}
};

// class template specialization
template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}
};

int main() {
	A<int>a_int(10);
	A<float>a_float(10.0f);
	A<char>a_char('a');

	a_int.DoSomething();
	a_float.DoSomething();
	a_char.DoSomething();

	a_int.Test();
	a_float.Test();
	// ���ø� Ŭ������ Ư��ȭ�� ��� ����� ��� �ٸ��� ������ �ִ�.
	// a_char.Test(); : char������ Ư��ȭ�� class A���� Test() ��� �Լ��� ����.

	return 0;
}