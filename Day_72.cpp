#include<bits/stdc++.h>
using namespace std;

int lps(string str) {
        // Your code goes here
      int n=str.size();
      int p=0,suf=1,pos=1,cnt=0;
      while(p<n && suf<n){
          if(str[p]==str[suf]){
            p++;
            suf++;
            cnt++;
          }
          else{
              p=0;
              pos++;
              suf=pos;
              cnt=0;
          }
          
      }
      
      return cnt;
    }
int main(){
    string s="";
    cin>>s;
    cout<<lps(s);
}