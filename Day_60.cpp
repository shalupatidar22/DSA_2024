#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int isCircle(vector<string> &arr) {
        int n = arr.size(), start = 0;
        vector<vector<bool>> graph(26, vector<bool>(26));
        vector<int> degree(26);
        for (auto &str : arr) {
            int u = str.front() - 'a', v = str.back() - 'a';
            degree[u]++, degree[v]--;
            graph[u][v] = true;
            start = u;
        }
        if (any_of(degree.begin(), degree.end(), [&](int x) { return x; })) 
            return false;
        auto dfs = [&](auto self, int u) -> void {
            for (int v = 0; v < 26; v++)
                if (graph[u][v])
                    graph[u][v] = false, self(self, v);
        };
        dfs(dfs, start);
        return !any_of(graph.begin(), graph.end(), [&](const auto &v) { return count(v.begin(), v.end(), 1); });
    }

int main(){
    int n;
    cin>>n;
    vector<string> A;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        A.push_back(s);
    }
    cout<<isCircle(A);
}