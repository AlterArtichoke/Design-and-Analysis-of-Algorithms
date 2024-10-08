#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    vector<int> elements;
    int n, ele;
    
    ifstream inputFile("random_50000.txt");
    
    inputFile >> n;
    for (int i = 0; i < n; i++) {
        inputFile >> ele;
        elements.push_back(ele);
    }
    
    inputFile.close();
    
    clock_t tStart = clock();
    mergeSort(elements, 0, n - 1);
    
    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken by Merge Sort is " << time1 << " seconds." << endl;

    return 0;
}
