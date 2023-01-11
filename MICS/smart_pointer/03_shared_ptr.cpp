// 03_shared_ptr.cpp

/*
	shared_ptr
		- ����ũ �����Ϳ� �޸� ������ ������ ������
		- �����͸� �Լ��� �����ؾ� �� ��, ����ũ ������ ��� ����ϱ� �����ϴ�.
		- ���� ī���� ����� ����Ѵ�.
			������ dull �����͸� �����ϰ� �ִ� ����Ʈ �������� ������ ī�����Ͽ� 
			  ������ ����Ʈ �����Ͱ� �Ҹ��� �� �����ϴ� ���
*/

#include<iostream>
#include<memory>
#include"02_02_resource.h"
using namespace std;

int main()
{
	{
		// dull �����͸� �޾� res1�� �������� ī��Ʈ 0 -> 1����
		auto res1 = std::make_shared<Resource>(5);

		res1->SetAll(2);
		res1->Print();

		// use_count() : ���� �ڽ��� ������ �� �����͸� �����ϰ� �ִ� ����Ʈ ������ ����
		cout << "Count : " << res1.use_count() << endl;
		{
			// res1�� ������ �ּҸ� �����޴´�. ī��Ʈ 1 -> 2 ����
			auto res2(res1);

			cout << "Count res1 : " << res1.use_count() << endl;
			cout << "Count res2: " << res2.use_count() << endl;
		} // res2 �Ҹ�, ī��Ʈ ���� 2 -> 1, ���� �� �����͸� ������ �����Ͱ� �־� ���� x 
		cout << "Count : " << res1.use_count() << endl;
	} // res1 �Ҹ�, ī��Ʈ ���� 1 -> 0, �� �����͸� ������ ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� dull������ ����

	// �� �����͸� ���� ����ϸ� �߻��ϴ� ����

	Resource* ptr = new Resource(10);
	{
		// ī��Ʈ ���� 0 -> 1
		std::shared_ptr<Resource> res1(ptr);

		res1->SetAll(2);
		res1->Print();
	
		cout << "Count : " << res1.use_count() << endl;
		{
			// res2 ī��Ʈ ���� 0 -> 1
			std::shared_ptr<Resource> res2(ptr);

			cout << "Count res1 : " << res1.use_count() << endl;
			cout << "Count res2: " << res2.use_count() << endl;
		} // res2 ī��Ʈ ����, 1 -> 0 ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� �޸� ����
		cout << "Count : " << res1.use_count() << endl;
	} // res1 ī��Ʈ ����, 1 -> 0 ������ ����Ʈ �����Ͱ� �Ҹ��Ͽ� �޸�����
		// ��������� ���� �߻�
	return 0;
}