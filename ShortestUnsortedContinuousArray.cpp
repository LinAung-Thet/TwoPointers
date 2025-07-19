// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int maxSoFar = nums[0];
        int minSoFar = nums[n - 1];

        // Step 1: Find the right boundary
        for (int i = 1; i < n; ++i) {
            if (nums[i] < maxSoFar)
                right = i;
            else
                maxSoFar = nums[i];
        }

        // Step 2: Find the left boundary
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > minSoFar)
                left = i;
            else
                minSoFar = nums[i];
        }

        // Step 3: Return the length of subarray
        return (right == -1) ? 0 : (right - left + 1);
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    cout << "Test case 1" << endl;
    nums = {2, 6, 4, 8, 10, 9, 15};
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Result: " << sol.findUnsortedSubarray(nums) << endl; 
    cout << "Expected: 5" << endl << endl;

    cout << "Test case 2" << endl;
    nums = {1, 2, 3, 4};
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Result: " << sol.findUnsortedSubarray(nums) << endl; 
    cout << "Expected: 0" << endl << endl;

    cout << "Test case 3" << endl;
    nums = {1};
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Result: " << sol.findUnsortedSubarray(nums) << endl; 
    cout << "Expected: 0" << endl << endl;

    return 0;
}