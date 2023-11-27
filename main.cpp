#include <iostream>
#include "File.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    File x("D:\\C++\\Assignment 5\\Assignment-5-CS\\test.txt");
    x.openAndRead();
    vector<DataSet> v;
    v = x.getContents();
    Heap test(v);
    test.buildMaxHeap();
    test.printHeap();



}
