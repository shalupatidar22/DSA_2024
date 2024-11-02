#include <iostream>
#include <vector>
using namespace std;
bool containsNearbyDuplicate(const vector<int>& arr, int k) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j] && j - i <= k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int k = 3;

    bool result = containsNearbyDuplicate(arr, k);

    cout << "Contains nearby duplicate within distance " << k << ": " 
              << (result ? "true" : "false") << endl;

    return 0;
}
