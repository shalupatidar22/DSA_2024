#include<bits/stdc++.h>
using namespace std;

int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
                }
            }
        }
        return dp[n-1];
    }
int main(){
    vector<int> ans={10,30,40,20,50};
    cout<<minimizeCost(3,ans);
}