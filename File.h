//
// Created by Marwan on 11/27/2023.
//
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Heap.h"
#ifndef ASSIGNMENT_5_CS_FILE_H
#define ASSIGNMENT_5_CS_FILE_H


class File {
public:
    File(const string& file_name);
    void openAndRead();
    vector<DataSet> getContents() const;
    float getmean();
private:
    vector<DataSet> data;
    string file_name;
    float count;
    float sum = 0;




};


#endif //ASSIGNMENT_5_CS_FILE_H
