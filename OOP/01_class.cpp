 // 01_class.cpp

/*
	PP : peocedual programming - 프로시저(함수) - 함수 단위로 실행
	OOP : object oriented programming - 객체지향(c++) - 객체 단위로 실행
*/

/*
	객체(object) => class + instance

	 @ class : 무엇을 만들지에 대한 설계도 혹은 상상 ex) dna, 붕어빵틀, 자동차 설계도, ...
	  - 사물의 공통된 특성과 동작을 각각 멤버 변수(data)와 멤버 함수(method)로 만들어 표현(추상화)

	 @ instance : class를 통해 만들어진 실체
	  - class는 하나지만 하나의 class를 통해 다양한 instance가 존재한다.
	  ex) 붕어빵틀 하나에서 팥, 슈크림등 다양한 붕어빵을 만들 수 있다.
*/

/*
	객체지향 3요소

	1. 캡슐화(Encapulation) : 객체의 속성(맴버변수)와 동작(멤버함수)를 클래스로 묶는것
	 - 접근 지정자를 통해 외부에 필요한 내용만 공개하고 나머지는 숨긴다.
	   => 정보은닉(information hiding)
	 - 필요한 정보만 공개해 사용하기 쉽게 한다. 
	   ex) 리모컨은 버튼만 조작하면 내부 회로를 몰라도 사용가능

	2. 상속(Inheritance) : 상위 클래스의 속성과 기능을 물려받는 하위 클래스를 만들어 속성과 기능을 확장 가능하다.
	 - 부모 클래스, 자식 클래스라고도 부른다.

	3. 다형성(Polymorphism) : 하나의 객체가 여러가지 형태의 자료형을 자질수 있는 것
							=> 다양한 형태로 객체를 표현가능
	 - 오버라이딩 : 부모 클래스네서 상속받은 매소드를 자식 클래스에서 재정의 하는것
	 - 오버로딩 : 같은 이름을 가진 매소드를 인자값의 형태나 개수를 다르게 하여 다른 기능을 수행하도록 정의하는 것
*/

#include<iostream>
#include<string>

class Person // 설계도
{ // Encapsulation : 캡슐화
	// 접근 지정자(access apecifier) : 접근 범위를 제어한다.
public : // 모두에게 공개한다.
	void Work()
	{

	}

	void Sleep()
	{

	}

protected: // 자신과 자식 클래스 내부에서만 접근가능(friend 사용시 한정적으로 공개가능)

	// Information hiding - 정보은닉
private: // 자신 클래스 내부에서만 접근가능(friend 사용시 한정적으로 공개가능)
	std::string name;
	int age;
	float height;
	float weight;
	bool favorite;

};
int main() {

	Person person; // object, instance
	// person.age; <= 은닉된 정보접근 : error
	person.Sleep(); // 공개된 내용만 접근 가능
}