 // 15_nested_types.cpp

/*
	nested types : 자료형을 중첩하여 사용
	 - 한 자료형에서만 특정 자료형을 만들어서 사용하고 싶을 경우 사용한다.
*/

#include <iostream>
#include <string>

using namespace std;

class Character 
{
public:
	// 한 클래스에서만 사용하고 싶을때 내부에 선언하여 사용
	enum class Movement
	{
		Min = 0,
		Idle = Min, 
		Walk, 
		Run,
		Max = Run,
		count
	};

public:
	Character(std::string&& name) 
		: name(name)
	{
	
	}

	void SetCharacterMovement(enum class Movement in_move)
	{
		movement_state = in_move;
		speed = movement_speed[static_cast<int>(in_move)];
	}

	void PrintCurrentMovementState()
	{
		switch (movement_state) 
		{
		case Character::Movement::Idle:
			cout << name << "의 현재 이동 상태 : idle, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Walk:
			cout << name << "의 현재 이동 상태 : Walk, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : Run, 현재 속도 : " << speed << endl;
			break;
		}
	}

private:
	const int movement_speed[static_cast<int>(Movement::count)] = { 0,200,500 };		// 이동 상태에 따른 속도를 담은 배열
	Movement movement_state = Movement::Idle;

	int speed = movement_speed[static_cast<int>(Movement::Idle)];

	std::string name;
};

int main() {
	Character player(string("Player"));

	player.PrintCurrentMovementState();

	player.SetCharacterMovement(Character::Movement::Walk);

	player.PrintCurrentMovementState();

	cout << endl;

	Character enemy(string("Enemy"));

	enemy.PrintCurrentMovementState();

	enemy.SetCharacterMovement(Character::Movement::Run);

	enemy.PrintCurrentMovementState();

	return 0;
}