 // 11_structures.cpp

#include<iostream>

struct person
{
	/*
		��� �Լ��� �޸� �ڵ� ������ �Ҵ�Ǿ� ����ü ������ ���Ե��� �ʴ´�.
		 -> ���� ��ü�� �ϳ��� �Լ��� �����Ͽ� ����Ѵ�.
		 �׷��� ������ ��� �Լ� ���ο��� �Լ��� ȣ���� ��ü�� ������ �˾ƾ� �ϴµ�
		 __thiscall ����� ����ؼ� ���������� 
		 �ش� �Լ��� ȣ���� ��ü�� �����͸� �Ѱ� �޾� �����Ѵ�.
	*/

	// C�� �ٸ��� �Լ��� �־��� �� �ִ�.
	void /*__thiscall*/ Print(/* person* this */)
	{
		this->age;
		std::cout << age << std::endl;
	}

	// C�� �ٸ��� �⺻�� ������ ����
	int age;
	float weight = 50.f;
	std::string name = "DiDi";
};

int main() {
	person p1{ 10, 50.0f, "DiDi" };
	person p2;

	p1.Print(/*&p1*/);
	p2.Print();

	return 0;
}