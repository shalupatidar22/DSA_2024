#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum circular subarray sum
int circularSubarraySum(vector<int> &arr) {
    int max_so_far = 0;   // Tracks the maximum subarray sum ending at the current position
    int min_so_far = 0;   // Tracks the minimum subarray sum ending at the current position
    int maxSum = arr[0];  // Stores the maximum sum of any subarray (non-circular)
    int minSum = arr[0];  // Stores the minimum sum of any subarray (non-circular)
    int total = 0;        // Stores the total sum of the array

    for (int i = 0; i < arr.size(); i++) {
        // Kadane's algorithm for maximum subarray sum
        max_so_far = max(max_so_far + arr[i], arr[i]);
        maxSum = max(maxSum, max_so_far);

        // Kadane's algorithm for minimum subarray sum
        min_so_far = min(min_so_far + arr[i], arr[i]);
        minSum = min(minSum, min_so_far);

        // Calculate total array sum
        total += arr[i];
    }

    // If all elements are negative, return the maximum non-circular subarray sum
    if (total == minSum) {
        return maxSum;
    }

    // Return the maximum of:
    // 1. The non-circular maximum subarray sum
    // 2. The circular subarray sum (total - minSum)
    return max(maxSum, total - minSum);
}

int main() {
    // Input array
    vector<int> arr = {5, -2, 3, 4};

    // Find and print the result
    cout << "Maximum Circular Subarray Sum: " << circularSubarraySum(arr) << endl;

    return 0;
}
