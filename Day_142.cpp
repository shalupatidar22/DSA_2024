#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the first non-repeating character in a string
char nonRepeatingChar(string &s) {
    unordered_map<char, int> mp;
    // Count occurrences of each character
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    // Find the first character with a count of 1
    for (int i = 0; i < s.size(); i++) {
        if (mp[s[i]] == 1) {
            return s[i];
        }
    }
    return '$'; // Return '$' if no non-repeating character is found
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char result = nonRepeatingChar(str);
    if (result == '$') {
        cout << "No non-repeating character found." << endl;
    } else {
        cout << "The first non-repeating character is: " << result << endl;
    }

    return 0;
}
