 // 01_stl_and_container.cpp

/*
	STL
	 - �����̳�(Container), �ݺ���(iterator), �˰���(algorithm)�� ���ԵǾ��ִ�.
	    * �����̳�(Container) : ���� Ÿ���� �����͸� ������ �� �ִ�.
	    * �ݺ���(iterator) : �����̳ʿ� ������ ���ҿ� ������ �� ����Ѵ�.
	    * �˰���(algorithm) : �ݺ��ڵ��� ������ �Ϸ��� �۾��� �����Ѵ�.
	 - ���ø��� ����Ͽ� ��� Ÿ���� �����͵� ���� ���̺귯�� ����� ����� �� �ִ�.
	  => �ڷ����� �Ϲ�ȭ�Ͽ� �ڵ��� �������� ������ �۾��� ������ �� �ְ� ���ش�.

*/

/*
	�����̳�(Container) : ������ Ÿ���� ���� ��ü�� �����ϴ� ����, ����Ҹ� ���Ѵ�.
	 - ���ø��� ����� �����ϴ� �������� �ڷ����� �����ϰ� �����̵� �� ���ְ� ������� �ִ�.
	 - 3���� ������ �����̳ʷ� �̷���� �ִ�.
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

void Sequence_Container();
void Associative_Container();
void Container_Adapter();

int main() {
	Sequence_Container();
	Associative_Container();
	Container_Adapter();

	return  0;
}

void Sequence_Container()
{
	// SequenceContainer : �迭ó�� �����͸� �������� �����ϴ� �����̳�, Ư���� ��Ģ�̳� ������� ���Ҹ� �����Ѵ�.

	/*
		Vector : ���� ���� �迭, ���� �迭�� ���ø�ȭ�� ��
		 - ���Ұ� ���� �޸𸮿� ���������� ����Ǿ��־� �������� �����͸� ó���ϱ⿡ �����ϴ�.
		 - ���� ������ �����Ѵ�. [], at()
		 - �Ҵ�� ������ �� ä���� ���, ���ο� ū ������ �������� ���Ҵ��Ͽ� ������ ���ҵ��� �����Ѵ�.
		 - �� �ڿ� ���Ҹ� ����, �����Ҷ��� ������. 
		   ������ ��ġ�� �ִ� ���Ҹ� ����, �����ϴ� ���, �� ���� ���Ҹ� ��ĭ�� �̵������־�� �ϱ� ������ ������.

		  * ����ϱ� ���� ���
		   - ũ�⸦ ������ ������ ��
		   - ����, ������ ���� ���� ��
		   - �������� ������ ó���� �ʿ��� �� 
	*/
	{
		vector<int> vec; // template�̸� template Ŭ������ ������� ��ü(�迭ó�� �������� �޸𸮸� ������ ����)

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		Dequeue : ���Ϳ� ����ϳ� ���Ұ� �޸� ������ ���������� ���� ���� �ʴ´�.
		 - �޸𸮸� ���Ҵ��� ��, �߰��� �޸� ������ ����� �������� �̾���δ�. -> �������Ҵ��� ������
		 - ���� �������ִ� �޸� ������ ������ �����ϱ� ���� ���ͺ��� �߰����� �޸𸮰� �ʿ��ϴ�.
		 - ������ ��ġ�� �ִ� ������ ����, ������ ���ͺ��� ������.
		 - ���� ������ �����Ѵ�. [], at()

		   * ����ϱ� ���� ��
		    - �� �հ� �� ���� ���Ҹ� ����, �����ϴ� ��찡 ���� ���
			- ����ó�� ����ϰ� ������ ũ�Ⱑ ������ �ȵǴ� ���
	*/
	{
		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		List : ����� ���Ḯ��Ʈ�� ���ø�ȭ
		 - ����Ʈ�� ���� ������ �ּҿ� ������ ������ ��ġ���� ����Ѵ�.
		 - ������ ���Ұ� �ڽ��� �հ� �ڿ� ���� ���Ҹ� ����Ű�� �ִ�.
		 - �������� 
		     ->, <- �� �����ͷ� �հ� ���� ������ �ּҸ� �����ϰ� �ִ�.

				������        ������        ������
				������   ->   ������   ->   ������  
				���Ҥ�        ���Ҥ�        ���Ҥ�
				��1 ��   <-   ��2 ��   <-   ��3 �� 
				������        ������        ������

		 - ���� ������ �������־� ������ ��ġ�� �ִ� ���ҿ� �ٷ� ������ �ȵǰ� ���������� �����ؾ��Ѵ�.
		 - ������ ���� ������ �Ͼ ��� ��ũ�� �ٲپ��ָ� �Ǳ⿡ ���� ������ ������.

		   * ����ϱ� ������
		     - ������ ����, ������ ����ϰ� �̷������
			 - ���ҵ��� ���������θ� �����ҋ�
	*/
	{
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);


		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl;
	}
}

