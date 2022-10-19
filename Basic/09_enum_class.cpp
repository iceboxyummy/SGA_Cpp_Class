 // 09_enum_class.cpp
#include<iostream>
int main() {

	{ // C style enum�� ������
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

		if (color == fruit) // �ǹ̰� �ٸ����� ��� ������ �� ����
		{

		}

		if (color == 0) // ������ �ǹ̸� �ο��ϴ� �ǵ� ����
		{

		}
	}

	// Scoped Enumerations(c++ 11) : ���� ���� ������
	{
		enum class BaseColor : unsigned long long int // ������� �ڷ��� ��������
		{
			Red,
			Blue
		};

		enum class BaseTintColor
		{
			Red,
			Blue
		};

		// �̸������� �ٿ����ؼ� �ߺ��ذ�
		BaseColor::Red;
		BaseTintColor::Red;

		BaseColor c = BaseColor::Red;
		BaseTintColor tc = BaseTintColor::Red;

		//if (c == tc) // �������¸� �񱳰���
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

		// �ѹ��� �ڵ��ϼ� ����
		// swit-> �� -> ���� or Ÿ�� �Է� -> ���콺 ��Ŭ��

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