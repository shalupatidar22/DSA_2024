#include<bits/stdc++.h>
using namespace std;

 vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int> ans;
        int i=0,j=n-1;
        while(i<=j){
            if(i==j){
                ans.push_back(arr[i]);
                break;
            }
            ans.push_back(arr[j]);
            ans.push_back(arr[i]);
            i++;
            j--;
        }
        return ans;
    }

int main(){
    vector<int> a={3,2,8,9,5,1,4};
    vector<int> v=alternateSort(a);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}