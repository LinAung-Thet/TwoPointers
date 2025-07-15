// https://leetcode.com/problems/rotate-array/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k += n;
        vector<int> tmp = nums;
        for(int i = 0; i < n; i++) {
            nums[k++%n] = tmp[i];
        }
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    // Test case 1
    nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    cout << "Result  : ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 5 6 7 1 2 3 4" << endl << endl;

    // Test case 2
    nums = {-1, -100, 3, 99};
    k = 2;
    sol.rotate(nums, k);
    cout << "Result  : ";
    for(int num : nums) cout << num << " ";
    cout << endl;
    cout << "Expected: 3 99 -1 -100" << endl << endl;

    return 0;
}