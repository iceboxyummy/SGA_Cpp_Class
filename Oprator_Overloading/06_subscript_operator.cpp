  // 06_subscript_operator.cpp -> []

#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

class IntArray
{
public:
	// 1.
	int Get(int index) { return list[index]; }
	void Set(int index, int value) { list[index] = value; }

	// 2.
	int* GetList() { return list; }

	// 3. 2���� ���������� ������.
	int& operator[](int index)
	{
		//if (index >= 10 || index < 0)
		//{
		//	// ����ó��
		//}

		// 4. ����׽ÿ��� üũ, ��������� ������.
		assert(index >= 0);
		assert(index < 10);

		return list[index];
	}

private:
	int list[10];
};

int main() {
	IntArray list;

	// 1. ���ŷӴ�
	// list.Set(0, 1);
	// list.Set(1, 2);
	// list.Set(2, 3);
	// list.Set(3, 4);
	// list.Set(4, 5);
	// list.Set(5, 6);
	
	// cout << list.Get(0) << endl;
	// cout << list.Get(1) << endl;
	// cout << list.Get(2) << endl;
	// cout << list.Get(3) << endl;
	// cout << list.Get(4) << endl;
	// cout << list.Get(5) << endl;

	//2. �迭�� ���Ϲ޾� ��밡��
	// ������ ũ�⿡ ���� ������ ���� -> �������� �ʴ�.
	// auto arr = list.GetList();
	
	// arr[0] = 1;
	// arr[1] = 2;
	// arr[2] = 3;
	// arr[3] = 4;
	// arr[4] = 5;
	 
	// cout << arr[0] << endl;
	// cout << arr[1] << endl;
	// cout << arr[2] << endl;
	// cout << arr[3] << endl;
	// cout << arr[4] << endl;

	// 3. [] �����ε�
	list[0] = 1;
	list[1] = 1;
	list[2] = 1;
	list[3] = 1;

	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[2] << endl;

	IntArray* list3 = new IntArray;

	// list3[0] = 10; �����Ϳ� �ٿ� error
	(*list3)[0] = 10;

	vector<int>vecs;

	// ����׿��� üũ
	vecs[0];
	vecs[1];
	
	// ��������� üũ
	vecs.at(0);
	vecs.at(1);

	// �ӵ��鿡�� ��밡���� ��� 
	int* arr = vecs.data(); // Ư�� �������� �����ּҸ� ���� 
	arr++;

	return 0;
}