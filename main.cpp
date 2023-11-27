#include <iostream>
#include "File.h"
#include "Heap.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    ofstream outputFile("output.txt");
    streambuf *coutBuffer = std::cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());
    File x("test.txt"); // Put the txt files in cmake debug build
    int N = 10;
    x.openAndRead();
    vector<DataSet> v;
    v = x.getContents();
    Heap test(v);

    cout << "Top " << N << " Increases:"<<endl;
    test.findTopNIncrease(N,x.getmean());
    cout << "Top " << N << " Decreases:"<<endl;
    test.findTopNDecrease(N,x.getmean());

    Subsequence result = test.findMaxSubsequence(v,x.getmean());

    cout << "Maximum Subsequence Sum: " << result.sum << std::endl;
    cout << "Start Index: " << result.start << std::endl;
    cout << "End Index: " << result.end << std::endl;

    cout << "Start Date: " << v[result.start].date << std::endl;
    cout << "End Date: " << v[result.end].date << std::endl;

    std::cout.rdbuf(coutBuffer);
    





}
