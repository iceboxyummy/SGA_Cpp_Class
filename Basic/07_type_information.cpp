// 07_type_information.cpp

/*
	RTTI(Run Time Type Information) : ��Ÿ�� �߿� �ǽð����� ������ Ÿ�Կ� ���� ������ ��� ���
	 - �ش� ����� �����־�� �ǽð����� ������ Ȯ�ΰ���
	 - dynamic_cast�ÿ��� �ʿ��ϴ�
	 - ��Ÿ�Ӷ� �ڷ����� ����ϴ°Ŷ� ������.
*/

#include<iostream>
#include<typeinfo>

//int add(int a, int b) { return a + b; }
//float add(float a, float b) { return a + b; }
//short add(short a, short b) { return a + b; }

template<typename T>

T add(T a, T b)
{
	std::cout << "a : " << typeid(a).name() << std::endl;
	std::cout << "b : " << typeid(b).name() << std::endl;

	return a + b;
}

int main()
{
	auto a = add(10, 20);
	std::cout << add(10.0f, 20.0f);

	return 0;
}