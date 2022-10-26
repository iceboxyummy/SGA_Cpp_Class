 // 02_encapsulation.cpp

#include<iostream>
using namespace std;

struct Data1
{
	// public : ����ü�� �⺻ ���� ������
	int hp;
	int attack;
	float luck;
};

/*
   C++�� ��ü ������ ����°� �⺻
   ������ �����ؼ� �ڵ带 ¥�� �ʵ��� �Ѵ�. -> hp -= 1; hp -= 1; hp -= 1; hp -= 1; -> ���������� ���������.
   ���������� ���� ex) void attack() { hp -= 1; }
   ������ �ٷ� ���� �ϴ°� �ƴ� �Լ��� ���� ������ �Ѵ�. -> ������� �߻�
*/

class Data2
{
	// private : Ŭ������ �⺻ ���� ������
public:
	/* access function, getter, setter*/
	/* member function */

	/* setter : ����� �����͸� �ʱ�ȭ or �����ϴ� ��*/
	void SetData2(int hp_data, int attack_data, float luck_data)
	{
		hp = hp_data;
		attack = attack_data;
		luck = luck_data;
	}

	void SetData2(Data2 data)
	{
		// ���� Ŭ���� Ÿ�Գ����� private�̾ ���ٰ���
		hp = data.hp;
		attack = data.attack;
		luck = data.luck;
	}

	// getter : ����� ������ ���� ��� ��
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
	// ȣ������ �ʴ´ٸ� ������ ���� ����.
	// -> constructor�� ������ ȣ��ǰ� �Ͽ� �ذᰡ��

	d.SetData2(10, 5, 10.0f);
	cout << d.GetHp() << endl;
	cout << d.GetAttack() << endl;

	return 0;
}