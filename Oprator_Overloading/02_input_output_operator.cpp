 // 02_input_outpit_operator.cpp

#include<iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}

	int GetX() const { return x; }
	int GetY() const { return y; }

	void print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

	// ostream : ��� ��Ʈ��
	// &�� �����Ͽ� ü�̴�
	friend ostream& operator<<(ostream& out, const Point& p)
	{
		out << "(" << p.x << "," << p.y << ")" << endl;
		return out;
	}

	// istream : �Է� ��Ʈ��
	friend istream& operator>>(istream& in, Point& p)
	{
		in >> p.x >> p.y;
		return in;
	}

private:
	int x = 0;
	int y = 0;
};

int main() {

	Point p1(0, 1), p2{ 5,5 };

	cout << p1 << p2;
	cin >> p1 >> p2;
	cout << p1 << p2;

	//p1.print();
	//p2.print();
	
	return 0;
}