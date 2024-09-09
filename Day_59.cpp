#include<iostream>
#include<vector>

using namespace std;

void sort012(vector<int>& arr) {
        // code here
       int low=0,mid=0,high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }

int main(){
    int N;
    cin>>N;
    vector<int> ar(N);
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }
    sort012(ar);
}