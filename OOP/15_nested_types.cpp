 // 15_nested_types.cpp

/*
	nested types : �ڷ����� ��ø�Ͽ� ���
	 - �� �ڷ��������� Ư�� �ڷ����� ���� ����ϰ� ���� ��� ����Ѵ�.
*/

#include <iostream>
#include <string>

using namespace std;

class Character 
{
public:
	// �� Ŭ���������� ����ϰ� ������ ���ο� �����Ͽ� ���
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
			cout << name << "�� ���� �̵� ���� : idle, ���� �ӵ� : " << speed << endl;
			break;
		case Character::Movement::Walk:
			cout << name << "�� ���� �̵� ���� : Walk, ���� �ӵ� : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "�� ���� �̵� ���� : Run, ���� �ӵ� : " << speed << endl;
			break;
		}
	}

private:
	const int movement_speed[static_cast<int>(Movement::count)] = { 0,200,500 };		// �̵� ���¿� ���� �ӵ��� ���� �迭
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