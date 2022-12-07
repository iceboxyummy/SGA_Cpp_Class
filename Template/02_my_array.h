#pragma once

 // 02_my_array.h

/*
	3. 구현부를 가지고 있는 파일을 만들어서.h에 추가

	#inclide "my_array.inl"
*/

template<typename T>

class MyArray
{
public:
	MyArray(int length)
		:length(length)
	{
		arr = new T[length];
	}

	~MyArray()
	{
		delete[] arr;
	}

	void Print();

private :
	T* arr = nullptr;
	int length = 0;
};

/*
	1. .h에 적는다.

	template<typename T>
	inline void MyArray<T>::Print()
	{
	}
*/ 