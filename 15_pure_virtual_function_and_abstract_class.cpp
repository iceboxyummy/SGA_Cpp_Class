 // 15_pure_virtual_function_and_abstract_class.cpp

/*
	pure virtual function ( 순수 가상 함수 ) : 파생 클래스에서 반드시 재정의해야 하는 함수
	 - 동작을 정의하는 몸체가 없음
     - 정의되지 않은 함수이므로 순수 가상 함수를 포함한 클래스는
       인스턴스화가 안되고 상속만 가능 -> 포인터 타입 자료형은 선언 가능

	abstract class ( 추상 클래스 ) : 하나 이상의 순수 가상 함수를 포함한 클래스

	interface ( 인터페이스 ) : 순수 가상 함수로만 이루어진 클래스
   - C++에서는 보통 추상 클래스와 구분이 잘 가지 않아 이름앞에 I를 붙여 표시
*/

#include<iostream>
using namespace std;

//#define 순수가상함수와_추상클래스
#define 인터페이스

#ifdef  순수가상함수와_추상클래스

class Animal // 추상클래스
{
public:
	Animal(string name) : name(name) {}
	virtual ~Animal() = default;

	auto GetName()const { return name; }

	virtual void Speak() const = 0; // 순수가상함수

protected:
	string name;
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	virtual void Speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	virtual void Speak() const { cout << "Woof" << endl; }
};

class Fox : public Animal
{
public:
	Fox(string name) : Animal(name) {}
};

int main() {

	// 순수가상함수를 포함한 추상클래스는 인스턴스화가 불가능
	// Animal ani("ll"); error

	// 포인터 형태는 선언 가능 -> 해당클래스를 상속받는 자식클래스를 하나도 묶는 용도로 사용한다.
	Animal* ani;

	Cat cat("DiDi");
	Dog dog("Corgi");

	cat.Speak();
	dog.Speak();

	// 상속받은 순수가상함수를 재정의하지않아 error
	// Fox fox("RuRu");

	return 0;
}

#endif //  순수가상함수와_추상클래스

#ifdef 인터페이스

class IErrorLog
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) = 0;
};

class FileErrorLog :public IErrorLog
{
public:
	virtual bool ReportError(const char* error)override
	{
		cout << "Writting error to a file : " << error << endl;
	}
};

class ConsoleErrorLog :public IErrorLog
{
public:
	virtual bool ReportError(const char* error)override
	{
		cout << "Writting error to a console : " << error << endl;
	}
};

void DoSomething(IErrorLog& log, const char* error)
{
	log.ReportError(error);
}

int main() {
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	DoSomething(file_log, "캐릭터가 생성이 안됨!!");
	DoSomething(console_log, "캐릭터가 생성이 안됨!!");
}

#endif // 인터페이스