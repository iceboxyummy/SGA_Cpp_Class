// 03_constructor.cpp

#include <iostream>
#include <utility>

using namespace std;

class Fraction // �м�
{
public:
	// constructor(������) : ��ü�� �ν��Ͻ�ȭ �Ҷ� ȣ�� �ȴ�. �ٸ� �Լ��� �����ϱ� ���� ��ȯ ���� ����.

	Fraction()
	{
		cout << "construtor1!" << endl;
	}

	Fraction(int a, int b)
	{
		cout << "construtor2!" << endl;
	}

	/*Fraction(int a=1, int =2) ��ȣ��
	{
		cout << "construtor3!" << endl;
	}*/

	// �⺻������ �����ε��Ǵ� ������ 3����
	// Fraction(){}				// default constructor : �����ڰ� �ϳ��� �ִٸ� ���Ե����ʴ´�.
	// Fraction(const Fraction&){} // copy constructor : �ܺο� ������ �����ϹǷ� const ����� �����Ѵ�.
	// Fraction(Fraction&&){}		// move constructor : ���� ��ü�� ���������Ƿ� const ���x

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
	int numerator = 10; // ����
	int denominator = 10; // �и�
};

int main() {
	// Fraction frac0();
	Fraction frac1;
	Fraction frac2(1.0, 2);	// direct
	Fraction frac3{ 1.0, 2 }; // uniform
	Fraction frac4(frac1); // ���� ������
	Fraction frac4(std::move(frac1)); // �̵� ������ ȣ��

	return 0;
}