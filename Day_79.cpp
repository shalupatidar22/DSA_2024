#include<bits/stdc++.h>
using namespace std;

int totalCount(int k, vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(arr[i]>k){
               arr[i]=arr[i]-k;
               cnt++;
            }
           sum+=cnt+1; 
        }
        return sum;
    }

int main(){
    vector<int> res={5,8,9,2,6,10};
    cout<<totalCount(3,res);
}