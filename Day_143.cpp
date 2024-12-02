#include<bits/stdc++.h>
using namespace std;

 vector<int> search(string& pat, string& txt) {
        // code here
        vector<int>ans;
       int k=pat.length();
       for(int i=0;i<txt.length()-k+1;i++){
          if(pat[0]!=txt[i])
          continue;
           string str=txt.substr(i,k);
           if(str==pat)
           ans.push_back(i);
       }
       return ans;
    }

int main(){
    string s,s1;
    cin>>s >> s1;
    vector<int> res= search(s,s1);
    if(res.size()==0) cout<<"[]";
    else{
        for(int i=0;i,res.size();i++){
            cout<<res[i];
        }
    }
}