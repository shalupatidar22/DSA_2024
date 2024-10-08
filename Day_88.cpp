#include<bits/stdc++.h>
using namespace std;
int pairsum(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        return arr[n-1]+arr[n-2];
    }

int main(){
    vector<int> a={20,90,5,30,50};
    cout<<pairsum(a);
}
