// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string longest;
        for(string& word: dictionary) {
            const char* c = s.c_str();
            bool found = false;
            const char* w = word.c_str();
            while(*c != '\0') {
                if(*w == *c)
                    ++w;
                ++c;
            }
            
            // Check if all the characters have been compared
            if(*w == '\0') {
                if(word.size() == longest.size())
                    longest = word < longest ? word : longest;
                else if(word.size() > longest.size()) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<string> dictionary;

    cout << "Test case 1" << endl;
    string s = "abpcplea";
    dictionary = {"ale", "apple", "monkey", "plea"};
    cout << "String  : " << s << endl;
    cout << "Dictionary: ale, apple, monkey, plea" << endl;
    cout << "Longest word: " << sol.findLongestWord(s, dictionary) << endl; 
    cout << "Expected: apple" << endl << endl;

    cout << "Test case 2" << endl;
    s = "abpcplea";
    dictionary = {"a", "b", "c"};
    cout << "String  : " << s << endl;
    cout << "Dictionary: a, b, c" << endl;
    cout << "Longest word: " << sol.findLongestWord(s, dictionary) << endl; 
    cout << "Expected: a" << endl << endl;

    cout << "Test case 3" << endl;
    s = "abce";
    dictionary = {"abe", "abc"};
    cout << "String  : " << s << endl;
    cout << "Dictionary: abe, abc" << endl;
    cout << "Longest word: " << sol.findLongestWord(s, dictionary) << endl; 
    cout << "Expected: abc" << endl << endl;

    return 0;
}