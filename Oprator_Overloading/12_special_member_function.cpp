 // 12_special_member_function.cpp

/*
   special member function - 특수 멤버 함수
   - 자동으로 작성되는 함수 6가지를 말한다.
   - 각 함수는 명시적으로 작성하지 않을 경우 자동으로 작성이 된다.
   - 각 종류/함수별로 특정 조건에 의해 자동 작성이 되지 않을 수 있다.

   메서드 종류
   default constructor - 기본 생성자
   - 작성한 생성자가 하나라도 없을 때 작성된다.
   - 아무런 기능이 없다.

   destructor - 소멸자
   - 소멸자를 작성하지 않을 경우 자동 작성된다.

   copy constructor/assigment operator - 복사 생성자/대입 연산자
   - 둘 중 하나라도 작성 되어 있을 경우, 다른 하나는 작성이 되지 않는다.
   - move constructor/assigment operator가 하나라도 작성되어 있다면 작성이 되지 않는다.

   move constructor/assigment operator - 이동 생성자/대입 연산자
   - 둘 중 하나라도 작성 되어 있을 경우, 다른 하나는 작성이 되지 않는다.
   - copy constructor/assigment operator가 하나라도 작성되어 있다면 작성이 되지 않는다.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	// constructor
	Test()
		:value(++count)
	{
		cout << "default constructor" << endl;
	}

	Test(const Test& t)
		:value(++count)
	{
		cout << "copy constructor" << endl;
	}

	Test(Test&& t) noexcept
		:value(++count)
	{
		cout << "move constructor" << endl;
	}

	// assignment
	Test& operator = (const Test& t)
	{
		cout << "copy assignment" << endl;
		return *this;
	}

	Test& operator = (Test& t)
	{
		cout << "move assignment" << endl;
		return *this;
	}

	// destructor
	~Test()
	{
		cout << "destructor : " << value << endl;
	}

public:
	static int count;

private:
	int value;
};

int Test::count = 0;

int main() {
	cout << "1###########################" << endl;
	Test t1; // 기본 생성자

	cout << "2###########################" << endl;
	Test t2 = t1; // 선언 단계에서는 =가 대입을 의미 x, 복사 생성자 호출
	Test t3(t1);

	cout << "3###########################" << endl;
	Test t4=move(t1); // 이동 생성자 호출
	Test t5(move(t1));

	cout << "4###########################" << endl;
	t1 = t2; // 복사 대입 연산자

	cout << "5###########################" << endl;
	t1 = move(t2); // 이동 대입 연산자

	cout << "6###########################" << endl;

	return 0;
}