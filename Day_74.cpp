#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string smallestWindow(string s, string p) {
    int n = s.length();
    int m = p.length();
    
    if (m > n) return "-1";
    
    vector<int> pFreq(26, 0);
    vector<int> windowFreq(26, 0);
    
    for (char c : p) {
        pFreq[c - 'a']++;
    }
    
    int start = 0, minStart = -1, minLen = INT_MAX;
    int count = 0;
    int required = 0;
    
    for (int i = 0; i < 26; i++) {
        if (pFreq[i] > 0) required++;
    }
    
    for (int end = 0; end < n; end++) {
        int index = s[end] - 'a';
        windowFreq[index]++;
        
        if (pFreq[index] > 0 && windowFreq[index] == pFreq[index]) {
            count++;
        }
        
        while (count == required) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }
            
            index = s[start] - 'a';
            windowFreq[index]--;
            
            if (pFreq[index] > 0 && windowFreq[index] < pFreq[index]) {
                count--;
            }
            
            start++;
        }
    }
    
    return minStart == -1 ? "-1" : s.substr(minStart, minLen);
}

int main() {
    string s1 = "timetopractice";
    string p1 = "toc";
    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"" << endl;
    cout << "Output: " << smallestWindow(s1, p1) << endl;
    
    string s2 = "zoomlazapzo";
    string p2 = "oza";
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"" << endl;
    cout << "Output: " << smallestWindow(s2, p2) << endl;
    
    return 0;
}