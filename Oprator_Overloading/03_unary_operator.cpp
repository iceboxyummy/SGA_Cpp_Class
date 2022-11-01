 // 03_unary_operater.cpp

#include<iostream>

class Won
{
public:
	Won(int value = 0):value(value){}

	int GetValue() const { return value; }
	// 매개변수로 이항, 단항 연산자인지를 구분한다.
	Won operator-() const
	{
		return -value;
	}
		
	bool operator ! () const
	{
		return (value == 0) ? true : false;
	}

	friend ostream& operator<<(ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
};

int main() {
	const Won w1(10);
	const Won w2(0);

	cout << w1 << endl;
	cout << w2 << endl;

	cout << -w1 << endl;
	cout << -w2 << endl;
	
	cout << boolalpha;
	cout << !w1 << endl;
	cout << !w2 << endl;
	cout << noboolalpha;

	return 0;
}