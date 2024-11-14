#include<bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int>& arr, int k) {
        // code
        int n=arr.size();
        priority_queue<int ,vector<int>,greater<int>> pq;
        for(int i=0;i<=k;i++){
            pq.push(arr[i]);
        }
        int j=0;
        for(int i=k+1;i<n;i++){
            arr[j++]=pq.top();
            pq.pop();
            pq.push(arr[i]);
            
        }
        while(!pq.empty()){
            arr[j++]=pq.top();
            pq.pop();
        }
    }

int main(){
    vector<int> m={6, 5, 3, 2, 8, 10, 9};
    nearlySorted(m,3);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
    }

}