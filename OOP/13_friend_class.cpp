 // 13_friend_class.cpp

/*
	friend : �ܺο��� Ŭ������ ������ ����� ������ �� �ְ� ���ִ� Ű����
	 - ������ �����ϰ� ���� �ʿ��� �����Ѵ�. -> �ܹ���
	 - friend�� ����� ���� �ʴ´�.
*/

#include <iostream>
using namespace std; 

// #define FRIEND_GLOBAL_FUNTION
// #define FRIEND_MEMBER_CLASS
#define FRIEND_CLASS

#ifdef FRIEND_GLOBAL_FUNTION
 // ���� �Լ����� �����ϴ� ���

class A
{
private:
	int value = 1;

private:
	// 1.
	// friend Ű���带 ����ϸ� ���� �Լ����� ������ ����� ���ٰ���
	friend void do_something1(const A& a);

	// 2.
	// �Լ��� ���Ǻθ� �ٷ� �ۼ����� (�ۿ� �����ϴ� �Ͱ� �������� ����.)
	// ���ο� �����ص� �����Լ� ���
	friend void do_something2(const A& a)
	{
		// friend Ű���带 ����� ������ ����� ���ٰ���
		cout << a.value << endl;
	}

};

 // 1.
void do_something1(const A& a)
{
	// friend Ű���带 ����� ������ ����� ���ٰ���
	cout << a.value << endl;
}

int main()
{
	A a;
	do_something1(a);

	return 0;
}

#endif

#ifdef FRIEND_MEMBER_CLASS
// Ÿ���� �ٸ� Ŭ������ Ư�� ��� ���� ������ �����ϰ� �ϴ°��

class B;
/* 
	���� ���� : �ڿ� �ۼ��� �ڵ带 ���� �ڵ忡 ������Ű�� ������ ����Ѵ�.
	 - ���漱���� ���־�� class A���� class B�� ���縦 �ν��� �� �ִ�.
*/

// B b;  error
/* 
	���� ������ �ϸ� B�� ����� ������ ��ü���� ������ �� ������.
	 -> Bũ�� ��ŭ�� �޸𸮸� �������� ���� ����� �� ���� ����.
*/

B* b; // �����ʹ� ����
class B* b2; // ���漱��� ���ÿ� ��밡��

class A
{
public:
	void attack(B& b);

	/*
		���漱������ class B�� ���縸 �� �� �����δ� �� ������.-> error
		����ο� �����θ� �и��Ͽ� �ذ��Ѵ�.

		{
			cout << "b�� ü�� : " << b.hp << endl;
			cout << "����!!" << endl;
			b.hp -= 10;

			cout << "b�� ü�� : " << b.hp << endl;
		}
	*/
};

class B
{
	friend void A::attack(B& b);

private:
	int hp;
};

int main() {

	return 0;
}

void A::attack(B& b)
{
	cout << "b�� ü�� : " << b.hp << endl;
	cout << "����!!" << endl;
	b.hp -= 10;

	cout << "b�� ü�� : " << b.hp << endl;
}

#endif  

#ifdef FRIEND_CLASS
 // Ÿ���� �ٸ� Ŭ������ ��� �������� ������ �����ϰ� �ϴ°��

class A 
{
public:
	void Print_B_Value1(class B& b);
	void Print_B_Value2(class B& b);
};

class B
{
	// class A�� ��� ������� ���ٰ��� : B���� A���� ������ �Ұ���(�ܹ���)
	friend class A;

private:
	int value1 = 10;
	int value2 = 20;
};

int main() {
	
	return 0;
}

#endif  