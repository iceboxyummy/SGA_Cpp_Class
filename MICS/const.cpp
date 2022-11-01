#include<iostream>
using namespace std;

int main() {

	const int a = 10;
	const int& c = a;
	int* b = const_cast<int*>(&c);

	*b = 14;
	cout << a << endl;
	cout << *b << endl;

	return 0;
}