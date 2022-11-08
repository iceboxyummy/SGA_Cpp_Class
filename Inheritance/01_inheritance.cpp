// 01_Inheritance.cpp

/*
   Inheritance ( ��� ) : �ٸ� Ŭ������ ������ �״�� ������ �� �ִ� ��� <= ���������� ������
    - ����� ������ ���ȭ�Ͽ� �ڵ带 ���� �ϱ⿡ �����ϴ�.
    - �Ļ� Ŭ������ ����� ��� Ŭ������ ����� ����/Ȯ���ϱ⿡ ����
    - �ڵ��� �ߺ��� �ٿ� ����ȭ �� �� ����
*/

#include<iostream>
using namespace std;

class Mother   //base class - ��� Ŭ����
{
public:
    auto GetA() const
    {
        cout << "Mother" << endl;
        return a;
    }
    void SetA(const int& a) { this->a = a; }

private:
    int a;
public:
    int b;
    int c;
};

//Derived class - �Ļ� Ŭ����, ��� Ŭ������ ������ �״�� ��������
class Daughter : public Mother
{
public:

    auto GetA() const
    {
        //�θ��� ����� ���ԵǾ� �ִ� �� Ȯ�� ����
        c;   //Mother::c;

        //���/�Ļ� Ŭ������ ���� �̸��� ��ġ�� ����� �ִٸ� �Ļ� Ŭ������ ����� �켱�� ��.
        b;   //Daughter::b

        Mother::b;   //�ߺ��Ǵ� ����� �ִٸ� ���ӽ����̽�(::)�� ����Ͽ� ���� ����
        Daughter::b;

        //��� Ŭ������ private ����� �����ϳ� ������ �ȵ� �ڽĿ����� protected(����)�̳� public����� ������ �����ϴ�.
        //return a;   error

        cout << "Daughter" << endl;
        return Mother::GetA();

        //__super Ű����� �θ� Ŭ���� ǥ�� ����, VC���� Ű����
        //return __super::GetA();
    }

private:
    int b;
};

int main()
{
    // ��ü�� �ν��Ͻ�ȭ �� �� ��ӹ��� Ŭ������ �����Ѵٸ� �ֻ��� Ŭ���� �κк��� ������ �ȴ�.
    // Mother ������ ȣ�� -> Daughter ������ ȣ��
    Daughter d;

    //��� Ŭ�������� �������� ��� �Լ�
    d.SetA(10);

    //��� Ŭ������ �Ļ� Ŭ������ ����� ��ġ�� ��� ������°� �ƴ϶� ��� Ŭ������ ����� ��������.
    d.GetA();   //�Ļ� Ŭ������ GetA()�Լ��� ����

    cout << "###############" << endl;

    //���� �����̽��� ����Ͽ� �θ� Ŭ������ ������ �Լ� ȣ�� ����
    d.Mother::GetA();

    return 0;
}