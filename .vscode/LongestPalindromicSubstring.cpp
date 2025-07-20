// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            // Check if the substring allocated by the sliding window is palindromic
            int winSize = n - i;
            for(int w = 0; w <= n - winSize; w++) {
                int left = w, right = w + winSize - 1;
                bool palindromic = true;

                // Check if palindromic
                while(left <= right) {
                    if(s[left++] != s[right--]) {
                        palindromic = false;
                        break;  // Isn't palindromic
                    }
                }
                if(palindromic)
                    return s.substr(w, winSize);    // Is palindromic
            }
        }
        return "";
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