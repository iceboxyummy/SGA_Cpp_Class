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
	cout << ct(20) << endl; // 객체를 함수처럼 사용

	return 0;
} 