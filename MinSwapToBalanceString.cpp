// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;     // Number of unmatched closing brackets
        int swaps = 0;         // Minimum swaps needed
        int open = 0;          // Count of '[' seen so far

        for (char ch : s) {
            if (ch == '[')
                ++open;
            else {  // ch == ']'
                if (open > 0)
                    --open;    // Match found
                else {
                    ++imbalance;   // Need to swap in a '[' later
                }
            }
        }

        // Each swap fixes two brackets: one '[' and one ']'
        return (imbalance + 1) / 2;
    }
};
// Test cases
int main() {
    Solution sol;
    string s;

    cout << "Test case 1" << endl;
    s = "]]][[[";
    cout << "String: " << s << endl;
    cout << "Minimum swaps: " << sol.minSwaps(s) << endl; // Expected: 2
    cout << "Expected     : 2" << endl << endl;

    cout << "Test case 2" << endl;
    s = "[]";
    cout << "String: " << s << endl;
    cout << "Minimum swaps: " << sol.minSwaps(s) << endl; // Expected: 0
    cout << "Expected     : 0" << endl << endl;

    cout << "Test case 3" << endl;
    s = "][][";
    cout << "String: " << s << endl;
    cout << "Minimum swaps: " << sol.minSwaps(s) << endl; // Expected: 0
    cout << "Expected     : 1" << endl << endl;

    return 0;
}