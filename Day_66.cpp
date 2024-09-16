#include<bits/stdc++.h>
using namespace std;

int maxLength(string& str) {
        // code here
        stack<int> st;
        st.push(-1);
        
        int maxi = 0;
        
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i-st.top();
                    maxi = max(maxi,len);
                }
            }
        }
        return maxi;
    }
int main(){
    string s;
    cin>>s;

    cout<<maxLength(s);
}