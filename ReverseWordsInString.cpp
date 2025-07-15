// https://leetcode.com/problems/reverse-words-in-a-string/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        stack<string> stk;

        // Push each word onto the stack
        while (iss >> word) {
            stk.push(word);
        }

        // Build reversed string from stack
        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
            if (!stk.empty()) result += " ";
        }

        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    string s;

    // Test case 1
    s = "the sky is blue";
    cout << "Original: " << s << endl;
    cout << "Result  : " << sol.reverseWords(s) << endl; 
    cout << "Expected: blue is sky the" << endl << endl;

    // Test case 2
    s = "  hello world  ";
    cout << "Original: " << s << endl;
    cout << "Result  : " << sol.reverseWords(s) << endl; 
    cout << "Expected: world hello" << endl << endl;

    // Test case 3
    s = "a good   example";
    cout << "Original: " << s << endl;
    cout << "Result  : " << sol.reverseWords(s) << endl; 
    cout << "Expected: example good a" << endl;

    return 0;
}