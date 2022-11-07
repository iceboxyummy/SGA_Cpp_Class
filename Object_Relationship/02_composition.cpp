 // 02_composition.cpp

#include <iostream>
using namespace std;

class Point2D {
public:
	int x;
	int y;
};

class Monster
{
public:
	// 1. ����
	Monster(int x, int y) {
		position1.x = x;
		position1.y = y;
	}

	// 2. ����
	Monster(Point2D* point) {
		position2 = point;
	}
private:
	std::string name;
	Point2D position1; // Monster �ν��Ͻ��� ������� ���� ����� -> ����
	Point2D* position2; // Monster  �ν��Ͻ��� ������� ������ -> ����
};

int main() {
	// ����
	Monster m(10, 20);

	// ����
	Point2D point;
	{
		Monster mon(&point);
	}
	return 0;
}