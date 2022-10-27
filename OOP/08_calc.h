#pragma once

// 헤더에 포함할 경우 헤더를 포함하는 모든 파일에 추가되기 때문에 문제가 발생할 여지가 생김
// -> .cpp 파일로 넘겨주어 처리
 
// #include <iostream> : 필요없는 헤더가 컴파일되며 컴파일 시간 증가
// using namespace std; : 중복 문제

void Test(int a);

class Calc
{
public:
	Calc(int value) : value(value) {}
	// 헤더에 구현부 까지 작성후 .cpp로 넘겨주게되면 inlne을 자동적으로 포함
	// -> 헤더에 작성한 클래스안에 멤버함수들을 구현부까지 적어 놓으면 자동으로 inline이 자동으로 포함되기 때문
	// -> 따라서 코드가 짧고 자주 호출되는 함수는 헤더에 적어놓는 것도 최적화 방법중 하나이다.

	void Add(int value);
	void Sub(int value);
	void Mul(int value);
	void Div(int value);
	void Mod(int value);

	void Print();
	
	void Test(); // 구현부를 작성하지 않고 넘기면 inline이 붙지 않는걸 확인가능

private:
	int value;
};