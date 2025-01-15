//
// Created by hp on 1/14/2025.
//

#ifndef HASH_H
#define HASH_H

#include <list>
#include <string>
#include <vector>
using namespace std;

struct data {
    int ID;
    string Name;
    string Department;
    int Semester;
    double CGPA;
};

class Hash {
private:
    int size;
    list<int>* table;
    string dataFilename = "students_data.csv";
    string indexFilename = "index.csv";

    void appendToFile(const struct data &student);
    void removeFromIndexFile(int id);
    streampos getOffsetFromIndexFile(int id);
    struct data getFromFile(streampos offset);
    void loadIndexFromFile();
    void appendToIndexFile(int id, streampos offset);

public:
    Hash();
    ~Hash();

    int hashFunction(int x) const;
    bool insertdata(const struct data& student);
    bool deletedata(int key);
    struct data searchh(int key);
    bool update (int key);
    vector<int> getIDs();
};



#endif //HASH_H
