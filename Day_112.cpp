#include <bits/stdc++.h>
using namespace std;

long long maxSum(vector<int>& arr) {
    // Sort the array to facilitate picking elements from both ends
    sort(arr.begin(), arr.end());

    long long n = arr.size();
    long long i = 0, j = n - 1;
    vector<int> temp;

    // Alternate picking elements from both ends
    while (i <= j) {
        if (i == j) {
            temp.push_back(arr[i]);
            break;
        }
        temp.push_back(arr[i]);
        temp.push_back(arr[j]);
        i++;
        j--;
    }

    // Calculate the difference sum
    long long diff = 0;
    for (int k = 0; k < n - 1; k++) {
        diff += abs(temp[k] - temp[k + 1]);
    }
    // Add the difference between the first and last element
    diff += abs(temp[0] - temp[n - 1]);

    return diff;
}
int main(){
    vector<int> a={2,6,5,8,9};
    long long ans=maxSum(a);
    cout<<ans;
}