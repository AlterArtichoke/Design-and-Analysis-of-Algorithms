#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Global variables to track statistics
int totalComparisons = 0;
int totalRecursiveCalls = 0;
int leftDirectPlacements = 0;
int rightDirectPlacements = 0;

// Function to merge two sorted subarrays
void merge(char *arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *L[n1], *R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        totalComparisons++;
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k++] = L[i++];
            leftDirectPlacements++;
        } else {
            arr[k++] = R[j++];
            rightDirectPlacements++;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
        leftDirectPlacements++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        rightDirectPlacements++;
    }
}

// Function to implement merge sort
void mergeSort(char *arr[], int left, int right) {
    totalRecursiveCalls++;
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to print the sorted array
void printArray(char *arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

// Main function
int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);
    getchar(); // Consume newline after the number

    char *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        printf("Enter word %d: ", i + 1);
        fgets(arr[i], MAX_STRING_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove newline character
    }

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    printf("\nTotal number of comparisons: %d\n", totalComparisons);
    printf("Total number of recursive calls: %d\n", totalRecursiveCalls);
    printf("Total number of left subarray direct placements: %d\n", leftDirectPlacements);
    printf("Total number of right subarray direct placements: %d\n", rightDirectPlacements);

    // Free allocated memory
    for (int i = 0; i < n; i++)
        free(arr[i]);

    return 0;
}
