#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Patients
{
    string name;
    string age;
    string address;
    string disease;
    string prevHosp;
};

void addRecord();
void editRecord();
void viewRecord();
void deleteRecord();

int main()
{
    int opt1;
    cout << "Medical Records Management System" << endl;
    cout << "===============================" << endl;
    cout << "Select an option below: " << endl
         << endl;
    cout << "1) Create Medical Record" << endl;
    cout << "2) Edit Medical Record" << endl;
    cout << "3) View Medical Record" << endl;
    cout << "4) Delete Medical Record" << endl;
    cout << "5) Exit Program" << endl
         << endl;

    cout << "Enter choice: ";
    cin >> opt1;

    switch (opt1)
    {
    //! Add Patient Records
    case 1:
    {
        addRecord();
        system("cls");
        return main();
    }
    //! Edit Patient Records
    case 2:
    {
        break;
    }
    //! View Patient Records
    case 3:
    {
        viewRecord();
        system("cls");
        return main();
    }
    //! Delete Patient Records
    case 4:
    {
        break;
    }
    //! Program is KIL :(
    case 5:
    {
        break;
    }
    //! Failed Input Option
    default:
    {
        cout << "Invalid Option" << endl;
        system("pause");
        system("cls");
        return main();
    }
    }
    return 0;
}

void addRecord()
{
    Patients patient[10];
    char check = 'n';
    int i = 0;

    do
    {
        i++;
        cout << endl;
        cout << "Patient Number: " << i << endl;
        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, patient[i].name);
        cout << "Enter Patient Address: ";
        getline(cin, patient[i].address);
        cout << "Enter Patient Disease: ";
        getline(cin, patient[i].disease);
        cout << "Enter Patient's Previous Hospital: ";
        getline(cin, patient[i].prevHosp);
        cout << "Would you like to input another record? [y/n] ";
        cin >> check;
    } while (check == 'y' || check == 'Y');

    ofstream file;
    file.open("patients.csv");
    file << "Patient Number,Patient Name,Address,Disease,Previous Hospital\n";
    int ctr = 0;
    do
    {
        ctr++;
        file << ctr << "," << patient[ctr].name + "," << patient[ctr].address + "," << patient[ctr].disease + "," << patient[ctr].prevHosp + "\n";
    } while (ctr < i);
    file.close();
}

void viewRecord()
{
    ifstream myReadFile("patients.csv");
    string TableCategories;
    string Number;
    string Name;
    string Address;
    string Disease;
    string PrevHosp;
    int x = 0;
    while (myReadFile.good())
    {
        //? Read and Skip .CSV Table Categories.
        if (x < 1)
        {
            getline(myReadFile, TableCategories, '\n');
            x++;
        }
        //? Reads the first number in the .CSV to output values.
        getline(myReadFile, Number, ',');
        if (!Number.empty())
        {
            getline(myReadFile, Name, ',');
            getline(myReadFile, Address, ',');
            getline(myReadFile, Disease, ',');
            getline(myReadFile, PrevHosp, '\n');

            cout << "Patient Number: " << Number << '\n';
            cout << "Patient Name: " << Name << '\n';
            cout << "Patient Address: " << Address << '\n';
            cout << "Patient Diseas: " << Disease << '\n';
            cout << "Patient Previous Hospital: " << PrevHosp << '\n'
                 << endl;
        }
    }
    myReadFile.close();
    system("pause");
}