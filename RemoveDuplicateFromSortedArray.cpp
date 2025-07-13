// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removedItem = -INT_MAX; // to mark removed items
    void shiftLeft(vector<int>& nums, int& start, int& n) {
        for (int i = start; i < n-1; ++i) {
            if(nums[i+1] == removedItem) {
                nums[i] = removedItem; // mark as removed
                return; // no need to shift further
            }
            nums[i] = nums[i + 1];
        }
        nums[n - 1] = removedItem; // mark last item as removed
        return;
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int k = 0, left = 0, right = 1, duplicate = 0;

        while(right < n && nums[right] != removedItem) {
            if (nums[left] == nums[right]) {
                ++duplicate;
                if (duplicate == 1) { // first duplicate found
                    k = right + 1;
                }
                else {
                    // shift the items, starting from right + 1 until -INT_MAX, to the left
                    for (int i = right; i < n-1; ++i) {
                        if(nums[i+1] == removedItem) {
                            nums[i] = removedItem; // mark as removed
                            break; // no need to shift further
                        }
                        nums[i] = nums[i + 1];
                    }
                    nums[n - 1] = removedItem; // mark last item as removed

                    --duplicate; // decrement duplicate count since we just shifted one item
                    continue; // continue to check the next item
                }
            }
            else {
                k = right + 1;
                duplicate = 0; // reset duplicate count
            }
            ++left; 
            ++right;
        }
        return nums[n-1] == removedItem ? k : n; // if last item is removed, return k, else return n
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
