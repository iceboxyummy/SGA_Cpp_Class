// 08_typename_and_nested_depentdent_type_name.cpp

#include<iostream>
using namespace std;

class A
{
public:
	using my_int = int;
};

template<typename T>
class B
{
public:
	/*
		depent name(의존이름) : 위의 typename T 처럼 타입을 인자로 받아 사용할때, T를 의존이름이라고 부른다.

		nested depent name(중첩 의존 타입 이름) : 위의 이름속에 다른 타입이 정의 된 경우 중첩 의존 타입 이름이라고 부른다.
		 - 중첩 의존 타입 이름을 사용할 때에는 typename 키워드를 사용해야한다.
	*/

	// T::my_int i;  T::my_int가 타입인지, 정적 멤버 변수인지 구분 x -> 정적 멤버변수로 인지해 에러가 발생한다.
	 
	typename T::my_int i; // typename 키워드를 사용해 T::my_int가 자료형임을 명시하여 해결가능하다.
};

int main() {
	B<A> test;

	return 0;
}