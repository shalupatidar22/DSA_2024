#include<bits/stdc++.h>
using namespace std;

long long findSmallest(vector<int> &arr) {
        // Your code goes here.
           // Your code goes here.
        int sum=0;
        sum+=arr[0];
        if(arr[0]!=1){
            return 1;
        }
        for(int i=1;i<arr.size();i++){
            if(sum+1>=arr[i]){
                sum+=arr[i];
            }
            else{ 
                return sum+1;
            }
        }
        return sum+1;
    }
int main(){
    vector<int> ar={1,2,4,6,8,9};
    cout<<findSmallest(ar);
}