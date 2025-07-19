// https://leetcode.com/problems/valid-triangle-number/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();

        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return count;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    cout << "Test case 1" << endl;
    nums = {2, 2, 3, 4};
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Result: " << sol.triangleNumber(nums) << endl; 
    cout << "Expected: 3" << endl << endl;

    cout << "Test case 2" << endl;
    nums = {4, 2, 3, 4};
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Result: " << sol.triangleNumber(nums) << endl; 
    cout << "Expected: 4" << endl;

    return 0;
}