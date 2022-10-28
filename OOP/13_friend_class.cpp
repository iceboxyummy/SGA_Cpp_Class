 // 13_friend_class.cpp

/*
	friend : 외부에서 클래스의 숨겨진 멤버에 접근할 수 있게 해주는 키워드
	 - 정보에 접근하게 해줄 쪽에서 선언한다. -> 단방향
	 - friend는 상속이 되지 않는다.
*/

#include <iostream>
using namespace std;
#define FRIEND_GLOBAL_FUNTION

#ifdef FRIEND_GLOBAL_FUNTION
/*
	전역 함수에서 접근하는 경우
*/

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

#ifdef FRIEND_CLASS

#endif  