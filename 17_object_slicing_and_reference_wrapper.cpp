 // 17_object_slicing_and_reference_wrapper.cpp

// Object Slicing ( 객체 슬라이싱 ) : 파생클라스의 인스턴스를 기반클래스의 인스턴스로 복사할때 발생한다.
//  - 파생클래스가 가진 정보가 손실된다.

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

// 2. 실수로 레퍼런스 형태로 받지 않는다면 의도와 다르게 코드가 실행될 수 있다.
void DoSomething(Base b)
{
	b.Print();
}

int main() {
	// 1. 
	Derived1 d;
	Base& ref = d; // reference -> 형태만 부모의 형태로 자식의 데이터를 가진다.
	ref.Print(); // Derived1 출력

	// copy -> Base 메모리가 새로 만들어지고 d에서 가져올수 있는 부분만 복사
	Base base = d; // object slicing
	base.Print(); // Base 출력

	// 3. 단순 Base형태이기 때문에 자식 클래스를 받는다면 문제 발생
	// vector<Base> my_vec;

	// &형태로 백터에 데이터를 넘겨 줄 수 없다 -> 포인터나 reference_wrapper 사용
	// vector<Base&> my_vec;

	Derived1 derived1;
	Derived1 derived2;
	Derived2 derived3;
	Derived2 derived4;

	// * 사용 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();

	// reference_wrapper 사용
	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();

	return 0;
}