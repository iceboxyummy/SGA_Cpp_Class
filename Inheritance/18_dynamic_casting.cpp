// 18_dynamic_casting.cpp

#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Print() { cout << "Base" << endl; }

public:
	int i = 0;
};

class Derived1 : public Base 
{
	/*
		Base::i;
		Derived1::j;

		i i i i j j j j
	*/

public:
	virtual void Print() { cout << "Derived1" << endl; }

public:
	int j = 1;
};

class Derived2 : public Base 
{
	/*
		Base::i;
		Derived1::k;

		i i i i k k k k
	*/

public:
	virtual void Print() { cout << "Derived2" << endl; }

public:
	int k = 2;
};

void DoSomething(Base* b)
{
	/* 
		static_cast : 자료형이 논리적으로 변경가능한 경우 캐스팅을 수행한다.
		 - 단순 자료형을 가지고 판단하므로 실제 데이터의 실체를 검사하지않아 
		   의도치않은 형변환이 일어날 수 있어 안전성이 떨어진다.
	
		Derived2* base_to_d2 = static_cast<Derived2*>(b);
		base_to_d2->k = 888;

		의도하지 않은 형변환이 발생해 Derived1의 j가 수정이 된다.
		우연히도 상대적인 위치가 동일해 발생하는 문제
	*/

	Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);
	/*
		dynamic_cast : 실제 데이터의 상속관계를 파악하여 가능하다면 형변환을 수행하고 아니라면 nullptr를 반환해준다.
		 - 캐스팅을 할때 마다 검사해야하기 떄문에 속도면에서 느리다.
			-> 타입 확인이 가능한 id를 클래스에 부여하여 static_cast를 사용하는게 좋다.
	*/

	if (base_to_d2 == nullptr)
	{
		cout << "error" << endl;
		return;
	}
	base_to_d2->k = 888;
}

int main() {

	// 업 캐스팅
	Derived1 d1;
	Base* base = &d1;

	// 다운캐스팅은 명시적 형변환을 해주어야 가능
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();

	DoSomething(&d1);
	cout << d1.j << endl;

	return 0;
}