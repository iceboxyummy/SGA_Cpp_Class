 // 12_singleton_pattern.cpp

// singleton pattern (싱글톤 패턴) : 객제의 인스턴스가 하나만 존재하는 패턴

#include<iostream>

class Audio
{
public:

	static Audio& GetInstance()
	{
		static Audio audio;
		return audio;
	}

	// 생성자, 복사 생성자, 복사 대입 연산자를 숨기거나 삭제해 인스턴스가 여러개 생성 되는것을 방지
private:
	Audio(){}
	Audio(const Audio& audio) = delete;
	Audio& operator=(const Audio audio) = delete;
};

int main() {

	// audio A error
	// audio B error
}