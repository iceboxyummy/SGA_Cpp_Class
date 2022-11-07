 // 03_association.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient
{
public:
	Patient(const string& name)
		:name(name)
	{

	}

	void AddDoctor(class Doctor* const doctor) 
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor(); // Doctor�� ���Ǻΰ� �ڿ� �����Ƿ� ���Ǹ� ���� �����־���Ѵ�.
private:
	string name;
	friend class Doctor;
	vector<class Doctor*> doctors;
};

class Doctor
{
public:
	Doctor(const string& name) : name(name) 
	{
	
	}

	void AddPatient(class Patient* const patient) 
	{
		patients.push_back(patient);
	}

	void MeetPatient() 
	{
		for (const auto& patient : patients)
			cout << "Meet Patient : " << patient->name << endl;
	}
	
private:
	string name;
	friend class Patient;
	vector <class Patient*> patients;
};

int main() {
	Patient* p1 = new Patient("Kim");
	Patient* p2 = new Patient("Part");
	Patient* p3 = new Patient("Lee");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	// ����
	// ��Ⱓ ġ�Ḧ ���� ��� ȯ�ڿ� �ǻ�� ���θ� �˾ƾ� �Ѵ�.
	// ���ΰ� ���ο��� ������ ���� �� �ִ�. (���� ���� ���, �ϳ� �ٲ�� �� �� ������ �� �ֱ� ���� <Ŀ�ø�����>)

	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	p2->MeetDoctor();
	d2->MeetPatient();

	// ���� ������� Ŭ������ �ٸ� Ŭ������ ���踦 ������ �ֱ� ������
	// �ٸ� Ŭ�������� ���� ����� �Ǹ� ������ ���� �� �ִ�. 
	// �׷��� ������ ���� �� ������ �������� �����ϴ°� ����.
	// �Ҹ��� ������ �������� �����Ѵ�. ���� ������ Ŭ������ �ٸ� Ŭ������ ���踦 �ΰ� ���� ���ɼ��� ���� �����̴�.
	delete d2; 
	delete d1;
	delete p3;
	delete p2;
	delete p1;

	return 0;
}

void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
		cout << "Meet Doctor : " << doctor->name << endl;
}