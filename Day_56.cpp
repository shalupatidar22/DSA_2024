#include<iostream>
#include<vector>
using namespace std;

/*Kadane's Algorithm :  Given an integer array arr[].
 Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.
  */


long long maxSubarraySum(vector<int> &arr) {
        
       long long sum=0;
       long long maxsum=INT_MIN;
       for(int i=0;i<arr.size();i++){
           sum+=arr[i];
           if(sum>maxsum){
               maxsum=sum;
           }
           if(sum<0){
               sum=0;
           }
       }
       return maxsum;
    }

int main(){
    int N;
    cin>>N;
    vector<int> ar(N);
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }

    cout<<maxSubarraySum(ar);
}