 // 11_static_member_function.cpp

/*
	static member function : Ŭ������ ��ü�� �������� �ʰ� Ŭ���� �̸������� ȣ���� ������ �Լ�
	 - ��ü�� �����Ƿ� this ������ ����� �ȵǰ� ���� ��� ������ ��밡��
     - const �Լ��� ���� �� �ִ�.
*/

#include<iostream>
#include<functional>
using namespace std;

class Test
{
public:
	void Temp1() { this->value1; } // __thiscall

	//__thiscall ����� �ƴϱ� ������ this ������ ���x
	// Ŭ���� ī�װ��� ���Ե� ���� �Լ��� �����ϴ�.
	// static void Temp2() { this->value1; } this x
	// static void Temp2() const { } const x
	static void Temp2() { value2; }
	
private:
	int value1;
	static int value2;

public:
	int test;
};

int main() {
	// Test::Temp1();  error: __thiscall ����� �Լ��� this �����Ϳ� �� �ν��Ͻ��� �ʿ��ϴ�.

	Test t1;
	t1.Temp1();

	t1.Temp2();
	Test::Temp2();

	// �Ϲ� �Լ� ����̿��� ����
	void(*ptr1)() = Test::Temp2;

	// __thiscall�̶� �����ڸ� �� �� ���� �Ϲ� �Լ� ������ x
	// void(*ptr2)() = Test::Temp1;

	/*
		��� ������ : Ư�� Ŭ������ ���� ����� ����Ű�� ������
		 - ��� �����͸� ����� ��� �Լ��� ���� �� �ִ�.
         - Ư�� �ν��Ͻ�ȭ�� ����� ��ġ�� �ƴ� ����� Ŭ������ �����ϴ� 
		   ������� ��ġ�� ������ ������ ����ϱ� ���ؼ� �ν��Ͻ��� �ʿ��ϴ�.
         - �ּҿ� ������ �� (.*) �����ڸ� ����Ѵ�. 
         - �⺻ ������ ���Ŀ��� ���� �����̽��� �߰��Ͽ� ��밡���ϴ�.
	*/

	// int a;
	// int b;
	// a a a a b b b b
	
	// ��� ���� ������
	int Test::* ptr3 = &Test::test;
	t1.*ptr3 = 10; // ��ü�� �־� ���

	// ��� �Լ� ������
	void(Test:: * ptr4)() = Test::Temp1;
	(t1.*ptr4)(); // ��ü�� �־� ����Ѵ�.

	std::function<void(Test)> fp = Test::Temp1;
	fp(t1);

	std::function<void()> fp = Test::Temp2;
	return 0;
}