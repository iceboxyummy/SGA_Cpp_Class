 // 01_stl_and_container.cpp

/*
	STL
	 - 컨테이너(Container), 반복자(iterator), 알고리즘(algorithm)이 포함되어있다.
	    * 컨테이너(Container) : 임의 타입의 데이터를 보관할 수 있다.
	    * 반복자(iterator) : 컨테이너에 보관된 원소에 접근할 때 사용한다.
	    * 알고리즘(algorithm) : 반복자들을 가지고 일련의 작업을 수행한다.
	 - 템플릿을 사용하여 어떠한 타입의 데이터도 위의 라이브러리 기능을 사용할 수 있다.
	  => 자료형을 일반화하여 코드의 수정없이 동일한 작업을 수행할 수 있게 해준다.

*/

/*
	컨테이너(Container) : 동일한 타입의 여러 객체를 저장하는 집합, 저장소를 말한다.
	 - 템플릿을 사용해 저장하는 데이터의 자료형에 무관하게 무엇이든 할 수있게 만들어져 있다.
	 - 3가지 종류의 컨테이너로 이루어져 있다.
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
	// SequenceContainer : 배열처럼 데이터를 선형으로 저장하는 컨테이너, 특별한 규칙이나 제약없이 원소를 보관한다.

	/*
		Vector : 가변 길이 배열, 동적 배열을 템플릿화한 것
		 - 원소가 실제 메모리에 순차적으로 저장되어있어 연속적인 데이터를 처리하기에 유리하다.
		 - 임의 접근을 제공한다. [], at()
		 - 할당된 공간을 다 채웠을 경우, 새로운 큰 공간을 동적으로 재할당하여 기존의 원소들을 복사한다.
		 - 맨 뒤에 원소를 삽입, 삭제할때는 빠르나. 
		   임의의 위치에 있는 원소를 삽입, 삭제하는 경우, 그 뒤의 원소를 한칸씩 이동시켜주어야 하기 때문에 느리다.

		  * 사용하기 좋은 경우
		   - 크기를 예측이 가능할 때
		   - 삽입, 삭제가 별로 없을 때
		   - 연속적인 데이터 처리가 필요할 때 
	*/
	{
		vector<int> vec; // template이며 template 클래스로 만들어진 객체(배열처럼 연속적인 메모리를 가지고 있음)

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		Dequeue : 백터와 비슷하나 원소가 메모리 공간에 연속적으로 존재 하지 않는다.
		 - 메모리를 재할당할 때, 추가로 메모리 공간을 만들어 논리적으로 이어붙인다. -> 데이터할당이 빠르다
		 - 서로 떨어져있는 메모리 공간의 정보를 보관하기 위해 벡터보다 추가적인 메모리가 필요하다.
		 - 임의의 위치에 있는 원소의 삽입, 삭제가 벡터보다 빠르다.
		 - 임의 접근을 제공한다. [], at()

		   * 사용하기 좋을 때
		    - 멘 앞과 맨 뒤의 원소를 삽입, 삭제하는 경우가 많은 경우
			- 벡터처럼 사용하고 싶지만 크기가 예측이 안되는 경우
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
		List : 양방향 연결리스트를 템플릿화
		 - 리스트는 시작 원소의 주소와 마지막 원소의 위치만을 기억한다.
		 - 각각의 원소가 자신의 앞과 뒤에 오는 원소를 가리키고 있다.
		 - 구조예시 
		     ->, <- 는 포인터로 앞과 뒤의 원소의 주소를 저장하고 있다.

				ㅁㅁㅁ        ㅁㅁㅁ        ㅁㅁㅁ
				ㅁ원ㅁ   ->   ㅁ원ㅁ   ->   ㅁ원ㅁ  
				ㅁ소ㅁ        ㅁ소ㅁ        ㅁ소ㅁ
				ㅁ1 ㅁ   <-   ㅁ2 ㅁ   <-   ㅁ3 ㅁ 
				ㅁㅁㅁ        ㅁㅁㅁ        ㅁㅁㅁ

		 - 위의 구조를 가지고있어 임의의 위치에 있는 원소에 바로 접근이 안되고 순차적으로 접근해야한다.
		 - 원소의 삽입 삭제가 일어날 경우 링크만 바꾸어주면 되기에 삽입 삭제가 빠르다.

		   * 사용하기 좋을떄
		     - 원소의 삽입, 삭제가 빈번하게 이루어질때
			 - 원소들을 순차적으로만 접근할떄
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
		associactive container : 데이터를 일정한 규칙에 따라 저장하고 관리하는 컨테이너
		 - 저장한 요소의 위치를 지정할 수 없고 균형 이진 트리나 해시테이블을 이용하여 구현한다.
		 - 원소를 삽입할 경우 자종으로 지정해주기 때문에 원하는 원소를 찾는 검색 속도가 빠르다.
		 - 키(key) - 값(value) 구조를 가져 특정한 키값을 넣으면 대응하는 값을 돌려준다.
	*/

	/*
		set과 multiset : 저장하는 데이터값 그 자체를 키로 사용한다.
		 - 테이터의 존재유무 만 체크하는경우 사용한다.
	*/

	// set : 키의 중복을 허용하지 않는다.
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("World");

		// 두 개가 출력된다.
		//  set은 중복을 허용하지 않기 때문에 중복된 데이터를 삽입할 경우 무시한다.
		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	// multiset : 키의 중복을 허용한다
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
		map과 multimap : 키와 값으로 데이터를 관리한다.
		 - map은 중복을 허용하지 않지만 multimap은 중복을 허용해 하나의 키가 여러 값과 연결될 수 있다.
	*/

	// map : key / value - pair
	{
		map<char, int> map; // mapping : 대응시킨다.
		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl; // 키값에 매핑된 값 10출력

		map['a'] = 100;
		cout << map['a'] << endl; // 새로운 값으로 초기화 한다.

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
		// multimap.insert(pair('c', 500));  c++17에서는 타입 생략가능

		cout << multimap.count('a') << endl;

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	/*
		unordered associative container : 정렬되지 않은 연관 컨테이너
		- 위의 연관 컨테이너는 트리를 사용하지만 정렬되지 않은 원소를 저장할 때 해시 테이블을 사용한다.
		- 삽입, 삭제, 검색 모두 빠르다.
		
		- unordered_set
		- unordered_multiset
		- unordered_map
		- unordered_multimap
	*/
}

void Container_Adapter()
{
	/*
		adapter container : 기존 컨테이너의 인터페이스를 제한하여 만들어 기능이 제한되거나 변형된 컨테이너
		 - 각각의 기초가 되는 클래스 인터페이스를 제한하며, 특정형태의 동작만을 수행하도록한다.
		 - 반복자를 지원하지 않아 stl 알고리즘 사용이 안된다.
	*/

}