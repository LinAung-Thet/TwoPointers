// https://leetcode.com/problems/sentence-similarity-iii/description/?envType=problem-list-v2&envId=two-pointers

#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
#include<sstream>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() > sentence2.size()) swap(sentence1, sentence2);

        int n = sentence1.size(), m = sentence2.size();
        if(n == m) return sentence1 == sentence2;

        int prefixEnd = -1, suffixStart = -1;
        int i = 0;
        while (i < n && sentence1[i] == sentence2[i]) {
            if (sentence1[i] == ' ') prefixEnd = i;
            ++i;
        }
        if (i == n && (sentence2[i] == ' ')) return true;

        int j = n - 1, k = m - 1;
        while (j >= 0 && sentence1[j] == sentence2[k]) {
            if (sentence1[j] == ' ') suffixStart = j;
            --j; --k;
        }
        if (j < 0 && (sentence2[k] == ' ')) return true;
        
        return prefixEnd != -1 && suffixStart != -1 && suffixStart <= prefixEnd;
    }
};
// Test cases
int main() {
    string str1, str2;
    bool result;
    Solution solution;

    cout<< "Test case 1" << endl;
    str1 = "My name is Haley";
    str2 = "My Haley";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 2" << endl;
    str1 = "of";
    str2 = "A lot of words";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: false" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 3" << endl;
    str1 = "Eating right now";
    str2 = "Eating";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 4" << endl;
    str1 = "TjZ ScAi m xz PNWaKigqqY p IyJ B rok";
    str2 = "TjZ ScAi m LlbJhCf gL u m R pZpiH mSk a og xz PNWaKigqqY p IyJ B rok";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 5" << endl;
    str1 = "qbaVXO Msgr aEWD v ekcb";
    str2 = "Msgr aEWD ekcb";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: false" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 6" << endl;
    str1 = "A";
    str2 = "a A b A";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    cout<< "Test case 7" << endl;
    str1 = "B A";
    str2 = "B a B A A";
    result = solution.areSentencesSimilar(str1, str2);
    cout << "Sentence 1: " << str1 << endl;
    cout << "Sentence 2: " << str2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result  : " << (result ? "true" : "false") << endl << endl;

    return 0;
}