#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    std::string id;
    std::string name;
    int age;
    std::string gender;
    std::string diagnosis;

public:
    Patient();
    Patient(const std::string& id, const std::string& name, int age, const std::string& gender, const std::string& diagnosis);

    void setId(const std::string& id);
    void setName(const std::string& name);
    void setAge(int age);
    void setGender(const std::string& gender);
    void setDiagnosis(const std::string& diagnosis);

    std::string getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    std::string getDiagnosis() const;

    void display() const;
};

#endif // PATIENT_H
