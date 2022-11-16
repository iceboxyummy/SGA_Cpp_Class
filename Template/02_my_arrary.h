#pragma once

 // 02_my_arrary.h
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
	1. .h¿¡ Àû±â

	template<typename T>
	inline void MyArray<T>::Print()
	{
	}
*/ 
