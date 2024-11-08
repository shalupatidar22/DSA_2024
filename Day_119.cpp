#include <iostream>
#include <string>
using namespace std;

int minRepeats(string& s1, string& s2) {
    string rep = s1;   // Store the original string
    int cnt = 1;       // Start with one repetition

    // Keep adding the original string until the length of s1 is at least as large as s2
    while(s1.size() < s2.size()) {
        s1 += rep;
        cnt++;
    }

    // Check if s2 is now a substring of s1
    if(s1.find(s2) != string::npos) {
        return cnt;
    }

    // Add one more repetition and check again
    s1 += rep;
    cnt++;
    if(s1.find(s2) != string::npos) {
        return cnt;
    }

    // If s2 is still not a substring, return -1
    return -1;
}

int main() {
    string s1 = "abcd";
    string s2 = "cdabcdab";
    int result = minRepeats(s1, s2);

    if(result != -1) {
        cout << "Minimum repeats required: " << result << endl;
    } else {
        cout << "Not possible to form s2 as a substring of repeated s1." << endl;
    }

    return 0;
}
