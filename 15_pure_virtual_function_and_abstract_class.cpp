 // 15_pure_virtual_function_and_abstract_class.cpp

/*
	pure virtual function ( ���� ���� �Լ� ) : �Ļ� Ŭ�������� �ݵ�� �������ؾ� �ϴ� �Լ�
	 - ������ �����ϴ� ��ü�� ����
     - ���ǵ��� ���� �Լ��̹Ƿ� ���� ���� �Լ��� ������ Ŭ������
       �ν��Ͻ�ȭ�� �ȵǰ� ��Ӹ� ���� -> ������ Ÿ�� �ڷ����� ���� ����

	abstract class ( �߻� Ŭ���� ) : �ϳ� �̻��� ���� ���� �Լ��� ������ Ŭ����

	interface ( �������̽� ) : ���� ���� �Լ��θ� �̷���� Ŭ����
   - C++������ ���� �߻� Ŭ������ ������ �� ���� �ʾ� �̸��տ� I�� �ٿ� ǥ��
*/

#include<iostream>
using namespace std;

//#define ���������Լ���_�߻�Ŭ����
#define �������̽�

#ifdef  ���������Լ���_�߻�Ŭ����

class Animal // �߻�Ŭ����
{
public:
	Animal(string name) : name(name) {}
	virtual ~Animal() = default;

	auto GetName()const { return name; }

	virtual void Speak() const = 0; // ���������Լ�

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

	// ���������Լ��� ������ �߻�Ŭ������ �ν��Ͻ�ȭ�� �Ұ���
	// Animal ani("ll"); error

	// ������ ���´� ���� ���� -> �ش�Ŭ������ ��ӹ޴� �ڽ�Ŭ������ �ϳ��� ���� �뵵�� ����Ѵ�.
	Animal* ani;

	Cat cat("DiDi");
	Dog dog("Corgi");

	cat.Speak();
	dog.Speak();

	// ��ӹ��� ���������Լ��� �����������ʾ� error
	// Fox fox("RuRu");

	return 0;
}

#endif //  ���������Լ���_�߻�Ŭ����

#ifdef �������̽�

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

	DoSomething(file_log, "ĳ���Ͱ� ������ �ȵ�!!");
	DoSomething(console_log, "ĳ���Ͱ� ������ �ȵ�!!");
}

#endif // �������̽