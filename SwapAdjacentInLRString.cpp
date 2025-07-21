// https://leetcode.com/problems/swap-adjacent-in-lr-string/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string result) {
        if (start.length() != result.length()) return false;

        int n = start.length();
        int i = 0, j = 0;

        while (i < n && j < n) {
            // Skip 'X' characters
            while (i < n && start[i] == 'X') ++i;
            while (j < n && result[j] == 'X') ++j;

            // If both strings are fully traversed
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;

            // Characters at current positions must match (ignoring X)
            if (start[i] != result[j]) return false;

            // Movement constraints
            if (start[i] == 'L' && i < j) return false; // L can only move left
            if (start[i] == 'R' && i > j) return false; // R can only move right

            ++i;
            ++j;
        }

        // Remaining characters should be only X
        while (i < n) if (start[i++] != 'X') return false;
        while (j < n) if (result[j++] != 'X') return false;

        return true;
    }
};
// Test cases
int main() {
    Solution sol;
    string start, result;

    cout << "Test case 1" << endl;
    start = "RXXLRXRXL";
    result = "XRLXXRRLX";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: Yes" << endl << endl;

    cout << "Test case 2" << endl;
    start = "X";
    result = "L";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: No" << endl << endl;

    cout << "Test case 3" << endl;
    start = "RL";
    result = "LR";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: No" << endl << endl;

    cout << "Test case 4" << endl;
    start = "LXXLXRLXXL";
    result = "XLLXRXLXLX";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: No" << endl << endl;

    cout << "Test case 5" << endl;
    start = "XXXXXLXXXX";
    result = "LXXXXXXXXX";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: Yes" << endl << endl;

    return 0;
}