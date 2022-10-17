 // 02_input output stream.cpp

#include<iostream>
#include<iomanip>

//stream( >> , << ) : ������ ������� �帧�� ǥ���� ��

int main() {
	// cout

	int x = 1028;
	double pi = 3.141592;

	std::cout << "x is" << x << "\npi is" << pi << std::endl << std::endl;

	// cin

	int z;

	std::cin >> z;
	std::cout << "Your input is " << z << std::endl << std::endl;

	// ������(manipulator) : ��������� �������ش�, �ٲ��� �ʴ� �� ��� �����ȴ�.
	
	int num = 100;
	
	// ���� ��� ���� ������
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl << std::endl;

	// showbase : � ���� ���·� ��µǴ��� ǥ��
	// showpos : ������ ������ ��ȣǥ��
	// noshowbase, noshowpos�� ���� ����
	std::cout << std::showbase << std::showpos;
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl << std::endl;
	std::cout << std::noshowbase << std::noshowpos;

	bool is_true = true;
	bool is_false = false;

	// bool������ ��¹�� �ٲٱ�
	std::cout << std::boolalpha;
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	std::cout << std::noboolalpha;
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	return 0;
}