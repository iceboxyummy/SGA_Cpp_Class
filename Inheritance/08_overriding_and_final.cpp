 // 08_overriding_and_final.cpp

/*
	Overriding : 파생클래스가 상속받은 기반 클래스의 메서드를 파생 클래스에서 새로 정의하는 것
	 - 리턴 타입과 인자 구성이 서로 같아야 한다.
	 - 오버라이딩된 기반 클래스의 함수는 가려지고 패생클래스의 함수가 호출이 된다.
	  + 기반 클래스의 함수를 범위지정 연산자로 호출은 가능하다.
	  + 기반 클래스에서 오버라이딩 된 함수의오버로딩된 함수도 가려진다.
	 - 단순히 함수를 오버라이딩을 할 경우, 업 캐스팅시 파생 클래스의 함수가 아닌 기반 클래스의 함수가 호출된다.
	   그 이유는, C++ 컴파일러가 실제로 가리키는 자료형을 기준으로 하는게 아니라 포인터 변수의 자료형을 기준으로 하기 때문이다.
	   virtual키워드를 사용하여 해결이 가능하다.

	  + virtual
	   - 자신을 호출하는 객체의 실제 타입에 따라 호출할 함수를 결정하게 해준다.
	   - 기반 함수에만 키워드를 추가해도 된다. -> 파생클래스에서는 생략이 가능 
*/

#include<iostream>
using namespace std;

// class A final  // final : 클래스 상속을 제한하는 키워드
				  // 메서드에 붙이면 해당 메서드 오버라이딩을 제한한다.
class A
{
public:
	// 가상함수
	virtual void Print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:

	// 반환형과 매개변수가 같아야한다. => 매개변수가 다를 경우 오버로딩이다.
	// void Print(short x) { cout << "B" << endl; }

	// 오버라이딩은 상속받은 메서드를 가상 함수 테이블을 통해 하나만 골라 쓰는 것
	void Print(int x) override { cout << "B" << endl; }

	/*
		override : 오버라이딩이 가능한 함수인지 판단해준다.-> 불가능하다면 error
		 - 파생 클래스에서 재정의한 함수에 붙인다.
		 - 오버라이딩 함수를 명시적으로 표시한다. -> 코드 가독성이 좋아진다.
	*/

	// 메서드에 final키워드를 추가할 경우 자식 클래스에서 오버라이딩이 제한된다.
	// void Print(int x) override final { cout << "B" << endl; }
};

class C :public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main() {
	A a;
	B b;
	C c;

	a.Print(0);
	b.Print(0);
	c.Print(0);

	cout << "##################" << endl;

	A& ab = b;
	A& ac = c;

	a.Print(0);
	ab.Print(0);
	ac.Print(0);

	return 0;
}