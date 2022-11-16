 // 02_my_arrary.cpp

#include"02_my_array.h"

/*
	2. 분리한 .cpp

	template<typename T>
	inline void MyArray<T>::Print()
	{
	}
*/ 

// 4. 명시적 특수화
template<typename T>
void MyArray<T>::Print()
{
}

template<>
void MyArray<int>::Print()
{
}

template<>
void MyArray<float>::Print()
{
}

