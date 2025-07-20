// https://leetcode.com/problems/find-k-closest-elements/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == k) return arr;

        vector<int> closetNums;

        auto pos = lower_bound(arr.begin(), arr.end(), x);

        int l;
        if(pos == arr.begin()) {
            l = 0;
        }
        else if(pos == arr.end()) {
            l = n - k;
        }
        else {
            int i = distance(arr.begin(), pos);
            int length = k;
            int left = i, right = i;

            while(length > 0 && left > 0 && right < n) {
                int dist1 = abs(x - arr[left - 1]);
                int dist2 = abs(arr[right] - x);

                if(dist1 <= dist2) --left;
                else ++right;

                --length;
            }

            left = right >= n ? left - length: left;
            l = left;
        }

        closetNums.assign(arr.begin() + l, arr.begin() + l + k);

        return closetNums;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> arr;
    vector<int> result;
    int k, x;

    cout << "Test case 1" << endl;
    arr = {1, 2, 3, 4, 5};
    k = 4; x = 3;
    cout << "Input: arr = {1, 2, 3, 4, 5}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 1 2 3 4" << endl << endl;

    cout << "Test case 2" << endl;
    arr = {1, 1, 2, 3, 4, 5};
    k = 4; x = -1;
    cout << "Input: arr = {1, 1, 2, 3, 4, 5}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 1 1 2 3" << endl << endl;

    cout << "Test case 3" << endl;
    arr = {1, 2, 2, 3, 4, 5};
    k = 1; x = 1;
    cout << "Input: arr = {1, 2, 2, 3, 4, 5}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 1" << endl << endl;

    cout << "Test case 4" << endl;
    arr = {0, 1, 1, 1, 2, 3, 6, 7, 8, 9};
    k = 9; x = 4;
    cout << "Input: arr = {0, 1, 1, 1, 2, 3, 6, 7, 8, 9}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 0,1,1,1,2,3,6,7,8" << endl << endl;

    cout << "Test case 5" << endl;
    arr = {1,1,1,10,10,10};
    k = 1; x = 9;
    cout << "Input: arr = {1,1,1,10,10,10}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 10" << endl << endl;

    cout << "Test case 6" << endl;
    arr = {0,0,1,2,3,3,4,7,7,8};
    k = 3; x = 5;
    cout << "Input: arr = {0,0,1,2,3,3,4,7,7,8}, k = " << k << ", x = " << x << endl;
    result = sol.findClosestElements(arr, k, x);
    cout << "Result  : ";
    for(int num : result) cout << num << " ";
    cout << endl; 
    cout << "Expected: 3, 3, 4" << endl << endl;

    return 0;
}