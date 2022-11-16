// 08_typename_and_nested_depentdent_type_name.cpp

#include<iostream>
using namespace std;

class A
{
public:
	using my_int = int;
};

template<typename T>
class B
{
public:
	/*
		depent name(�����̸�) : ���� typename T ó�� Ÿ���� ���ڷ� �޾� ����Ҷ�, T�� �����̸��̶�� �θ���.

		nested depent name(��ø ���� Ÿ�� �̸�) : ���� �̸��ӿ� �ٸ� Ÿ���� ���� �� ��� ��ø ���� Ÿ�� �̸��̶�� �θ���.
		 - ��ø ���� Ÿ�� �̸��� ����� ������ typename Ű���带 ����ؾ��Ѵ�.
	*/

	// T::my_int i;  T::my_int�� Ÿ������, ���� ��� �������� ���� x -> ���� ��������� ������ ������ �߻��Ѵ�.
	 
	typename T::my_int i; // typename Ű���带 ����� T::my_int�� �ڷ������� ����Ͽ� �ذᰡ���ϴ�.
};

int main() {
	B<A> test;

	return 0;
}