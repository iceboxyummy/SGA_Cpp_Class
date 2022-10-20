 // 15_reference_variable.cpp

/*
    L-value -> copy, R-value ->mave

	L-value &  : 나중에 다시 접근이 가능한 값
	R-value && : 식이 끝나면 접근이 불가능한 값
*/

#include <iostream>

// 두 레퍼런스로 프로그래머의 의도를 알 수 있다.
int Test1(int& a) // a는 외부에 원본이 있음을 표시하고 복사의 필요성을 표시
{
	return a;
}

int Test2(int&& a) // a는 밖에서 존재하지 않음을 표시 -> 복사할 필요가 없다.
{
	return a;
}


int main()
{
	int val = 5;

	int& r = val; // 자료형 옆에 붙은 & -> L-value Reference;
	 // val == r value와 r은 같다. 편하게 사용하기 위해 별명을 붙인 것
	 // 내부적으로는 포인터, 변수처럼 사용하면된다.

	r = 10;

	std::cout << val << std::endl;

	// int& r2 = 10; // L-value만 넣을 수 있다.
	const int& r2 = 10; // const를 붙이면 가능

	int&& rr = 10; // R-value reference

	return 0;
}