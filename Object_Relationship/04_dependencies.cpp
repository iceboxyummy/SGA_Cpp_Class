 // 04_dependencies.cpp

#include <iostream>
#include <chrono> // �ð� ���� ���̺귯��

using namespace std;
using namespace std::chrono;

class Timer
{
public:
	Timer() {
		start_time = high_resolution_clock::now(); // now : ����ð� ����
	}

	void Elapsed() {
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli> delta = current_time - start_time;
		// duration<T1, T2> : �ð��� �����ϴ� �ڷ��� T1 ���·� T2������ �ð��� ������
		start_time = current_time;

		cout << delta.count() << std::endl; // count :  ������ �ִ� �� ����
	}
private:
	time_point<high_resolution_clock> start_time; // �ð��� �� ������ �����ϴ� �ڷ���

};

class Worker 
{
public:
	void DoSomething() 
	{
		// ���� : �ʿ��Ҷ��� ������ ���� ����
		Timer timer;
		for (int i = 0; i < 100'000'000; i++) ;
		timer.Elapsed();
	}
};

int main() {
	Worker w;
	w.DoSomething();

	return 0;
}