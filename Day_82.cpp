#include<bits/stdc++.h>
using namespace std;

 int rotateDelete(vector<int> &arr) {
        // Your code here
       int n=arr.size();
       int k=1;
       while(n>1){
           arr.insert(arr.begin(),arr.back());
           arr.pop_back();
           if(k>n){
               arr.erase(arr.begin());

           }
           else arr.erase(arr.begin()+(n-k));
           n=arr.size();
           k++;
       }
       return arr[0];
    }

int main(){
    vector<int> ans={2,4,6,7,8,9,10};
    cout<<rotateDelete(ans);
}