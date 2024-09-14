#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        
        int m=pos.size();
        int o=neg.size();
        int i=0;
        int j=0;
        int k=0;
        while(i<n){
            if(j<m){
                arr[i]=pos[j];
                i++;
                j++;
            }
            if(k<o){
                arr[i]=neg[k];
                i++;
                k++;
            }
        }
    }
int main(){
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    rearrange(ar);
}