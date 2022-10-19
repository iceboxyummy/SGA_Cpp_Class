 // 10_type_ aliases.cpp

#include<iostream>
#include<vector> // 동적배열

int main(){

	// type aliaes : 가명, 별명 -> using

	typedef double distance_t;

	// 너무길다.
	std::vector<std::pair<std::string, std::string>> pair_list;

	using namespace std;

	// 그래도 길다.
	vector<pair<string, string>> pair_list2;

	// typedef를 이용한 별명지정
	typedef vector<pair<string, string>> pair_list_t;
	pair_list_t pair_list_t_1;

	// using을 이용한 별명지정
	using  pair_list_tu = vector<pair<string, string>>;
	pair_list_tu pair_list_tu_1;

	return 0;
}