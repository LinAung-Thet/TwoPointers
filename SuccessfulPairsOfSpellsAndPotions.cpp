// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=problem-list-v2&envId=two-pointers

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for (int s : spells) {
            // Minimum potion value needed for s × p ≥ success → p ≥ success / s
            long long target = (success + s - 1) / s;  // Ceiling division to avoid precision errors
            auto it = lower_bound(potions.begin(), potions.end(), target);
            result.push_back(m - (it - potions.begin()));
        }

        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    vector<int> spells, potions;
    long long success;
    vector<int> pairs;

    cout << "Test case 1" << endl;
    spells = {5, 1, 3};
    potions = {1, 2, 3, 4, 5};
    success = 7;
    pairs = solution.successfulPairs(spells, potions, success);
    cout << "Expected : 4 0 3" << endl;
    cout << "Result   : ";
    for (int pair : pairs) {
        cout << pair << " ";
    }
    cout << endl << endl;

    cout << "Test case 2" << endl;
    spells = {3, 1, 2};
    potions = {8, 5, 8};
    success = 16;
    pairs = solution.successfulPairs(spells, potions, success);
    cout << "Expected : 2 0 2" << endl;
    cout << "Result   : ";
    for (int pair : pairs) {
        cout << pair << " ";
    }
    cout << endl << endl;

    return 0;
}