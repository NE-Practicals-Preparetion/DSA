#include <iostream>
#include <fstream>
// #include "hospital/user.h"
#include "user/User.h"
#include <sstream>


using namespace std;

void addUser(User &user)
{
    ofstream file("users.txt", ios::app);
    if (file.is_open())
    {
        file << user.getId() << "," << user.getFullName() << "," << user.getEmail() << "," << user.getTelNo() << "," << user.getGender() << "," << user.getAge() << endl;
        file.close();
        cout << "User added successfully." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void updateUser(User &user)
{
    // Read the users from the file
    ifstream file("users.txt");
    ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t pos = line.find(user.getId());
            if (pos != string::npos)
            {
                tempFile << user.getId() << "," << user.getFullName() << "," << user.getEmail() << "," << user.getTelNo() << "," << user.getGender() << "," << user.getAge() << endl;
                cout << "User updated successfully." << endl;
            }
            else
            {
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();

        // Rename the temp file to users.txt
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void deleteUser(const string &userId)
{
    // Read the users from the file
    ifstream file("users.txt");
    ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t pos = line.find(userId);
            if (pos == string::npos)
            {
                tempFile << line << endl;
            }
            else
            {
                cout << "User deleted successfully." << endl;
            }
        }
        file.close();
        tempFile.close();

        // Rename the temp file to users.txt
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void readUsersFromFile()
{
    ifstream file("users.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // Split the line into fields
            size_t pos = line.find(',');
            string userId = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            string fullName = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            string email = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            string telNo = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            string gender = line.substr(0, pos);
            line.erase(0, pos + 1);

            int age = stoi(line);

            // Create a user object
            User user(userId, fullName, email, telNo, gender, age);

            // Display user information
            user.display();
            cout << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void addUser()
{

    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "Error opening file!" << endl;
    }

    string id, fullName, gender, email, telNo;
    int age;

    cout << "Enter user ID: ";
    cin >> id;
    cout << "Enter full names: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter gender: ";
    cin.ignore();
    getline(cin, gender);
    cout << "Enter telNo: ";
    getline(cin, telNo);
    cout << "Enter user age: ";
    cin >> age;

    User user(id, fullName, email, telNo, gender, age);
    user.display();

    // file << user.getId() << "," << user.getFullName() << "," << user.getAge() << "," << user.getGender() << "," << user.getTelNo()<<" ," << user.getEmail() << endl;

    file.close();

    cout << "user information saved to file." << endl;
}


bool userExists(const string& id)
{
    // Read the users from the file and check if the user with the given ID exists
    ifstream file("users.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string userId;
            getline(ss, userId, ',');

            if (userId == id)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }

    return false;
}


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
        cout << endl;

        int choice;
        cout << "           Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Adding a new user..." << endl;

            // Read user data from the console
            string id, fullName, email, telNo, gender;
            int age;

            cout << "Enter user ID: ";
            cin >> id;

            cout << "Enter full name: ";
            cin.ignore();
            getline(cin, fullName);

            cout << "Enter email: ";
            cin >> email;

            cout << "Enter telephone number: ";
            cin >> telNo;

            cout << "Enter gender: ";
            cin >> gender;

            cout << "Enter age: ";
            cin >> age;

            // Create a user object with the provided data
            User user(id, fullName, email, telNo, gender, age);

            // Add the user
            addUser(user);

            break;
        }
        case 2:
        {
            cout << "Updating a user..." << endl;

            // Read the ID of the user to be updated
            string id;
            cout << "Enter user ID to update: ";
            cin >> id;

            // Check if the user exists
            if (userExists(id))
            {
                // Read the updated user data from the console
                string fullName, email, telNo, gender;
                int age;

                cout << "Enter new full name: ";
                cin.ignore();
                getline(cin, fullName);

                cout << "Enter new email: ";
                cin >> email;

                cout << "Enter new telephone number: ";
                cin >> telNo;

                cout << "Enter new gender: ";
                cin >> gender;

                cout << "Enter new age: ";
                cin >> age;

                // Create a user object with the updated data
                User updatedUser(id, fullName, email, telNo, gender, age);

                // Update the user
                updateUser(updatedUser);

                cout << "User updated successfully." << endl;
            }
            else
            {
                cout << "User with ID " << id << " not found." << endl;
            }

            break;
        }
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
    cout << "*          5. Exit                                                                     *" << endl;
    cout << endl;

    while (true)
    {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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

    return 0;
}
