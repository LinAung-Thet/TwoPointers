// https://leetcode.com/problems/sort-colors/description/?envType=problem-list-v2&envId=two-pointers

# include <iostream>
# include <vector> 
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
            int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            } else if (nums[mid] == 1) {
                ++mid;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Sorted colors: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Expected: 0 0 1 1 2 2

    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Sorted colors: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl; // Expected: 0 1 2

    // Test case 3
    vector<int> nums3 = {0};
    sol.sortColors(nums3);
    cout << "Sorted colors: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl; // Expected: 0

    return 0;
}