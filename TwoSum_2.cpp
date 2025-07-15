// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 1, right = n;

        while(left < right) {
            int leftNum = numbers[left - 1]; 
            int rightNum = numbers[right - 1];
            int sum = leftNum + rightNum;

            if(sum == target)
                return {left, right};
            else if(sum < target) ++left;
            else --right;
        }
        return {};
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> numbers;

    // Test case 1
    numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    cout << "Result  : [" << result[0] << ", " << result[1] << "]" << endl; 
    cout << "Expected: [1, 2]" << endl << endl;

    // Test case 2
    numbers = {2, 3, 4};
    target = 6;
    result = sol.twoSum(numbers, target);
    cout << "Result  : [" << result[0] << ", " << result[1] << "]" << endl; 
    cout << "Expected: [1, 3]" << endl << endl;

    // Test case 3
    numbers = {-1, 0};
    target = -1;
    result = sol.twoSum(numbers, target);
    cout << "Result  : [" << result[0] << ", " << result[1] << "]" << endl; 
    cout << "Expected: [1, 2]" << endl;

    return 0;
}