// https://leetcode.com/problems/camelcase-matching/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;

        for (const string& query : queries) {
            int i = 0, j = 0;

            while (i < query.size() && j < pattern.size()) {
                if (query[i] == pattern[j]) {
                    ++i;
                    ++j;
                } else if (islower(query[i])) {
                    ++i;
                } else {
                    break;
                }
            }

            // Match is valid if entire pattern is consumed and remaining query chars are lowercase
            bool isMatch = (j == pattern.size());
            while (i < query.size()) {
                if (isupper(query[i])) {
                    isMatch = false;
                    break;
                }
                ++i;
            }

            result.push_back(isMatch);
        }

        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<string> queries;
    string pattern;
    vector<bool> result;

    cout << "Test case 1" << endl;
    queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    pattern = "FB";
    result = sol.camelMatch(queries, pattern);
    cout << "Pattern: " << pattern << endl;
    cout << "Expected: true false true true false" << endl;
    cout << "Result  : ";
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    pattern = "FoBa";
    result = sol.camelMatch(queries, pattern);
    cout << "Pattern: " << pattern << endl;
    cout << "Expected: true false true false false" << endl;
    cout << "Result  : ";
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl << endl;

    cout << "Test case 3" << endl;
    queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    pattern = "FoBaT";
    result = sol.camelMatch(queries, pattern);
    cout << "Pattern: " << pattern << endl;
    cout << "Expected: false true false false false" << endl;
    cout << "Result  : ";
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl << endl;

    cout << "Test case 4" << endl;
    queries = {"uAxaqlzahfialcezsLfj","cAqlzyahaslccezssLfj","AqlezahjarflcezshLfj","AqlzofahaplcejuzsLfj","tAqlzahavslcezsLwzfj","AqlzahalcerrzsLpfonj","AqlzahalceaczdsosLfj","eAqlzbxahalcezelsLfj"};
    pattern = "AqlzahalcezsLfj";
    result = sol.camelMatch(queries, pattern);
    cout << "Pattern: " << pattern << endl;
    cout << "Expected: true true true true true true true true" << endl;
    cout << "Result  : ";
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl << endl;


    cout << "Test case 5" << endl;
    queries = {"abcd"};
    pattern = "z";
    result = sol.camelMatch(queries, pattern);
    cout << "Pattern: " << pattern << endl;
    cout << "Expected: false" << endl;
    cout << "Result  : ";
    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl << endl;
    return 0;
}