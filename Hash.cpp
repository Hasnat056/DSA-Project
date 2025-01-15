//
// Created by hp on 1/14/2025.
//

#include "Hash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <string>
Hash::Hash() {
        this->size = 1000;
        table = new list<int>[size];
        loadIndexFromFile();
    }

    int Hash::hashFunction(int x) const {
        return (x % size);
    }

bool Hash::insertdata(const struct data &student) {
    int index = hashFunction(student.ID);
    for (int id : table[index]) {
        if (id == student.ID) {
            return false;
        }
    }
    appendToFile(student);
    table[index].push_back(student.ID);

    return true;
}



bool Hash::deletedata(int key) {
    int index = hashFunction(key);

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            removeFromIndexFile(key);
            return true;
        }
    }

    return false;
}


    struct data Hash::searchh(int key) {
    int index = hashFunction(key);
    struct data student(-1,"-1", "-1",-1,-1);
    for (int id : table[index]) {
        if (id == key) {
            streampos offset = getOffsetFromIndexFile(key);
            if (offset != -1) {
                student = getFromFile(offset);
                if (student.ID != -1) {
                    return student;
                }
                throw runtime_error("STUDENT WITH THIS ID EXISTS IN HASH TABLE BUT NOT IN INDEX.");
            }
        }throw runtime_error("STUDENT WITH THIS ID DOES NOT EXIST." );
    }
return student;}

   void Hash::appendToFile(const struct data &student) {
        // Open main data file in append mode
        ofstream outFile(dataFilename, ios::in | ios::out | ios::app);  // Open for reading and writing

        if (!outFile.is_open()) {
            throw runtime_error("ERROR: COULD NOT OPEN DATA FILE TO WRITE.");
        }
        outFile.seekp(0, ios::end);
        streampos offset = outFile.tellp();
        outFile << student.ID << "," << student.Name << "," << student.Department << "," << student.Semester << "," << student.CGPA << endl;
        outFile.flush();
        outFile.close();

        ofstream indexFile(indexFilename, ios::app);
        if (!indexFile.is_open()) {
            throw runtime_error("ERROR: COULD NOT OPEN INDEX FILE TO WRITE.");
        }
        indexFile << student.ID << "," << offset << endl;
        indexFile.close();
    }





    void Hash::appendToIndexFile(int id, streampos offset) {
        ofstream indexFile(indexFilename, ios::app);
        if (indexFile.is_open()) {
            indexFile << id << "," << offset << endl;
            indexFile.close();
        } else {
            throw runtime_error("ERROR: COULD NOT OPEN INDEX FILE TO WRITE.");
        }
    }

    void Hash::removeFromIndexFile(int id) {
        ifstream inFile(indexFilename);
        ofstream tempFile("temp_index.csv");

        if (!inFile.is_open() || !tempFile.is_open()) {
            throw runtime_error("ERROR: INDEX FILE OPERATION FAILED.");
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
                throw runtime_error("Invalid data encountered in index file. Skipping line.");
            }
        }

        inFile.close();
        tempFile.close();
        remove(indexFilename.c_str());
        rename("temp_index.csv", indexFilename.c_str());
    }

    streampos Hash::getOffsetFromIndexFile(int id) {
        ifstream inFile(indexFilename);
        if (!inFile.is_open()) {
           // throw runtime_error("ERROR: COULD NOT OPEN INDEX FILE TO READ.");

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
                throw runtime_error( "ERROR: Invalid data encountered in index file. Skipping line." );
            }
        }

        inFile.close();
        return -1;
    }

    struct data Hash::getFromFile(streampos offset) {
        ifstream inFile(dataFilename);
       struct data student = {-1, "", "", -1, -1.0};

        if (!inFile.is_open()) {
            throw runtime_error("ERROR: COULD NOT OPEN DATA FILE TO READ.");
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

    void Hash::loadIndexFromFile() {
        ifstream inFile(indexFilename);

        if (!inFile.is_open()) {
           throw runtime_error ("ERROR: COULD NOT OPEN INDEX FILE TO READ.");
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

bool Hash::update(int key) {
    int index = hashFunction(key);

    for (int id : table[index]) {
        if (id == key) {
            deletedata(key);
            insertdata(searchh(key));
            return true;
        }
    }

   throw runtime_error("FAILED: STUDENT WITH THIS ID NOT FOUND.");
}

vector<int> Hash::getIDs() {
    vector<int> ids;

    // Loop through the hash table and collect all IDs into the vector
    for (int i = 0; i < this->size; i++) {
        for (auto x : table[i]) {
            ids.push_back(x);  // Add each ID to the vector
        }
    }

    return ids;  // Return the vector of IDs
}


Hash::~Hash() {

}
