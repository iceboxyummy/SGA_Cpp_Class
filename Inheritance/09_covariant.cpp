 // 09_covariant.cpp

/*
	covariant ( ������ȯ�� ) : �ڽ��� ������ ��ȯ�ϴ� ��� ��Ӱ��迡�� ���� ������ �Լ��� �����Ǵ� ��
	 - is-a �����̱� ������ �ڽ��� ������ ������ �� ���������� �ν�
	 - ��ȯ���� �޶� ������ �������̵� ���
*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
};

class B : public A
{
public:
	// ������ȯ�� : �ڽ��� ������ ������ ��� ��Ӱ��迡�� ���� ���·� �νĵȴ�.
	// override Ű���带 �־ ����� �������̵��� ���� Ȯ�� ����
	B* GetThisPointer() override { cout << "B" << endl; return this; }
};

int main() {
	return 0;
}