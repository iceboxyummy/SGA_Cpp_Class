 // 22_variable_argument.cpp

/*
	variable argument(가변 인자) : 함수에 들어가는 인자의 갯수가 변하는것
	 - printf()에 있는 ...을 말한다.
*/

//#define V_1
//#define V_2
#define V_3

#include<iostream>
#include<cstring>
#include<string>
#include<stdarg.h>

// 가변인자 함수 사용해보기
#ifdef V_1  

// arg_count : 가변인자의 갯수를 받음
// ...		  : 가변인자를 받겠다는 표시
void print_number(int arg_count, ...)
{
	// 가변 인자를 다루는 포인터
	va_list arg_list;

	/*
	va_start(가변인자 포인터, 마지막 고정인수)
		- 가변 인자의 포인터 설정 매크로
		- 마지막 고정 인수를 기준으로 위치를 찾아준다.

	---------------------------------------------------
	| arg_count | arg_list1 | arg_list2 | arg_list3 |
	---------------------------------------------------
			    ↑
			arg_list
   마지막 고정 인수를 기준으로 가변 인자의 시작 위치를 찾아준다.
	*/

	va_start(arg_list, arg_count);

	// 가변 인자의 갯수만큼 출력
	for (int i = 0; i < arg_count; i++)
	{	
		/* 
		va_arg(arg_list, int) : 
		arg_list에서 4바이트(int형의 크기) 만큼 역참조하여 데이터를 가져온뒤 
		arg_list에서 4바이트(int형의 크기) 만큼 이동시킨다.
		-> 다음 가변인자의 시작위치로 이동시킨다.
		*/

		int num = va_arg(arg_list, int);
		printf("%d ", num);
	}
	printf("\n");

	// va_end : 해당 가변 인자 포인터를 nullptr로 초기화
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

// 다양한 자료형을 가변 인자로 받아 출력해보자
#ifdef V_2

// const char* arg_format : 뒤에 들어올 가변 인자의 타입을 받는다,
void print_value(const char* arg_format, ...)
{
	va_list arg_list;

	va_start(arg_list, arg_format);

	int i = 0;
	// 문자열의 끝이 나올때까지 반복
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

// 더 쉽게 다양한 자료형을 가변 인자로 받아 출력해보자
#ifdef V_3

void print_string(const std::string arg_format, ...)
{
	va_list arg_list;

	va_start(arg_list, arg_format);
	{
		// _vscprintf -> 형식과 인자가 합쳐서 만들어질 총 문자열의 길이를 알려준다.
		// -> '\0'의 길이는 따로 넣어주어야 한다.
		int size = _vscprintf(arg_format.c_str(), arg_list) + sizeof('\0');

		// 만들어질 크기만큼 동적할당을 받는다.
		char* string = new char[size];

		// vsprintf_s() : string에 size 만큼 arg_format(형식)과 arg_list(인자)를 합쳐 문자열을 만들어 준다.
		vsprintf_s(string, size, arg_format.c_str(), arg_list);

		// 완성된 문자열을 출력한다.
		printf("%s", string);

		// 사용 후 해제해준다.
		delete[] string;
	}
	va_end(arg_list);
	printf("\n");
}

int main()
{
	print_string("문자열 출력 가능 : %s, 숫자도 가능 : %d, Escape sequence도 가능 : \nTest", "Hello World!", 123);

	return 0;
}
#endif