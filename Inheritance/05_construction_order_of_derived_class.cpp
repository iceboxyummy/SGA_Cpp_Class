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

	// ��ӹ��� ��� Ŭ������ ������ �켱 ȣ��
	Child test;

	cout << "#################" << endl;
	D d;

	return 0;
}