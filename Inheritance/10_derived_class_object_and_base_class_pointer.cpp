 // 10_derived_class_object_and_base_class_pointer.cpp

#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	Animal(string name) : name(name){}
	virtual void Speak() const { cout << "??" << endl; }

protected:
	string name;
};

class Cat : public Animal
{
public:
	Cat(string name): Animal(name){}
	virtual void Speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	virtual void Speak() const { cout << "Woof" << endl; }
};

int main() {
	Cat cats[]{ Cat("cat1"), Cat("cat2"), Cat("cat3") ,Cat("cat4") ,Cat("cat5") };
	Dog dogs[]{ Dog("dog1"), Dog("dog2") ,Dog("dog3") ,Dog("dog4") ,Dog("dog5") };

	for (const auto& cat : cats)
		cat.Speak();

	for (const auto& dog : dogs)
		dog.Speak();

	// 부모 클래스로 업캐스팅하여 자식 클래스를 하나의 클래스로 묶어 사용 가능
	Animal* animals[]
	{
		&cats[0],
		&cats[1],
		&cats[2],
		&cats[3],
		&cats[4],
		&dogs[0],
		&dogs[1],
		&dogs[2],
		&dogs[3],
		&dogs[4],
	};

	// animal 자료형 하나로 다양한 형태의 자료형을 표현 가능 -> 다형성
	for (const auto& animal : animals)
		animal->Speak();

	return 0;
} 
