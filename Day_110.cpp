#include<bits/stdc++.h>
using namespace std;

/* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        map<int,int> map;
        for(int i:arr) map[i]++;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            //  main condition
            if(map[ k + arr[i]]) count += map[k+arr[i]];
        }
        return count;
    }

int main(){
    vector<int> a={4,5,9,8,2,10};
    cout<<countPairsWithDiffK(a,2);
}