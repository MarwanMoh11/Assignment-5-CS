#include <iostream>
#include "File.h"
#include "Heap.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    File x("D:\\C++\\Assignment 5\\Assignment-5-CS\\test.txt");
    int N = 10;
    x.openAndRead();
    vector<DataSet> v;
    v = x.getContents();
    Heap test(v);

    cout << "Top " << N << " Increases:"<<endl;
    test.findTopNIncrease(N,x.getmean());
    cout << "Top " << N << " Decreases:"<<endl;
    test.findTopNDecrease(N,x.getmean());

    Subsequence result = test.findMaxSubsequence(v);

    std::cout << "Maximum Subsequence Sum: " << result.sum << std::endl;
    std::cout << "Start Index: " << result.start << std::endl;
    std::cout << "End Index: " << result.end << std::endl;
    cout << x.getmean();





}
