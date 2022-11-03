 //	09_02_RVO_NRVO.	cpp

/*
	RVO - Return Value Optimization) : 어떤 함수가 객체를 반환해야 할 경우, 필요하지 않은 임시 객체를 생성하지 않도록 최적화 하는 것
	 - Debug, Rlease 에서 가능
	 - 반환 객체가 변수명을 가지지 않은 경우 최적화된다.
	 - 변수명을 가진 경우 최적화 되지 않았지만 NRVO가 추가되어 가능하게 되었다.

	 NRVO(Named Return Value Optimization) : RVO와 같은 방식으로 최적화를 지원한다.
	  - Debug에서는 최적화 x, Rlease 에서만 최적화 o
*/

#include<iostream>
using namespace std;

class Test
{
public:
	Test(int value) : value1(value), value2(count++)
	{
		cout << " constructor : " << this->value1 << "," << this->value2 << endl;
	}

	Test(const Test& rhs) : value1(rhs.value1), value2(count++)
	{
		cout << " copy constructor : " << this->value1 << "," << this->value2 << endl;
	}

	~Test()
	{
		cout << " destructor : " << this->value1 << "," << this->value2 << endl;
	}

public:
	static int count;

private:
	int value1;
	int value2;
};

int Test::count = 1;

// Debug, Release : 임시객체 생성 x
Test MakeRVO(int value)
{
	return Test(value); // RVO -> 반환 객체가 이름이 없는 겅우 
}

// Debug : 임시객체 생성 x, Release : 임시객체 생성 ㅇ
Test MakeNRVO(int value)
{
	return Test(value); // NRVO -> 반환 객체가 이름이  있는 겅우 
}

int main() {
	
	cout << "-----------RVO-----------" << endl;
	Test t1 = MakeRVO(1);

	cout << "----------NRVO-----------" << endl;
	Test t2 = MakeNRVO(2);

	cout << "-----------End-----------" << endl;

	return 0;
}