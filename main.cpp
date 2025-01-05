#include <iostream>
#include <conio.h>
#include <list>
#include <fstream>
#include <sstream>
#include <stdexcept> // To handle exceptions
using namespace std;

//HASH FUNCTION
class Hash {
    int size;
    list<int>* table;
    struct Student {
        int ID;
        string Name;
        string Department;
        int Semester;
        double CGPA;
    };

    string filename = "students_data.csv";

public:
    Hash(int size) {
        this->size = size;
        table = new list<int>[this->size];
        loadFromFile();
    }

    int hashFunction(int x) {
        return (x % this->size);
    }

    void insertdata() {
        Student student;
        cout << "KINDLY ENTER STUDENT'S INFORMATION" << endl;
        cout << "ENTER THE ID OF THE STUDENT..........  ";
        cin >> student.ID;
        cin.ignore();
        cout << "ENTER THE NAME OF THE STUDENT........  ";
        getline(cin,student.Name);
        cout << "ENTER THE DEPARTMENT OF THE STUDENT..  ";
        getline(cin,student.Department);
        cout << "ENTER CURRENT SEMESTER OF THE STUDENT. ";
        cin >> student.Semester;
        cout << "ENTER THE CGPA OF THE STUDENT........  ";
        cin >> student.CGPA;

        int index = hashFunction(student.ID);

        for (int id : table[index]) {
            if (id == student.ID) {
                cout << "ERROR: STUDENT WITH THIS ID ALREADY EXISTS." << endl;
                return;
            }
        }

        table[index].push_back(student.ID);
        appendToFile(student);
        cout << "STUDENT DATA INSERTED SUCCESSFULLY." << endl;
    }

    void deletedata(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                removeFromFile(key);
                cout << "STUDENT DATA DELETED SUCCESSFULLY." << endl;
                return;
            }
        }

        cout << "FAILED: STUDENT WITH THIS ID NOT FOUND." << endl;
    }

    bool searchh(int key) {
        int index = hashFunction(key);

        for (int id : table[index]) {
            if (id == key) {
                Student student = getFromFile(key);
                if (student.ID != -1) {
                    cout << "STUDENT FOUND: " << endl;
                    cout << "ID: " << student.ID << endl;
                    cout << "Name: " << student.Name << endl;
                    cout << "Department: " << student.Department << endl;
                    cout << "Semester: " << student.Semester << endl;
                    cout << "CGPA: " << student.CGPA << endl;
                }
                return true;
            }
        }

        cout << "STUDENT WITH THIS ID DOES NOT EXIST." << endl;
        return false;
    }

    bool update(int key) {
        int index = hashFunction(key);

        for (int id : table[index]) {
            if (id == key) {
                cout << "STUDENT FOUND. ENTER UPDATED INFORMATION:" << endl;
                deletedata(key);
                insertdata();
                return true;
            }
        }

        cout << "FAILED: STUDENT WITH THIS ID NOT FOUND." << endl;
        return false;
    }

    void displayHash() {
        for (int i = 0; i < this->size; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }

private:
    void appendToFile(Student student) {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << student.ID << "," << student.Name << "," << student.Department << "," << student.Semester << "," << student.CGPA << endl;
            outFile.close();
        } else {
            cout << "ERROR: COULD NOT OPEN FILE TO WRITE." << endl;
        }
    }

    void removeFromFile(int id) {
        ifstream inFile(filename);
        ofstream tempFile("temp.csv");

        if (!inFile.is_open() || !tempFile.is_open()) {
            cout << "ERROR: FILE OPERATION FAILED." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            try {
                if (stoi(token) != id) {
                    tempFile << line << endl;
                }
            } catch (const invalid_argument&) {
                // Handle invalid data in file gracefully
                cout << "ERROR: Invalid data encountered in file. Skipping line." << endl;
            }
        }

        inFile.close();
        tempFile.close();
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());
    }

    Student getFromFile(int id) {
        ifstream inFile(filename);
        Student student = {-1, "", "", -1, -1.0};

        if (!inFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN FILE TO READ." << endl;
            return student;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            try {
                if (stoi(token) == id) {
                    student.ID = stoi(token);
                    getline(ss, student.Name, ',');
                    getline(ss, student.Department, ',');
                    ss >> student.Semester;
                    ss.ignore();
                    ss >> student.CGPA;
                    break;
                }
            } catch (const invalid_argument&) {
                // Handle invalid data in file gracefully
                cout << "ERROR: Invalid data encountered in file. Skipping line." << endl;
            }
        }

        inFile.close();
        return student;
    }

    void loadFromFile() {
        ifstream inFile(filename);

        if (!inFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN FILE TO READ." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            try {
                int id = stoi(token);
                table[hashFunction(id)].push_back(id);
            } catch (const invalid_argument&) {
                // Handle invalid data in file gracefully
                cout << "ERROR: Invalid data encountered in file. Skipping line." << endl;
            }
        }

        inFile.close();
    }
};

// Main function
int main() {
    int choice, adminPass;

    cout << "LOADING..." << endl;
    system("cls");
    cout << "WELCOME TO THE STUDENT DATABASE MANAGEMENT SYSTEM" << endl;
    getch();
    system("cls");

    Hash h(1000); // Create hash table with 10 buckets

    cout << "1. ADMIN LOGIN\n2. STUDENT LOGIN" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "ENTER ADMIN PASSWORD: ";
        cin >> adminPass;
        if (adminPass == 1234) {
            int action;
            do {
                cout << "1. INSERT\n2. DELETE\n3. SEARCH\n4. UPDATE\n5. DISPLAY\n6. EXIT" << endl;
                cin >> action;
                switch (action) {
                case 1:
                    h.insertdata();
                    break;
                case 2:
                    int idToDelete;
                    cout << "ENTER ID TO DELETE: ";
                    cin >> idToDelete;
                    h.deletedata(idToDelete);
                    break;
                case 3:
                    int idToSearch;
                    cout << "ENTER ID TO SEARCH: ";
                    cin >> idToSearch;
                    h.searchh(idToSearch);
                    break;
                case 4:
                    int idToUpdate;
                    cout << "ENTER ID TO UPDATE: ";
                    cin >> idToUpdate;
                    h.update(idToUpdate);
                    break;
                case 5:
                    h.displayHash();
                    break;
                case 6:
                    cout << "EXITING..." << endl;
                    break;
                default:
                    cout << "INVALID OPTION. TRY AGAIN." << endl;
                }
            } while (action != 6);
        } else {
            cout << "INCORRECT PASSWORD." << endl;
        }
        break;
    case 2:
        cout << "STUDENT LOGIN FEATURE NOT IMPLEMENTED YET." << endl;
        break;
    default:
        cout << "INVALID CHOICE." << endl;
    }

    return 0;
}
