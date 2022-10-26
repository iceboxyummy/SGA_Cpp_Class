// 03_constructor.cpp

#include <iostream>
#include <utility>

using namespace std;

class Fraction // 분수
{
public:
	// constructor(생성자) : 객체를 인스턴스화 할때 호출 된다. 다른 함수와 구분하기 위헤 반환 값이 없다.

	Fraction()
	{
		cout << "construtor1!" << endl;
	}

	Fraction(int a, int b)
	{
		cout << "construtor2!" << endl;
	}

	/*Fraction(int a=1, int =2) 모호함
	{
		cout << "construtor3!" << endl;
	}*/

	// 기본적으로 오버로딩되는 생성자 3가지
	// Fraction(){}				// default constructor : 생성자가 하나라도 있다면 포함되지않는다.
	// Fraction(const Fraction&){} // copy constructor : 외부에 원본이 존재하므로 const 사용을 권장한다.
	// Fraction(Fraction&&){}		// move constructor : 원본 자체를 가져왔으므로 const 사용x

	//Fraction() { cout << "construtor1!" << endl; }

	Fraction(const Fraction&) 
	{
		cout << "construtor4!" << endl;
	}

	Fraction(Fraction&&)
	{
		cout << "construtor5!" << endl;
	}

private:
	int numerator = 10; // 분자
	int denominator = 10; // 분모
};

int main() {
	// Fraction frac0();
	Fraction frac1;
	Fraction frac2(1.0, 2);	// direct
	Fraction frac3{ 1.0, 2 }; // uniform
	Fraction frac4(frac1); // 복사 생성자
	Fraction frac4(std::move(frac1)); // 이동 생성자 호출

	return 0;
}