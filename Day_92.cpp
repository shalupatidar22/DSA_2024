#include<bits/stdc++.h>
using namespace std;

int pairWithMaxSum(vector<int>& arr) {
        // code here
           if(arr.size()==1){
            return -1;
        }
        int left=1;int right=arr.size();
        int nums=arr[0];
        int ans=INT_MIN;
        while(left<right){
            nums+=arr[left];
            ans=max(ans,nums);
            nums=arr[left];
            left++;
        }
        return ans;
    }
int main(){
    vector<int> a={2,3,7,9,4,6};
    cout<<pairWithMaxSum(a);
}
