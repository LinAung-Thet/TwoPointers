// https://leetcode.com/problems/3sum-closest/description/?envType=problem-list-v2&envId=two-pointers

#include<vector>
#include<limits.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    // Exact match
                    return target;
                }
            }
        }

        return closestSum;
    }
};
int main() {
    Solution sol;
    vector<int> nums;
    int target;
    int expected;

    // Test case 1
    nums = {-1, 2, 1, -4};
    target = 1;
    expected = 2;
    cout << "Closest sum to " << target << " is: " << sol.threeSumClosest(nums, target) << ", Expected: " << expected << endl;

    // Test case 2
    nums = {0, 0, 0};
    target = 1;
    expected = 0;
    cout << "Closest sum to " << target << " is: " << sol.threeSumClosest(nums, target) << ", Expected: " << expected << endl;

    // Test case 3
    nums = {10,20,30,40,50,60,70,80,90};
    target = 1;
    expected = 60;
    cout << "Closest sum to " << target << " is: " << sol.threeSumClosest(nums, target) << ", Expected: " << expected << endl;
    
    return 0;
}