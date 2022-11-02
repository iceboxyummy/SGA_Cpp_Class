 // 09_01_copy_constructor_and_copy_initialization.cpp

#include<iostream>

using namespace std;

class Fraction 
{
public:
	Fraction(int num = 0, int den = 0)
		:numerator(num), denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	Fraction(const Fraction& fraction)
		:numerator(fraction.numerator), denominator(fraction.denominator)
	{
		cout << "copy constructor!!" << endl;
	}

	Fraction& operator =(const Fraction rhs)
	{
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		cout << "copy assigment constructor!!" << endl;

		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	return Fraction();

	Fraction temp(5, 2); // constructor

	return temp;  // copy constructor
}

int main() {
	Fraction frac; // constructor

	Fraction copy1(frac); // copy constructor
	Fraction copy2 = frac; // copy constructor -> ���������̹Ƿ� copy2(frac)�� ����, �򰥸��Ƿ� ������� �ʴ°��� �����Ѵ�.

	copy1 = frac; // copy operator = 

	cout << "#######################" << endl;
	CreateFraction(); // Debug��忡���� ���簡 �߻������� Release������ �߻����� ���� -> NRVO

	return 0;
}