// 07_dead_lock.cpp
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

//========================================
// [ dead lock의 문제 확인과 해결 1]
//========================================
//mutex mtx1;
//
//int main() 
//{
//	// =========================
//	// [ 문제 확인 ]
//	// =========================
//	auto worker1 = []()
//	{
//		for (int i = 0; i < 1000; i++)
//		{
//			mtx1.lock();
//
//			// 해당 공간이 해제되기전에 종료되어 공간을 해제하지 못함
//			// -> 해당 공간이나 자원이 풀리기를 무한이 대기함 -> dead lock
//			if (i == 10) return;
//
//			mtx1.unlock();
//		}
//	};
//
//	// =========================
//	// [ 문제 해결 ]
//	// =========================
//	auto solution = []()
//	{
//		for (int i = 0; i < 1000; i++)
//		{
//			/*
//				lock_guard
//				 - 생성자에서 받은 mutex의lock()를 호출
//				 - 소멸자에서 받은 mutex의 unlock()를 호출
//				 - lock_guard가 생성과 소멸이 되면서 스마트 포인터와 같이 mutex를 관리해준다.
//			*/
//			lock_guard<mutex> guard(mtx1);
//			if (i == 10) return;
//		}
//	};	
//	return 0;
//}

//========================================
// [ dead lock의 문제 확인과 해결 2]
//========================================
mutex mtx1;
mutex mtx2;

int main()
{
	// =========================
	// [ 문제 확인 ]
	// =========================
	/*auto worker1 = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			lock_guard<mutex> guard1(mtx1);
			lock_guard<mutex> guard2(mtx2);
		}
	};

	auto worker2 = []()
	{
		for (int i = 0; i < 1000; i++)
		{
			lock_guard<mutex> guard2(mtx2);
			lock_guard<mutex> guard1(mtx1);
		}
	};

	thread t1(worker1);
	thread t2(worker2);
	
	t1.join();
	t2.join();*/

	/*
		실행결과 -> 프로그램이 종료되지 않는다.

		worker1 : mtx1을 lock()하고 mtx2를 lock()한다.
		worker1 : mtx1을 lock()하고 mtx2를 lock()한다.

		이 코드에서 서로가 첫번째 mutex인 mtx1, mtx2를 각각 lock()하게 된다면
		worker1은 mtx2를 lock()하지 못하고 worker2는 mtx1을 lock()하지 못하게 된다.
		서로가 서로의 자원이 unlock() 되기를 무한히 대기함 -> dead lock

		해결 방법 중 하나로는 한 스레드에게 우선권을 주는 방법이 있다.
	*/

	// =========================
	// [ 문제 해결 ]
	// =========================
	auto worker1 = []()
	{
		for (int i = 0; i < 10; i++)
		{
			mtx1.lock();
			mtx2.lock();

			printf("worker1 working\n");

			mtx2.unlock();
			mtx1.unlock();
		}
	};

	auto worker2 = []()
	{
		for (int i = 0; i < 10; i++)
		{
			mtx2.lock();
			if (mtx1.try_lock() == false)
			{
				mtx2.unlock();
				i--;
				continue;
			}	
			printf("worker2 working\n");

			mtx1.unlock();
			mtx2.unlock();
		}
	};

	thread t1(worker1);
	thread t2(worker2);

	t1.join();
	t2.join();

	/*
		문제는 해결하였지만 기아 상태를 발생시킬 수 있다.
		 -> 스레드 사이의 우위가 생겨 한 스레드가 작업을 하고 다른 스레드는 작업을 하지 못하는 상황

		 데드락 상황을 피하기 위한 가이드 라인
		  - 중첩된 lock()을 사용하는 것을 피해라
		    -> 모든 스레드가 lock를 하나만 사용한다면 데드락을 회피할 수 있다.

		  - lock을 소유하고 있을 떄 유저 코드를 호출하는 것을 피해라
		    -> 유저 코드 내부에 lock이 있을 수 있기 때문에 중첩 될 수 있다.

		  - 여러개의 lock()들을 얻어야 한다면 언제나 정해진 순서대로 획득해라
		    -> 위의 우리가 발생한 상황도 lock을 얻는 순서가 서로 달라 생긴 문제이다.
			   만약 정해진 순서대로 받았다면 데드락이 발생하지 않았을 것이다.
	*/
	return 0;
}