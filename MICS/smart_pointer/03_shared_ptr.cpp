// 03_shared_ptr.cpp

/*
	shared_ptr
		- 유니크 포인터와 달리 공유가 가능한 포인터
		- 포인터를 함수에 전달해야 할 때, 유니크 포인터 대신 사용하기 적합하다.
		- 참조 카운팅 방식을 사용한다.
			ㄴ해장 dull 포인터를 소유하고 있는 스마트 포인터의 개수는 카운팅하여 
			  마지막 스마트 포인터가 소멸할 때 해제하는 방식
*/

#include<iostream>
#include<memory>
#include"02_02_resource.h"
using namespace std;

int main()
{
	{
		// dull 포인터를 받아 res1을 기준으로 카운트 0 -> 1증가
		auto res1 = std::make_shared<Resource>(5);

		res1->SetAll(2);
		res1->Print();

		// use_count() : 현재 자신이 소유한 날 포인터를 소유하고 있는 스마트 포인터 개수
		cout << "Count : " << res1.use_count() << endl;
		{
			// res1이 소유한 주소를 공유받는다. 카운트 1 -> 2 증가
			auto res2(res1);

			cout << "Count res1 : " << res1.use_count() << endl;
			cout << "Count res2: " << res2.use_count() << endl;
		} // res2 소멸, 카운트 감소 2 -> 1, 아직 날 포인터를 소유한 포인터가 있어 해제 x 
		cout << "Count : " << res1.use_count() << endl;
	} // res1 소멸, 카운트 감소 1 -> 0, 날 포인터를 소유한 마지막 스마트 포인터가 소명하여 dull포인터 해제

	// 날 포인터를 같이 사용하면 발생하는 문제

	Resource* ptr = new Resource(10);
	{
		// 카운트 증가 0 -> 1
		std::shared_ptr<Resource> res1(ptr);

		res1->SetAll(2);
		res1->Print();
	
		cout << "Count : " << res1.use_count() << endl;
		{
			// res2 카운트 증가 0 -> 1
			std::shared_ptr<Resource> res2(ptr);

			cout << "Count res1 : " << res1.use_count() << endl;
			cout << "Count res2: " << res2.use_count() << endl;
		} // res2 카운트 감소, 1 -> 0 마지막 스마트 포인터가 소멸하여 메모리 해제
		cout << "Count : " << res1.use_count() << endl;
	} // res1 카운트 감소, 1 -> 0 마지막 스마트 포인터가 소멸하여 메모리해제
		// 허상포인터 문제 발생
	return 0;
}