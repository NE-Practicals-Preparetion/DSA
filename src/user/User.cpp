#include "user/User.h"
#include <iostream>
#include "User.h"

using namespace std;

User::User() {}

User::User(const string &id, const string &fullName, const string &email, const string &telNo, const string &gender, const int &age) : id(id), fullName(fullName), email(email), telNo(telNo), gender(gender), age(age){};

void User::setId(const string &id)
{
    this->id = id;
}

void User::setFullName(const string &fullName)
{
    this->fullName = fullName;
}

void User::setAge(int &age)
{
    this->age = age;
}

void User::setEmail(const string &email)
{
    this->email = email;
}

void User::setGender(const string &gender)
{
    this->gender = gender;
}

void User::setTelNo(const string &telNo)
{
    this->telNo = telNo;
}

string User::getId() const {
    return id;
}

string User::getFullName() const {
    return fullName;
}

int User::getAge() const {
    return age;
}

string User::getGender() const {
    return gender;
}

string User::getTelNo() const {
    return telNo;
}

string User::getEmail() const {
    return email;
}

void User::display() const
{
    std::cout << "User ID: " << id << std::endl;
    std::cout << "Name: " << fullName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "TelNo: " << telNo << std::endl;
    std::cout << "Email: " << email << std::endl;
}