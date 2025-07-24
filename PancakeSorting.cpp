// https://leetcode.com/problems/pancake-sorting/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();

        // Sort the array from largest to smallest
        for (int target = n; target > 1; --target) {
            // Find the index of the current maximum element
            int i = 0;
            while (arr[i] != target) ++i;

            if (i == target - 1) continue;  // Already in correct position

            if (i != 0) {
                // Bring target to front
                reverse(arr.begin(), arr.begin() + i + 1);
                result.push_back(i + 1);
            }

            // Flip target to its final position
            reverse(arr.begin(), arr.begin() + target);
            result.push_back(target);
        }

        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> arr;

    cout << "Test case 1" << endl;
    arr = {3, 2, 4, 1};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    vector<int> result = sol.pancakeSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Pancake flips: ";
    for (int flip : result) cout << flip << " ";
    cout << endl;

    cout << "Test case 2" << endl;
    arr = {1, 2, 3};
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    result = sol.pancakeSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Pancake flips: ";
    for (int flip : result) cout << flip << " ";
    cout << endl;

    return 0;
}