#include<bits/stdc++.h>
using namespace std;

 int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0,cntx=0,cnty=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                cntx++;
            }
            if(arr[i]==y){
                cnty++;
            }
            int diff=cntx-cnty;
            if(mp.find(diff)!=mp.end()){
                ans+=mp[diff];
            }
            mp[diff]++;
        }
        return ans;
    }

int main(){
    vector<int> a={1,2,1};
    cout<<sameOccurrence(a,1,2);
}