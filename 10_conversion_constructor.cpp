 // 10_conversion_constructor.cpp

/*
	conversion constructor( 변환 생성자 ) : 매개변수가 하나인 생성자
	 - 다른 자료형이 들어오게 되면 암시적 형변환이 일어나면서 호출이 된다.
	 - 함수에서 변환생성자가 있는 클래스의 매개변수를 값으로 받을때 임시 객체가 생성될 수있자.
	  +>esplicit 키워드를 추가하여 예방가능
*/

#include<iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int num, int den) :numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:
		numerator(other.numerator), denominator(other.denominator)
	{
		cout << "copy constructor" << endl;
	}

	Fraction(int a) // 매개 변수가 하나 -> conversion constructor
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	// explicit : 암시적형변환을 막는 키워드
	//explicit Fraction(int a) // 매개 변수가 하나 -> conversion constructor
	//	:numerator(a), denominator(1)
	//{
	//	cout << "conversion constructor" << endl;
	//}


	friend std::ostream& operator<<(std::ostream& out, const Fraction frac)
	{
		out << frac.numerator << "/" << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;
}

int main() {

	//Fraction frac1(10, 20); // constructor
	//Fraction frac2(frac1);  // copys constructor 
	//
	//Fraction frac3(1);		// 변화 생성자 호출
	//Fraction frac4('a');	// 자료형이 다를경우 암시적 형변환
	//Fraction frac5(3.14f);	// 자료형이 잘리는 형변환

	//PrintFraction(frac1);
	//PrintFraction(frac2);

	PrintFraction('a');
	PrintFraction(3.14);
	PrintFraction(100);

	return 0;
}