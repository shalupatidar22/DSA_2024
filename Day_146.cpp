#include<bits/stdc++.h>
using namespace std;

// Function to sort an array containing 0s, 1s, and 2s
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    string line;
    getline(cin, line);
    vector<int> ans;

    // Reading input numbers from a line
    stringstream ss(line);
    int n;
    while (ss >> n) {
        ans.push_back(n);
    }

    // Sorting the array
    sort012(ans);

    // Printing the sorted array
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
