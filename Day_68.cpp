#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        // Your code here
        if(x.size()<=1)return false;
        stack<char> st;
    
        for(int i=0;i<x.size();i++){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
                st.push(x[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(st.top()=='(' && x[i]==')' ){
                    st.pop();
                }
                else if(st.top()=='{' && x[i]=='}'){
                    st.pop();
                }
                else if(st.top()=='[' && x[i]==']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return st.empty();
    }
int main(){
    string s;
    cin>>s;
    cout<<ispar(s);
}