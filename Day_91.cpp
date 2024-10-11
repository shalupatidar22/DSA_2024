#include<bits/stdc++.h>
using namespace std;

 vector<int> rearrange(const vector<int>& arr) {
        // Code here
        unordered_set<int>st(arr.begin(), arr.end());
        int n=arr.size();
        vector<int>ans(n, -1);
        
        for(int i=0; i<n; i++){
            if(st.find(i)!=st.end()){
                ans[i]=i;
            }
        }
        return ans;
    }
int main(){
    vector<int> arr={3,2,5,6,4,7,0};
    vector<int> ans=rearrange(arr);
    for(auto it:ans){
        cout<<it;
    }
}