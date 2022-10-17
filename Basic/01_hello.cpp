 // 01_hello.cpp

#include<iostream> // input + output + stream
#include<stdio.h>
#include<cstdio>

int main() {
	std::cout << "Hello, C++!!" << std::endl;
	// endl : '\n' + fflusf()
	std::cout << "Hello, C++!!" << '\n';

	int x = 10, y = 10;
	std::cout << "x = " << x << "\ny = " << y << std::endl;
	std::cout << "x + y = " << x + y << std::endl;

	return 0;
}