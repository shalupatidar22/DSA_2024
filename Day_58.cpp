#include<iostream>
#include<vector>

using namespace std;
int minJumps(vector<int>& arr) {
        // Your code here
      int mr=0;
      int maxi=0;
      int jumps=0;
      int n=arr.size();
      for(int i=0;i<arr.size();i++){
           maxi=max(maxi,i+arr[i]);
          if(i==mr){
              jumps++;
              mr=maxi;
              if(mr>=n-1){
                  return jumps;
              }
          }
      }
      return -1;
    }

int main(){
    int n;
    cin>>n;

    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    cout<<minJumps(ar);
}
