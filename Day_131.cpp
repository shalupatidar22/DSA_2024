#include<bits/stdc++.h>
using namespace std;

 // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n=arr.size();
        int m=n/3;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second>m){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

int main(){
        string line;
        getline(cin,line);
        stringstream ss(line);
        int num;
        vector<int> v;
        while(ss >> num){
            v.push_back(num);
        }
        vector<int> res=findMajority(v);
        if(v.empty()){
            cout<<"[]";
        }
        else{
            for(auto &i:res){
                cout<< i << " ";
            }
            cout<<"\n";
        }
}