 // 05_increment_decrement.cpp

#include<iostream>
using namespace std;

class Number
{
public:
	Number(const int& num=0):num(num){}
	
	// prefix
	Number& operator ++()
	{
		++num;
		return *this;
	}

	// postfix
	Number operator ++(int) // dummy -> 전위와 후위를 구분한는 쓰레기 값
	{
		Number temp(num); // 리턴할 임시 인스턴스
		++(*this);
		return temp;
	}

	friend ostream& operator << (ostream& out, const Number& number)
	{
		out << number.num;
		return out;
	}
	
private:
	int num;
};

int main(){
	
	Number num1{ 0 };
	Number num2{ 0 };

	cout << ++num1 << endl;
	cout << num1 << endl;

	cout << num2++ << endl;
	cout << num2 << endl;

	for(int i=0; i<10000;i++){} // 1
	for(int i=0; i<10000;++i){} // 2
	// 결과는 같지만 prefix 연산과정이 짧아 2가 더 빠르다.
	// 현대 컴파일러는 알아서 최적화를 해주나 최적화 기능이 없는 컴파일러도 있을 수 있어서 2번을 권장한다.

	return 0;
} 
