// 03_algorithm.cpp

// algorithm Library : 컨테이너 반복자를 사용하여 여러 작업을 쉽게 수행하게 도와주는 라이브러리

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<random>

using namespace std;
random_device rd;
mt19937_64 mt(rd());

int main() {
	//vector<int> container;
	list<int> container;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	// 셔플함수
	// shuffle(container.begin() + 3, container.end(), mt); list는 셔플 지원x

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 범위안에서 최솟값 탬색
	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	// 범위안에서 최댓값 탬색
	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	// 원하는 데이터를 가지는 원소 탐색
	iter = find(container.begin(), container.end(), 7);

	// 퀵정렬
	// sort(container.begin(), container.end()); list는 내부적으로 sort함수를 가지고 있어서 지원ㅌ
	container.sort(); // list의 sort

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	return 0;
}