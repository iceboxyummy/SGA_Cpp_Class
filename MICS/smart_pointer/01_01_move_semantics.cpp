// 01_01_move_semantics.cpp

/*
	����Ʈ ������ : ������ó�� �����ϴ� Ŭ���� ���ø�
	 - ���������, �޸� ������ ���� �����ϱ� ���� �����Ͽ���.
	 - memory����� ����ִ�.
	 - ����
	  + auto_ptr
	  + unique_ptr
	  + shared_ptr
	  + weak_ptr
*/

#include<iostream>
#include<memory>

#include"01_02_resource.h"
#include"01_03_auto_ptr.h"

using namespace std;

/*
	RAII : Resourcd Acquisition is initialization
	 - ������ �������� �����ϴ°�
	 - RAII�� ��Ģ�� ����Ʈ �����Ϳ� ����Ǿ� �ִ�.
*/

// Early return : �̸� ��ȯ

void DoSomething1()
{
	Resource* resource = new Resource;

	// if (true) return; // �޸𸮴��� �߻�

	if (true)
	{
		// �ذ�� : �����ϴ� �κп� ������ ���� ���ش�.
		// ���� : �Ǽ��� Ȯ���� ���� -> �Ű澲�� �ʾƵ� �ڵ����� �����Ǿ��� ���ڴ�. -> ����Ʈ ������
		delete resource;
		return;
	}

	//...
	//...
	//...

	delete resource;
}

/* fix */
void DoSomething2()
{
	// �ذ�� : �Ҹ��ڿ��� ����
	// ��ü�� �Ҹ��ϸ鼭 �Ҹ��ڰ� ȣ��
	// �Ҹ��ڿ� ���������� ���ִ� �ڵ尡�־� �Ű������ �ʾƵ� �ڵ����� �޸𸮸� �����Ѵ�. -> ����Ʈ �������� ����
	AutoPtr<Resource> res(new Resource);
}

void DoSomething3(AutoPtr<Resource> temp)
{
}

int main() 
{
	// ���� �޸𸮸� ������ �����Ͱ� �Ҹ��Ҷ� �ڵ����� �����Ѵ�.
	{
		cout << "{" << endl;
		AutoPtr<Resource> res = new Resource;
		cout << "}" << endl;
	}

	// ����Ʈ ������ ������
	AutoPtr<Resource> res1 = new Resource;

	// .�����ڸ� ���� �����°� ����Ʈ �������� ���
	res1.Test();

	// ������ ���� �޸𸮿� �����ϸ� -> �����ڸ� ���� ����
	// res1->

	// AutoPtr�� ������1
	// AutoPtr�� ���� �������� �������� �Ѿ ������.
	DoSomething3(res1);

	// ���� ������ �õ��ҽ� ��� ������ ���� �߻�
	// res1->

	// ������2
	// autoptr�� �迭 ������ ����, ������ �������� �ʴ´�.

	// �������� ���������־� autoptr�� ����������� -> 3���� ���·ιٲ�
	return 0;
}