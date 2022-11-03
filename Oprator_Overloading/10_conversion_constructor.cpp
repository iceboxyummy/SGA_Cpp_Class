 // 10_conversion_constructor.cpp

/*
	conversion constructor( ��ȯ ������ ) : �Ű������� �ϳ��� ������
	 - �ٸ� �ڷ����� ������ �Ǹ� �Ͻ��� ����ȯ�� �Ͼ�鼭 ȣ���� �ȴ�.
	 - �Լ����� ��ȯ�����ڰ� �ִ� Ŭ������ �Ű������� ������ ������ �ӽ� ��ü�� ������ ������.
	  +>esplicit Ű���带 �߰��Ͽ� ���氡��
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

	Fraction(int a) // �Ű� ������ �ϳ� -> conversion constructor
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	// explicit : �Ͻ�������ȯ�� ���� Ű����
	//explicit Fraction(int a) // �Ű� ������ �ϳ� -> conversion constructor
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
	//Fraction frac3(1);		// ��ȭ ������ ȣ��
	//Fraction frac4('a');	// �ڷ����� �ٸ���� �Ͻ��� ����ȯ
	//Fraction frac5(3.14f);	// �ڷ����� �߸��� ����ȯ

	//PrintFraction(frac1);
	//PrintFraction(frac2);

	PrintFraction('a');
	PrintFraction(3.14);
	PrintFraction(100);

	return 0;
}