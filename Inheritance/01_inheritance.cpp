// 01_Inheritance.cpp

/*
   Inheritance ( 상속 ) : 다른 클래스의 내용을 그대로 포함할 수 있는 기능 <= 유지보수가 쉬워짐
    - 공통된 동작을 모듈화하여 코드를 재사용 하기에 유리하다.
    - 파생 클래스를 만들어 기반 클래스의 기능을 수정/확장하기에 용이
    - 코드의 중복을 줄여 간소화 할 수 있음
*/

#include<iostream>
using namespace std;

class Mother   //base class - 기반 클래스
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

//Derived class - 파생 클래스, 기반 클래스의 내용을 그대로 물려받음
class Daughter : public Mother
{
public:

    auto GetA() const
    {
        //부모의 멤버가 포함되어 있는 걸 확인 가능
        c;   //Mother::c;

        //기반/파생 클래스의 서로 이름이 겹치는 멤버가 있다면 파생 클래스의 멤버가 우선시 됨.
        b;   //Daughter::b

        Mother::b;   //중복되는 멤버가 있다면 네임스페이스(::)를 사용하여 구분 가능
        Daughter::b;

        //기반 클래스의 private 멤버는 존재하나 접근이 안됨 자식에서는 protected(권장)이나 public멤버만 접근이 가능하다.
        //return a;   error

        cout << "Daughter" << endl;
        return Mother::GetA();

        //__super 키워드로 부모 클래스 표현 가능, VC전용 키워드
        //return __super::GetA();
    }

private:
    int b;
};

int main()
{
    // 객체를 인스턴스화 할 때 상속받은 클래스가 존재한다면 최상위 클래스 부분부터 생성이 된다.
    // Mother 생성자 호출 -> Daughter 생성자 호출
    Daughter d;

    //기반 클래스에서 물려받은 멤버 함수
    d.SetA(10);

    //기반 클래스와 파생 클래스의 멤버가 겹치는 경우 사라지는게 아니라 기반 클래스의 멤버가 가려진다.
    d.GetA();   //파생 클래스의 GetA()함수가 선택

    cout << "###############" << endl;

    //네임 스페이스를 사용하여 부모 클래스의 가려진 함수 호출 가능
    d.Mother::GetA();

    return 0;
}