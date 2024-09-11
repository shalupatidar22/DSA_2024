#include<bits/stdc++.h>
using namespace std;

long long minCost(vector<long long>& arr) {
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        for(auto it: arr){
            pq.push(it);
        }
        
        long long ans=0;
        while(pq.size()>1){
            long long ele1=pq.top();
            pq.pop();
            long long ele2=pq.top();
            pq.pop();
            int sum=ele1+ele2;
            ans+=sum;
            pq.push(sum);
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<minCost(a);
}