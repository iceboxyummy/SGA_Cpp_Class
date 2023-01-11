// 04_weak_ptr.cpp

/*
	strong reference vs weak reference
	 - strong reference : �޸� ������ ������ ��ġ�� ����, shared_ptr�� �����͸� �����Ҷ� ����
	 - weak reference : �޸� ������ ������ ��ġ�� �ʴ� ����, weak_ptr�� �����͸� �����Ҷ� ����

	weak_ptr
	 - �ٸ� �� ����Ʈ �����Ϳ� �޸� �ܵ����� ������� ���ϴ� ����Ʈ ������
	 - shared_ptr�� ��ȯ ������ ������ �ذ��ϱ� ���� ���
*/

#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Person
{
public:
    Person(const string& name) : name(name)
    {
        cout << name << " created" << endl;
    }

    ~Person()
    {
        cout << name << " destroyed" << endl;
    }

    const string& GetName() const { return name; }

    friend bool PartnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (!p1 == true || !p2 == true)
            return false;

        p1->partner = p2;
        p2->partner = p1;

        cout << p1->name << " is partnered with " << p2->name << endl;

        return true;
    }

private:
    std::string name;
    //std::shared_ptr<Person> partner;
    std::weak_ptr<Person> partner;
};

class Test : public Person
{
public:
    Test(const std::string& name)
        : Person(name)
    {}
};

int main()
{
    /*
        Circular Dependency Issues : ��ȯ ������ ����

        ���ΰ� ���θ� �����ϴ� ��Ȳ���� ī������ ���ο��� �����־�
        ���� �������� ��ٸ��� �ֱ� ������ ī������ ���� �ʰ� ����ϰ� �ִ�. (�޸� ���� ���� �߻�)
    */

    // ��ȯ ������ ����
    {
        // �Ҵ�� Lucy�� ����Ʈ �����Ͱ� Lucy�� ����, �������� Ƚ�� 0 -> 1
        auto lucy = std::make_shared<Person>("Lucy");
        // �Ҵ�� Ricky�� ����Ʈ �����Ͱ� Ricky�� ����, �������� Ƚ�� 0 -> 1
        auto ricky = std::make_shared<Person>("Ricky");

        // ���� �Ҵ�� Lucy���� Ricky�� ����
        // ���� �Ҵ�� Ricky���� Lucy�� ����
        // ������ ī��Ʈ 1->2�� ����
        PartnerUp(lucy, ricky);
    }
    /* 
        ����Ʈ ������ lucy, ricky �Ҹ� -> ������ ī��Ʈ ���� 2->1

        ������ ���� �Ҵ�� ��ü Lucy, Ricky�� ��� ������ ���θ� ���� ������ ���·� ��������

        1. Lucy�� �Ҹ��ϱ� ���� Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ���
        2. Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ��ϱ� ���ؼ��� Ricky�� �Ҹ��ؾ���
        3. Ricky�� �Ҹ��ϱ� ���� Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ���
        4. Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ��ϱ� ���ؼ��� Lucy�� �Ҹ��ؾ���
        -> ���� �ݺ�

        ���ΰ� ��ȯ ���·� �����ϰ� �־� ��ȯ ������ ������� �θ�
        -> ���θ� ������ �� weak_ptr�� �����Ͽ� ���� �ذ� ����
    */

    // weak_ptr ���
    {
        auto test = std::make_shared<Person>("Test");
        std::weak_ptr<Person> weak = test;

        cout << endl << "1----------------------------" << endl;

        // ���� ǥ��
        test.reset();
        //test = nullptr;

        if (weak.expired() == true)
            cout << "��ȿ���� ����" << endl;
        else
            cout << "��ȿ��" << endl;
        cout << endl << "2----------------------------" << endl;

        /*
            weak_ptr ���·δ� ����� �ȵǰ� shared_ptr�� �ٲپ� ����ؾ� �Ѵ�.
             -> ��Ƽ ������ ȯ�濡�� weak_ptr�� ����� �� ���� shared_ptr�� ���� �����Ǿ� weak_ptr�� 
                ������ �����Ͱ� �Ҹ��ϴ� ���� �������� ������� �ּ� 1�� ���� ������ Ȯ���ϱ� ����
        */

        // weak-> // error
        weak.lock() -> GetName();
    }

    // �߰����� ����Ʈ ������ ���� + ������
    {
        auto test1 = std::make_shared<Person>("Test1");
        auto test2 = std::make_shared<Person>("Test2");

        // 1. ���� ����
        test1.swap(test2);

        // 2. �ش� ����Ʈ �������� �� ������ ����, �ش� ����Ʈ �������� �����Ǹ� �����Ѵ�,
        //   -> �ش� �ּҸ� �����ϴ� ��� ����Ʈ �����Ϳ��� �������ִ°� x
        test1.reset();

        // 3. ����Ʈ �������� ĳ����

        // �Ϲ����� ĳ���ð� ���� �� ĳ����, �ٿ� ĳ������ ����
        // �Ͻ���, ����� ����ȯ ����

        // �Ͻ��� ����ȯ ����
        std::shared_ptr<Person> parent = std::make_shared<Test>("Test");

        // ����� ����ȯ ����, ĳ������ ���� �Լ��� ���ؼ� ó���Ѵ�.
  
        std::shared_ptr<Person> child = std::static_pointer_cast<Test>(parent);

        // 4. ����Ʈ �����Ϳ��� nullüũ ���

        // �Ϲ� �����Ϳ� ���� üũ����
        if (test1 == nullptr);
        if (!test1 == false);
    }
    return 0;
}