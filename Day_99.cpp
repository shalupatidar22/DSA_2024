#include<bits/stdc++.h>
using namespace std;

 string roundToNearest(string str) {
        // Complete the function
        int n=str.length();
        n--;
        if(str[n]<='5'){
            str[n]='0';
            return str;
        }
        str[n]='0';
        n--;
        while(n>=0 && str[n]=='9'){
            str[n]='0';
            n--;
        }
        if(n==-1)return '1'+str;
        str[n]+=1;
        return str;
    }

int main(){
    string s;
    cin>>s;
    cout<<roundToNearest(s);
}