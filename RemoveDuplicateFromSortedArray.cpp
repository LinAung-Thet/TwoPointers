// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removedItem = -INT_MAX; // to mark removed items
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int k = 0, left = 0, right = n - 1;
        int removedItem = -INT_MAX; // to mark removed items

        while(left < right) {
            if (nums[left] == nums[left + 1]) {
                int count = 0; // count duplicates
                int tmp = left + 2;
                
                // count the number of duplicates
                while (tmp < n && nums[tmp] == nums[left]) {
                    ++count;
                    ++tmp;
                }
                if(count > 0) {
                    // shift the items, starting from tmp until -INT_MAX, to the left
                    for (int i = left + 2; i <= right - count; ++i) {
                        nums[i] = nums[i + count];
                    }
                    for(int i = 0; i < count; ++i) {
                        nums[right--] = removedItem; // mark the items behind the shifted ones as removed
                    }   
                }

                left += 2;
            }
            else {
                ++left; 
            }
        }
        return right + 1;
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
