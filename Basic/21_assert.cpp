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

	//assert(x != 0 && "x is 0");

	cout << "hello" << endl;

	// static_assert(false); // ������ Ÿ�Ӷ� üũ�� �� �ִ� assert

	constexpr int x1 = 6;
	constexpr int y1 = 7;
	static_assert(x1 < y1, "x1 is bigger than y1");

	int z = 10;
	const int w = z;
	static_assert(w); // ������ Ÿ�Ӌ� �� �� ���� �����δ� üũ�� �� ����.

	return 0;
}