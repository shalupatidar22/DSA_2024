#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string& s1, string& s2) {
    // Reverse the input strings for easier computation
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    int n = s1.size(), m = s2.size();
    int carry = 0;
    string ans;
    
    // Perform binary addition
    for (int i = 0; i < max(n, m); i++) {
        if (i < n) carry += s1[i] - '0';
        if (i < m) carry += s2[i] - '0';
        ans.push_back('0' + carry % 2); // Append the binary result (0 or 1)
        carry >>= 1; // Update carry
    }
    
    // If there's a carry left, append it
    if (carry) {
        ans.push_back('0' + carry);
    }
    
    // Remove any leading zeros and reverse the result
    while (ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    string s1, s2;
    cout << "Enter first binary string: ";
    cin >> s1;
    cout << "Enter second binary string: ";
    cin >> s2;

    string result = addBinary(s1, s2);
    cout << "The sum of the binary strings is: " << result << endl;

    return 0;
}
