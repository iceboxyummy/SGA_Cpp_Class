// 21_assert.cpp

#include <iostream>
#include <cassert> // assert : ��ȣ��
using namespace std;;

int main() {
	int x = 0;
	cout << x << endl;

	// assert(x != 0);
	assert(false); // ���ܹ߻�
	// ���� true ��� ��� ����, false�� ������ ����ó��, Ư�������� ���������� üũ�Ҷ� ����Ѵ�. 
	// debug ��忡���� ���, release ��忡���� üũ���� �ʴ´�.
	// assert()�� ��Ÿ�ӿ� Ȯ���� �ȴ� -> �����غ��� ����� �� �� �ִ�.
	// if (x == 0) { exit(0); }

	assert(x != 0 && "x is 0");

	cout << "hello" << endl;

	return 0;
}