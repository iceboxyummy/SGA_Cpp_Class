 // 02_iterator.cpp

/*
	iterator(�ݺ���) : �����̳� ���ҿ� ������ �� �ִ� �����Ϳ� ���� ��ü
	 - �ݺ��ڸ� ����Ͽ� �����̳��� Ÿ�Կ� ������� �˰����� ����� �� �ִ�.
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

		std::vector<int>::iterator iter; // iterator�� �ڷ���
		iter = container.begin(); // begin() : �����̳��� ù���� ���Ҹ� ����Ű�� �ݺ��� ��ȯ

		while (iter != container.end()) // end() : �����̳��� ���������� �� ĭ �ڸ� ����Ű�� �ݺ��� ��ȯ
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
	// �ڵ尡 �Ϲ�ȭ�Ǿ� �־� �ٸ� �����̳ʳ� �ڷ����� �ٲ� �� ������ ����.
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
	// �����ϴ� �κ��� insert()�θ� �ٲٸ� �����ϴ�.
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
	// set���� pair���·� �ٲ��.
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