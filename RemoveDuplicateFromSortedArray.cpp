// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int k = 2;  // Position to overwrite

        for (int i = 2; i < n; ++i) {
            // Accept the current number if it's one of the first two occurrences
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Test case 1
    nums = {1, 1, 1, 2, 2, 3};
    k= sol.removeDuplicates(nums);
    cout << "Result:   ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl; 
    cout << "Expected: 1 1 2 2 3" << endl << endl;

    // Test case 2
    nums = {0, 0, 0, 0, 0};
    k = sol.removeDuplicates(nums);
    cout << "Result:   ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl; // Expected: 0 0
    cout << "Expected: 0 0" << endl << endl;

    // Test case 3
    nums = {1, 2, 3, 4, 5};
    k = sol.removeDuplicates(nums);
    cout << "Result:   ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl; // Expected: 1 2 3 4 5
    cout << "Expected: 1 2 3 4 5" << endl << endl;

    // Test case 4
    nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    k = sol.removeDuplicates(nums);
    cout << "Result:   ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl; // Expected: 0 0 1 1 2 3 3
    cout << "Expected: 0 0 1 1 2 3 3" << endl << endl;

    // Test case 5
    nums = {0,1,1,1,2,3,3,3,3,4,4};
    k = sol.removeDuplicates(nums);
    cout << "Result:   ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl; // Expected: 0 0 1 1 2 3 3
    cout << "Expected: 0 1 1 2 3 3 4 4" << endl << endl;

    return 0;
}
