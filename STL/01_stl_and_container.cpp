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
	/*
		 SequenceContainer : �迭ó�� �����͸� �������� �����ϴ� �����̳�
		  - Ư���� ��Ģ�̳� ������� ���Ҹ� �����Ѵ�.

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
}

void Associative_Container()
{
}

void Container_Adapter()
{
}