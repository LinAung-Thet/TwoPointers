// https://leetcode.com/problems/camelcase-matching/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void split(string& str, vector<string>& output) {
        if(str.size() < 1) return;

        const char* s = str.c_str();
        while(*s - 'a' >= 0 && *s != '\0') ++s; // Skip initial lowercase letters
        if(*s == '\0') return; // If no uppercase letter found, return

        while(*s != '\0') {
            string substring;
            do {
                substring += *s++;
            } while (*s - 'a' >= 0 && *s != '\0'); // Collect characters until an uppercase letter is found
            output.push_back(substring);
        }
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answers;

        // Split the pattern into sub-strings starting with a capital
        vector<string> splitP;
        split(pattern, splitP);

        // Traverse each query in the queries
        for(auto query: queries) {
            
            // Split the query into sub-strings starting with a capital
            vector<string> splitQ;
            split(query, splitQ);

            // If the number of sub-strings are not the same, add false to the answer.
            if(splitP.size() != splitQ.size()) {
                answers.push_back(false);
                continue;
            }

            // Compare all sub-strings with those of the pattern
            bool ans = true;
            for(int n = 0; n < splitP.size(); ++n) {

                // Compare each sub-string by using two pointers
                string sp = splitP[n], sq = splitQ[n];
                const char* p = sp.c_str();
                const char* q = sq.c_str();  
                while(*p != '\0') {
                    // while(*q != *p && *q != '\0') ++q;
                    if(*q == *p) ++p;
                    if(*q != '\0') ++q;
                    else break;
                }
                if(*p != '\0') {
                    ans = false;
                    break;
                }
            }

            answers.push_back(ans);
        }
        return answers;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<string> queries;
    string pattern;
    vector<bool> result;

    // cout << "Test case 1" << endl;
    // queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    // pattern = "FB";
    // result = sol.camelMatch(queries, pattern);
    // cout << "Pattern: " << pattern << endl;
    // cout << "Expected: true false true true false" << endl;
    // cout << "Result  : ";
    // for (bool res : result) {
    //     cout << (res ? "true" : "false") << " ";
    // }
    // cout << endl << endl;

    // cout << "Test case 2" << endl;
    // queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    // pattern = "FoBa";
    // result = sol.camelMatch(queries, pattern);
    // cout << "Pattern: " << pattern << endl;
    // cout << "Expected: true false true false false" << endl;
    // cout << "Result  : ";
    // for (bool res : result) {
    //     cout << (res ? "true" : "false") << " ";
    // }
    // cout << endl << endl;

    // cout << "Test case 3" << endl;
    // queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    // pattern = "FoBaT";
    // result = sol.camelMatch(queries, pattern);
    // cout << "Pattern: " << pattern << endl;
    // cout << "Expected: false true false false false" << endl;
    // cout << "Result  : ";
    // for (bool res : result) {
    //     cout << (res ? "true" : "false") << " ";
    // }
    // cout << endl << endl;

    // cout << "Test case 4" << endl;
    // queries = {"uAxaqlzahfialcezsLfj","cAqlzyahaslccezssLfj","AqlezahjarflcezshLfj","AqlzofahaplcejuzsLfj","tAqlzahavslcezsLwzfj","AqlzahalcerrzsLpfonj","AqlzahalceaczdsosLfj","eAqlzbxahalcezelsLfj"};
    // pattern = "AqlzahalcezsLfj";
    // result = sol.camelMatch(queries, pattern);
    // cout << "Pattern: " << pattern << endl;
    // cout << "Expected: true true true true true true true true" << endl;
    // cout << "Result  : ";
    // for (bool res : result) {
    //     cout << (res ? "true" : "false") << " ";
    // }
    // cout << endl << endl;


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