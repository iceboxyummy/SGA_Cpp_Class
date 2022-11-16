 // 02_class_template.cpp
 // 02_my_arrary.cpp
 // 02_my_arrary.h

 // 02_class_template.cpp

#include <iostream>
#include "02_my_arrary.h"
// #include "02_my_arrary.cpp" : 2. 분리한 .cpp까지추가 -> .h와 .ccp로 분리한 이유가 사라진다.
using namespace std;

int main() {
	MyArray<int> int_arr(10);
	MyArray<float> float_arr(10);

	int_arr.Print();
	float_arr.Print();

	return 0;
}

/*
	템플릿 코드를 작성할 때 선언과 정의를 분리하면 링크에러가 발생한다.

	이유
	 - 템플릿코드는 함수를 정의한게 아니라 함수의 정의를 생성하기위해 만든 툴이다.
	 - 템플릿 코드는 컴파일 타임때 구체화 된다. -> 특정 데이터형에 맞게 함수를 작성한다.
	 - 컴파일 타임에서 정해진다. -> 사용시점에서 이미 구현부가 정의되어 있어야 작성이 된다.
	 - 만약 구현부가 분리되어 있다면 코드가 작성이 되지않아 링크에러가 발생한다.

	해결방법
	 1. 템플릿 코드를 .h에 적는다.
	 2. 구현부를 분리했다면 .cpp까지 포함시켜준다.
	 2. 템플릿 함수의 구현부를 가지고 있는 파일을 만들어서 .h에 추가해준다.
	 4. TODO 4,5 수업후 설명
*/
