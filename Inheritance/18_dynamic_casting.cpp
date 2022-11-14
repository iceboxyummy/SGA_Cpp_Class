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
		static_cast : �ڷ����� �������� ���氡���� ��� ĳ������ �����Ѵ�.
		 - �ܼ� �ڷ����� ������ �Ǵ��ϹǷ� ���� �������� ��ü�� �˻������ʾ� 
		   �ǵ�ġ���� ����ȯ�� �Ͼ �� �־� �������� ��������.
	
		Derived2* base_to_d2 = static_cast<Derived2*>(b);
		base_to_d2->k = 888;

		�ǵ����� ���� ����ȯ�� �߻��� Derived1�� j�� ������ �ȴ�.
		�쿬���� ������� ��ġ�� ������ �߻��ϴ� ����
	*/

	Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);
	/*
		dynamic_cast : ���� �������� ��Ӱ��踦 �ľ��Ͽ� �����ϴٸ� ����ȯ�� �����ϰ� �ƴ϶�� nullptr�� ��ȯ���ش�.
		 - ĳ������ �Ҷ� ���� �˻��ؾ��ϱ� ������ �ӵ��鿡�� ������.
			-> Ÿ�� Ȯ���� ������ id�� Ŭ������ �ο��Ͽ� static_cast�� ����ϴ°� ����.
	*/

	if (base_to_d2 == nullptr)
	{
		cout << "error" << endl;
		return;
	}
	base_to_d2->k = 888;
}

int main() {

	// �� ĳ����
	Derived1 d1;
	Base* base = &d1;

	// �ٿ�ĳ������ ����� ����ȯ�� ���־�� ����
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();

	DoSomething(&d1);
	cout << d1.j << endl;

	return 0;
}