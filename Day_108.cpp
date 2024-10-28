#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int,int> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(s.find(arr[i])==s.end()){
                ans.push_back(arr[i]);
                s[arr[i]]++;
            }
        }
        return ans;
    }
int main(){
    vector<int> v={2,2,3,4,5,5};
    vector<int> ans=removeDuplicate(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}