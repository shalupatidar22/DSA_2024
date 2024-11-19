#include<bits/stdc++.h>
using namespace std;

 void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int peak=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                peak=i;
                break;
            }
        }
        if(peak==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        
        for(int i=n-1;i>peak;i--){
            if(arr[peak]<arr[i]){
                swap(arr[peak],arr[i]);
                break;
            }
        }
        reverse(arr.begin()+peak+1,arr.end());
        return;
    }

int main(){
    vector<int> v;
    string line;
    getline(cin,line);
    stringstream ss(line);

    int n;
    while(ss >> n){
        v.push_back(n);
    }
    nextPermutation(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}