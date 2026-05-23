// Hospital Patient Record System

#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

// Patient Structure
struct Patient
{
    int patientID;
    string name;
    int age;
    string gender;
    string disease;
    string doctor;
    string appointmentDate;
};

// Function Declarations
void registerUser();
bool login();
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void appointmentSystem();

// Main Function
int main()
{
    int choice;

    cout << "========== Hospital Patient Record System ==========\n";

    // Login/Register Menu
    while(true)
    {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            registerUser();
        }

        else if(choice == 2)
        {
            if(login())
            {
                cout << "\nLogin Successful.\n";

                int menuChoice;

                // Main Menu
                while(true)
                {
                    cout << "\n========== MAIN MENU ==========";
                    cout << "\n1. Add Patient";
                    cout << "\n2. View Patients";
                    cout << "\n3. Search Patient";
                    cout << "\n4. Update Patient";
                    cout << "\n5. Delete Patient";
                    cout << "\n6. Appointment System";
                    cout << "\n7. Logout";

                    cout << "\n\nEnter Choice: ";
                    cin >> menuChoice;

                    if(menuChoice == 1)
                    {
                        addPatient();
                    }

                    else if(menuChoice == 2)
                    {
                        viewPatients();
                    }

                    else if(menuChoice == 3)
                    {
                        searchPatient();
                    }

                    else if(menuChoice == 4)
                    {
                        updatePatient();
                    }

                    else if(menuChoice == 5)
                    {
                        deletePatient();
                    }

                    else if(menuChoice == 6)
                    {
                        appointmentSystem();
                    }

                    else if(menuChoice == 7)
                    {
                        cout << "\nLogged Out Successfully.\n";
                        break;
                    }

                    else
                    {
                        cout << "\nInvalid Choice.\n";
                    }
                }
            }

            else
            {
                cout << "\nInvalid Username or Password.\n";
            }
        }

        else if(choice == 3)
        {
            cout << "\nProgram Closed.\n";
            break;
        }

        else
        {
            cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}

// Register Function
void registerUser()
{
    string username, password;
    string existingUsername, existingPassword;

    bool duplicate = false;

    ifstream checkFile("users.txt");

    cout << "\nEnter Username: ";
    cin >> username;

    // Duplicate Username Validation
    while(checkFile >> existingUsername >> existingPassword)
    {
        if(username == existingUsername)
        {
            duplicate = true;
            break;
        }
    }

    checkFile.close();

    if(duplicate)
    {
        cout << "\nUsername Already Exists.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();
    cout << "\nRegistration Successful.\n";
}

// Login Function
bool login()
{
    string username, password;
    string fileUsername, filePassword;

    ifstream file("users.txt");

    cout<<"\nEnter Username: ";
    cin>>username;

    cout << "Enter Password: ";
    cin>>password;

    while(file >> fileUsername >> filePassword)
    {
        if(username == fileUsername && password == filePassword)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Add Patient Function
void addPatient()
{
    Patient p;

    int existingID;

    string temp, tempName, tempAge, tempGender;
    string tempDisease, tempDoctor, tempAppointment;

    bool duplicate = false;

    // Duplicate Patient ID Validation
    ifstream checkFile("patients.txt");

    cout << "\nEnter Patient ID: ";
    cin >> p.patientID;

    while(getline(checkFile, temp, '|'))
    {
        if(temp == "")
        {
            break;
        }

        existingID = atoi(temp.c_str());

        getline(checkFile, tempName, '|');
        getline(checkFile, tempAge, '|');
        
        getline(checkFile, tempGender, '|');
        getline(checkFile, tempDisease, '|');
        getline(checkFile, tempDoctor, '|');
        getline(checkFile, tempAppointment);

        if(existingID == p.patientID)
        {
            duplicate = true;
            break;
        }
    }

    checkFile.close();

    if(duplicate)
    {
        cout << "\nPatient ID Already Exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, p.name);

    cout << "Enter Age: ";
    cin >> p.age;

    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, p.gender);

    cout << "Enter Disease: ";
    getline(cin, p.disease);

    cout << "Enter Doctor Name: ";
    getline(cin, p.doctor);

    cout << "Enter Appointment Date: ";
    getline(cin, p.appointmentDate);

    ofstream file("patients.txt", ios::app);

    file << p.patientID << "|"
         << p.name << "|"
         << p.age << "|"
         << p.gender << "|"
         << p.disease << "|"
         << p.doctor << "|"
         << p.appointmentDate << endl;

    file.close();

    cout << "\nPatient Added Successfully.\n";
}



// View Patients Function
void viewPatients()
{
    ifstream file("patients.txt");

    string id, name, age, gender;
    string disease, doctor, appointment;

    cout << "\n========== PATIENT RECORDS ==========\n";

    while(getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, gender, '|');
        getline(file, disease, '|');
        getline(file, doctor, '|');
        getline(file, appointment);

        cout << "\nPatient ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
        cout << "\nDisease: " << disease;
        cout << "\nDoctor: " << doctor;
        cout << "\nAppointment Date: " << appointment;
        cout << "\n-------------------------------------";
    }

    file.close();
}

// Search Patient Function
void searchPatient()
{
    int searchID;
    int patientID;

    string id, name, age, gender;
    string disease, doctor, appointment;

    bool found = false;

    ifstream file("patients.txt");

    cout << "\nEnter Patient ID to Search: ";
    cin >> searchID;

    while(getline(file, id, '|'))
    {
        patientID = atoi(id.c_str());

        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, gender, '|');
        getline(file, disease, '|');
        getline(file, doctor, '|');
        getline(file, appointment);

        if(patientID == searchID)
        {
            cout << "\nPatient Found:\n";

            cout << "\nPatient ID: " << patientID;
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
            cout << "\nGender: " << gender;
            cout << "\nDisease: " << disease;
            cout << "\nDoctor: " << doctor;
            cout << "\nAppointment Date: " << appointment<<endl;

            found = true;
            break;
        }
    }

    file.close();

    if(!found)
    {
        cout << "\nPatient Not Found.\n";
    }
}

// Update Patient Function
void updatePatient()
{
    int updateID;
    int patientID;

    string id, name, age, gender;
    string disease, doctor, appointment;

    bool found = false;

    ifstream file("patients.txt");
    ofstream tempFile("temp.txt");

    cout << "\nEnter Patient ID to Update: ";
    cin >> updateID;

    cin.ignore();

    while(getline(file, id, '|'))
    {
        patientID = atoi(id.c_str());

        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, gender, '|');
        getline(file, disease, '|');
        getline(file, doctor, '|');
        getline(file, appointment);

        if(patientID == updateID)
        {
            found = true;

            cout << "\nEnter New Name: ";
            getline(cin, name);

            cout << "Enter New Age: ";
            getline(cin, age);

            cout << "Enter New Gender: ";
            getline(cin, gender);

            cout << "Enter New Disease: ";
            getline(cin, disease);

            cout << "Enter New Doctor Name: ";
            getline(cin, doctor);

            cout << "Enter New Appointment Date: ";
            getline(cin, appointment);
        }

        tempFile << patientID << "|"
                 << name << "|"
                 << age << "|"
                 << gender << "|"
                 << disease << "|"
                 << doctor << "|"
                 << appointment << endl;
    }

    file.close();
    tempFile.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if(found)
    {
        cout << "\nPatient Updated Successfully.\n";
    }

    else
    {
        cout << "\nPatient Not Found.\n";
    }
}

// Delete Patient Function
void deletePatient()
{
    int deleteID;
    int patientID;

    string id, name, age, gender;
    string disease, doctor, appointment;

    bool found = false;

    ifstream file("patients.txt");
    ofstream tempFile("temp.txt");

    cout << "\nEnter Patient ID to Delete: ";
    cin >> deleteID;

    while(getline(file, id, '|'))
    {
        patientID = atoi(id.c_str());

        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, gender, '|');
        getline(file, disease, '|');
        getline(file, doctor, '|');
        getline(file, appointment);

        if(patientID == deleteID)
        {
            found = true;
        }

        else
        {
            tempFile << patientID << "|"
                     << name << "|"
                     << age << "|"
                     << gender << "|"
                     << disease << "|"
                     << doctor << "|"
                     << appointment << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if(found)
    {
        cout << "\nPatient Deleted Successfully.\n";
    }

    else
    {
        cout << "\nPatient Not Found.\n";
    }
}

// Appointment System
void appointmentSystem()
{
    string patientName;
    string doctorName;
    string date;

    ofstream file("appointments.txt", ios::app);

    cin.ignore();

    cout << "\nEnter Patient Name: ";
    getline(cin, patientName);

    cout << "Enter Doctor Name: ";
    getline(cin, doctorName);

    cout << "Enter Appointment Date: ";
    getline(cin, date);

    file << patientName << "|"
         << doctorName << "|"
         << date << endl;

    file.close();

    cout << "\nAppointment Added Successfully.\n";
}
