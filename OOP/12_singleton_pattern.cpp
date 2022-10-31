 // 12_singleton_pattern.cpp

// singleton pattern (�̱��� ����) : ������ �ν��Ͻ��� �ϳ��� �����ϴ� ����

#include<iostream>

class Audio
{
public:

	static Audio& GetInstance()
	{
		static Audio audio;
		return audio;
	}

	// ������, ���� ������, ���� ���� �����ڸ� ����ų� ������ �ν��Ͻ��� ������ ���� �Ǵ°��� ����
private:
	Audio(){}
	Audio(const Audio& audio) = delete;
	Audio& operator=(const Audio audio) = delete;
};

int main() {

	// audio A error
	// audio B error
}