// 06_race_condition.cpp

#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<atomic>
using namespace std;

//==========================================
// [ race condition ���� Ȯ��]
//==========================================

//int shared_memory;
//
//int main()
//{
//	auto count_func = []()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			//std::this_thread::sleep_for(chrono::milliseconds(1));
//			++shared_memory;
//		}
//	};
//
//	thread t1 = thread(count_func);
//	thread t2 = thread(count_func);
//
//	t1.join();
//	t2.join();
//
//	cout << "Result : " << shared_memory << endl;
//
//	/*
//		������ ������ �� ���� ���� ������ �ȴ�.
//		 -> �̰� �ٸ� ��������� ���� �ڿ��� ������ �� �������� �޶����� ������ �߻�
//		 -> �̰� ���� ����(race condition)���θ���.
//	*/
//}

//==========================================
// [ race condition ���� �ذ� : mutex]
//==========================================
/*
	mutex 
	 -Ư�� ������ ��� �ѹ��� �� �����常 ������ �� �ֵ��� �Ѵ�.
	 -�ش������ �Ӱ迵���̶�� �θ���.
*/

//int shared_memory;
//mutex mtx; // Ư�� ������ ��� �� �ִ�mutex
//
//int main()
//{
//	auto count_func = []()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			// lock() : �� �����尡 lock()�Լ��� ȣ���� ������ ��� �ٸ� �����尡 ������ �۾��� �������� ���ϵ��� �Ѵ�.
//			mtx.lock();
//			{// critical section : �Ӱ迵�� -> �ϳ��� �����常 ���� �ִ� ����
//				++shared_memory;
//			}
//			// unlock() : �� �����尡 unlock()�Լ��� ȣ���� ������ �ٽ� Ǯ���־� �ٸ� �����尡 �ش� ������ �����ϵ��� ����Ѵ�.
//			mtx.unlock();
//		}
//	};
//
//	thread t1 = thread(count_func);
//	thread t2 = thread(count_func);
//
//	t1.join();
//	t2.join();
//
//	// ���� ����� ����� �ȴ�.
//	cout << "Result : " << shared_memory << endl;
//
//	return 0;
//}

//==========================================
// [ race condition ���� �ذ� : atomic]
//==========================================
/*
	atomic
	 - �����尡 Ư�� �����͸� ���ÿ� �������� ���ϵ��� ���´�.
	 - atomic���� ���� �����ʹ� atomic���� �����ǵ� �����ڸ� ��� -> ����
	 - �ݺ������� ȣ��Ǵ� �����Ϳ� ����ϸ� ������ ���� �� �� �ִ�.
*/

atomic <int> shared_memory;

int main()
{
	auto count_func = []()
	{
		for (int i = 0; i < 100000; i++)	
			{
				++shared_memory;
			}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "Result : " << shared_memory << endl;

	return 0;
}