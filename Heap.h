#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef ASSIGNMENT_5_CS_HEAP_H
#define ASSIGNMENT_5_CS_HEAP_H

struct DataSet {
    string date;
    float rate;
    DataSet(string x, float y) : date(x), rate(y) {}
};

struct Subsequence {
    int start;
    int end;
    float sum;
};

template <typename T>
class Heap {
public:
    Heap(const vector<T>& data);
    void buildMaxHeap();
    void buildMinHeap();
    vector<DataSet> findTopNIncrease(int N, float mean);
    vector<DataSet> findTopNDecrease(int N, float mean);
    void printHeap();
    bool compareChanges(const DataSet& a, const DataSet& b);
    Subsequence findMaxSubsequence(const vector<DataSet>& data, float mean);

private:
    vector<T> heapData;

    void heapifyMax(int n, int i);
    void heapifyMin(int n, int i);
    void buildheapMax();
    void buildheapMin();
};

template<typename T>
Subsequence Heap<T>::findMaxSubsequence(const vector<DataSet> &data, float mean) {
    Subsequence maxSubsequence;
    maxSubsequence.start = -1;
    maxSubsequence.end = -1;
    maxSubsequence.sum = 0.0;

    float currentSum = 0.0;
    int currentStart = 0;

    for (int i = 0; i < data.size(); ++i) {
        currentSum += (data[i].rate - mean);

        if (currentSum < 0.0) {
            currentSum = 0.0;
            currentStart = i + 1;
        }

        if (currentSum > maxSubsequence.sum) {
            maxSubsequence.start = currentStart;
            maxSubsequence.end = i;
            maxSubsequence.sum = currentSum;
        }
    }

    return maxSubsequence;
}

template<typename T>
Heap<T>::Heap(const vector<T>& data) : heapData(data) {}

template<typename T>
void Heap<T>::heapifyMax(int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && heapData[left].rate > heapData[largest].rate) {
        largest = left;
    }

    if (right < n && heapData[right].rate > heapData[largest].rate) {
        largest = right;
    }

    if (largest != i) {
        swap(heapData[i], heapData[largest]);
        heapifyMax(n, largest);
    }
}

template<typename T>
void Heap<T>::heapifyMin(int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && heapData[left].rate < heapData[smallest].rate) {
        smallest = left;
    }

    if (right < n && heapData[right].rate < heapData[smallest].rate) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heapData[i], heapData[smallest]);
        heapifyMin(n, smallest);
    }
}

template<typename T>
void Heap<T>::buildheapMax() {
    int heapSize = static_cast<int>(heapData.size());

    for (int i = heapSize / 2 - 1; i >= 0; --i) {
        heapifyMax(heapSize, i);
    }
}

template<typename T>
void Heap<T>::buildheapMin() {
    int heapSize = static_cast<int>(heapData.size());

    for (int i = heapSize / 2 - 1; i >= 0; --i) {
        heapifyMin(heapSize, i);
    }
}

template<typename T>
void Heap<T>::buildMaxHeap() {
    buildheapMax();
}

template<typename T>
void Heap<T>::buildMinHeap() {
    buildheapMin();
}

template<typename T>
vector<DataSet> Heap<T>::findTopNIncrease(int N,float mean) {
    buildheapMax(); // Build the max heap before entering the loop

    // Ensure that N is not greater than the heap size
    N = min(N, static_cast<int>(heapData.size()));
    vector<DataSet> output;

    for (int i = 0; i < N; i++) {
        DataSet x = heapData.front(); // Use front() instead of back()

        // Remove the maximum element (root of the max heap)
        swap(heapData.front(), heapData.back());
        heapData.pop_back(); // Remove the last element

        // Adjust the heap by heapifying the root
        heapifyMax(heapData.size(), 0);
        output.emplace_back(x);

        cout << "Date:" << x.date << ", " << "Rate: " << x.rate - mean << endl;
    }

    return output;
}


template<typename T>
vector<DataSet> Heap<T>::findTopNDecrease(int N, float mean) {
    buildheapMin(); // Build the max heap before entering the loop

    // Ensure that N is not greater than the heap size
    N = min(N, static_cast<int>(heapData.size()));
    vector<DataSet> output;

    for (int i = 0; i < N; i++) {
        DataSet x = heapData.front(); // Use front() instead of back()

        // Remove the maximum element (root of the max heap)
        swap(heapData.front(), heapData.back());
        heapData.pop_back(); // Remove the last element

        // Adjust the heap by heapifying the root
        heapifyMin(heapData.size(), 0);
        output.emplace_back(x);

        cout << "Date:" << x.date << ", " << "Rate: " << x.rate - mean << endl;
    }
    return output;
}

template<typename T>
void Heap<T>::printHeap() {
    for (const auto& element : heapData) {
        cout << "Date: " << element.date << ", Rate: " << element.rate << endl;
    }
    cout << endl;
}



#endif //ASSIGNMENT_5_CS_HEAP_H
