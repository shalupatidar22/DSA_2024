#include<bits/stdc++.h>
using namespace std;

 // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
       int n=arr.size();
        sort(arr.begin(), arr.end());
        int cnt=1;
        
        for(int i=0; i<n; i++){
            if(arr[i]<=0) continue;
            else if(arr[i]==cnt){
                cnt++;
            }else if(arr[i]<cnt){
                continue;
            }else{
                return cnt;
            }
        }
        return cnt;
        
    }

int main(){
    vector<int> v={2, -3, 4, 1, 1, 7};
    cout<<missingNumber(v);
}