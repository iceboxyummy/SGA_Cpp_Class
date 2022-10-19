 // 12_random_number.cpp

#include<iostream>

// c����
#include<stdlib.h>
#include<time.h>

// c++ ����
#include<random>

int main() {
	{ 
		/* 
			c style ������ ������ : �õ尪�� ���� �ð����� �ϱ� ������ ���� �ð����� ���α׷����� ���� �õ尪�� ������.
			 - %�� ������ �ٿ� ���� ���ϱ� ������ �յ������ʴ�.
			 - rand()��ü�� ���� �˰����� �����ʴ�.
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

		random_device rd; // ���� �Ұ����� ������ �������
		mt19937_64 merssenne(rd()); // ���� ���� ����, �õ尪 �ʱ�ȭ
		// 19937 -> 2�� 199937����

		// ������ Ȯ���� 1 ~ 6�� ������ ����
		uniform_int_distribution<> dice(1, 6);
	
		for (int i = 0; i < 10; i++)
			cout << dice(merssenne) << ",";
	}
	return 0;
}