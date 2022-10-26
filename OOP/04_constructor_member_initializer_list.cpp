 // 04_constructor_member_initializer_list.cpp

#include<iostream>

using namespace std;

class Data 
{
public:
	Data(int a_data, int b_data, int c_data)
		// ������ ���ÿ� �ʱ�ȭ �ϴ� �Ͱ� ���� -> ����� const ���� ����
		:a(a_data), b{b_data}, c(c_data)
	{
		/*
		�̹� a, b, c �޸𸮰� ������� ���·� ó���Ǵ°Ŷ�
		const�� ���� �����ʹ� {}�ȿ��� ������ �ȵ�

		a = a_data;
		b = b_data;
		c = c_data; 
		*/
	}

private:
	const int a = 10;
	const int b;
	const int c;
	// int& d; // �����ϴ�.
};

int main() {

	return 0;
}