// 20_function_pointer.cpp

#include <iostream>
#include <functional> // �Լ� �����͸� ���� �� �� �ְ� ���ִ� ���̺귯��

using namespace std;

bool func(const int& x)
{
	return x > 0;
}

// �Լ��� �̸��κ��� Ÿ�� �κ��� �ȴ�.
typedef bool(*func_ptr)(const int&);

// using
using func_type = bool(*)(const int&);

int main() {

	bool (*pf)(const int&) = func;

	func_ptr f = func;

	func_type f2 = func;

	// ��ȯ���� �Ű������� �־��ָ� �ȴ�. �Լ� �����Ϳ� ���� ������ ����ϴ�.
	std::function<bool(const int&)>f3 = func;

	return 0;
}