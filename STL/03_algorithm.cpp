// 03_algorithm.cpp

// algorithm Library : �����̳� �ݺ��ڸ� ����Ͽ� ���� �۾��� ���� �����ϰ� �����ִ� ���̺귯��

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<random>

using namespace std;
random_device rd;
mt19937_64 mt(rd());

int main() {
	//vector<int> container;
	list<int> container;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	// �����Լ�
	// shuffle(container.begin() + 3, container.end(), mt); list�� ���� ����x

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// �����ȿ��� �ּڰ� �ƻ�
	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	// �����ȿ��� �ִ� �ƻ�
	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	// ���ϴ� �����͸� ������ ���� Ž��
	iter = find(container.begin(), container.end(), 7);

	// ������
	// sort(container.begin(), container.end()); list�� ���������� sort�Լ��� ������ �־ ������
	container.sort(); // list�� sort

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	return 0;
}