#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
int maxProduct(vector<int> &arr) {
    int pre = 1, suff = 1;
    int n = arr.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];
        maxi = max(maxi, max(pre, suff));
    }

    return maxi;
}

int main() {
    vector<int> v = {-2, 6, -3, -10, 0, 2};
    cout << maxProduct(v);
    return 0; // Added return statement for `main` function
}
