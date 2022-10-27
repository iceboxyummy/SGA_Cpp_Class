 // 09_class_and_const.cpp

/*
	const ��� �Լ�
	 - �ش� ��� �Լ������� ���ο��� ��� ������ ���ȭ �� -> ���� �Ұ���
	 - mutable�� ����� ��� ������ ����
*/

#include<iostream>
using namespace std;

class Data
{
public:
	Data(): value1(0), value2(0){}

	int Test() { return 0; }

	int GetValue1() { cout << "not const" << endl; return value1; }

	// ��ȸ������ ���� ������ �� �ֱ� ������ error
	// int& GetValue1() const { cout << "const" << endl; return value1; } error
	const int& GetValue1() const { cout << "const" << endl; return value1; }

	// �ɹ� ������ ���ȭ�Ǿ� ���� �Ұ���
	// void SetValue1(int value) const { this->value1 = value; } error
	// mutable Ű���带 �߰��� �ɹ� ������ ����
	void SetValue2(int value) const { this->value2 = value; }

private:
	int value1;
	mutable int value2;
};

void Print(const Data& data)
{
	/*
		const ��ü�� const ��� �Լ��� ȣ���� �����ϴ�.
		 -> �Ϲ� �Լ��� ȣ���� ��� ��������� ������ ���ɼ��� �־� ��õ������ ����

		�Լ����� ���ڸ� const���·� ���� �� �ܺο����� �� ��ü�� �ƴϴ��� const �Լ��� ȣ���ϰԵȴ�.
		�׷��� ������ const ������ ������ �������� �ʴ��� �ʿ��� ��찡 ����
		 -> ������ ������ const�� �ٿ��־� ��� ��ü������ �������� �۵��ϵ��� ó�����ִ°� ����.
	*/

	// data.Test(); error
	data.GetValue1();
}
int main() {

	Data data1;
	//const Data data2;

	data1.GetValue1();
	//data2.GetValue1();

	return 0;
}