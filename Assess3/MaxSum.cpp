#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <climits>

using namespace std;
using namespace std::chrono;

// Function to generate random array with both positive and negative numbers
void generateRandomArray(vector<int>& arr, int n) {
    srand(time(0)); 
    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % 201 - 100); // Random numbers between -100 and 100
    }
}

// Brute Force Algorithm (O(n^2))
int maxSubarrayBruteForce(const vector<int>& arr) {
    int max_sum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

// Helper function for Divide and Conquer to find the max crossing subarray
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

// Divide and Conquer Algorithm (O(n log n))
int maxSubarrayDivideConquer(const vector<int>& arr, int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;
    return max(
        max(maxSubarrayDivideConquer(arr, left, mid),
        maxSubarrayDivideConquer(arr, mid + 1, right)),
        maxCrossingSum(arr, left, mid, right)
    );
}

// Kadane's Algorithm (O(n))
int maxSubarrayKadane(const vector<int>& arr) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr;
    generateRandomArray(arr, n);

    // Brute Force Algorithm
    auto start = high_resolution_clock::now();
    int bruteForceResult = maxSubarrayBruteForce(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Brute Force result: " << bruteForceResult << ", Time: " << duration.count() << " microseconds" << endl;

    // Divide and Conquer Algorithm
    start = high_resolution_clock::now();
    int divideConquerResult = maxSubarrayDivideConquer(arr, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Divide and Conquer result: " << divideConquerResult << ", Time: " << duration.count() << " microseconds" << endl;

    // Kadane's Algorithm (Extra Credit)
    start = high_resolution_clock::now();
    int kadaneResult = maxSubarrayKadane(arr);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Kadane's Algorithm result: " << kadaneResult << ", Time: " << duration.count() << " microseconds" << endl;

    return 0;
}