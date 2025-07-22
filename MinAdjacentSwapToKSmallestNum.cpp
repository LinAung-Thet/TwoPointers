// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Count adjacent swaps to turn source into target
    int countSwaps(string source, string target) {
        int swaps = 0;
        int n = source.size();

        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) continue;

            int j = i;
            while (source[j] != target[i]) ++j;

            while (j > i) {
                swap(source[j], source[j - 1]);
                --j;
                ++swaps;
            }
        }

        return swaps;
    }

    int getMinSwaps(string num, int k) {
        string target = num;

        // Step 1: Get kth next permutation
        for (int i = 0; i < k; ++i)
            next_permutation(target.begin(), target.end());

        // Step 2: Count adjacent swaps
        return countSwaps(num, target);
    }
};
// Test cases
int main() {
    Solution sol;
    string num;
    int k;

    cout << "Test case 1" << endl;
    num = "5489355142";
    k = 4;
    cout << "Number: " << num << endl;
    cout << "K: " << k << endl;
    cout << "Minimum swaps: " << sol.getMinSwaps(num, k) << endl; // Expected: 2
    cout << "Expected     : 2" << endl << endl;

    cout << "Test case 2" << endl;
    num = "11112";
    k = 4;
    cout << "Number: " << num << endl;
    cout << "K: " << k << endl;
    cout << "Minimum swaps: " << sol.getMinSwaps(num, k) << endl; // Expected: 4
    cout << "Expected     : 4" << endl << endl;

    cout << "Test case 3" << endl;
    num = "00123";
    k = 1;
    cout << "Number: " << num << endl;
    cout << "K: " << k << endl;
    cout << "Minimum swaps: " << sol.getMinSwaps(num, k) << endl;
    cout << "Expected     : 1" << endl << endl;

    cout << "Test case 4" << endl;
    num = "059";
    k = 5;
    cout << "Number: " << num << endl;
    cout << "K: " << k << endl;
    cout << "Minimum swaps: " << sol.getMinSwaps(num, k) << endl;
    cout << "Expected     : 3" << endl << endl;

    return 0;
}