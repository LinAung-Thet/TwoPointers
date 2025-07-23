// https://leetcode.com/problems/maximum-width-ramp/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> mono;  // decreasing stack of indices
        int maxWidth = 0;

        // Step 1: Build the monotonic decreasing stack
        for (int i = 0; i < n; ++i) {
            if (mono.empty() || nums[i] < nums[mono.top()])
                mono.push(i);
        }

        // Step 2: Traverse from the end and update max width
        for (int j = n - 1; j >= 0; --j) {
            while (!mono.empty() && nums[j] >= nums[mono.top()]) {
                maxWidth = max(maxWidth, j - mono.top());
                mono.pop();
            }
        }

        return maxWidth;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    cout << "Test case 1" << endl;
    nums = {6, 0, 8, 2, 1, 5};
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 4" << endl;
    cout << "Result: " << sol.maxWidthRamp(nums) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 7" << endl;
    cout << "Result: " << sol.maxWidthRamp(nums) << endl << endl;

    cout << "Test case 3" << endl;
    nums = {2, 2, 1};
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << sol.maxWidthRamp(nums) << endl << endl;

    cout << "Test case 4" << endl;
    nums = {6,7,8,8,6,5,5,8,2,2};
    cout << "Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 7" << endl;
    cout << "Result: " << sol.maxWidthRamp(nums) << endl << endl;

    return 0;
}