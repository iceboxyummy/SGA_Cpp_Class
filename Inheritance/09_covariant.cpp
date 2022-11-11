 // 09_covariant.cpp

/*
	covariant ( 공변반환형 ) : 자신의 참조를 반환하는 경우 상속관계에서 같은 형태의 함수로 인정되는 것
	 - is-a 관계이기 때문에 자신의 참조를 리턴할 때 같은것으로 인식
	 - 반환값이 달라도 가능한 오버라이딩 방법
*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
};

class B : public A
{
public:
	// 공변반환형 : 자신의 참조를 리턴할 경우 상속관계에서 같은 형태로 인식된다.
	// override 키워드를 넣어서 제대로 오버라이딩된 것을 확인 가능
	B* GetThisPointer() override { cout << "B" << endl; return this; }
};

int main() {
	return 0;
} 
