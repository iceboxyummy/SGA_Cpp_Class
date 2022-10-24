// 21_assert.cpp

#include <iostream>
#include <cassert> // assert : 단호한
using namespace std;;

int main() {
	int x = 0;
	cout << x << endl;

	// assert(x != 0);
	assert(false); // 예외발생
	// 식이 true 라면 계속 진행, false가 들어오면 예외처리, 특정조건의 성공유무를 체크할때 사용한다. 
	// debug 모드에서만 사용, release 모드에서는 체크하지 않는다.
	// assert()는 런타임에 확인이 된다 -> 싱행해봐야 결과를 알 수 있다.
	// if (x == 0) { exit(0); }

	assert(x != 0 && "x is 0");

	cout << "hello" << endl;

	return 0;
}