#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
        // code here
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            if(prices[i+1]>prices[i]) profit+= prices[i+1]-prices[i];
         }
        return profit;
    }
int main(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int> v;
    int n;
    while(ss>> n){
        v.push_back(n);
    }
    cout<<maximumProfit(v);
}