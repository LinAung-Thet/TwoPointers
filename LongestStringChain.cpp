// https://leetcode.com/problems/longest-string-chain/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int maxLen = 1;

        for (const string& word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pred)) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }
            maxLen = max(maxLen, dp[word]);
        }

        return maxLen;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<string> words;

    cout << "Test case 1" << endl;
    words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "Words: ";
    for (const string& word : words) cout << word << " ";
    cout << endl;
    cout << "Expected: 4" << endl;
    cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    cout << "Test case 2" << endl;
    words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << "Words: ";
    for (const string& word : words) cout << word << " ";
    cout << endl;
    cout << "Expected: 5" << endl;
    cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    cout << "Test case 3" << endl;
    words = {"abcd","dbqca"};
    cout << "Words: ";
    for (const string& word : words) cout << word << " ";
    cout << endl;
    cout << "Expected: 1" << endl;
    cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    return 0;
}