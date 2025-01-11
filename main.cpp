#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <string> // For handling strings
#include <conio.h>
using namespace std;

// HASH FUNCTION
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

    string dataFilename = "students_data.csv";
    string indexFilename = "index.csv";

public:
    Hash(int size) {
        this->size = size;
        table = new list<int>[size];
        loadIndexFromFile();
    }

    int hashFunction(int x) {
        return (x % size);
    }

    void insertdata() {
        Student student;
        cout << "KINDLY ENTER STUDENT'S INFORMATION" << endl;
        cout << "ENTER THE ID OF THE STUDENT..........  ";
        cin >> student.ID;
        cin.ignore();
        cout << "ENTER THE NAME OF THE STUDENT........  ";
        cin  >> student.Name;
        cout << "ENTER THE DEPARTMENT OF THE STUDENT..  ";
        cin >> student.Department;
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

        // Append data to main file and capture offset
         appendToFile(student); // Get offset directly from appendToFile

        // Add ID and offset to index file
       // appendToIndexFile(student.ID, offset);

        // Add ID to hash table
        table[index].push_back(student.ID);
       // cout << "STUDENT DATA INSERTED SUCCESSFULLY." << endl;
    }

    void deletedata(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                removeFromIndexFile(key); // Delete only from the index file
                cout << "STUDENT DATA DELETED SUCCESSFULLY FROM INDEX." << endl;
                return;
            }
        }

        cout << "FAILED: STUDENT WITH THIS ID NOT FOUND IN INDEX." << endl;
    }

    bool searchh(int key) {
        int index = hashFunction(key);

        for (int id : table[index]) {
            if (id == key) {
                streampos offset = getOffsetFromIndexFile(key);
                if (offset != -1) {
                    Student student = getFromFile(offset);
                    if (student.ID != -1) {
                        cout << "STUDENT FOUND: " << endl;
                        cout << "ID: " << student.ID << endl;
                        cout << "Name: " << student.Name << endl;
                        cout << "Department: " << student.Department << endl;
                        cout << "Semester: " << student.Semester << endl;
                        cout << "CGPA: " << student.CGPA << endl;
                    }
                } else {
                    cout << "STUDENT WITH THIS ID EXISTS IN HASH TABLE BUT NOT IN INDEX." << endl;
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

                // Remove the old entry
                deletedata(key);

                // Insert the updated record
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
        // Open main data file in append mode
        ofstream outFile(dataFilename, ios::in | ios::out | ios::app);  // Open for reading and writing

        if (!outFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN DATA FILE TO WRITE." << endl;
            return;
        }

        // Move file pointer to the end and capture the offset
        outFile.seekp(0, ios::end);
        streampos offset = outFile.tellp();

        // Write the student data to the data file
        outFile << student.ID << "," << student.Name << "," << student.Department << "," << student.Semester << "," << student.CGPA << endl;

        // Ensure data is written to the file
        outFile.flush();
        outFile.close();

        // Debugging: Print captured offset to see its value
        cout << "Captured Offset: " << offset << endl;

        // Open index file in append mode
        ofstream indexFile(indexFilename, ios::app);
        if (!indexFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN INDEX FILE TO WRITE." << endl;
            return;
        }

        // Write ID and offset to the index file
        indexFile << student.ID << "," << offset << endl;
        indexFile.close();

        cout << "STUDENT DATA INSERTED SUCCESSFULLY." << endl;
    }





    void appendToIndexFile(int id, streampos offset) {
        ofstream indexFile(indexFilename, ios::app);
        if (indexFile.is_open()) {
            indexFile << id << "," << offset << endl;
            indexFile.close();
        } else {
            cout << "ERROR: COULD NOT OPEN INDEX FILE TO WRITE." << endl;
        }
    }

    void removeFromIndexFile(int id) {
        ifstream inFile(indexFilename);
        ofstream tempFile("temp_index.csv");

        if (!inFile.is_open() || !tempFile.is_open()) {
            cout << "ERROR: INDEX FILE OPERATION FAILED." << endl;
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
                cout << "ERROR: Invalid data encountered in index file. Skipping line." << endl;
            }
        }

        inFile.close();
        tempFile.close();
        remove(indexFilename.c_str());
        rename("temp_index.csv", indexFilename.c_str());
    }

    streampos getOffsetFromIndexFile(int id) {
        ifstream inFile(indexFilename);
        if (!inFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN INDEX FILE TO READ." << endl;
            return -1;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            try {
                if (stoi(token) == id) {
                    // Read the offset from the index file
                    string offsetStr;
                    getline(ss, offsetStr);
                    streampos offset = static_cast<streampos>(stoll(offsetStr)); // Convert string to streampos
                    inFile.close();
                    return offset;
                }
            } catch (const invalid_argument&) {
                cout << "ERROR: Invalid data encountered in index file. Skipping line." << endl;
            }
        }

        inFile.close();
        return -1;
    }

    Student getFromFile(streampos offset) {
        ifstream inFile(dataFilename);
        Student student = {-1, "", "", -1, -1.0};

        if (!inFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN DATA FILE TO READ." << endl;
            return student;
        }

        inFile.seekg(offset);
        string line;
        getline(inFile, line);

        stringstream ss(line);
        getline(ss, line, ',');
        student.ID = stoi(line);
        getline(ss, student.Name, ',');
        getline(ss, student.Department, ',');
        ss >> student.Semester;
        ss.ignore();
        ss >> student.CGPA;

        inFile.close();
        return student;
    }

    void loadIndexFromFile() {
        ifstream inFile(indexFilename);

        if (!inFile.is_open()) {
            cout << "ERROR: COULD NOT OPEN INDEX FILE TO READ." << endl;
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
                cout << "ERROR: Invalid data encountered in index file. Skipping line." << endl;
            }
        }

        inFile.close();
    }
};


// Main function
int main() {
    int choice, adminPass;
    cout << "WELCOME TO THE STUDENT DATABASE MANAGEMENT SYSTEM" << endl;

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
