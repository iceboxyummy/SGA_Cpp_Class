 // 09_enum_class.cpp
#include<iostream>
int main() {

	{ // C style enum의 문제점
		enum Color
		{
			Color_Red,
			Color_Blue
		};

		enum TintColor
		{
			TintColor_Red,
			TintColor_Blue
		};

		enum Fruit
		{
			Apple,
			Banana
		};

		Color color = Color_Red;
		Fruit fruit = Apple;

		if (color == fruit) // 의미가 다르지만 상수 값으로 비교 가능
		{

		}

		if (color == 0) // 고유한 의미를 부여하는 건데 가능
		{

		}
	}

	// Scoped Enumerations(c++ 11) : 영역 제한 열거형
	{
		enum class BaseColor : unsigned long long int // 상수값의 자료형 지정가능
		{
			Red,
			Blue
		};

		enum class BaseTintColor
		{
			Red,
			Blue
		};

		// 이름공간을 붙여야해서 중복해결
		BaseColor::Red;
		BaseTintColor::Red;

		BaseColor c = BaseColor::Red;
		BaseTintColor tc = BaseTintColor::Red;

		//if (c == tc) // 같은형태만 비교가능
		//{

		//}

		if (static_cast<int>(c) == 0)
		{

		}

		enum class Test
		{
			A,
			B,
			C,
			D,
			E,
			F,
			G,
		};

		Test t = Test::A;

		// 한번에 자동완성 가능
		// swit-> 탭 -> 변수 or 타입 입력 -> 마우스 왼클릭

		switch (t)
		{
		case Test::A:
			break;
		case Test::B:
			break;
		case Test::C:
			break;
		case Test::D:
			break;
		case Test::E:
			break;
		case Test::F:
			break;
		case Test::G:
			break;
		default:
			break;
		}
	}
	return 0;
}