// https://leetcode.com/problems/k-diff-pairs-in-an-array/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;  // Absolute difference can't be negative

        unordered_map<int, int> freq;
        int count = 0;

        // Count frequency of each number
        for (int num : nums) {
            ++freq[num];
        }

        // Check for valid pairs
        for (const auto& [num, val] : freq) {
            if (k == 0) {
                // Count numbers that appear more than once
                if (val > 1) ++count;
            } else {
                // Check if num + k exists
                if (freq.count(num + k)) ++count;
            }
        }

        return count;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;
    int k;

    cout << "Test case 1" << endl;
    nums = {3, 1, 4, 1, 5};
    k = 2;
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "K: " << k << endl;
    cout << "Pairs count: " << sol.findPairs(nums, k) << endl; 
    cout << "Expected   : 2" << endl << endl;

    cout << "Test case 2" << endl;
    nums = {1, 2, 3, 4, 5};
    k = 1;
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "K: " << k << endl;
    cout << "Pairs count: " << sol.findPairs(nums, k) << endl; 
    cout << "Expected   : 4" << endl << endl;

    cout << "Test case 3" << endl;
    nums = {1, 3, 1, 5, 4};
    k = 0;
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "K: " << k << endl;
    cout << "Pairs count: " << sol.findPairs(nums, k) << endl; 
    cout << "Expected   : 1" << endl << endl;

    cout << "Test case 4" << endl;
    nums = {-1, -2, -3};
    k = 1;
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "K: " << k << endl;
    cout << "Pairs count: " << sol.findPairs(nums, k) << endl; 
    cout << "Expected   : 2" << endl  << endl;

    return 0;
}