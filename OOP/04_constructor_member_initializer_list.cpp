 // 04_constructor_member_initializer_list.cpp

#include<iostream>

using namespace std;

class Data 
{
public:
	Data(int a_data, int b_data, int c_data)
		// 생성과 동시에 초기화 하는 것과 동일 -> 멤버가 const 여도 가능
		:a(a_data), b{b_data}, c(c_data)
	{
		/*
		이미 a, b, c 메모리가 만들어진 상태로 처리되는거라
		const가 붙은 데이터는 {}안에서 수정이 안됨

		a = a_data;
		b = b_data;
		c = c_data; 
		*/
	}

private:
	const int a = 10;
	const int b;
	const int c;
	// int& d; // 가능하다.
};

int main() {

	return 0;
}