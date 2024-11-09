#include<bits/stdc++.h>
using namespace std;


string minSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s1="";
        string s2="";
        for(int i=0;i<n;i++){
            if(i%2==0) s1+=to_string(arr[i]);
            else s2+=to_string(arr[i]);
        }
        string ans;
        int i=0,j=0;
        int carry=0;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        while(i<s1.size() || j<s2.size()){
            int sum=0;
            if(i<s1.size()) sum+=s1[i++]-'0';
            if(j<s2.size()) sum+=s2[j++]-'0';
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ans+=to_string(sum);
        }
        ans+=to_string(carry);
        while(ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    vector<int> a={4,3,8,9,2,3};
    cout<<minSum(a);
}