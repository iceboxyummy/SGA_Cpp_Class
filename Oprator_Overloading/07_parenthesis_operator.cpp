 // 07_parenthesis_operator.cpp -> ()

#include<iostream>
using namespace std;

class Counter
{
public:
	int operator()(int i) { return count += 1;}

private:
	int count = 0;
};

int main() {
	Counter ct;

	cout << ct(10) << endl; // Function Object - Functor
	cout << ct(20) << endl; // ��ü�� �Լ�ó�� ���

	return 0;
}