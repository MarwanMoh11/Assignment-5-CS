//
// Created by Marwan on 11/27/2023.
//

#include "File.h"
#include <sstream>

File::File(const string &file_name) {
    this->file_name = file_name;
}

void File::openAndRead() {
    ifstream file(this->file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);

            // Extract date
            string dateStr;
            iss >> dateStr;

            // Extract rate by skipping whitespace
            float number;
            while (iss >> ws >> number) {
                data.emplace_back(dateStr, number);
                count = count+ 1;

                sum = sum + number;

            }

        }
        cout << "File '" << this->file_name << "' successfully read.\n";
    } else {
        cerr << "Error opening file '" << this->file_name << "'.\n";
    }
}

vector<DataSet> File::getContents() const {
    return data;
}

float File::getmean() {
    return sum/count;
}

