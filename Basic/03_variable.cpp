 // 03_variable.cpp

#include<iostream>
#include<numeric>

int main() {
	// Initialization

	int x = 10;		// copy
	int y(10);		// direct
	int z{ 10 };	// uniform : 형변환을 허용하지 않는다. -> 안전하다.

	int a = 1.1;		// warning : 데이터 손실
	// int b{ 1.1 };	// error : 값이 잘림
	char c = 500;		// warning
	// char d{ 500 };	// error 

	int e = 0, f(1), g{ 2 };

	// limits : 각각의 자료형의 한계값을 가지고 있는 클래스
	// <> : temlpate
	std::cout << std::numeric_limits<short>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl << std::endl;

	// casting
	float k = 10.123f;
	std::cout << k << std::endl;
	std::cout << (int)k << std::endl; // c ctyle 너무 강력함 -> 관계없는 자료형끼리의 형변환도 가능
	std::cout << int(k) << std::endl; // c++ style

	std::cout << static_cast<int>(k) << std::endl; // c++ style

	// const vs constexpr 

	// const : 받는 값에 따라 컴파일이나 런타임 때 값이 결정된다.

	const int c1 = 123;

	int i1 = 10;
	const int c2 = i1;

	int arr_1[c1];
	// int arr_2[c2]; // error : 초기화 값을 변수로 받아 런타임때 값이 정해진다.

	/* 
		constexpr : 컴파일타임때 값이 정해진다.
		 ->컴파일때 알 수 없는 값은 받을 수 없다.
		 - 매크로와 유사하지만 디버깅이 가능하다.
	 */

	constexpr float pi1 = 3.1415921f;
	float pi2 = 3.141592f;
	// constexpr float pi3 = pi2; // error : 변수는 컴파일 시점에 알 수 없어 안된다.

	return 0;
}

