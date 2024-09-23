#include<bits/stdc++.h>
using namespace std;

 vector<int> findTwoElement(vector<int>& arr) {
       vector<int>ans;
        int miss,extra=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            auto it=mp.find(i);
            if(it==mp.end()) miss=i;
            if(it!=mp.end() && it->second==2) extra=i;
        }
        ans.push_back(extra);
        ans.push_back(miss);
        return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

     vector<int> result = findTwoElement(arr);
    cout << "Extra element: " << result[0] << endl;
    cout << "Missing element: " << result[1] << endl;

    return 0;


}