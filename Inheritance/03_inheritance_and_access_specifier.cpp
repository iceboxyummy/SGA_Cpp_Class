 // 03_inheritance_and_access_specifier.cpp

/*
   ��� ���� ������ : ��� Ŭ������ �Ļ� Ŭ������ ��� ������ �� ����ϴ� �����ڰ� ��� ���� ������.
    - ��� ���� �����ڰ� ��� Ŭ������ ����� ���� �����ں��� ���� ���ѵ� ���� ������ ���, ��� ���� �����ڷ� ����ȴ�.
    - private����� ����� ������ ��� �Ļ� Ŭ�������� ���������� �Ұ����ϴ�.

   ��� ���� ������  |    ��� Ŭ����     |    �Ļ�Ŭ����
  ------------------|-------------------|----------------
   public           |     public        |    public
                    |     protected     |    protected
                    |     private       |    ���� �Ұ�
                    |                   |
   protected        |     public        |    protected
                    |     protected     |    protected
                    |     private       |    ���� �Ұ�
                    |                   |
   private          |     public        |     private
                    |     protected     |     private
                    |     private       |     ���� �Ұ�
*/

#include <iostream>
using namespace std;

class Base 
{
public: // ��� �������� ���ٰ���
    void Test(){}
    int public_data;

protected: // �ڽ� / �Ļ� Ŭ���������� ���� ����
    int protected_data;

private: // �ڽ� Ŭ���������� ���ٰ���
    int private_data;
};

// ��� Ŭ������ ��� ���� �����ڸ� ��� private���� ����
class Derived : private Base
{
public:
    Derived()
    {
        // private_data; ��ӹ��� private ����� ���� �Ұ�
        // 
        // �Ʒ� ������� ��� ���� �����ڿ� ���� private��� �ٲ�
        Test();
        public_data;
        protected_data;
    }
};

// Derived�� Base�� ����� private���·� �޾ұ� ������ ��� ���� �����ڸ� public�� �����Ͽ��� �ǹ̰� ����.
// -> ��� ���� �����ڰ� �� ������ ���ѵ� ��쿡�� ������ �Ǳ� �����̴�.
class A : public Derived
{
public:
    A()
    {
        // private ����� ��� �޾� ���� �Ұ���
        Test();
        public_data;
        protected_data;
        private_data;
    }
};

int main() {

    Base base;

    // �ܺο��� ���� ���� public
    base.Test();
    base.public_data;

    // �ܺο��� ���� �Ұ��� protected, private
    base.protected_data;
    base.private_data;

    // ��� �����ڸ� ��� private���� �޾� 
    // �ܺο��� ���� �Ұ���
    A a;

    a.Test();
    a.public_data;
    a.protected_data;
    a.private_data;

	return 0;
}