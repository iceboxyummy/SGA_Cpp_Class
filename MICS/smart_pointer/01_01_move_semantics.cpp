// 01_01_move_semantics.cpp

/*
	스마트 포인터 : 포인터처럼 동작하는 클래스 템플릿
	 - 허상포인터, 메모리 누수를 쉽게 관리하기 위해 등장하였다.
	 - memory헤더에 들어있다.
	 - 종류
	  + auto_ptr
	  + unique_ptr
	  + shared_ptr
	  + weak_ptr
*/

#include<iostream>
#include<memory>

#include"01_02_resource.h"
#include"01_03_auto_ptr.h"

using namespace std;

/*
	RAII : Resourcd Acquisition is initialization
	 - 생성한 지역에서 삭제하는것
	 - RAII의 원칙이 스마트 포인터에 적용되어 있다.
*/

// Early return : 이른 반환

void DoSomething1()
{
	Resource* resource = new Resource;

	// if (true) return; // 메모리누수 발생

	if (true)
	{
		// 해결법 : 리턴하는 부분에 해제를 같이 해준다.
		// 문제 : 실수할 확률이 생김 -> 신경쓰지 않아도 자동으로 관리되었음 좋겠다. -> 스마트 포인터
		delete resource;
		return;
	}

	//...
	//...
	//...

	delete resource;
}

/* fix */
void DoSomething2()
{
	// 해결법 : 소멸자에서 해제
	// 객체가 소멸하면서 소멸자가 호출
	// 소멸자에 동적해제를 해주는 코드가있어 신경써주지 않아도 자동으로 메모리를 해제한다. -> 스마트 포인터의 원리
	AutoPtr<Resource> res(new Resource);
}

void DoSomething3(AutoPtr<Resource> temp)
{
}

int main() 
{
	// 동적 메모리를 소유한 포인터가 소멸할때 자동으로 해제한다.
	{
		cout << "{" << endl;
		AutoPtr<Resource> res = new Resource;
		cout << "}" << endl;
	}

	// 스마트 포인터 주의점
	AutoPtr<Resource> res1 = new Resource;

	// .연산자를 통해 나오는건 스마트 포인터의 멤버
	res1.Test();

	// 소유한 동적 메모리에 접근하면 -> 연산자를 통해 접근
	// res1->

	// AutoPtr의 문제점1
	// AutoPtr이 가진 포인터의 소유권이 넘어가 버린다.
	DoSomething3(res1);

	// 이후 접근을 시도할시 허상 포인터 문제 발생
	// res1->

	// 문제점2
	// autoptr은 배열 단위의 생성, 해제를 지원하지 않는다.

	// 여러가지 문제점이있어 autoptr은 사용하지않은 -> 3가지 형태로바뀜
	return 0;
}