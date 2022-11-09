 // 04_inheritance_and_casting.cpp

/*
	Up Casting : �ڽ� Ŭ������ �θ� Ŭ���� �����ͷ� ����Ű�� ��
	 - �ڽ� Ŭ������ �� ũ�� ������ ���������� �� ū �������� ���� ���̴�. (�Ͻ��� ĳ���ð���)
	 - �پ��� �ڽ� Ŭ������ �ϳ��� �θ� Ŭ���� �ڷ������� �ٷ� �� �ְ� �ȴ�.
	
	Down Casting : �θ� Ŭ���� �����Ͱ� ����Ű�� ��ü�� �ڽ� Ŭ������ �����ͷ� ����Ű�� ��
	 - �θ� Ŭ���� �����Ͱ� �θ��� ��ü�� ����ų ���, �ڽ� Ŭ������ �����ͷ� ��ȯ �� ���� ����.
	 - ���������� �Ʒ��� ���°��̱⿡ ������ ����ȯ�� �ȵǴ� ����� ����ȯ�� ���־���Ѵ�.
*/

#include <iostream>
using namespace std;

class Snack{};

class Chitos : public Snack{};
class ChocoChip : public Snack{};
class Homerunball : public Snack{};

int main() {
	Snack* chocochip = new ChocoChip(); // up casting : �Ͻ��� ����ȯ ����
	Snack* chitos = new Chitos(); // up casting : �Ͻ��� ����ȯ ����
	
	// ���� �ٸ� �ڽ� Ŭ������ ���� �θ� Ŭ������ ���� ����� �����ϴ�.
	Snack* snack[2] = { chitos, chocochip };

	Chitos* test = static_cast<Chitos*>(chitos); // down casting : ����� ����ȯ �ʿ� 

	return 0;
}