#include<bits/stdc++.h>
using namespace std;

 int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int>map;
        int dist=0;
        for(int i=0;i<arr.size();i++){
            if(map.find(arr[i])==map.end())map[arr[i]]=i;
            else dist=max(dist,i-map[arr[i]]);
        }
        return dist;
    }
int main(){
    vector<int> arr={1, 1, 2, 2, 2, 1};
    cout<<maxDistance(arr);
}