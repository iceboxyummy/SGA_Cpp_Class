 // 04_relational.cpp

#include<iostream>
#include<vector>		// �����迭
#include<algorithm>		// stl���� �˰���

using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value) {}

	int GetValue() const { return value; }
	void SetValue(const int& value) { this->value = value; }

	bool operator == (const Won& rhs) const
	{
		return value == rhs.value && value1 == rhs.value1;
	}

	bool operator != (const Won& rhs) const
	{
		// return value != rhs.value || value1 != rhs.value1;
		return!(*this == rhs);
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend ostream& operator<<(ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
	int value1;
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.GetValue() > rhs.GetValue();
}

int main() {
	Won w1(10), w2(20);

	if (w1 == w2)
	{

	}

	//Won* wons1 = new Won[20];

	vector<Won> wons(20); // ���̰� 20�� won �����迭 ����

	int i = 0;
	for (auto& won : wons)
	{
		won.SetValue(i);
		i++;
	}

	// �˰��� �ִ� ������ ���� �Լ�
	random_shuffle(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	// �⺻������ ������������ ���� ->  < �����ڰ� ���ǵǾ� �־�� �Ѵ�.
	std::sort(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	// ����ڰ� ������ �Լ��� �־� ����
	std::sort(wons.begin(), wons.end(), test);

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	// ���ٽ� ���
	sort(wons.begin(), wons.begin(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.GetValue() > rhs.GetValue();
		}
	);

	for (const auto& won : wons)
			cout << won << " ";
		cout << endl;

	return 0;
}