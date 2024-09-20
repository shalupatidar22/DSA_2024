#include<bits/stdc++.h>
using namespace std;

 // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int cnt=0;
        int maxi=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>maxi){
                cnt++;
                maxi=max(maxi,height[i]);
            }
        }
        return cnt;
    }
int main(){
    int n;
    cin>>n;
    vector<int> ht(n);
    for(int i=0;i<n;i++){
        cin>>ht[i];
    }
    cout<<countBuildings(ht);
}