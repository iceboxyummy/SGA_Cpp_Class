 // 22_variable_argument.cpp

/*
	variable argument(���� ����) : �Լ��� ���� ������ ������ ���ϴ°�
	 - printf()�� �ִ� ...�� ���Ѵ�.
*/

//#define V_1
//#define V_2
#define V_3

#include<iostream>
#include<cstring>
#include<string>
#include<stdarg.h>

// �������� �Լ� ����غ���
#ifdef V_1  

// arg_count : ���������� ������ ����
// ...		  : �������ڸ� �ްڴٴ� ǥ��
void print_number(int arg_count, ...)
{
	// ���� ���ڸ� �ٷ�� ������
	va_list arg_list;

	/*
	va_start(�������� ������, ������ �����μ�)
		- ���� ������ ������ ���� ��ũ��
		- ������ ���� �μ��� �������� ��ġ�� ã���ش�.

	---------------------------------------------------
	| arg_count | arg_list1 | arg_list2 | arg_list3 |
	---------------------------------------------------
			    ��
			arg_list
   ������ ���� �μ��� �������� ���� ������ ���� ��ġ�� ã���ش�.
	*/

	va_start(arg_list, arg_count);

	// ���� ������ ������ŭ ���
	for (int i = 0; i < arg_count; i++)
	{	
		/* 
		va_arg(arg_list, int) : 
		arg_list���� 4����Ʈ(int���� ũ��) ��ŭ �������Ͽ� �����͸� �����µ� 
		arg_list���� 4����Ʈ(int���� ũ��) ��ŭ �̵���Ų��.
		-> ���� ���������� ������ġ�� �̵���Ų��.
		*/

		int num = va_arg(arg_list, int);
		printf("%d ", num);
	}
	printf("\n");

	// va_end : �ش� ���� ���� �����͸� nullptr�� �ʱ�ȭ
	va_end(arg_list);
}

int main() {

	print_number(1, 1);
	print_number(2, 1, 2);
	print_number(3, 1, 2, 3);
	print_number(4, 1, 2, 3, 4);
	print_number(5, 1, 2, 3, 4, 5);

	return 0;
}
#endif

// �پ��� �ڷ����� ���� ���ڷ� �޾� ����غ���
#ifdef V_2

// const char* arg_format : �ڿ� ���� ���� ������ Ÿ���� �޴´�,
void print_value(const char* arg_format, ...)
{
	va_list arg_list;

	va_start(arg_list, arg_format);

	int i = 0;
	// ���ڿ��� ���� ���ö����� �ݺ�
	while (arg_format[i] != '\0')
	{
		switch (arg_format[i++])
		{
		case 'i': printf("%d ", va_arg(arg_list, int)); break;
		case 'd': printf("%lf ", va_arg(arg_list, double)); break;
		case 'c': printf("%c ", va_arg(arg_list, char)); break;
		case 's': printf("%s ", va_arg(arg_list, char*)); break;
		}
	}
	printf("\n");
	va_end(arg_list);
}

int main() {
	print_value("i", 10);
	print_value("di", 3.141592, 10);
	print_value("cdi", 'A', 3.141592, 10);
	print_value("scdi", "arg_list", 'A', 3.141592, 10);

	return 0;
}
#endif

// �� ���� �پ��� �ڷ����� ���� ���ڷ� �޾� ����غ���
#ifdef V_3

void print_string(const std::string arg_format, ...)
{
	va_list arg_list;

	va_start(arg_list, arg_format);
	{
		// _vscprintf -> ���İ� ���ڰ� ���ļ� ������� �� ���ڿ��� ���̸� �˷��ش�.
		// -> '\0'�� ���̴� ���� �־��־�� �Ѵ�.
		int size = _vscprintf(arg_format.c_str(), arg_list) + sizeof('\0');

		// ������� ũ�⸸ŭ �����Ҵ��� �޴´�.
		char* string = new char[size];

		// vsprintf_s() : string�� size ��ŭ arg_format(����)�� arg_list(����)�� ���� ���ڿ��� ����� �ش�.
		vsprintf_s(string, size, arg_format.c_str(), arg_list);

		// �ϼ��� ���ڿ��� ����Ѵ�.
		printf("%s", string);

		// ��� �� �������ش�.
		delete[] string;
	}
	va_end(arg_list);
	printf("\n");
}

int main()
{
	print_string("���ڿ� ��� ���� : %s, ���ڵ� ���� : %d, Escape sequence�� ���� : \nTest", "Hello World!", 123);

	return 0;
}
#endif