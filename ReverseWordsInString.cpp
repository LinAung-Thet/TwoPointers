// https://leetcode.com/problems/reverse-words-in-a-string/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;

        // const char eosChar = '\0';
        const char space = ' ';
        const char* str = s.c_str();
        const char* end = str + s.length();
        string reverse;
        string word;

        while(str != end) {

            // If there is a space
            if(*str == space) {
                // If the word is not empty, add it to the reverse string
                if(!word.empty()) {
                    if(!reverse.empty()) {
                        reverse = word + space + reverse; // Add a space before the word
                    } else {
                        reverse = word; // First word, no leading space
                    }
                    word.clear(); // Clear the current word
                }

                while(*str == space) {
                    ++str;    // skip all the white space
                    if(str == end) {
                        return reverse;
                    }
                }
            } 
            else {
                word += *str;   // Add character to the current word

                ++str; // Move to the next character
            }
        }
        if(!word.empty()) {
            if(!reverse.empty()) {
                reverse = word + space + reverse; // Add a space before the last word
            } else {
                reverse = word; // Last word, no leading space
            }
        }
        return reverse;
    }
};
// Test cases
int main() {
    Solution sol;
    string s;

    // Test case 1
    s = "the sky is blue";
    cout << "Original: " << s << endl;
    cout << "Result:   " << sol.reverseWords(s) << endl; 
    cout << "Expected: blue is sky the" << endl << endl;

    // Test case 2
    s = "  hello world  ";
    cout << "Original: " << s << endl;
    cout << "Result:   " << sol.reverseWords(s) << endl; 
    cout << "Expected: world hello" << endl << endl;

    // Test case 3
    s = "a good   example";
    cout << "Original: " << s << endl;
    cout << "Result:   " << sol.reverseWords(s) << endl; 
    cout << "Expected: example good a" << endl;

    return 0;
}