 // 11_structures.cpp

#include<iostream>

struct person
{
	/*
		멤버 함수는 메모리 코드 영역에 할당되어 구조체 변수에 포함되지 않는다.
		 -> 여러 객체가 하나의 함수를 공유하여 사용한다.
		 그렇기 떄문에 멤버 함수 내부에서 함수를 호출한 객체의 정보를 알아야 하는데
		 __thiscall 방식을 사용해서 내부적으로 
		 해당 함수를 호출한 객체의 포인터를 넘겨 받아 구분한다.
	*/

	// C와 다르게 함수를 넣어줄 수 있다.
	void /*__thiscall*/ Print(/* person* this */)
	{
		this->age;
		std::cout << age << std::endl;
	}

	// C와 다르게 기본값 예약이 가능
	int age;
	float weight = 50.f;
	std::string name = "DiDi";
};

int main() {
	person p1{ 10, 50.0f, "DiDi" };
	person p2;

	p1.Print(/*&p1*/);
	p2.Print();

	return 0;
}