 // 13_friend_class.cpp

/*
	friend : 외부에서 클래스의 숨겨진 멤버에 접근할 수 있게 해주는 키워드
	 - 정보에 접근하게 해줄 쪽에서 선언한다. -> 단방향
	 - friend는 상속이 되지 않는다.
*/

#include <iostream>
using namespace std; 

// #define FRIEND_GLOBAL_FUNTION
// #define FRIEND_MEMBER_CLASS
#define FRIEND_CLASS

#ifdef FRIEND_GLOBAL_FUNTION
 // 전역 함수에서 접근하는 경우

class A
{
private:
	int value = 1;

private:
	// 1.
	// friend 키워드를 사용하면 전역 함수에서 숨겨진 멤버에 접근가능
	friend void do_something1(const A& a);

	// 2.
	// 함수의 정의부를 바로 작성가능 (밖에 정의하는 것과 차이점이 없다.)
	// 내부에 정의해도 전역함수 취급
	friend void do_something2(const A& a)
	{
		// friend 키워드를 사용해 숨겨진 멤버에 접근가능
		cout << a.value << endl;
	}

};

 // 1.
void do_something1(const A& a)
{
	// friend 키워드를 사용해 숨겨진 멤버에 접근가능
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
// 타입이 다른 클래스의 특정 멤버 에서 접근이 가능하게 하는경우

class B;
/* 
	전방 선언 : 뒤에 작성한 코드를 앞의 코드에 인지시키고 싶을때 사용한다.
	 - 전방선언을 해주어야 class A에서 class B의 존재를 인식할 수 있다.
*/

// B b;  error
/* 
	전방 선었을 하면 B의 존재는 알지만 구체적인 정보는 알 수없다.
	 -> B크기 만큼의 메모리를 잡을수도 없고 만들어 줄 수도 없다.
*/

B* b; // 포인터는 가능
class B* b2; // 전방선언과 동시에 사용가능

class A
{
public:
	void attack(B& b);

	/*
		전방선언으로 class B의 존재만 알 뿐 구현부는 알 수없다.-> error
		선언부와 구현부를 분리하여 해결한다.

		{
			cout << "b의 체력 : " << b.hp << endl;
			cout << "공격!!" << endl;
			b.hp -= 10;

			cout << "b의 체력 : " << b.hp << endl;
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
	cout << "b의 체력 : " << b.hp << endl;
	cout << "공격!!" << endl;
	b.hp -= 10;

	cout << "b의 체력 : " << b.hp << endl;
}

#endif  

#ifdef FRIEND_CLASS
 // 타입이 다른 클래스의 모든 영역에서 접근이 가능하게 하는경우

class A 
{
public:
	void Print_B_Value1(class B& b);
	void Print_B_Value2(class B& b);
};

class B
{
	// class A의 모든 멤버에서 접근가능 : B에서 A로의 접근은 불가능(단방향)
	friend class A;

private:
	int value1 = 10;
	int value2 = 20;
};

int main() {
	
	return 0;
}

#endif  