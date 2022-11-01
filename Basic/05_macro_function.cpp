// 05_macro_function.cpp

#include<iostream>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
// 가독성이 좋지않다.
// 무슨 타입이 들어오는지 알 수 없다.
// 디버깅이 안된다.

/*
	inline
	- 매크로와 같이 컴파일된 함수 코드가 프로그램의 코드안에 직접 삽입된다.
	- 함수 호출에 의한 성능저하가 없어 일반적인 함수보다 속도면에서 유리하다.
	- 여러번 호출되거나 덩치가 큰 함수에 사용할 경우 프로그램의 크기가 커질 수 있다.
	- 빈번하게 호출이 있는 짧은 함수를 사용할 때 유리하다. 그렇지 않은 함수에
	사용한 경우에는 성능 향상이 미비하다.
	- 긴 함수를 인라인화 하려는 경우 컴파일러가 무시할 가능성이 있다.
	- 최신 컴파일러는 함수를 인라인화 하여 코드를 사용할 필요는 없음.
*/

inline int Max(int a, int b)
{
	return (a > b) ? a : b;
}

/*
	inline과 macro의 차이
	- 매크로는 오류방지를 위해 모든 인자를 괄호로 묶어 가독성이 좋지 않다.
	인라인은 일반적인 함수와 형식이 비슷해 괄호로 묶을 필요가 없다.

	- 매크로는 인수타입을 명시하지 않는다.
	인라인은 인수의 타입을 명시해야 한다.

	- 매크로는 단순 텍스트 치환이기에 복잡한 함수의 기능 구현이 어렵다.
	인라인은 일반적인 함수와 형식이 비슷해 함수의 모든 기능을 구현할 수 있다.

	- 매크로는 단순치환이라 디버깅x
	인라인은 디버깅o
*/

int main()
{
	using namespace std;
	cout << MAX(1, 2) << endl;
	cout << Max(1, 2) << endl;

	return 0;
}