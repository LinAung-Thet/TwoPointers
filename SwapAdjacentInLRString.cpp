// https://leetcode.com/problems/swap-adjacent-in-lr-string/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        if(n < 2) return start == result;

        bool changed = false;
        do {
            changed = false;
            int i = -1;
            while(i < n - 2) {
                ++i;

                if((start[i] == result[i] && start[i+1] == result[i+1]) ||
                    (start[i] == start[i+1]) || 
                    (start[i] != 'X' && start[i+1] != 'X')) { 
                    continue; 
                }

                string sub {start[i], start[i+1]};
                if((sub == "XL" || sub == "RX") && 
                        start[i] == result[i+1] && start[i+1] == result[i]) {
                    start[i+1] = result[i+1];
                    start[i] = result[i];

                    changed = true;
                }
            }
        } while(changed && start != result);

        return start == result;
    }
};
// Test cases
int main() {
    Solution sol;
    string start, result;

    // cout << "Test case 1" << endl;
    // start = "RXXLRXRXL";
    // result = "XRLXXRRLX";
    // cout << "Start: " << start << endl;
    // cout << "Result: " << result << endl;
    // cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    // cout << "Expected: Yes" << endl << endl;

    // cout << "Test case 2" << endl;
    // start = "X";
    // result = "L";
    // cout << "Start: " << start << endl;
    // cout << "Result: " << result << endl;
    // cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    // cout << "Expected: No" << endl << endl;

    // cout << "Test case 3" << endl;
    // start = "RL";
    // result = "LR";
    // cout << "Start: " << start << endl;
    // cout << "Result: " << result << endl;
    // cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    // cout << "Expected: No" << endl << endl;

    // cout << "Test case 4" << endl;
    // start = "LXXLXRLXXL";
    // result = "XLLXRXLXLX";
    // cout << "Start: " << start << endl;
    // cout << "Result: " << result << endl;
    // cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    // cout << "Expected: No" << endl << endl;

    cout << "Test case 5" << endl;
    start = "XXXXXLXXXX";
    result = "LXXXXXXXXX";
    cout << "Start: " << start << endl;
    cout << "Result: " << result << endl;
    cout << "Can transform: " << (sol.canTransform(start, result) ? "Yes" : "No") << endl; 
    cout << "Expected: Yes" << endl << endl;

    return 0;
}