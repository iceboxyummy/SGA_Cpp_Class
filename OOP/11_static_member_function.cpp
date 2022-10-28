 // 11_static_member_function.cpp

/*
	static member function : 클래스의 객체를 생성하지 않고도 클래스 이름만으로 호출이 가능한 함수
	 - 객체가 없으므로 this 포인터 사용이 안되고 정적 멤버 변수만 사용가능
     - const 함수로 만들 수 있다.
*/

#include<iostream>
#include<functional>
using namespace std;

class Test
{
public:
	void Temp1() { this->value1; } // __thiscall

	//__thiscall 방식이 아니기 때문에 this 포인터 사용x
	// 클래스 카테고리에 포함된 전역 함수와 동일하다.
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
	// Test::Temp1();  error: __thiscall 방식의 함수는 this 포인터에 들어갈 인스턴스가 필요하다.

	Test t1;
	t1.Temp1();

	t1.Temp2();
	Test::Temp2();

	// 일반 함수 취급이여서 가능
	void(*ptr1)() = Test::Temp2;

	// __thiscall이라 소유자를 알 수 없어 일반 함수 포인터 x
	// void(*ptr2)() = Test::Temp1;

	/*
		멤버 포인터 : 특정 클래스에 속한 멤버를 가리키는 포인터
		 - 멤버 포인터를 사용해 멤버 함수를 넣을 수 있다.
         - 특정 인스턴스화된 멤버의 위치가 아닌 멤버가 클래스에 존재하는 
		   상대적인 위치를 가지기 때문에 사용하기 위해선 인스턴스가 필요하다.
         - 주소에 접근할 때 (.*) 연산자를 사용한다. 
         - 기본 포인터 형식에서 네임 스페이스를 추가하여 사용가능하다.
	*/

	// int a;
	// int b;
	// a a a a b b b b
	
	// 멤버 변수 포인터
	int Test::* ptr3 = &Test::test;
	t1.*ptr3 = 10; // 객체를 넣어 사용

	// 멤버 함수 포인터
	void(Test:: * ptr4)() = Test::Temp1;
	(t1.*ptr4)(); // 객체를 넣어 사용한다.

	std::function<void(Test)> fp = Test::Temp1;
	fp(t1);

	std::function<void()> fp = Test::Temp2;
	return 0;
}