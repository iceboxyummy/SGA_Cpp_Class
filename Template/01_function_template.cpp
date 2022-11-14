 // 01_function_template.cpp

/*
	Template : ���α׷��Ӱ� ���ϴ� Ÿ���� �־��ָ� �˸°� �ڵ带 ���ִ� ƫ
	 - int�� double���� ��ü���� �ڷ����� ������ �� �ִ� �Ϲ���(generic type)���� �����Ѵ�.
	 - � ���������� ���ø��� �Ű������� �����ϸ�, �����Ϸ��� �� ������ ���� �´� �ڵ带 �������ش�.
	 - ��ü���� �������� ��� �Ϲ������� ���α׷��� �ϴµ� �̰��� �Ϲ�ȭ ���α׷����̶�� �θ���.
	 - �پ��� �ڷ����� ������ �˰����� �����ؾ� �Ѵٸ�, ���ø��� ����Ѵ�.
*/

#include<iostream>
using namespace std;
/*
	�����ε����� ���������� ���ο� Ÿ���� �ʿ��Ҷ� ���� �߰��� �־���Ѵ�.
	 -> ���ŷӰ� �ڵ� ��ü�� �������� ���� ��� ��� �������־���Ѵ�.
	
	int GetMax(int x, int y) { return (x > y) ? x : y; }
	float GetMax(float x, float y) { return (x > y) ? x : y; }
	double GetMax(double x, double y) { return (x > y) ? x : y; }
	long long GetMax(long long x, long long y) { return (x > y) ? x : y; }
*/

template<typename T> // ���ø� ���� T ����, �ڵ带 �ۼ��� �� ����� Ÿ�� �Ű�����
// template<class T> class��� ������ ������ ���̴� ����.
T GetMax(T x, T y) // ���� ������ T�� �ϳ��� �ڷ���ó�� �����Ͽ� ����Ѵ�.
{
	return (x > y) ? x : y;
}

class Won
{
public:
	Won(int value = 0) :value(value){}
	
	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream&operator <<(ostream&out, const Won&won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
};

int main() {
	// <>�� ���ø� ������ �ڷ����� ������ �� �� �ִ�.
	cout << GetMax<int>(1, 2u) << endl;
	//cout << GetMax<float>(1, 2) << endl;

	// �Լ� ���ø��� ���� Ÿ���� ���߸� <> �� Ÿ���� ���������� �ʾƵ� �����ϴ�
	cout << GetMax(1l, 2l) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;
	cout << GetMax(1.0, 2.0) << endl;

	// �츮�� ���� ���ø� �Լ��� �� ���� ���ڰ��� ���� Ÿ������ �ް� �ֱ� ������ �� ������ Ÿ���� �ٸ��ٸ� �Ͻ������� ���� x
	// cout << GetMax(1, 2u) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;
	return 0;
}