 // 07_multi_inheritance.cpp

/*
	multiinheritance (다중 상속) : 한 클래스가 두개 이상의 클래스를 상속하는 것
	 - 다중 상속이 좋은 방식은 아니기 때문에 다른 언어에서는 허용하지 않는 경우도 있다.
*/

#include <iostream>
using namespace std;

class USBDevice 
{
public:
	USBDevice() = default;
	USBDevice(int id) : id(id) { }

	int GetID() const { return id; }
	void PlugAndPlay() {}

private:
	int id;
};

class NetworkDevice {
public:
	NetworkDevice() = default;
	NetworkDevice(int id) : id(id) { }

	int GetID() const { return id; }
	void Networking() {}

private:
	int id;
};

// 두개 이상의 클래스를 상속 받음 -> 다중 상속
class USBNetworkDevice : public USBDevice, public NetworkDevice 
{
public:
	USBNetworkDevice(int usb_id, int net_id) 
		: USBDevice(usb_id)
		, NetworkDevice(net_id) 
	{
	}

	USBNetworkDevice(int id) 
		: USBDevice(id)
		, NetworkDevice(id) 
	{
	}
};

int main() {
	USBNetworkDevice device(1.10, 2.10);
	device.PlugAndPlay();
	device.Networking();

	// device.GetID(); error = embiguos : 기반 클래스의 멤버 함수가 중복되어 모호하다.

	// 해결방법1 -> 중복된 함수이름 변경 -> 번거로움
	// 해결방법2 -> namespace 사용

	cout << device.USBDevice::GetID() << endl;
	cout << device.NetworkDevice::GetID() << endl;

	return 0;
}