 // 06_partial_specialization.cpp

#include <iostream>
using namespace std;

// #define 일반함수_부분특수화
#define 클래스멤버함수_부분특수화

#ifdef 일반함수_부분특수화
template<class T, int size>
class StaticArray
{
public:
	T* GetArray() { return arr; }
	T& operator[](int index)
	{
		return arr[index];
	}

	void Print1()
	{
		for (int i = 0; i < size; i++)
			cout << (*this)[i] << ' ';
		cout << endl;
	}

private:
	T arr[size];
};

template<typename T, int size>
void Print2(StaticArray<T, size>& arr)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template<int size>
void Print2(StaticArray<char, size>& arr)
{
	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;
}
#endif // 일반함수_부분특수화

#ifdef 클래스멤버함수_부분특수화

template<class T, int size>
class StaticArray_Base
{
public:
	T* GetArray() { return arr; }
	T& operator[](int index)
	{
		return arr[index];
	}

	void Print1()
	{
		for (int i = 0; i < size; i++)
			cout << (*this)[i] << ' ';
		cout << endl;
	}

private:
	T arr[size];
};

template<class T, int size>
class StaticArray :public StaticArray_Base<T, size>
{

};

// 상속을 사용해 클래스의 기능을 그대로 물려받으면서 특정함수에 대해 처리해준다.
template<int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
	void Print1() override
	{
		for (int i - 0; i < size; i++)
			cout << (*this)[i];
		cout << endl;
	}
};
#endif

int main() {
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.Print1();
	//Print2(int4);

	StaticArray<char, 4> char6;
	char6[0] = 'H';
	char6[1] = 'E';
	char6[2] = 'L';
	char6[3] = 'l';
	char6[4] = 'O';
	char6[5] = '\0';

	char6.Print1();
	//Print2(char6);
	return 0;
}