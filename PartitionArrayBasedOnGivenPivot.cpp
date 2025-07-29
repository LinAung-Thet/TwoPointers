// https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=problem-list-v2&envId=two-pointers

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n , pivot);
        int i = 0, j = n - 1;
        int left = 0, right = n - 1;
        while(i < n && j >= 0){
            if(nums[i] < pivot) res[left++] = nums[i];
            if(nums[j] > pivot) res[right--] = nums[j];
            ++i; --j;
        }
        return res;
    }
};
// Test cases
int main() {
    vector<int> nums;
    int pivot;
    vector<int> result;
    Solution solution;

    cout << "Test case 1" << endl;
    nums = {9,12,5,10,14,3,10};
    pivot = 10;
    result = solution.pivotArray(nums, pivot);
    cout << "Expected : 9 5 3 10 10 12 14" << endl;
    cout << "Result   : ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    nums = {-3,4,3,2};
    pivot = 2;
    result = solution.pivotArray(nums, pivot);
    cout << "Expected : -3 2 4 3" << endl;
    cout << "Result   : ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl << endl;

    return 0;
}