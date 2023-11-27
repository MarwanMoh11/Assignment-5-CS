//
// Created by Marwan on 11/27/2023.
//

#include "File.h"
#include <sstream>

File::File(const string &file_name) {
    this->file_name = file_name;
}

void File::openAndRead() {
    std::ifstream file(this->file_name);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);

            // Extract date
            std::string dateStr;
            iss >> dateStr;

            // Extract rate by skipping whitespace
            float number;
            while (iss >> std::ws >> number) {
                data.emplace_back(dateStr, number);
            }
        }
        std::cout << "File '" << this->file_name << "' successfully read.\n";
    } else {
        std::cerr << "Error opening file '" << this->file_name << "'.\n";
    }
}

vector<DataSet> File::getContents() const {
    return data;
}

