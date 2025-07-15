// https://leetcode.com/problems/reverse-words-in-a-string/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;

        // Extract words from the stream
        while (iss >> word) {
            words.push_back(word);
        }

        // Reverse word order
        reverse(words.begin(), words.end());

        // Rebuild the string with single spaces
        ostringstream oss;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) oss << ' ';
            oss << words[i];
        }

        return oss.str();
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