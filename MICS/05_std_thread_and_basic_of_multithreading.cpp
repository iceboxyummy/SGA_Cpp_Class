 // 05_std_thread_and_basic_of_multithreading.cpp

/*
    Process�� Thread

    - Process
        - � ü������ ����Ǵ� ���α׷��� �ּ� ����
            -> ���� 1���� ���α׷��� 1���� ���μ����� �ǹ��Ѵ�.

        - ���� �ٸ� ���μ��� ������ �޸𸮸� �������� �ʴ´�.
        - ���μ����� CPU �ھ�� ������ �ȴ�.

    - Thread
        - CPU �ھ�� ���ư��� ���α׷� ����
        - CPU�ھ� �ϳ��� �� ���� �� ���� �������� ����� �����Ų��.
        - ���μ����� �ּ� �� �� �̻��� ������� �̷���� ������ �������� �������
        ������ ��� ��Ƽ ������ ���α׷��̶�� �θ���.
        - ���� ���μ��� ���� ��������� ���� �޸𸮸� �����Ѵ�.

    ��Ƽ �����带 ����ϴ� ���
        - �ϳ��� ū �۾��� ����ȭ �Ͽ� ȿ�������� ó��
            -> +1�� 10000�� ����� �Ѵٰ� �� �� �ϳ��� ������� ó���ϴ°� �ƴ�
            ���� �����忡�� �۾��� �������༭ �ϳ��� ó���ϴ°ͺ��� ������ ó��

        - ���� �۾��� ���ÿ� ó���ؾ� �ϴ� ���
            -> �ε��ϴ� ���� ���� ������ �ִϸ��̼ǵ��� �����ִ� ��
            �������� �۾��� ���ÿ� �� �� �ִ�.

    std::thread -> c++ 11

    <Process>

    thread�� ��Ÿ����� �ǹ̸� ������ �־ �������� ������ ǥ���ϱ⵵��

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
// [ ���ó�� ���α׷��� �����ϴ� ��� CPU��뷮 Ȯ���غ��� -> ���� ]
//=====================================================================

/*
int main()
{
    while (true) { cout << "�۾� 1" << endl; }
    while (true) { cout << "�۾� 2" << endl; }
    while (true) { cout << "�۾� 3" << endl; }
    while (true) { cout << "�۾� 4" << endl; }
    while (true) { cout << "�۾� 5" << endl; }
    while (true) { cout << "�۾� 6" << endl; }
    while (true) { cout << "�۾� 7" << endl; }
    while (true) { cout << "�۾� 8" << endl; }
    while (true) { cout << "�۾� 9" << endl; }
    while (true) { cout << "�۾� 10" << endl; }

    return 0;
}
*/

//========================================================
// [ �����带 ����Ͽ� �ѹ��� ���� �۾��� ó�� 1 ]
//========================================================

int main()
{
    // ���� ó�� ������ ������ ���� Ȯ��
    cout << std::thread::hardware_concurrency() << endl; // 4

    // ���� �����ִ� ������ id ���
    cout << std::this_thread::get_id() << endl;

    // ������ ������ ���� �̻����� ������ �����

    // std::thread �����̸�(�Լ� or ����)

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