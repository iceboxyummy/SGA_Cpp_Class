 // 04_function_template_specialization.cpp

/*
	function template specialization (�Լ� ���ø� Ư��ȭ) : Ư�� �ڷ����� ���ؼ� �ٸ� ����� �����ϰ� ���� �� ����Ѵ�.
	 - Ư�� �ڷ����� ���Ͽ� ��ȸ ó���� �����ϴ�.
*/
 
#include<iostream>
using namespace std;

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

// template specialization
// Ư��ȭ�� Ÿ�Կ� ���� �ٸ� ������ �����Ѵ�.
template<>
char GetMax(char x, char y)
{
	cout << "warning : comparing char" << endl;
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
public:
	Storage(T value)
		:value(value)
	{

	}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

template<>
void Storage<double>::Print()
{
	cout << scientific << value << endl;
}

int main() {
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;
	cout << GetMax('a', 'b') << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.2);
	s2.Print();

	return 0;
}