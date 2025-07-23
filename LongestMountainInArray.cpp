// https://leetcode.com/problems/longest-mountain-in-array/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if arr[i] is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // Expand to the left
                while (left > 0 && arr[left - 1] < arr[left]) --left;

                // Expand to the right
                while (right < n - 1 && arr[right] > arr[right + 1]) ++right;

                // Update maxLen
                maxLen = max(maxLen, right - left + 1);

                i = right + 1;  // Skip to end of current mountain
            } else {
                ++i;
            }
        }

        return maxLen;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> arr;

    cout << "Test case 1" << endl;
    arr = {2,1,4,7,3,2,5};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Expected: 5" << endl;
    cout << "Result  : " << sol.longestMountain(arr) << endl << endl;

    cout << "Test case 2" << endl;
    arr = {2, 2, 2};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Expected: 0" << endl;
    cout << "Result  : " << sol.longestMountain(arr) << endl << endl;

    cout << "Test case 3" << endl;
    arr = {0,1,2,3,4,5,4,3,2,1,0};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Expected: 11" << endl;
    cout << "Result  : " << sol.longestMountain(arr) << endl << endl;

    cout << "Test case 4" << endl;
    arr = {0,2,0,2,1,2,3,4,4,1};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Expected: 3" << endl;
    cout << "Result  : " << sol.longestMountain(arr) << endl << endl;

    cout << "Test case 5" << endl;
    arr = {0,0,1,0,0,1,1,1,1,1};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Expected: 3" << endl;
    cout << "Result  : " << sol.longestMountain(arr) << endl << endl;

    return 0;
}