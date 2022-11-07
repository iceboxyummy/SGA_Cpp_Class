 // 05_dependencies.cpp

#include <iostream>
#include <chrono> // �ð� ���� ���̺귯��

using namespace std;
using namespace std::chrono;

class Timer {
public:
	Timer() {
		start_time = high_resolution_clock::now(); // now : ����ð� ����
	}

	void Elapsed() {
		auto cuurent_time = high_resolution_clock::now();
		duration<double, std::milli> delta = cuurent_time - start_time;
		// duration<T1, T2> : �ð��� �����ϴ� �ڷ��� T1 ���·� T2������ �ð��� ������

		cout << delta.count() << std::endl; // count :  ������ �ִ� �� ����
	}
private:
	time_point<high_resolution_clock> start_time; // �ð��� �� ������ �����ϴ� �ڷ���

};

class Worker {
public:
	Worker() {

	}

	void DoSomething() {
		// ��������, �ʿ��Ҷ� ���� ����
		Timer timer;
		for (int i = 0; i < 10000000; ++i) {}
		timer.Elapsed();
	}
private:
};

int main() {

	return 0;
}