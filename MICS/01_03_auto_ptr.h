#pragma once

#include<iostream>

/*
	std::auto_ptr<T>
	- c++ 98 ó������
	- c++ 11 �Ⱦ���� ����
	- c++ 17 ����
*/

template<class T>

class AutoPtr final
{
public:
	AutoPtr(T* ptr = nullptr)
		:ptr(ptr)
	{}

	// �Ҹ�� �ڵ����� ������ ���� ���� ������ go��
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
		ptr = orher.ptr;		// other�� ������ �������� �Ѱ���
		other.ptr = nullptr;	// other�� ����Ŀ �������� ��ǽ�Ų��.
	}

	AutoPtr& operator =(AutoPtr& other)
	{
		if (&other == this)
			return this;

		if (ptr != nullptr) 
		{
			delete ptr;
		}

		ptr = orher.ptr;		// other�� ������ �������� �Ѱ���
		other.ptr = nullptr;	// other�� ����Ŀ �������� ��ǽ�Ų��.

		return this*;
	}

	void Test{}

	// ������ó�� ������ ���ְ� ������ ����
	T& operator* () const { return ptr; }
	T& operator -> () const { return ptr; }

private:
	T* ptr = nullptr;
};