// https://leetcode.com/problems/palindromic-substrings/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n < 2) return 1;

        int count = 0;
        for(int i = 0; i < n; i++) {
            // Find palindromic substrings with odd length.
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                ++count;
                --left; ++right;
            }

            // Find palindromic substrings with evn length.
            left = i; right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                ++count;
                --left; ++right;
            }        
        }
        return count;
    }
};
// Test cases
int main() {
    Solution sol;
    string s;

    cout << "Test case 1" << endl;
    s = "abc";
    cout << "Input: " << s << endl;
    cout << "Result: " << sol.countSubstrings(s) << endl; 
    cout << "Expected: 3" << endl << endl;

    cout << "Test case 2" << endl;
    s = "aaa";
    cout << "Input: " << s << endl;
    cout << "Result: " << sol.countSubstrings(s) << endl; 
    cout << "Expected: 6" << endl << endl;

    cout << "Test case 3" << endl;
    s = "a";
    cout << "Input: " << s << endl;
    cout << "Result: " << sol.countSubstrings(s) << endl; 
    cout << "Expected: 1" << endl << endl;

    cout << "Test case 4" << endl;
    s = "abab";
    cout << "Input: " << s << endl;
    cout << "Result: " << sol.countSubstrings(s) << endl; 
    cout << "Expected: 6" << endl << endl;

    return 0;
}