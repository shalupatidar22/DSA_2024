#include<bits/stdc++.h>
using namespace std;

  bool checkSorted(vector<int> &arr) {
        int cnt = 0;
        for(int i = 0; i<arr.size(); i++){
            while(arr[i] != i+1){
                swap(arr[i],arr[arr[i]-1]);
                cnt++;
                
                if(cnt>2){
                    return false;
                }

            }
        }
        if(cnt == 0 || cnt == 2){
        return true;
        }
        else{
            return false;
        }
    }

int main() {
    vector<int> a = {4, 3, 2, 1};

    bool ans = checkSorted(a);
    
    if (ans) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
