 // 06_destruction_order_of_derived_class.cpp

#include<iostream>
using namespace std;

class A
{
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }

private:
	int a;
};

class B : public A
{
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }

private:
	double b;
};

int main() {
	// �����ڴ� �⺻ Ŭ���� ���� �Ҹ��ڴ� �Ļ� Ŭ���� ����
	// ���� ������ ��ü�� �� ���� ���踦 �ΰ� ���� ���ɼ��� �־� ������ �������� �����ϴ°� �����ϴ�.

	B b;

	/*
		 �е� : Ŭ������ ����ü�� �е�����Ʈ�� �߰��Ͽ� CPU�� �����ϱ� �����ϰ� ���ִ� ���
		  - CPU�� �����͸� ���� �� �ڷ����� �߷� �����Ϳ� �� �� �����ϴ� ���� �����Ѵ�.
		  - �Ϲ������� ���� ū ��� ���� �� ����� ���� ū ������ ũ�⿡ ���߾� �е��� �Ѵ�.
		  
		  �� -> �е�����Ʈ

		  a a a a �� �� �� �� b b b b b b b b
	*/
	sizeof(B);

	class P1
	{
		char c;
		short s1;
		short s2;
	};

	// c �� s1 s1 s2 s2
	sizeof(P1);

	class P2
	{
		char c;
		short s;
		int i;
		double d;
	};

	// c s s i i i i �� d d d d d d d d
	sizeof(P2);

	return 0;
}