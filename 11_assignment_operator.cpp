 // 11_assignment_operator.cpp

/*
	deep copy( ���� ���� ) vs shallow copy( ���� ���� )
*/

#include <iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* const src = "")
	{
		length = strlen(src) + 1;
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] - '\0';
	}

	// copy constructor : ���� �������� ���� ��� ���� ����
	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;

		/*
			shallow copy : ������ �ִ� ���� �״�� �����ϴ� ��
			 - ���� : �����Ͱ� ����� ��� �ּҸ� �����ϰ� �ȴ�.
			 - ������ ������ �ּҿ� ������ �Ҹ��� �� ������ ���� �� �ִ�.
		*/
		//length = other.length;
		//data = other.data;

		// deep copy : ���ο� ������ ����� �����Ѵ�. -> ��������� ���� ����

		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;
	}

	// move constructor
	// ���� ��ü�� �������� ���� -> �ܺο� ���̻� other�� �������� �ʴ´�.
	MyString(MyString&& other) noexcept
	{
		cout << "move constructor" << endl;

		length = std::move(other.length);
		data = std::move(other.data);
		/*
			���� �Ű����� other�� ���̻� �������� �ʴ´ٰ� �����Ѵ�.
			�׷��� ������ ���� �Ҵ���� ���� �ִٸ� nullptr�� ����� �������� ��������� �Ѵ�.
		*/
		other.data = nullptr;
	}

	// copy assigment operator
	MyString& operator=(MyString&& other)
	{
		// ������ �ڵ带 ����� ���� ������

		// 1
		if (this == &other) // �ڱ��ڽ��� �Ҵ��ϴ� �� ����
			return *this;

		// 2 �̹� ���� ������ ���� ��� ���� �Ҷ� �޸� ���� ���ɼ��� �ִ�.
		if(this->data!=nullptr)
		{
			delete[] this->data;
			this->data=	
		}
		cout << "move constructor" << endl;

		length = std::move(other.length);
		data = std::move(other.data);
	
		other.data = nullptr;
		return *this;
	}

	// move assigment operator
	MyString& operator=(const MyString&& other){}

	~MyString()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
public:
	char* data = nullptr;
	int length = 0;
};

int main() {
	cout << "1###############" << endl;
	MyString str("Hello");
	cout << (int*)str.data << endl;
	cout << str.data << endl;

	cout << "2###############" << endl;

	{ //copy
		MyString copy(str); // copy constructor
		copy = str; // copy assignement operator
		cout << (int*)copy.data << endl;
		cout << copy.data << endl;
	}
	cout << "3###############" << endl;
	cout << (int*)str.data << endl;
	cout << str.data << endl;

	cout << "4###############" << endl;

	{ // move
		MyString move(std::move(str)); // move constructor
		move = std::move(str); // move assignment operator

		cout << (int*)move.data << endl;
		cout << move.data << endl;
	}

	cout << "5###############" << endl;
	cout << (int*)str.data << endl;
	cout << str.data << endl;

	return 0;
}