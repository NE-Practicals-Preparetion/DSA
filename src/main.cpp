#include <iostream>
#include <fstream>
#include "hospital/Patient.h"

int main() {
    std::ofstream file("patients.txt", std::ios::app);

    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::string id, name, gender, diagnosis;
    int age;

    std::cout << "Enter patient ID: ";
    std::cin >> id;
    std::cout << "Enter patient name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter patient age: ";
    std::cin >> age;
    std::cout << "Enter patient gender: ";
    std::cin.ignore();
    std::getline(std::cin, gender);
    std::cout << "Enter patient diagnosis: ";
    std::getline(std::cin, diagnosis);

    Patient patient(id, name, age, gender, diagnosis);

    file << patient.getId() << "," << patient.getName() << "," << patient.getAge() << "," << patient.getGender() << "," << patient.getDiagnosis() << std::endl;

    file.close();

    std::cout << "Patient information saved to file." << std::endl;

    return 0;
}
