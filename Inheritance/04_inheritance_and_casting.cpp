 // 04_inheritance_and_casting.cpp

/*
	Up Casting : 자식 클래스를 부모 클래스 포인터로 가리키는 것
	 - 자식 클래스가 더 크긴 하지만 개념적으로 더 큰 개념으로 가는 것이다. (암시적 캐스팅가능)
	 - 다양한 자식 클래스를 하나의 부모 클래스 자료형으로 다룰 수 있게 된다.
	
	Down Casting : 부모 클래스 포인터가 가리키는 객체를 자식 클래스의 포인터로 가리키는 것
	 - 부모 클래스 포인터가 부모의 객체를 가리킬 경우, 자식 클래스의 포인터로 변환 될 수는 없다.
	 - 개념적으로 아래로 가는것이기에 묵시적 형변환이 안되니 명시적 형변환을 해주어야한다.
*/

#include <iostream>
using namespace std;

class Snack{};

class Chitos : public Snack{};
class ChocoChip : public Snack{};
class Homerunball : public Snack{};

int main() {
	Snack* chocochip = new ChocoChip(); // up casting : 암시적 형변환 가능
	Snack* chitos = new Chitos(); // up casting : 암시적 형변환 가능
	
	// 서로 다른 자식 클래스를 같은 부모 클래스로 묶어 사용이 가능하다.
	Snack* snack[2] = { chitos, chocochip };

	Chitos* test = static_cast<Chitos*>(chitos); // down casting : 명시적 형변환 필요 

	return 0;
}