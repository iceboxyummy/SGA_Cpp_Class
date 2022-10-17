 // 02_input output stream.cpp

#include<iostream>
#include<iomanip>

//stream( >> , << ) : 데이터 입출력의 흐름을 표시한 것

int main() {
	// cout

	int x = 1028;
	double pi = 3.141592;

	std::cout << "x is" << x << "\npi is" << pi << std::endl << std::endl;

	// cin

	int z;

	std::cin >> z;
	std::cout << "Your input is " << z << std::endl << std::endl;

	// 조정자(manipulator) : 출력형식을 지정해준다, 바꾸지 않는 한 계속 유지된다.
	
	int num = 100;
	
	// 진수 출력 형식 조정자
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl << std::endl;

	// showbase : 어떤 진수 형태로 출력되는지 표시
	// showpos : 심진수 정수의 부호표시
	// noshowbase, noshowpos로 해제 가능
	std::cout << std::showbase << std::showpos;
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl << std::endl;
	std::cout << std::noshowbase << std::noshowpos;

	bool is_true = true;
	bool is_false = false;

	// bool형식의 출력방식 바꾸기
	std::cout << std::boolalpha;
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	std::cout << std::noboolalpha;
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	return 0;
}