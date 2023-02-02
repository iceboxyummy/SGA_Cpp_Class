// 07_dead_lock.cpp
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

//========================================
// [ dead lock�� ���� Ȯ�ΰ� �ذ� 1]
//========================================
//mutex mtx1;
//
//int main() 
//{
//	// =========================
//	// [ ���� Ȯ�� ]
//	// =========================
//	auto worker1 = []()
//	{
//		for (int i = 0; i < 1000; i++)
//		{
//			mtx1.lock();
//
//			// �ش� ������ �����Ǳ����� ����Ǿ� ������ �������� ����
//			// -> �ش� �����̳� �ڿ��� Ǯ���⸦ ������ ����� -> dead lock
//			if (i == 10) return;
//
//			mtx1.unlock();
//		}
//	};
//
//	// =========================
//	// [ ���� �ذ� ]
//	// =========================
//	auto solution = []()
//	{
//		for (int i = 0; i < 1000; i++)
//		{
//			/*
//				lock_guard
//				 - �����ڿ��� ���� mutex��lock()�� ȣ��
//				 - �Ҹ��ڿ��� ���� mutex�� unlock()�� ȣ��
//				 - lock_guard�� ������ �Ҹ��� �Ǹ鼭 ����Ʈ �����Ϳ� ���� mutex�� �������ش�.
//			*/
//			lock_guard<mutex> guard(mtx1);
//			if (i == 10) return;
//		}
//	};	
//	return 0;
//}

//========================================
// [ dead lock�� ���� Ȯ�ΰ� �ذ� 2]
//========================================
mutex mtx1;
mutex mtx2;

int main()
{
	// =========================
	// [ ���� Ȯ�� ]
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
		������ -> ���α׷��� ������� �ʴ´�.

		worker1 : mtx1�� lock()�ϰ� mtx2�� lock()�Ѵ�.
		worker1 : mtx1�� lock()�ϰ� mtx2�� lock()�Ѵ�.

		�� �ڵ忡�� ���ΰ� ù��° mutex�� mtx1, mtx2�� ���� lock()�ϰ� �ȴٸ�
		worker1�� mtx2�� lock()���� ���ϰ� worker2�� mtx1�� lock()���� ���ϰ� �ȴ�.
		���ΰ� ������ �ڿ��� unlock() �Ǳ⸦ ������ ����� -> dead lock

		�ذ� ��� �� �ϳ��δ� �� �����忡�� �켱���� �ִ� ����� �ִ�.
	*/

	// =========================
	// [ ���� �ذ� ]
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
		������ �ذ��Ͽ����� ��� ���¸� �߻���ų �� �ִ�.
		 -> ������ ������ ������ ���� �� �����尡 �۾��� �ϰ� �ٸ� ������� �۾��� ���� ���ϴ� ��Ȳ

		 ����� ��Ȳ�� ���ϱ� ���� ���̵� ����
		  - ��ø�� lock()�� ����ϴ� ���� ���ض�
		    -> ��� �����尡 lock�� �ϳ��� ����Ѵٸ� ������� ȸ���� �� �ִ�.

		  - lock�� �����ϰ� ���� �� ���� �ڵ带 ȣ���ϴ� ���� ���ض�
		    -> ���� �ڵ� ���ο� lock�� ���� �� �ֱ� ������ ��ø �� �� �ִ�.

		  - �������� lock()���� ���� �Ѵٸ� ������ ������ ������� ȹ���ض�
		    -> ���� �츮�� �߻��� ��Ȳ�� lock�� ��� ������ ���� �޶� ���� �����̴�.
			   ���� ������ ������� �޾Ҵٸ� ������� �߻����� �ʾ��� ���̴�.
	*/
	return 0;
}