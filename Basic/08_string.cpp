 // 08_string.cpp

#include <iostream>
#include <string>

int main() {
	using namespace std;

	// �����ͷ� ������ ���ڿ� ����� �ּҸ� �ޱ⶧���� ������ �ȵȴ�.
	// c�� �޸� c++������ const�� ������ ������ ���� ���ϵ��� ����Ǿ���.
	const char* test = "Hello";
	char my_str[] = "Hello, C++";

	// string : ���ڿ��� �ٷ�� ���� ���ִ� ��ü
	string str = "Hello, C++!";

	// ���� ��ȯ
	cout << str.size() << endl;
	cout << str.length() << endl;

	// ����ó�� �ʱ�ȭ ����
	string a("Hello, ");
	string b("C++!! ");

	// + ���� ����
	string c = a + b;

	c += ", good!!";
	cout << c << endl;

	// �迭ó�� ��밡��
	cout << c[3] << endl;

	return 0;
}
