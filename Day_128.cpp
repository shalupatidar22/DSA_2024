#include<bits/stdc++.h>
using namespace std;


void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

int main(){
    vector<int> v={2,4,1,5,7};
    reverseArray(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}