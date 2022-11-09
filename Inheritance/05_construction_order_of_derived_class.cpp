 // 05_construction_order_of_derived_class.cpp

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
		:a(10)
	{
		cout << "Base constructor" << endl;
	}

private:
	int a;
};

class Child : public Parent
{
public:
	Child()
		:b(10)
	{
		cout << "Derived constructor" << endl;
	}

private:
	int b;
};

class A { public: A() { cout << "A constructor" << endl; } };
class B :public A { public: B() { cout << "B constructor" << endl; } };
class C :public B { public: C() { cout << "C constructor" << endl; } };
class D :public C { public: D() { cout << "D constructor" << endl; } };

int main() {

	// 상속받은 기반 클래스의 생성자 우선 호출
	Child test;

	cout << "#################" << endl;
	D d;

	return 0;
}