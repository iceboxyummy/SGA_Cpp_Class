 // 10_type_ aliases.cpp

#include<iostream>
#include<vector> // �����迭

int main(){

	// type aliaes : ����, ���� -> using

	typedef double distance_t;

	// �ʹ����.
	std::vector<std::pair<std::string, std::string>> pair_list;

	using namespace std;

	// �׷��� ���.
	vector<pair<string, string>> pair_list2;

	// typedef�� �̿��� ��������
	typedef vector<pair<string, string>> pair_list_t;
	pair_list_t pair_list_t_1;

	// using�� �̿��� ��������
	using  pair_list_tu = vector<pair<string, string>>;
	pair_list_tu pair_list_tu_1;

	return 0;
}