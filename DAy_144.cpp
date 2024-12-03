#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(string s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to calculate the minimum number of characters to add
int minChar(string& s) {
    string rev_str = s;
    reverse(rev_str.begin(), rev_str.end());

    // Concatenate the string with its reverse, separated by a special character
    string concat_str = s + "#" + rev_str;

    // Compute the LPS array for the concatenated string
    vector<int> lps = computeLPS(concat_str);

    // Find the length of the longest palindromic prefix
    int palin_prefix_len = lps.back();

    // Return the number of characters needed to make the string a palindrome
    return s.length() - palin_prefix_len;
}

// Main function for testing
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = minChar(s);

    cout << "Minimum characters to add to make the string a palindrome: " << result << endl;

    return 0;
}
