#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string id;
    string fullName;
    string email;
    string telNo;
    string gender;
    int age;

public:
    User();
    User(const string &id, const string &fullName, const string &email, const string &telNo, const string &gender, const int &age);

    void setId(const std::string &id);
    void setFullName(const std::string &fullName);
void setAge(int & age);
    void setAge(int age);
    void setGender(const std::string &gender);
    void setEmail(const std::string &email);
    void setTelNo(const std::string &telNo);

    string getFullName() const;
    string getId() const;
    int getAge() const;
    string getGender() const;
    string getTelNo() const;
    string getEmail() const;

    void display() const;
};

#endif