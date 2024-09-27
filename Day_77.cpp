#include<bits/stdc++.h>
using namespace std;

// Function to find maximum of each subarray of size k.
     vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n = arr.size();
        vector<int> result; // To store the result of max of each subarray
        deque<int> dq;      // Will store indexes of elements in arr

        for (int i = 0; i < n; i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from back while they are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current element at the back of the deque
            dq.push_back(i);

            // Starting from index k-1, add the maximum of each window to the result
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
int main(){
    vector<int> out={1,2,3,5,-1,6,3};
    vector<int> res=max_of_subarrays(3,out);

    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }


}