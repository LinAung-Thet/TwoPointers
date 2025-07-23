// https://leetcode.com/problems/longest-mountain-in-array/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        bool asc = true;
        int left = n, right = 0;
        int maxLength = 0;

        for (int i = 0; i < n - 1; ++i) {
            int curr = arr[i], next = arr[i+1];
            if(asc){    // Ascending mode
                if (next == curr) {
                    left = n; // reset the left pointer
                }
                else if (next > curr) {
                    left = min(left, i);    // move the left pointer
                }
                else {
                    asc = false || left == n;
                }
            }
            else {  // Descending mode
                if (next >= curr) {
                    // Change the mode to asc
                    right = i;
                    maxLength = max(maxLength, right - left + 1);
                    left = next == curr ? n : i;  // reset/move the left pointer
                    asc = true;
                }
                else {
                    // No actions required
                }
            }
        }

        // Final check if we ended in descending mode
        if (!asc && arr[n - 1] < arr[n - 2]) {
            right = n - 1;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
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