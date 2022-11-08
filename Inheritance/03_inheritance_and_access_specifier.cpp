 // 03_inheritance_and_access_specifier.cpp

/*
   상속 접근 지정자 : 기반 클래스를 파생 클래스에 상속 시켜줄 때 사용하는 지정자가 상속 접근 지정자.
    - 상속 접근 지정자가 기반 클래스의 멤버의 접근 지정자보다 더욱 제한된 접근 권한일 경우, 상속 접근 지정자로 변경된다.
    - private멤버는 상속을 시켜줄 경우 파생 클래스에서 직접접근이 불가능하다.

   상속 접근 지정자  |    기반 클래스     |    파생클래스
  ------------------|-------------------|----------------
   public           |     public        |    public
                    |     protected     |    protected
                    |     private       |    접근 불가
                    |                   |
   protected        |     public        |    protected
                    |     protected     |    protected
                    |     private       |    접근 불가
                    |                   |
   private          |     public        |     private
                    |     protected     |     private
                    |     private       |     접근 불가
*/

#include <iostream>
using namespace std;

class Base 
{
public: // 모든 영역에서 접근가능
    void Test(){}
    int public_data;

protected: // 자신 / 파생 클래스에서만 접근 가능
    int protected_data;

private: // 자신 클래스에서만 접근가능
    int private_data;
};

// 기반 클래스의 멤버 접근 지정자를 모두 private으로 변경
class Derived : private Base
{
public:
    Derived()
    {
        // private_data; 상속받은 private 멤버는 접근 불가
        // 
        // 아래 멤버들이 상속 접근 지정자에 의해 private멤버 바뀜
        Test();
        public_data;
        protected_data;
    }
};

// Derived가 Base의 멤버를 private형태로 받았기 때문에 상속 접근 지정자를 public로 지정하여도 의미가 없다.
// -> 상속 접근 지정자가 더 접근이 제한된 경우에만 변경이 되기 때문이다.
class A : public Derived
{
public:
    A()
    {
        // private 멤버를 상속 받아 접근 불가능
        Test();
        public_data;
        protected_data;
        private_data;
    }
};

int main() {

    Base base;

    // 외부에서 접근 가능 public
    base.Test();
    base.public_data;

    // 외부에서 접근 불가능 protected, private
    base.protected_data;
    base.private_data;

    // 상속 지정자를 모두 private으로 받아 
    // 외부에서 접근 불가능
    A a;

    a.Test();
    a.public_data;
    a.protected_data;
    a.private_data;

	return 0;
}