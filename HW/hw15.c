#include <stdio.h>
#include <stdlib.h>

// 全域變數儲存 m 的值
int m_global;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    int *arr1 = *(int (*)[])a;
    int *arr2 = *(int (*)[])b;

    // Compare the elements of the arrays
    for (int i = 0; i < m_global; i++) {
        if (arr1[i] != arr2[i]) {
            return arr1[i] - arr2[i];
        }
    }

    return 0; // Arrays are equal
}

// Function to check if an array contains a duplicate element
int containsDuplicate(int arr[], int size) {
    int freq[10] = {0}; // Array to store frequency of elements

    for (int i = 0; i < size; i++) {
        if (freq[arr[i]] > 0) {
            return 1; // Duplicate element found
        }
        freq[arr[i]]++;
    }

    return 0; // No duplicate element found
}

// Function to check if a subsequence is a duplicate of any existing subsequence in array
int isDuplicate(int array[][3], int subseq[], int index) {
    for (int i = 0; i < index; i++) {
        int duplicate = 1; // Assume subsequence is duplicate initially
        for (int j = 0; j < 3; j++) {
            if (array[i][j] != subseq[j]) {
                duplicate = 0; // Set duplicate flag to 0 if elements are not equal
                break;
            }
        }
        if (duplicate) {
            return 1; // Subsequence is a duplicate
        }
    }
    return 0; // Subsequence is not a duplicate
}

int main() {
    int lens = 0, count = 0, i = 0;

    // Input m and integer sequence
    scanf("%d", &m_global);
    int input[21] = {0}; // Temporary array to store input sequence
    for (int i = 0; i < 21; i++) {
        scanf("%d", &input[i]);
        if (input[i] == -1) {
            lens = i - 1;
            break;
        }
    }

    // Count number of subsequences
    count = lens - m_global + 2;

    // Declare array for storing unique and non-repeating subsequences
    int array[count][m_global]; // Static array

    // Fill the array with unique and non-repeating subsequences
    int index = 0, index_2 = 0;
    for (i = 0; i < lens - m_global + 2; i++) {
        int subseq[m_global];
        for (int j = i; j < i + m_global; j++) {
            subseq[j - i] = input[j]; // Create subsequence of length m
        }

        // Check if subsequence contains duplicate elements
        if (!containsDuplicate(subseq, m_global) && !isDuplicate(array, subseq, index)) {
            for (int k = 0; k < m_global; k++) {
                array[index][k] = subseq[k];
            }
            index++;
        }
        if (!containsDuplicate(subseq, m_global))
        {
            index_2 ++;
        }
        
    }

    // Sort the array by the elements of each subsequence
    qsort(array, index, sizeof(array[0]), compare);

    // Output sorted and unique subsequences
    printf("%d\n", index_2);
    for (i = 0; i < index; i++) {
        for (int j = 0; j < m_global; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
