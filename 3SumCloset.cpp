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
        int n = nums.size();

        if(n<3) return target;
        if(n==3) return (nums[0]+nums[1]+nums[2]);

        int diff = INT_MAX, sum;

        sort(nums.begin(),nums.end());

        for(int i=0; i < n-2; i++){
            int left = i+1, right = n-1;

            while(left < right) {
                int bSum = nums[i] + nums[left] + nums[right];
                if(bSum == target) return bSum;

                int bDiff = abs(target - bSum);
                if(bDiff < diff) {
                    diff = bDiff;
                    sum = bSum;
                }

                if(bSum > target) right--;
                else left++;
            }
        }
        return sum;
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