#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];
    int partitionIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[right]);

    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);
}

int main() {
    vector<int> elements;
    int n, ele;
    
    ifstream inputFile("descending_10000.txt");
    
    inputFile >> n;
    for (int i = 0; i < n; i++) {
        inputFile >> ele;
        elements.push_back(ele);
    }
    
    inputFile.close();
    
    clock_t tStart = clock();
    quickSort(elements, 0, n - 1);
    
    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken by Quick Sort is " << time1 << " seconds." << endl;

    return 0;
}
