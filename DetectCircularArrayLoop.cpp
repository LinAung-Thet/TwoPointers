// https://leetcode.com/problems/circular-array-loop/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto next = [&](int i) {    // & for capture by reference
            return ((i + nums[i]) % n + n) % n;  // Handles wraparound for negative steps
        };

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;  // Already visited

            int slow = i, fast = i;
            bool isForward = nums[i] > 0;

            while (true) {
                // Move slow pointer one step
                int nextSlow = next(slow);
                if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != isForward || nextSlow == slow)
                    break;

                // Move fast pointer two steps
                int nextFast = next(fast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != isForward || nextFast == fast)
                    break;

                int nextFast2 = next(nextFast);
                if (nums[nextFast2] == 0 || (nums[nextFast2] > 0) != isForward || nextFast2 == nextFast)
                    break;

                slow = nextSlow;
                fast = nextFast2;

                if (slow == fast)
                    return true;
            }

            // Mark visited path as 0
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == isForward) {
                int temp = next(j);
                nums[j] = 0;
                j = temp;
            }
        }

        return false;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> nums;

    // Test case 1
    nums = {2, -1, 1, 2, 2};
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nHas circular loop: " << (sol.circularArrayLoop(nums) ? "Yes" : "No") << endl; 
    cout << "Expected: Yes" << endl << endl;

    // Test case 2
    nums = {-1, -2, -3, -4, -5, 6};
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nHas circular loop: " << (sol.circularArrayLoop(nums) ? "Yes" : "No") << endl; 
    cout << "Expected: No" << endl << endl;

    // Test case 3
    nums = {1, -1, 5, 1, 4};
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nHas circular loop: " << (sol.circularArrayLoop(nums) ? "Yes" : "No") << endl; 
    cout << "Expected: Yes" << endl;

    return 0;
}