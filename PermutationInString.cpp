// https://leetcode.com/problems/permutation-in-string/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        
        // Build the frequency table of the characters in s1
        int freqTable[26] = {0};
        for(auto c: s1) {
            ++freqTable[c - 'a'];
        }

        // Build the frequency table of the characters inside the sliding window of s2
        int window[26] = {0};
        for(int i=0; i < n; i++) {
            ++window[s2[i] - 'a'];
        }

        // Compare the 2 frequency tables
        if(equal(freqTable, freqTable + 26, window)) 
            return true;

        // Move the sliding window along s2 and compare the tables
        for(int i = n; i < m; i++) {
            --window[s2[i - n] - 'a']; // remove the old letter
            ++window[s2[i] - 'a'];     // add the new letter

            if(equal(freqTable, freqTable + 26, window)) 
                return true;
        }

        return false;
    }
};
// Test cases
int main() {
    Solution sol;
    string s1, s2;

    cout << "Test case 1" << endl;
    s1 = "ab";
    s2 = "eidbaooo";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Result: " << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl; 
    cout << "Expected: true" << endl << endl;

    cout << "Test case 2" << endl;
    s1 = "ab";
    s2 = "eidboaoo";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Result: " << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl; 
    cout << "Expected: false" << endl << endl;

    cout << "Test case 3" << endl;
    s1 = "hello";
    s2 = "ooolleoooleh";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Result: " << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl; 
    cout << "Expected: false" << endl << endl;

    cout << "Test case 4" << endl;
    s1 = "sea";
    s2 = "ate";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "Result: " << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl; 
    cout << "Expected: false" << endl << endl;

    return 0;
}