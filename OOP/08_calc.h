#pragma once

// ����� ������ ��� ����� �����ϴ� ��� ���Ͽ� �߰��Ǳ� ������ ������ �߻��� ������ ����
// -> .cpp ���Ϸ� �Ѱ��־� ó��
 
// #include <iostream> : �ʿ���� ����� �����ϵǸ� ������ �ð� ����
// using namespace std; : �ߺ� ����

void Test(int a);

class Calc
{
public:
	Calc(int value) : value(value) {}
	// ����� ������ ���� �ۼ��� .cpp�� �Ѱ��ְԵǸ� inlne�� �ڵ������� ����
	// -> ����� �ۼ��� Ŭ�����ȿ� ����Լ����� �����α��� ���� ������ �ڵ����� inline�� �ڵ����� ���ԵǱ� ����
	// -> ���� �ڵ尡 ª�� ���� ȣ��Ǵ� �Լ��� ����� ������� �͵� ����ȭ ����� �ϳ��̴�.

	void Add(int value);
	void Sub(int value);
	void Mul(int value);
	void Div(int value);
	void Mod(int value);

	void Print();
	
	void Test(); // �����θ� �ۼ����� �ʰ� �ѱ�� inline�� ���� �ʴ°� Ȯ�ΰ���

private:
	int value;
};