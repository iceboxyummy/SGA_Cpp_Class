 // 13_virtual_table.cpp

/*
    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1()
                                                       \-func2()

    - virtual 키워드를 붙이면 가상 함수 테이블 생성
    - 호출할 메서드를 동적 바인딩을 통해 결정한다.
    - 오버라이딩하지 않을 메서드를 가상 함수로 지정할 경우 의미 없는 성능 저하를 일으키기 때문에 주의!
*/

#include<iostream>
using namespace std;

class Base
{
public:
    virtual void func1() {}
    virtual void func2() {} // 의미 없는 가상 함수 
};

class Derived : public Base
{
public:
    virtual void func1() {}
};

int main()
{
    Derived d;
 
    return 0;
}
