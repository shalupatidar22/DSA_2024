#include<bits/stdc++.h>
using namespace std;

 int countgroup(vector<int>& arr) {
        // Complete the function
        int n=arr.size();
        int xr=0;
        for(int i=0;i<n;i++){
            xr^=arr[i];
        }
        if(xr!=0)return 0;
        int ans=1;
        int mod=1000000007;
        for(int i=0;i<n-1;i++){
            ans=(ans*2)%mod;
        }
        return ans-1;
    }
int main(){
    vector<int> a={1,2,3};
    cout<<countgroup(a);
}