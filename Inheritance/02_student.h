#pragma once

// 상속받기 위해서는 기반클래스의 전방선언이 아니라 헤더를 추가하여 구체적인 정보를 넘겨주어야 한다.
#include "02_person.h" // 기반 클래스의 헤더추가
// class Person; error -> 전방 선언 만으로는 모든것을 알 수없다.

class Student : public Person
{
public:
	// Student(const std::string& name)
	// 	:name(name) // 상속 받은 멤버는 생성자 멤버 리스트 사용 x
	// 				// 생성과 동시에 초기화 되는 곳인데 이미 존재하는 멤버이기 때문이다.
	// {
	// 	this->name = name; // 생성자 멤버 리스트가 아닌부분에서는 가능하다.
	// }

	Student(const std::string& name)
		// : Person() // 기반 클래스가 생성되고 파생 클래스가 생성이 된다.
					  // 그렇기 때문에 기반 클래스의 생성자를 명시적으로 호출하지 않은경우 내부적으로 기본 생성자를 호출한다.

		 : Person(name) // 기반 클래스의 생성자를 명시적으로 호출하여 원하는 기반 생성자 호출
	{

	}

	void Study(){} // Person을 상속받아 기능 확장

private:
};