#include <iostream>
#include <vector>
using namespace std;

// Function to push all zeros to the end of the array
void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array
    int index = 0;      // Initialize an index to track non-zero elements

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the current element is non-zero, move it to the 'index' position
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with zeros
    while (index < n) {
        arr[index++] = 0;
    }
}

// Function to print the elements of the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the above code
int main() {
    vector<int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    
    cout << "Original array: ";
    printArray(arr);

    pushZerosToEnd(arr);

    cout << "Array after pushing zeros to the end: ";
    printArray(arr);

    return 0;
}
