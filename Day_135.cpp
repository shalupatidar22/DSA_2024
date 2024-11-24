#include<bits/stdc++.h>
using namespace std;

  // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }  
        return maxi;
    }

int main(){
    string line;
    getline(cin,line);
    int n;
    stringstream ss(line);
    vector<int> num;
    while(ss >> n){
        num.push_back(n);
    }
    cout<<maxSubarraySum(num);
}