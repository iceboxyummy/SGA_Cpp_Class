  // 05_delegating_contructor.cpp

#include <iostream>
#include <string>
using namespace std;

/*
	delegating contructor(���� ������) : ���� Ŭ�������� �����ڰ� �ٸ� �����ڸ� ȣ���ϴ� �� 
	 - Ư�� ����� �ٸ� ������ �ʱ�ȭ �ϰ� ������ ��밡��
*/

class Student1
{
public:
	Student1(const int& id, const std::string& name)
		: id(id), name(name)
	{
		//...
		//...
		//...
	}

	Student1(const std::string& name)
		: Student1(0,name) // ���� ������
	{	
		//...
		//...
		//...
	}

private:
	int id;
	std::string name;
};

class Student2
{
public:
	Student2(const int& id, const std::string& name)
		: id(id), name(name)
	{
		//...
		//...
		//...
	}

	Student2(const std::string& name)
		: Student2(0, name) // ���� ������
	{
		//...
		//...
		//...
	}

	void Initialize(const int& id, const std::string name)
	{
		//...
		//...
		//...
	}

private:
	int id;
	std::string name;
};

int main() {
	return 0;
}