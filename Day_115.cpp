#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr) {
    int n = arr.size();
    // Sort the array to handle duplicates and make it easier to find triplets
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    // Iterate through each element as a potential first element in a triplet
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                ans.push_back({arr[i], arr[left], arr[right]});
                
                // Skip duplicates for the second element
                while (left < right && arr[left] == arr[left + 1]) left++;
                // Skip duplicates for the third element
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = findTriplets(arr);

    cout << "Triplets that sum to zero are:" << endl;
    for (const auto &triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}
