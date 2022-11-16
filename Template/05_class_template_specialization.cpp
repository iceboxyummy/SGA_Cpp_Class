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
	// 템플릿 클래스는 특수화할 경우 멤버를 모두 다르게 가지고 있다.
	// a_char.Test(); : char형으로 특수화한 class A에는 Test() 멤버 함수가 없다.

	return 0; 
}
