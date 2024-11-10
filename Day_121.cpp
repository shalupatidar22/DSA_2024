#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int n=a.size();
        int m=b.size();
        vector<int> ans;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i]<b[j]){
              ans.push_back(a[i++]);  
            }
            else if(b[j]<a[i]){
                ans.push_back(b[j++]);
            }
            else{
                ans.push_back(a[i++]);
                j++;
            }
        }
        
        while(i<n){
            ans.push_back(a[i++]);  
        }
         while(j<m){
            ans.push_back(b[j++]);  
        }
        return ans;
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={1,2,3};

    vector<int> res=findUnion(arr1,arr2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}