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
	/*
		 SequenceContainer : 배열처럼 데이터를 선형으로 저장하는 컨테이너
		  - 특별한 규칙이나 제약없이 원소를 보관한다.

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
}

void Associative_Container()
{
}

void Container_Adapter()
{
}