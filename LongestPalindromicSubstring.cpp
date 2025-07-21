// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindrome
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l; ++r;
            }

            // Even-length palindrome
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l; ++r;
            }
        }

        return s.substr(start, maxLen);
    }
};
// Test cases
int main() {
    Solution sol;
    string s;

    cout << "Test case 1" << endl;
    s = "babad";
    cout << "Input: " << s << endl;
    cout << "Longest palindromic substring: " << sol.longestPalindrome(s) << endl; 
    cout << "Expected                     : bab or aba" << endl << endl;

    cout << "Test case 2" << endl;
    s = "cbbd";
    cout << "Input: " << s << endl;
    cout << "Longest palindromic substring: " << sol.longestPalindrome(s) << endl; 
    cout << "Expected                     : bb" << endl << endl;

    cout << "Test case 3" << endl;
    s = "a";
    cout << "Input: " << s << endl;
    cout << "Longest palindromic substring: " << sol.longestPalindrome(s) << endl; 
    cout << "Expected                     : a" << endl << endl;

    cout << "Test case 4" << endl;
    s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    cout << "Input: " << s << endl;
    cout << "Longest palindromic substring   : " << sol.longestPalindrome(s) << endl; 
    cout << "Expected                        : qosoq" << endl << endl;

    return 0;
}