// 06_type_inference.cpp

// auto : �ʱ�ȭ�ϴ� ���� ���� ������ Ÿ���� �ڵ����� �������ִ� Ű����

#include<iostream>

auto add(int x, int y)
{
	return x + y;
}

int main()
{
	// Type inference : Ÿ�� �߷�

	int a = 10;
	float b = 3.14f;

	auto result = a + b;

	return 0;
}