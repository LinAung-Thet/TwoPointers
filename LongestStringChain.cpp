// https://leetcode.com/problems/longest-string-chain/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int checkWordChain(unordered_map<int, vector<int>>& table, int x, int y) {
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n < 2) return 1;

        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // Build Word length table
        unordered_map<int, vector<int>> wordCountTable;
        int length = 0, i = 0;
        for (const string& word : words) {
            int wordLength = word.size();
            if(length != 0 && wordLength > length + 1)
                break; // No longer possible to form a chain

            wordCountTable[wordLength].push_back(i++);
            length = wordLength;
        }

        int m = wordCountTable.size();
        vector<int> ids = wordCountTable[m - 1];

        for (int i = 0; i < ids.size(); i ++) {

        }

        return 0;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<string> words;

    // cout << "Test case 1" << endl;
    // words = {"a", "b", "ba", "bca", "bda", "bdca", "bdcaed"};
    // cout << "Words: ";
    // for (const string& word : words) cout << word << " ";
    // cout << endl;
    // cout << "Expected: 5" << endl;
    // cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    cout << "Test case 2" << endl;
    words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << "Words: ";
    for (const string& word : words) cout << word << " ";
    cout << endl;
    cout << "Expected: 5" << endl;
    cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    // cout << "Test case 3" << endl;
    // words = {"abcd","dbqca"};
    // cout << "Words: ";
    // for (const string& word : words) cout << word << " ";
    // cout << endl;
    // cout << "Expected: 1" << endl;
    // cout << "Result  : " << sol.longestStrChain(words) << endl << endl;

    return 0;
}