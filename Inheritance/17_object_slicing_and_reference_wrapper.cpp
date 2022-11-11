 // 17_object_slicing_and_reference_wrapper.cpp

// Object Slicing ( ��ü �����̽� ) : �Ļ�Ŭ���� �ν��Ͻ��� ���Ŭ������ �ν��Ͻ��� �����Ҷ� �߻��Ѵ�.
//  - �Ļ�Ŭ������ ���� ������ �սǵȴ�.

#include <iostream>
#include <vector>
#include <functional> // reference_wrapper

using namespace std;

class Base 
{
public:
	virtual void Print() { cout << "Base" << endl; }

public:
	int i = 0;
};

class Derived1 : public Base {
public:
	virtual void Print() { cout << "Derived1" << endl; }

public:
	int j = 1;
};

class Derived2 : public Base {
public:
	virtual void Print() { cout << "Derived2" << endl; }

public:
	int j = 1;
};

// 2. �Ǽ��� ���۷��� ���·� ���� �ʴ´ٸ� �ǵ��� �ٸ��� �ڵ尡 ����� �� �ִ�.
void DoSomething(Base b)
{
	b.Print();
}

int main() {
	// 1. 
	Derived1 d;
	Base& ref = d; // reference -> ���¸� �θ��� ���·� �ڽ��� �����͸� ������.
	ref.Print(); // Derived1 ���

	// copy -> Base �޸𸮰� ���� ��������� d���� �����ü� �ִ� �κи� ����
	Base base = d; // object slicing
	base.Print(); // Base ���

	// 3. �ܼ� Base�����̱� ������ �ڽ� Ŭ������ �޴´ٸ� ���� �߻�
	// vector<Base> my_vec;

	// &���·� ���Ϳ� �����͸� �Ѱ� �� �� ���� -> �����ͳ� reference_wrapper ���
	// vector<Base&> my_vec;

	Derived1 derived1;
	Derived1 derived2;
	Derived2 derived3;
	Derived2 derived4;

	// * ��� 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();

	// reference_wrapper ���
	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();

	return 0;
}