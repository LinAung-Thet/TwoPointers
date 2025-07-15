// https://leetcode.com/problems/find-the-duplicate-number/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j > i; j--) {
                if(nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        
        return -1;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    // Test case 1
    nums = {1, 3, 4, 2, 2};
    cout << "Numbers  : 1 3 4 2 2" << endl;
    cout << "Duplicate: " << sol.findDuplicate(nums) << endl; 
    cout << "Expected : 2" << endl << endl;

    // Test case 2
    nums = {3, 1, 3, 4, 2};
    cout << "Numbers  : 3 1 3 4 2" << endl;
    cout << "Duplicate: " << sol.findDuplicate(nums) << endl; 
    cout << "Expected : 3" << endl << endl;

    // Test case 3
    nums = {3, 3, 3, 3};
    cout << "Numbers  : 3 3 3 3" << endl;
    cout << "Duplicate: " << sol.findDuplicate(nums) << endl; 
    cout << "Expected : 3" << endl;

    // Test case 3
    nums = {4, 3, 1, 4, 2};
    cout << "Numbers  : 4 3 1 4 2" << endl;
    cout << "Duplicate: " << sol.findDuplicate(nums) << endl; 
    cout << "Expected : 4" << endl;

    return 0;
}