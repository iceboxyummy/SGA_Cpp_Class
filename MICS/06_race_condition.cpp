// 06_race_condition.cpp

#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<atomic>
using namespace std;

//==========================================
// [ race condition 문제 확인]
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
//		예상한 값보다 더 적은 값이 나오게 된다.
//		 -> 이걸 다른 스레드들이 같은 자원에 접근할 때 실행결과가 달라지는 문제가 발생
//		 -> 이걸 경쟁 상태(race condition)라고부른다.
//	*/
//}

//==========================================
// [ race condition 문제 해결 : mutex]
//==========================================
/*
	mutex 
	 -특정 공간을 잠궈 한번에 한 스레드만 접근할 수 있도록 한다.
	 -해당공간을 임계영역이라고 부른다.
*/

//int shared_memory;
//mutex mtx; // 특정 공간을 잠글 수 있는mutex
//
//int main()
//{
//	auto count_func = []()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			// lock() : 한 스레드가 lock()함수를 호출해 공간을 잠궈 다른 스레드가 이후의 작업에 접근하지 못하도록 한다.
//			mtx.lock();
//			{// critical section : 임계영역 -> 하나의 스레드만 들어갈수 있는 공간
//				++shared_memory;
//			}
//			// unlock() : 한 스레드가 unlock()함수를 호출해 공간을 다시 풀어주어 다른 스레드가 해당 공간에 접근하도록 허용한다.
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
//	// 값이 제대로 출력이 된다.
//	cout << "Result : " << shared_memory << endl;
//
//	return 0;
//}

//==========================================
// [ race condition 문제 해결 : atomic]
//==========================================
/*
	atomic
	 - 스레드가 특정 데이터를 동시에 접근하지 못하도록 막는다.
	 - atomic으로 만든 데이터는 atomic에서 재정의된 연산자를 사용 -> 느림
	 - 반복적으로 호출되는 데이터에 사용하면 성능이 저하 될 수 있다.
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