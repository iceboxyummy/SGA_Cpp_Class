 // 01_function_template.cpp

/*
	Template : 프로그래머가 원하는 타입을 넣어주면 알맞게 코드를 찍어내주는 튤
	 - int나 double같은 구체적인 자료형을 포괄할 수 있는 일반형(generic type)으로 정의한다.
	 - 어떤 데이터형을 템플릿에 매개변수로 전달하면, 컴파일러가 그 데이터 형에 맞는 코드를 생성해준다.
	 - 구체적인 데이터형 대신 일반형으로 프로그래밍 하는데 이걸을 일반화 프로그래밍이라고 부른다.
	 - 다양한 자료형에 동일한 알고리즘을 적용해야 한다면, 템플릿을 사용한다.
*/

#include<iostream>
using namespace std;
/*
	오버로딩으로 가능하지만 새로운 타입이 필요할때 마다 추가해 주어야한다.
	 -> 번거롭고 코드 자체에 변경점이 있을 경우 모두 수정해주어야한다.
	
	int GetMax(int x, int y) { return (x > y) ? x : y; }
	float GetMax(float x, float y) { return (x > y) ? x : y; }
	double GetMax(double x, double y) { return (x > y) ? x : y; }
	long long GetMax(long long x, long long y) { return (x > y) ? x : y; }
*/

template<typename T> // 템플릿 인자 T 선언, 코드를 작성할 때 사용할 타입 매개변수
// template<class T> class라고 쓸수도 있으나 차이는 없다.
T GetMax(T x, T y) // 위에 선언한 T를 하나의 자료형처럼 생각하여 사용한다.
{
	return (x > y) ? x : y;
}

class Won
{
public:
	Won(int value = 0) :value(value){}
	
	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream&operator <<(ostream&out, const Won&won)
	{
		out << won.value;
		return out;
	}

private:
	int value;
};

int main() {
	// <>로 템플릿 인자의 자료형을 지정해 줄 수 있다.
	cout << GetMax<int>(1, 2u) << endl;
	//cout << GetMax<float>(1, 2) << endl;

	// 함수 템플릿은 인자 타입을 맞추면 <> 로 타입을 지정해주지 않아도 가능하다
	cout << GetMax(1l, 2l) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;
	cout << GetMax(1.0, 2.0) << endl;

	// 우리가 만든 템플릿 함수는 두 개의 인자값을 같은 타입으로 받고 있기 때문에 두 인자의 타입이 다르다면 암시적으로 생성 x
	// cout << GetMax(1, 2u) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;
	return 0;
}