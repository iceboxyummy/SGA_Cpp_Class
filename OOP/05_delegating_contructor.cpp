  // 05_delegating_contructor.cpp

#include <iostream>
#include <string>
using namespace std;

/*
	delegating contructor(위임 생성자) : 같은 클래스에서 생성자가 다른 생성자를 호출하는 것 
	 - 특정 멤버만 다른 값으로 초기화 하고 싶을때 사용가능
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
		: Student1(0,name) // 위임 생성자
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
		: Student2(0, name) // 위임 생성자
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