 // 14_virtual_destrutor.cpp

#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
	Derived()
	{
		arr = new int[100];
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] arr; // ���� �Ҵ� ���� ����� Ư���� ��찡 �ƴ϶�� �Ҹ��ڿ��� �������ִ°� �����ϴ�.
	}

private:
	int* arr = nullptr;
};

int main() {
	{
		Derived d; // �ڽ��� �Ҹ��� ���� ȣ��
	}

	cout << "###################" << endl;

	// ���� Ŭ������ �� ĳ�����ϰ� �Ǹ� ���� Ŭ������ �Ҹ��ڰ� ���еǾ� �Ҹ��ڰ� ȣ���� �ȵǴ� ������ �߻��Ѵ�.
	// ���⼭ ���� Ŭ�������� �Ҵ� ���� ����� �ִٸ� ������ �����ʾ� �޳븮 ������ �߻��Ѵ�.
	// ����, virtualŰ���带 �ٿ� ���� �Ҹ��ڷ� ����� �־���Ѵ�.
	{
		// �θ� Ŭ������ �Ҹ��ڸ� �������� �������� ������ �ڽ��� �Ҹ���� ����
		Base* base = new Derived;
		delete base;
	}

	// Ŭ������ ������� �����Ŷ�� finalŰ���带 �ٿ����� Ŭ������ ����� �����̶�� ������ �Ҹ��ڿ� virtual Ű���带 �ٿ�����
	// -> �Ҹ��ڰ� �ʿ���� ��� �޸𸮸� �� ���� �� �� ������ ���� ������ �����ϴ°� ����.

	return 0;
}