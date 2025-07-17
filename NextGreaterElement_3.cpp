// https://leetcode.com/problems/next-greater-element-iii/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);

        // Find the pivot
        int i = digits.size() - 2;
        while(i >= 0 && digits[i] >= digits[i+1]) {
            --i;
        }
        if(i < 0) return -1; // n is already the last permutation.

        // Find the next larger digit right to the pivot
        int j = digits.size() - 1;
        while(j > i && digits[j] <= digits[i]) {
            --j;
        }

        // Swap the pivot and the next larger digit
        swap(digits[i], digits[j]);

        // Reverse the tail behind the pivot
        reverse(digits.begin() + i + 1, digits.end());

        // Check the overflow
        long long nextPer = stoll(digits);
        return nextPer > INT_MAX ? -1 : int(nextPer);
    }
};
// Test cases
int main() {
    Solution sol;
    int n;

    cout << "Test case 1" << endl;
    n = 12;
    cout << "Input: " << n << endl;
    cout << "Next greater element: " << sol.nextGreaterElement(n) << endl; 
    cout << "Expected            : 21" << endl << endl;

    cout << "Test case 2" << endl;
    n = 21;
    cout << "Input: " << n << endl;
    cout << "Next greater element: " << sol.nextGreaterElement(n) << endl; 
    cout << "Expected            : -1" << endl << endl;

    cout << "Test case 3" << endl;
    n = 11;
    cout << "Input: " << n << endl;
    cout << "Next greater element: " << sol.nextGreaterElement(n) << endl; 
    cout << "Expected            : -1" << endl << endl;

    cout << "Test case 4" << endl;
    n = 1234;
    cout << "Input: " << n << endl;
    cout << "Next greater element: " << sol.nextGreaterElement(n) << endl; 
    cout << "Expected            : 1243" << endl << endl;

    cout << "Test case 5" << endl;
    n = 1432;
    cout << "Input: " << n << endl;
    cout << "Next greater element: " << sol.nextGreaterElement(n) << endl; 
    cout << "Expected            : 2134" << endl << endl;

    return 0;
}