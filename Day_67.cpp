#include<bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
        // code here
       int n = arr.size();
        if(n==1)
        {
            return 0;
        }
        sort(arr.begin(),arr.end());
        
        int aks = arr[n-1] - arr[0];
        
        int s = arr[0] + k;
        int l = arr[n-1] - k;
        for(int i = 0 ;i<n-1;i++)
        {
            int mini = min(s,arr[i+1] - k);
            int maxi = max(l,arr[i]+k);
            if(mini>=0)
            {
              aks = min(aks,maxi-mini);  
            }
            
        }
        return aks;
    }

int main(){
    int n;
    cin>>n;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int s;
    cin>>s;

    cout<<getMinDiff(ans,s);
}