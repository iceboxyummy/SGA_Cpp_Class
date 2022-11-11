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

   B�� A�� ������ �ִ�.
   C�� A�� ������ �ִ�.
   B�� C�� ������ D�� A�� 2�� ������.
   => D���忡���� �� A�� ������� ����ؾ� �ϴ��� ���� ��ȣ���� �߻�
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

   ��ӽ� virtual Ű���带 �ٿ� ���� ����� �ϸ�
   A��ü�� �ϳ��� �����Ͽ� ������ ����.
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

class Scanner : virtual public PowerDevice // ������
{
public:
    Scanner(int scanner, int power)
        : PowerDevice(power)
    {
        cout << "Scanner" << scanner << endl;
    }

};

class Printer : virtual public PowerDevice // ������
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
        // �����ӽ� ���̾Ƹ�� ����� �޴� ������ �л�Ŭ������ ���� �����ڸ� �������־���Ѵ�.
        , PowerDevice(power3)
    {
    }
};
int main() {
    Copier copier(1, 2, 3, 4, 5);

    // Copier.i; ambiguos, ���̾Ƹ�� ��ӽ� ���� ���
    
    // �Ϲ� ��ӽ� �ٸ� �ּ� ��� -> �� ���� A�ν��Ͻ��� ����
    // ���� ��ӽ� ���� �ּ� ��� -> �� ���� A�ν��Ͻ��� ����
    cout << &copier.Scanner::PowerDevice::i << endl;
    cout << &copier.Printer::PowerDevice::i << endl;

	return 0;
}