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
	Number operator ++(int) // dummy -> ������ ������ �����Ѵ� ������ ��
	{
		Number temp(num); // ������ �ӽ� �ν��Ͻ�
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
	// ����� ������ prefix ��������� ª�� 2�� �� ������.
	// ���� �����Ϸ��� �˾Ƽ� ����ȭ�� ���ֳ� ����ȭ ����� ���� �����Ϸ��� ���� �� �־ 2���� �����Ѵ�.

	return 0;
}