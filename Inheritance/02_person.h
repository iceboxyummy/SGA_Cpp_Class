#pragma once
// 02_person.h
// 02_student.h
// 02_teacher.h

#include <string>

// ���� ���� ���۰� �����͸� ��� ����� ���� student�� teacher�� �ִ�.
// �̷� ��� �ڵ��� �ߺ��� ����� �����ϱ⿡ �����ʴ�. -> �����ϱ����ؼ� �Ѵ� �ٲپ����
// �̷� ��, student�� teacher�� ����� �κ��� ��� Ŭ������ �ۼ����� ��� �����־� �ذᰡ��.

// �Ʒ��� ���� �� Ŭ������ ����� ���� ������! 
class EX_Student
{
    EX_Student() = default;
    EX_Student(const std::string& name)
        : name(name)
    {}

    auto Getname() const { return name; }
    void SetName(const std::string& name) { this->name = name; }

    void Study() {} // ��ġ�� ���� �޼���

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

    void Teach() {} // ��ġ�� ���� �޼���

protected:
    std::string name;
};

// �ߺ��� ����� ��� Ŭ������ �ۼ�
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