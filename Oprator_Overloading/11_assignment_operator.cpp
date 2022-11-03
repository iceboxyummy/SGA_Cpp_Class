 // 11_assignment_operator.cpp

/*
	deep copy( 깊은 복사 ) vs shallow copy( 얉은 복사 )
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

	// copy constructor : 따로 정의하지 않을 경우 얕은 복사
	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;

		/*
			shallow copy : 가지고 있는 값을 그대로 전달하는 것
			 - 문제 : 포인터가 복사될 경우 주소를 공유하게 된다.
			 - 원본의 데이터 주소와 같아져 소멸할 때 문제가 생길 수 있다.
		*/
		//length = other.length;
		//data = other.data;

		// deep copy : 새로운 공간을 만들어 복사한다. -> 허상포인터 문제 방지

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
	// 원본 자체를 가져오는 개념 -> 외부에 더이상 other가 존재하지 않는다.
	MyString(MyString&& other) noexcept
	{
		cout << "move constructor" << endl;

		length = std::move(other.length);
		data = std::move(other.data);
		/*
			받은 매개변수 other은 더이상 존재하지 않는다고 가정한다.
			그렇기 때문에 동적 할당받은 값이 있다면 nullptr로 만들어 소유권을 해제해줘야 한다.
		*/
		other.data = nullptr;
	}

	// copy assigment operator
	MyString& operator=(MyString&& other)
	{
		// 안전한 코드를 만들기 위한 주의점

		// 1
		if (this == &other) // 자기자신을 할당하는 것 방지
			return *this;

		// 2 이미 값을 가지고 있을 경우 복사 할때 메모리 누수 가능성이 있다.
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