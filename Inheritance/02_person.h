#pragma once
// 02_person.h
// 02_student.h
// 02_teacher.h

#include <string>

// 서로 같은 동작과 데이터를 담는 멤버를 가진 student와 teacher가 있다.
// 이럴 경우 코드의 중복이 생기고 수정하기에 좋지않다. -> 수정하기위해선 둘다 바꾸어야함
// 이럴 때, student와 teacher의 공통된 부분을 기반 클래스에 작성한후 상속 시켜주어 해결가능.

// 아래와 같은 두 클래스를 상속을 통해 줄이자! 
class EX_Student
{
    EX_Student() = default;
    EX_Student(const std::string& name)
        : name(name)
    {}

    auto Getname() const { return name; }
    void SetName(const std::string& name) { this->name = name; }

    void Study() {} // 겹치지 않은 메서드

protected:
    std::string name;
};

class EX_Teacher
{
    EX_Teacher() = default;
    EX_Teacher(const std::string& name)
        : name(name)
    {}

    auto Getname() const { return name; }
    void SetName(const std::string& name) { this->name = name; }

    void Teach() {} // 겹치지 않은 메서드

protected:
    std::string name;
};

// 중복된 멤버를 기반 클래스에 작성
class Person
{
public:
    Person() = default;
    Person(const std::string & name)
        : name(name)
    {}

    auto Getname() const { return name; }
    void SetName(const std::string & name) { this->name = name; }

protected:
    std::string name;
};