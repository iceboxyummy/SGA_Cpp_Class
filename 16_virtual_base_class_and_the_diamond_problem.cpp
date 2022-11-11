 // 16_virtual_base_class_and_the_diamond_problem.cpp

/*
   A     A
   |     |
   B     C
    \   /
      D

   class A {};
   class B : public A {};
   class C : public A {};
   class D : public B, public C {};

   B가 A를 가지고 있다.
   C가 A를 가지고 있다.
   B와 C를 가지는 D는 A를 2개 가진다.
   => D입장에서는 두 A중 어느것을 사용해야 하는지 몰라 모호성이 발생
*/

/*
       A
     /   \
   B       C
     \   /
       D

   class A {};
   class B : virtual public A {};
   class C : virtual public A {};
   class D : public B, public C {};

   상속시 virtual 키워드를 붙여 가상 상속을 하면
   A객체가 하나만 존재하여 문제가 없다.
*/

#include<iostream>
using namespace std;

class PowerDevice
{
public:
    PowerDevice(int power) { cout << "powerDevice" << power << endl; }
public:
    int i;
};

class Scanner : virtual public PowerDevice // 가상상속
{
public:
    Scanner(int scanner, int power)
        : PowerDevice(power)
    {
        cout << "Scanner" << scanner << endl;
    }

};

class Printer : virtual public PowerDevice // 가상상속
{
public:
    Printer(int printer, int power)
        : PowerDevice(power)
    {
        cout << "Scanner" << printer << endl;
    }
};

class Copier :public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power1, int power2, int power3)
        :Scanner(scanner, power1)
        , Printer(printer, power2)
        // 가상상속시 다이아몬드 상속을 받는 최하위 패생클래스는 따로 생성자를 지정해주어야한다.
        , PowerDevice(power3)
    {
    }
};
int main() {
    Copier copier(1, 2, 3, 4, 5);

    // Copier.i; ambiguos, 다이아몬드 상속시 문제 방생
    
    // 일반 상속시 다른 주소 출력 -> 두 개의 A인스턴스가 생성
    // 가상 상속시 같은 주소 출력 -> 한 개의 A인스턴스가 생성
    cout << &copier.Scanner::PowerDevice::i << endl;
    cout << &copier.Printer::PowerDevice::i << endl;

	return 0;
}