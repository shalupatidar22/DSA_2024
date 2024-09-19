#include<bits/stdc++.h>
using namespace std;

 // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string res="";
        string cur="";
        int n=str.size();
        for(int i=0;i<str.size();i++){
            if(str[i]=='.'){
                res=cur+'.'+res;
                cur="";
            }
            else{
                cur+=str[i];
            }
        }
        res=cur+"."+res;
        return res.substr(0,n);
    }

int main(){
    string s;
    cin>>s;
    cout<<reverseWords(s);
}