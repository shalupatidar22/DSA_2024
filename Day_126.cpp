#include<bits/stdc++.h>
using namespace std;

 // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
       int first_bada=arr[0];
       int second_bada=arr[1];
       if(first_bada<second_bada){
           swap(first_bada,second_bada);
       }
       for(int i=2;i<n;i++){
           if(arr[i]>first_bada){
               second_bada=first_bada;
               first_bada=arr[i];
           }
           else if(arr[i]>second_bada && arr[i]<first_bada){
               second_bada=arr[i];
           }
       }
     
       if(first_bada==second_bada){
           return -1;
       }
         return second_bada;
    }

int main(){
    vector<int> s={3,2,10,15,1,30};
    cout<<getSecondLargest(s);
}