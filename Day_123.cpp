#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAttend(vector<vector<int>> &arr) {
    // Sort intervals by start time
    sort(arr.begin(), arr.end());

    // Check for overlapping intervals
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1][1] > arr[i][0]) { // Compare end time of previous with start time of current
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> intervals = {{1, 4}, {9, 12}, {6, 10}};

    if (canAttend(intervals)) {
        cout << "All intervals are non-overlapping. Can attend all." << endl;
    } else {
        cout << "Some intervals overlap. Cannot attend all." << endl;
    }

    return 0;
}
