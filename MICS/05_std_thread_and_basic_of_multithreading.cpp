 // 05_std_thread_and_basic_of_multithreading.cpp

/*
    Process와 Thread

    - Process
        - 운영 체제에서 실행되는 프로그램의 최소 단위
            -> 보통 1개의 프로그램은 1개의 프로세스를 의미한다.

        - 서로 다른 프로세스 끼리는 메모리를 공유하지 않는다.
        - 프로세스는 CPU 코어에서 실행이 된다.

    - Thread
        - CPU 코어에서 돌아가는 프로그램 단위
        - CPU코어 하나당 한 번에 한 개의 쓰레드의 명령을 실행시킨다.
        - 프로세스는 최소 한 개 이상의 쓰레드로 이루어져 있으며 여러개의 쓰레드로
        구성될 경우 멀티 쓰레드 프로그램이라고 부른다.
        - 같은 프로세스 내의 쓰레드들은 서로 메모리를 공유한다.

    멀티 스레드를 사용하는 경우
        - 하나의 큰 작업을 병렬화 하여 효율적으로 처리
            -> +1을 10000번 해줘야 한다고 할 때 하나의 스레드로 처리하는게 아닌
            여러 스레드에게 작업을 분할해줘서 하나가 처리하는것보다 빠르게 처리

        - 여러 작업을 동시에 처리해야 하는 경우
            -> 로딩하는 동안 게임 정보나 애니메이션등을 보여주는 등
            여러개의 작업을 동시에 할 수 있다.

    std::thread -> c++ 11

    <Process>

    thread가 실타래라는 의미를 가지고 있어서 찌글찌글한 선으로 표기하기도함

    main thread
        *
        |
        |            thread 0
        *----------------*
        |                |
        |                |                thread 1
        *---------------------------------------*
        |                |                      |
        |                |                      |                    thread 2
        *-------------------------------------------------------------------*
        |                |                      |                           |
        |                |                      |                           |
        |                |                      |                           |
        |                |                      |                           |
        *----------------*                      |                           |
        |                                       |                           |
        *---------------------------------------*                           |
        |                                                                   |
        *-------------------------------------------------------------------*
        |
        *
*/

#include<iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

//=====================================================================
// [ 평소처럼 프로그램을 실행하는 경우 CPU사용량 확인해보기 -> 성능 ]
//=====================================================================

/*
int main()
{
    while (true) { cout << "작업 1" << endl; }
    while (true) { cout << "작업 2" << endl; }
    while (true) { cout << "작업 3" << endl; }
    while (true) { cout << "작업 4" << endl; }
    while (true) { cout << "작업 5" << endl; }
    while (true) { cout << "작업 6" << endl; }
    while (true) { cout << "작업 7" << endl; }
    while (true) { cout << "작업 8" << endl; }
    while (true) { cout << "작업 9" << endl; }
    while (true) { cout << "작업 10" << endl; }

    return 0;
}
*/

//========================================================
// [ 스레드를 사용하여 한번에 여러 작업을 처리 1 ]
//========================================================

/*
int main()
{
    // 동시 처리 가능한 스레드 개수 확인
    cout << std::thread::hardware_concurrency() << endl; // 4

    // 현재 돌고있는 스레드 id 출력
    cout << std::this_thread::get_id() << endl;

    // 본인의 스레드 개수 이상으로 스레드 만들기

    // std::thread 변수이름(함수 or 람다)

    std::thread t1 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t2 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t3 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t4 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t5 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );

    std::thread t6 = std::thread(
        []()
        {
            cout << "ID : " << std::this_thread::get_id() << endl;
            while (true) {}
        }
    );
    
    출력후 결과1
    - 에러가 발생함
        -> 스레드가 join 이나 detach가 되지않은 상태에서 소멸자가
        호출이 되면 예외를 발생시키도록 되어있다.
    
    join : 해당 스레드가 실행을 종료하면 리턴하는 함수.
    -> 해당 스레드가 종료될때까지 대기한다.
    
    detach : 해당 스레드를 잊어버리는 것, 스레드가 종료되기를 기다리지 않고 프로그램을 진행한다.
    -> 이럴경우 해당 스레드는 알아서 백그라운드에서 돌아가게 된다.
    
    출력후 결과2
    - ID가 출력이 되는데 이상하게 출력이 된다.
        -> cout은 "cout << A" 처럼 하나의 데이터를 출력할 때는 다른 스레드가 접근하지 못하게 막지만
        "cout << A << B" 인 상황에는 A를 출력하고 B를 출력하기전에 다른 스레드가 접근할 수 있다.
        이 문제를 해결하기 위해서는 printf()를 사용하면 된다. printf()는 자신의 모든 문자열을 출력하기
        전까지는 다른 스레드가 접근하지 못하게 막기 때문이다.
    
    출력후 결과3
    - 작업 관리자에서 CPU 사용률을 보면 100%가 나온다.
        -> 현재 CPU가 한번에 처리할 수 있는 스레드의 개수만큼 만들어 동작했기 때문
        

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    t5.detach();
    t6.detach();

    return 0;
}
*/

//========================================================
// [ 스레드를 사용하여 한번에 여러 작업을 처리 2 ]
//========================================================

int main()
{
    auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            printf("%s %d : is working %d\n", name.c_str(), std::this_thread::get_id(), i);
        }
    };

    // 하나의 작업이 끝날떄까지 다음 작업은 대기해야함 -> 효율 하락
    //work_func("A");
    //work_func("B");
    
    std::thread t1 = std::thread(work_func, "A");
    std::thread t2 = std::thread(work_func, "B");

    t1.join();
    t2.join();

    return 0;
}
