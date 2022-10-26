 // 02_encapsulation.cpp

#include<iostream>
using namespace std;

struct Data1
{
	// public : 구조체의 기본 접근 지정자
	int hp;
	int attack;
	float luck;
};

/*
   C++의 객체 지향은 숨기는게 기본
   변수에 의존해서 코드를 짜지 않도록 한다. -> hp -= 1; hp -= 1; hp -= 1; hp -= 1; -> 유지보수가 힘들어진다.
   유지보수를 쉽게 ex) void attack() { hp -= 1; }
   변수에 바로 접근 하는게 아닌 함수를 통해 접근을 한다. -> 오버헤드 발생
*/

class Data2
{
	// private : 클래스의 기본 접근 지정자
public:
	/* access function, getter, setter*/
	/* member function */

	/* setter : 멤버의 데이터를 초기화 or 수정하는 것*/
	void SetData2(int hp_data, int attack_data, float luck_data)
	{
		hp = hp_data;
		attack = attack_data;
		luck = luck_data;
	}

	void SetData2(Data2 data)
	{
		// 같은 클래스 타입끼리는 private이어도 접근가능
		hp = data.hp;
		attack = data.attack;
		luck = data.luck;
	}

	// getter : 멤버의 데이터 값을 얻는 것
	const int& GetHp(){ return hp; }
	const int& GetAttack(){ return attack; }

private:
	int hp; // member variable
	int attack;
	float luck;
};

int main() {
	Data1 data1;
	data1.hp;

	Data2 d;
	// 호출하지 않는다면 쓰레기 값이 들어간다.
	// -> constructor로 무조건 호출되게 하여 해결가능

	d.SetData2(10, 5, 10.0f);
	cout << d.GetHp() << endl;
	cout << d.GetAttack() << endl;

	return 0;
}