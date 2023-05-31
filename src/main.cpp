#include <iostream>
#include <fstream>
#include "hospital/Patient.h"

using namespace std;

void userManagement()
{
    while (true)
    {
        cout << "========================================================================================" << endl;
        cout << "*          User Management                                                             *" << endl;
        cout << "========================================================================================" << endl;
        cout << "*          1. Add User                                                                 *" << endl;
        cout << "*          2. Update User                                                              *" << endl;
        cout << "*          3. Delete User                                                              *" << endl;
        cout << "*          4. Go Back                                                                  *" << endl;
        cout << "========================================================================================" << endl;

        int choice;
        cout << "*         Enter your choice:                                                           *";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Implement logic to add a new user
            cout << "Adding a new user..." << endl;
            break;
        case 2:
            // Implement logic to update a user
            cout << "Updating a user..." << endl;
            break;
        case 3:
            // Implement logic to delete a user
            cout << "Deleting a user..." << endl;
            break;
        case 4:
            // Go back to the main menu
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{

    cout << "========================================================================================" << endl;
    cout << "*          Welcome to Disease Cases Reporting System!                                  *" << endl;
    cout << "****************************************************************************************" << endl;
    cout << "*   It is developed by MUHIRE PATRICK as practical evaluation for the end of Year 3.   *" << endl;
    cout << "****************************************************************************************" << endl;
    cout << "========================================================================================" << endl;
    cout << "*          Starting Time: Tue Jul 05 08:00:00 CAT 2022                                 *" << endl;
    cout << "========================================================================================" << endl;
    cout << "*          1. User Management                                                          *" << endl;
    cout << "*          2. Location Management                                                      *" << endl;
    cout << "*          3. Disease Management                                                       *" << endl;
    cout << "*          4. Report New Case                                                          *" << endl;
    cout << "*          5. Exit" << endl;

    while(true){
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                userManagement();
                break;
            case 2:
                // Implement location management logic
                break;
            case 3:
                // Implement disease management logic
                break;
            case 4:
                // Implement new case reporting logic
                break;
            case 5:
                // Exit the program
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    // help();

    // ofstream file("patients.txt", ios::app);
    // ofstream userFile("users.txt", ios::app);

    // if (!file && !userFile)
    // {
    //     cout << "Error opening file!" << endl;
    //     return 1;
    // }

    // string id, name, gender, diagnosis;
    // int age;

    // cout << "Enter patient ID: ";
    // cin >> id;
    // cout << "Enter patient name: ";
    // cin.ignore();
    // getline(cin, name);
    // cout << "Enter patient age: ";
    // cin >> age;
    // cout << "Enter patient gender: ";
    // cin.ignore();
    // getline(cin, gender);
    // cout << "Enter patient diagnosis: ";
    // getline(cin, diagnosis);

    // Patient patient(id, name, age, gender, diagnosis);

    // file << patient.getId() << "," << patient.getName() << "," << patient.getAge() << "," << patient.getGender() << "," << patient.getDiagnosis() << endl;

    // file.close();

    // cout << "Patient information saved to file." << endl;

    return 0;
}
