#include<bits/stdc++.h>
using namespace std;

vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
         vector<int> ans;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                count++;
                continue;
            }
            if(arr[i]==arr[i+1]){
                arr[i]=2*arr[i];
                arr[i+1]=0;
            }
            ans.push_back(arr[i]);
        }
        while(count--){
            ans.push_back(0);
        }
        return ans;
    }
int main(){
    vector<int> a={2,2,0,0,4,0,8};
    vector<int> v=modifyAndRearrangeArray(a);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}