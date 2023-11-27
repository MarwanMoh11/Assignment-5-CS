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

template <typename T>
class Heap {
public:
    Heap(const std::vector<T>& data);
    void buildMaxHeap();
    void buildMinHeap();
    int findTopNIncrease(int N);
    int findTopNDecrease(int N);
    void printHeap();

private:
    vector<T> heapData;

    void heapifyMax(int n, int i);
    void heapifyMin(int n, int i);
    void buildheapMax();
    void buildheapMin();
};

template<typename T>
Heap<T>::Heap(const std::vector<T>& data) : heapData(data) {}

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
        std::swap(heapData[i], heapData[largest]);
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
        std::swap(heapData[i], heapData[smallest]);
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
int Heap<T>::findTopNIncrease(int N) {
    // Implement as needed
    return 0;
}

template<typename T>
int Heap<T>::findTopNDecrease(int N) {
    // Implement as needed
    return 0;
}

template<typename T>
void Heap<T>::printHeap() {
    for (const auto& element : heapData) {
        cout << "Date: " << element.date << ", Rate: " << element.rate << endl;
    }
    cout << endl;
}

#endif //ASSIGNMENT_5_CS_HEAP_H
