#include<iostream>
#include<vector>
using namespace std;

int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
    int idx=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            idx=i+1;
            break;
        }
    }
    if(idx==0)return n;
    return idx;
        
}

int main(){
    int N;
    cin>>N;
    vector<int> ar(N);
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }

    cout<<missingNumber(N,ar);

}