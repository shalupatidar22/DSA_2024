#include<bits/stdc++.h>
using namespace std;


 // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> temp;
    
        // Normalize d in case it is greater than n
        d = d % n;
    
        // Store the first d elements in temp
        for (int i = 0; i < d; i++) {
            temp.push_back(arr[i]);
        }
    
        // Shift the remaining elements of arr to the beginning
        for (int i = d; i < n; i++) {
            arr[i - d] = arr[i];
        }
    
        // Copy the elements from temp to the end of arr
        for (int i = 0; i < d; i++) {
            arr[n - d + i] = temp[i];
        }
    }

int main(){
    vector<int> a={3,4,5,7,9};
    rotateArr(a,2);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}