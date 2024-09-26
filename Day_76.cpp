#include<bits/stdc++.h>
using namespace std;
 // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code
        int maxi=INT_MIN;
       
        int n=arr.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            while (i < n - 1 && arr[i] < arr[i + 1]) {
            cnt++;  // Increase the count for each step
            i++;    // Move to the next element
        }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
int main(){
   vector<int> arr = {1, 2, 2, 3, 5, 6, 1, 2, 3, 4};
    cout << "Maximum increasing steps: " << maxStep(arr) << endl;

    return 0;
}