void Associative_Container()
{
	/*
		associactive container : �����͸� ������ ��Ģ�� ���� �����ϰ� �����ϴ� �����̳�
		 - ������ ����� ��ġ�� ������ �� ���� ���� ���� Ʈ���� �ؽ����̺��� �̿��Ͽ� �����Ѵ�.
		 - ���Ҹ� ������ ��� �������� �������ֱ� ������ ���ϴ� ���Ҹ� ã�� �˻� �ӵ��� ������.
		 - Ű(key) - ��(value) ������ ���� Ư���� Ű���� ������ �����ϴ� ���� �����ش�.
	*/

	/*
		set�� multiset : �����ϴ� �����Ͱ� �� ��ü�� Ű�� ����Ѵ�.
		 - �������� �������� �� üũ�ϴ°�� ����Ѵ�.
	*/

	// set : Ű�� �ߺ��� ������� �ʴ´�.
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("World");

		// �� ���� ��µȴ�.
		//  set�� �ߺ��� ������� �ʱ� ������ �ߺ��� �����͸� ������ ��� �����Ѵ�.
		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	// multiset : Ű�� �ߺ��� ����Ѵ�
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("World");

		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;		
	}

	/*
		map�� multimap : Ű�� ������ �����͸� �����Ѵ�.
		 - map�� �ߺ��� ������� ������ multimap�� �ߺ��� ����� �ϳ��� Ű�� ���� ���� ����� �� �ִ�.
	*/

	// map : key / value - pair
	{
		map<char, int> map; // mapping : ������Ų��.
		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl; // Ű���� ���ε� �� 10���

		map['a'] = 100;
		cout << map['a'] << endl; // ���ο� ������ �ʱ�ȭ �Ѵ�.

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	// multimap
	{
		multimap<char, int>multimap;
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		multimap.insert(pair<char, int>('a', 10000));
		// multimap.insert(pair('c', 500));  c++17������ Ÿ�� ��������

		cout << multimap.count('a') << endl;

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	/*
		unordered associative container : ���ĵ��� ���� ���� �����̳�
		- ���� ���� �����̳ʴ� Ʈ���� ��������� ���ĵ��� ���� ���Ҹ� ������ �� �ؽ� ���̺��� ����Ѵ�.
		- ����, ����, �˻� ��� ������.
		
		- unordered_set
		- unordered_multiset
		- unordered_map
		- unordered_multimap
	*/
}

void Container_Adapter()
{
	/*
		adapter container : ���� �����̳��� �������̽��� �����Ͽ� ����� ����� ���ѵǰų� ������ �����̳�
		 - ������ ���ʰ� �Ǵ� Ŭ���� �������̽��� �����ϸ�, Ư�������� ���۸��� �����ϵ����Ѵ�.
		 - �ݺ��ڸ� �������� �ʾ� stl �˰��� ����� �ȵȴ�.
	*/

}