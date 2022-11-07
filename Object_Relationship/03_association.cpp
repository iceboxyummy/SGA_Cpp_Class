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

	void MeetDoctor(); // Doctor의 정의부가 뒤에 있으므로 정의를 따로 적어주어야한다.
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

	// 연계
	// 장기간 치료를 받을 경우 환자와 의사는 서로를 알아야 한다.
	// 서로가 서로에게 영향을 끼질 수 있다. (좋지 않은 경우, 하나 바뀌면 둘 다 수정될 수 있기 때문 <커플링관계>)

	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	p2->MeetDoctor();
	d2->MeetPatient();

	// 먼저 만들어진 클래스는 다른 클래스와 관계를 가질수 있기 때문에
	// 다른 클래스보다 먼저 지우게 되면 문제가 생길 수 있다. 
	// 그렇기 때문에 생성 된 순서의 역순으로 해제하는게 좋다.
	// 소멸은 생성된 역순으로 해제한다. 먼저 생성된 클래스는 다른 클래스와 관계를 맺고 있을 가능성이 높기 때문이다.
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