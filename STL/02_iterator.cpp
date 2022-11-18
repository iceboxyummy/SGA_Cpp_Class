 // 02_iterator.cpp

/*
	iterator(반복자) : 컨테이너 원소에 접근할 수 있는 포인터와 객은 객체
	 - 반복자를 사용하여 컨테이너의 타입에 상관없이 알고리즘을 사용할 수 있다.
*/

#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main() {

	// vector
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		std::vector<int>::iterator iter; // iterator의 자료형
		iter = container.begin(); // begin() : 컨테이너의 첫번쨰 원소를 가리키는 반복자 반환

		while (iter != container.end()) // end() : 컨테이너의 마지막원소 한 칸 뒤를 가리키는 반복자 반환
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	// list
	// 코드가 일반화되어 있어 다른 컨테이너나 자료형을 바꿀 때 수정이 적다.
	{
		list<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		std::list<int>::iterator iter;
		iter = container.begin();

		while (iter != container.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	// set
	// 삽입하는 부분을 insert()로만 바꾸면 가능하다.
	{
		set<int> container;
		for (int i = 0; i < 10; i++)
			container.insert(i);

		std::set<int>::iterator iter;
		iter = container.begin();

		while (iter != container.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

	// map
	// set에서 pair형태로 바뀐다.
	{
		map<int,char> container;
		for (int i = 0; i < 10; i++)
			container.insert(make_pair(i, i + 32));

		std::map<int, char>::iterator iter;
		iter = container.begin();

		while (iter != container.end())
		{
			cout << iter->first << " " << iter->second << endl;
			++iter;
		}
		cout << endl;

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << iter->first << " " << iter->second << endl;
		cout << endl;
	}
	return 0;
}