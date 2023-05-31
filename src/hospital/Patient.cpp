#include "hospital/Patient.h"
#include <iostream>

Patient::Patient() {}

Patient::Patient(const std::string& id, const std::string& name, int age, const std::string& gender, const std::string& diagnosis)
    : id(id), name(name), age(age), gender(gender), diagnosis(diagnosis) {}

void Patient::setId(const std::string& id) {
    this->id = id;
}

void Patient::setName(const std::string& name) {
    this->name = name;
}

void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setGender(const std::string& gender) {
    this->gender = gender;
}

void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}

std::string Patient::getId() const {
    return id;
}

std::string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

std::string Patient::getGender() const {
    return gender;
}

std::string Patient::getDiagnosis() const {
    return diagnosis;
}

void Patient::display() const {
    std::cout << "Patient ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
}
