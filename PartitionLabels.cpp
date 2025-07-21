// https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int lastPos[26];

        // Step 1: Record the last occurrence of each character
        for (int i = 0; i < s.size(); ++i) {
            lastPos[s[i] - 'a'] = i;
        }

        // Step 2: Traverse the string and partition greedily
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastPos[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    string s;
    vector<int> result;

    cout << "Test case 1" << endl;
    s = "ababcbacadefegdehijhklij";
    cout << "Input: " << s << endl;
    result = sol.partitionLabels(s);
    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl; 
    cout << "Expected: 9 7 8" << endl << endl;

    cout << "Test case 2" << endl;
    s = "eccbbbbdec";
    cout << "Input: " << s << endl;
    result = sol.partitionLabels(s);
    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl; 
    cout << "Expected: 10" << endl;

    return 0;
}