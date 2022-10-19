 // 12_random_number.cpp

#include<iostream>

// c난수
#include<stdlib.h>
#include<time.h>

// c++ 난수
#include<random>

int main() {
	{ 
		/* 
			c style 난수의 문제점 : 시드값을 현재 시간으로 하기 때문에 같은 시간대의 프로그램들은 같은 시드값을 가진다.
			 - %로 범위를 줄여 값을 구하기 때문에 균등하지않다.
			 - rand()자체의 난수 알고리즘이 좋지않다.
		*/

		/*
			0 ~ 5
			%4
			0 : 0, 4
			1 : 1, 
			2 : 2
			3 : 3
		*/

		srand((unsigned int)time(NULL));

		for (int i = 0; i < 10; i++)
			printf("%d, ", rand() % 10);
		printf("\n");
	}

	{	//c++ style

		using namespace std;

		random_device rd; // 예측 불가능한 난수를 만들어줌
		mt19937_64 merssenne(rd()); // 난수 생성 엔진, 시드값 초기화
		// 19937 -> 2의 199937제곱

		// 동일한 확률로 1 ~ 6이 나오게 정의
		uniform_int_distribution<> dice(1, 6);
	
		for (int i = 0; i < 10; i++)
			cout << dice(merssenne) << ",";
	}
	return 0;
}