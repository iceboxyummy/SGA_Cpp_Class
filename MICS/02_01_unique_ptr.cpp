/*
	unique_ptr
	 - 특정 개체를 하나의 스마트 포인터만 소유권을 가지게 하는 스마트 포인터
	 - auto_ptr의 문제점을 개선한 포인터
	 - unique_ptr이 소멸할 때 자신이 소유한 dull 포인터를 해제한다.
		ㅁ dull pointer : 스마트 포인터가 소유한 원시 포인터
*/

#include<iostream>
#include<memory>
#include"02_02_resource.h"

using namespace std;

int main()
{
	// 1.
	{
		// 복사 생성자 사용이 불가능, 이동 생성자만 가능
		std::unique_ptr<Resource> res1(new Resource(5)); // 이동 생성자 호출
		//std::unique_ptr<Resource> res2 = new Resource(5)); // 복사 생성자 호출

		// 위의 코드에서 생길 수 있는 문제점
		/*
			생성시점이 맞지 않을 수 있다. -> 예상하지 못한 에러가 발생할 확률이 있다.
			스마트 포인터 자체는 빠르게 생성되지만 동적 할당된 데이터를 만들때는 느리다.
			해당 문제를 해결하기 위해 내부적으로 스마트포인터를 만들어주는 make_xxxx 함수들이 있다.
		*/

		// make_ : 안전하게 객체를 할당해주는 함수, 내부적으로 받은 템플릿 타입을 동적 할당해준다.
		// 매개변수로는 템플릿 타입을 생성자를 호출할때 넘겨줄 인자를 넣어준다.
		auto res2 = std::make_unique<Resource>(10);

		res2->SetAll(5);
		res2->Print();

		//res2 = res1; //error : 복사x
		res2 = std::move(res1); // r-value 형태로 변환해야한다.

		// res2 로 넘기는 순간 res1이 가지고 있던 메모리에 대한 소유권이 해제(nullptr로 바뀜)되기 때문에
		// 그 후에 접근을 시도하면 에러가 발생
		res1->Print(); //error
	}

	return 0;
}