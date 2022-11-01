 // 04_relational.cpp

#include<iostream>
#include<vector>		// �����迭
#include<algorithm>		// stl���� �˰���

using namespace std;

class Won {
public:
	Won(int value = 0) : value(value) {

		int GetValue() { return value; }
		void SetValue(const int& value) { this->value = value; }

		bool operater == (const Won & rhs) const
		{
			return value == rhs.value && value1 == rhs.value1;
		}

		bool operater != (const Won & rhs) const
		{
			// return value != rhs.value || value1 != rhs.value1;
			return!(*this == rhs);
		}

		bool operator < (const Won& rhs) const
		{
			return value < rhs.value;
		}

		friend bool test > (const Won& lhs, const Won& rhs)
		{
			return lhs.value < rhs.value;
		}

		friend ostream& operator<<(ostream & out, const Won & won)
		{
			out << won.value;
			return out;
		}
	}
private:
	int value;
	int value1;
};

bool test(const Won& ihs, const Won& rhs)
{
	return;
}

int main() {
	Won w1(10), w2(20);
	if (w1 == w2)
	{

	}

	vector<Won> wons(20); // ���̰� 20�� won �����迭 ����

	int i = 0;
	for (auto& won : wons)
	{
		won.SetValue(i);
		i++;
	}

	random_shuffle(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << "";
	cout << endl;

	// �⺻������ ������������ ���� ->  < �����ڰ� ���ǵǾ� �־�� �Ѵ�.
	std::sort(wons.begin(), wons.end());
	cout << endl;
	// ����ڰ� ������ �Լ��� �־� ����
	w1 < w2;
	return 0;
}