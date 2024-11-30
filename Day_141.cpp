#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string& s1, string& s2) {
    // If the lengths of the strings are not the same, they can't be anagrams
    if (s1.length() != s2.length()) {
        return false;
    }

    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Compare the sorted strings
    return s1 == s2;
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
