 // 09_class_and_const.cpp

/*
	const 멤버 함수
	 - 해당 멤버 함수에서는 내부에서 멤버 변수가 상수화 됨 -> 수정 불가능
	 - mutable을 사용한 멤버 변수는 예외
*/

#include<iostream>
using namespace std;

class Data
{
public:
	Data(): value1(0), value2(0){}

	int Test() { return 0; }

	int GetValue1() { cout << "not const" << endl; return value1; }

	// 우회적으로 값을 수정할 수 있기 때문에 error
	// int& GetValue1() const { cout << "const" << endl; return value1; } error
	const int& GetValue1() const { cout << "const" << endl; return value1; }

	// 맴버 변수가 상수화되어 수정 불가능
	// void SetValue1(int value) const { this->value1 = value; } error
	// mutable 키워드를 추가한 맴버 변수는 가능
	void SetValue2(int value) const { this->value2 = value; }

private:
	int value1;
	mutable int value2;
};

void Print(const Data& data)
{
	/*
		const 객체는 const 멤버 함수만 호출이 가능하다.
		 -> 일반 함수는 호출할 경우 멤버변수가 수정될 가능성이 있어 원천적으로 막음

		함수에서 인자를 const형태로 받을 시 외부에서는 상가 객체가 아니더라도 const 함수를 호출하게된다.
		그렇기 때문에 const 형태의 변수를 정의하지 않더라도 필요한 경우가 생김
		 -> 가능한 곳에는 const를 붙여주어 상수 객체에서도 무리없이 작동하도록 처리해주는게 좋다.
	*/

	// data.Test(); error
	data.GetValue1();
}
int main() {

	Data data1;
	//const Data data2;

	data1.GetValue1();
	//data2.GetValue1();

	return 0;
}