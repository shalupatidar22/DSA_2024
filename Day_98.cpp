#include<bits/stdc++.h>
using namespace std;

 int getSingle(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second%2!=0){
                return it.first;
            }
        }
    }
int main(){
    vector<int> a={2,2,3,3,3,4,4};
    cout<<getSingle(a);
}