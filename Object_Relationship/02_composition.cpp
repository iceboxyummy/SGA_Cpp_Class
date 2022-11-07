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
	// 1. 구성
	Monster(int x, int y) {
		position1.x = x;
		position1.y = y;
	}

	// 2. 집합
	Monster(Point2D* point) {
		position2 = point;
	}
private:
	std::string name;
	Point2D position1; // Monster 인스턴스가 사라지면 같이 사라짐 -> 구성
	Point2D* position2; // Monster  인스턴스가 사라져도 존재함 -> 집합
};

int main() {
	// 구성
	Monster m(10, 20);

	// 집합
	Point2D point;
	{
		Monster mon(&point);
	}
	return 0;
}