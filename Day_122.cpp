#include<bits/stdc++.h>
using namespace std;

int minIncrements(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                ans+=arr[i-1]-arr[i]+1;
                arr[i]=arr[i-1]+1;
                
            }
        }
        return ans;
       
    }
int main(){
    vector<int> v={1,3,9,3,1};
    cout<<minIncrements(v);
}