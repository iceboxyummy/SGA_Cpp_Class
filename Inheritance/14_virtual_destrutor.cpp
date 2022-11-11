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
		delete[] arr; // 동적 할당 받은 멤버는 특수한 경우가 아니라면 소멸자에서 해제해주는게 안전하다.
	}

private:
	int* arr = nullptr;
};

int main() { 
	{
		Derived d; // 자신의 소멸자 정상 호출
	}

	cout << "###################" << endl;

	// 상위 클래스로 업 캐스팅하게 되면 하위 클래스의 소멸자가 은닉되어 소멸자가 호출이 안되는 문제가 발생한다.
	// 여기서 하위 클래스에서 할당 받은 멤버가 있다면 해제가 되지않아 메노리 누수가 발생한다.
	// 따라서, virtual키워드를 붙여 가상 소멸자로 만들어 주어야한다.
	{
		// 부모 클래스의 소멸자를 가상으로 정의하지 않을시 자신의 소며멸자 생략
		Base* base = new Derived;
		delete base;
	}

	// 클래스를 상속하지 않을거라면 final키워드를 붙여주자 클래스를 상속할 생각이라면 무조건 소명자에 virtual 키워드를 붙여주자
	// -> 소멸자가 필요없을 경우 메모리를 더 차지 할 수 있지만 누수 현상을 방지하는게 좋다.

	return 0;
}
