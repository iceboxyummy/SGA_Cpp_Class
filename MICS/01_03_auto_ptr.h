#pragma once

#include<iostream>

/*
	std::auto_ptr<T>
	- c++ 98 처음등장
	- c++ 11 안쓰기로 정함
	- c++ 17 삭제
*/

template<class T>

class AutoPtr final
{
public:
	AutoPtr(T* ptr = nullptr)
		:ptr(ptr)
	{}

	// 소멸시 자동으로 본인이 가진 동적 데이터 go제
	~AutoPtr()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}

	AutoPtr(AutoPtr& other)
	{
		ptr = orher.ptr;		// other의 데이터 소유권을 넘겨줌
		other.ptr = nullptr;	// other의 데이커 소유권을 상실시킨다.
	}

	AutoPtr& operator =(AutoPtr& other)
	{
		if (&other == this)
			return this;

		if (ptr != nullptr) 
		{
			delete ptr;
		}

		ptr = orher.ptr;		// other의 데이터 소유권을 넘겨줌
		other.ptr = nullptr;	// other의 데이커 소유권을 상실시킨다.

		return this*;
	}

	void Test{}

	// 포잍터처럼 동작할 수있게 연상자 정의
	T& operator* () const { return ptr; }
	T& operator -> () const { return ptr; }

private:
	T* ptr = nullptr;
};