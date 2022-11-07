 // 05_dependencies.cpp

#include <iostream>
#include <chrono> // 시간 관련 라이브러리

using namespace std;
using namespace std::chrono;

class Timer {
public:
	Timer() {
		start_time = high_resolution_clock::now(); // now : 현재시간 리턴
	}

	void Elapsed() {
		auto cuurent_time = high_resolution_clock::now();
		duration<double, std::milli> delta = cuurent_time - start_time;
		// duration<T1, T2> : 시간을 저장하는 자료형 T1 형태로 T2단위의 시간을 저장함

		cout << delta.count() << std::endl; // count :  가지고 있는 값 리턴
	}
private:
	time_point<high_resolution_clock> start_time; // 시간의 한 지점을 저장하는 자료형

};

class Worker {
public:
	Worker() {

	}

	void DoSomething() {
		// 의존관계, 필요할때 쓰고 버림
		Timer timer;
		for (int i = 0; i < 10000000; ++i) {}
		timer.Elapsed();
	}
private:
};

int main() {

	return 0;
}