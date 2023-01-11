// 04_weak_ptr.cpp

/*
	strong reference vs weak reference
	 - strong reference : 메모리 해제에 영향을 미치는 참조, shared_ptr가 포인터를 참조할때 증가
	 - weak reference : 메모리 해제에 영향을 미치지 않는 참조, weak_ptr가 포인터를 참조할때 증가

	weak_ptr
	 - 다른 두 스마트 포인터와 달리 단독으로 사용하지 못하는 스마트 포인터
	 - shared_ptr의 순환 의존성 문제를 해결하기 위해 사용
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
        Circular Dependency Issues : 순환 의존성 문제

        서로가 서로를 참조하는 상황에서 카운팅이 서로에게 물려있어
        서로 지워지길 기다리고 있기 때문에 카운팅이 되지 않고 대기하고 있다. (메모리 누수 문제 발생)
    */

    // 순환 의존성 문제
    {
        // 할당된 Lucy를 스마트 포인터가 Lucy가 소유, 강한참조 횟수 0 -> 1
        auto lucy = std::make_shared<Person>("Lucy");
        // 할당된 Ricky를 스마트 포인터가 Ricky가 소유, 강한참조 횟수 0 -> 1
        auto ricky = std::make_shared<Person>("Ricky");

        // 동적 할당된 Lucy에서 Ricky를 소유
        // 동적 할당된 Ricky에서 Lucy를 소유
        // 서로의 카운트 1->2로 증가
        PartnerUp(lucy, ricky);
    }
    /* 
        스마트 포인터 lucy, ricky 소멸 -> 각각의 카운트 감소 2->1

        하지만 동적 할당된 객체 Lucy, Ricky가 멤버 변수로 서로를 공유 포인터 형태로 참조중임

        1. Lucy가 소멸하기 위해 Ricky가 가진 스마트 포인터가 소멸해야함
        2. Ricky가 가진 스마트 포인터가 소멸하기 위해서는 Ricky가 소멸해야함
        3. Ricky가 소멸하기 위해 Lucy가 가진 스마트 포인터가 소멸해야함
        4. Lucy가 가진 스마트 포인터가 소멸하기 위해서는 Lucy가 소멸해야함
        -> 무한 반복

        서로가 순환 형태로 참조하고 있어 순환 의존성 문제라고 부름
        -> 서로를 소유할 때 weak_ptr로 소유하여 문제 해결 가능
    */

    // weak_ptr 사용
    {
        auto test = std::make_shared<Person>("Test");
        std::weak_ptr<Person> weak = test;

        cout << endl << "1----------------------------" << endl;

        // 같은 표현
        test.reset();
        //test = nullptr;

        if (weak.expired() == true)
            cout << "유효하지 않음" << endl;
        else
            cout << "유효함" << endl;
        cout << endl << "2----------------------------" << endl;

        /*
            weak_ptr 형태로는 사용이 안되고 shared_ptr로 바꾸어 사용해야 한다.
             -> 멀티 스레드 환경에서 weak_ptr을 사용할 때 먼저 shared_ptr이 전부 해제되어 weak_ptr이 
                참조한 데이터가 소멸하는 것을 막기위해 사용전에 최소 1의 강한 참조를 확보하기 위함
        */

        // weak-> // error
        weak.lock() -> GetName();
    }

    // 추가적인 스마트 포인터 사용법 + 주의점
    {
        auto test1 = std::make_shared<Person>("Test1");
        auto test2 = std::make_shared<Person>("Test2");

        // 1. 스왑 가능
        test1.swap(test2);

        // 2. 해당 스마트 포인터의 날 포인터 비우기, 해당 스마트 포인터의 소유권만 포기한다,
        //   -> 해당 주소를 참조하는 모든 스마트 포인터에서 해제해주는것 x
        test1.reset();

        // 3. 스마트 포인터의 캐스팅

        // 일반적인 캐스팅과 같이 업 캐스팅, 다운 캐스팅이 가능
        // 암시적, 명시적 형변환 가능

        // 암시적 형변환 가능
        std::shared_ptr<Person> parent = std::make_shared<Test>("Test");

        // 명시적 형변환 가능, 캐스팅은 전용 함수를 통해서 처리한다.
  
        std::shared_ptr<Person> child = std::static_pointer_cast<Test>(parent);

        // 4. 스마트 포인터에서 null체크 방법

        // 일반 포인터와 같이 체크가능
        if (test1 == nullptr);
        if (!test1 == false);
    }
    return 0;
}