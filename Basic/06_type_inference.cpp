// 06_type_inference.cpp

// auto : 초기화하는 값에 따라서 데이터 타입을 자동으로 정리해주는 키워드

#include<iostream>

auto add(int x, int y)
{
	return x + y;
}

int main()
{
	// Type inference : 타입 추론

	int a = 10;
	float b = 3.14f;

	auto result = a + b;

	return 0;
}