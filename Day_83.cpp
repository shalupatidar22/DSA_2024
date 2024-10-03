#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int m=floor(n/3);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second>m){
                ans.push_back(it.first);
            }
        }
        
        sort(ans.begin(),ans.end());
        if(ans.empty()){
            return {-1};
        }
        return ans;
    }

int main(){
    vector<int>res={2,2,2,2,3,4,5,6,6,6,6};
    vector<int> my=findMajority(res);
    for(int i=0;i<my.size();i++){
        cout<<my[i]<<" ";
    }
}