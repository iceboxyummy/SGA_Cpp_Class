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

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    t1.detach();

    return 0;
}