#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);  // Calculate the total sum of elements in the array
        
        // If sum is not divisible by 3, it's not possible to divide into 3 equal parts
        if (sum % 3 != 0) return {-1, -1};
        
        int target = sum / 3;  // The target sum for each of the three parts
        int first = -1, second = -1;
        int curr_sum = 0;
        
        // Iterate through the array to find two positions where the array can be split
        for (int i = 0; i < arr.size(); i++) {
            curr_sum += arr[i];
            
            // If the current sum matches the target, mark the split point
            if (curr_sum == target) {
                if (first == -1) {
                    first = i;  // First split point found
                } else if (second == -1) {
                    second = i;  // Second split point found
                    break;  // Stop after finding both split points
                }
                curr_sum = 0;  // Reset the current sum after a successful split
            }
        }
        
        // If both split points are found, return their indices
        if (first != -1 && second != -1)
            return {first, second};
        else
            return {-1, -1};  // Return {-1, -1} if no valid split is found
    }
};

// Test the function
int main() {
    Solution solution;
    vector<int> arr = {3, 3, 3, 3, 3, 3};
    
    vector<int> result = solution.findSplit(arr);
    
    if (result[0] != -1 && result[1] != -1) {
        cout << "Array can be split at indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Array cannot be split into three equal sum sets." << endl;
    }

    return 0;
}
