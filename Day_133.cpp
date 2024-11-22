#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
        // code here
        int profit=0;
        int n=prices.size();
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit =max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }

int main(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    int n;
    vector<int> v;
    while(ss >> n){
        v.push_back(n);
    }
    cout<<maximumProfit(v);
}