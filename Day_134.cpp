#include <bits/stdc++.h>
using namespace std;

int minimizeDifference(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 1) return 0; // If there's only one element, difference is 0.

    sort(arr.begin(), arr.end()); // Sort the array
    int mini = arr[0];            // Initial minimum
    int maxi = arr[n - 1];        // Initial maximum
    
    // Initial difference between max and min
    int ans = maxi - mini;

    for (int i = 1; i < n; i++) {
        // Calculate new minimum and maximum after modifying the elements
        int newMin = min(arr[0] + k, arr[i] - k);
        int newMax = max(arr[i - 1] + k, arr[n - 1] - k);

        // Update the minimized difference
        ans = min(ans, newMax - newMin);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 15, 10};
    int k = 6;

    int result = minimizeDifference(arr, k);
    cout << "The minimized difference is: " << result << endl;

    return 0;
}
