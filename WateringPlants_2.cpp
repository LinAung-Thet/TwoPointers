// https://leetcode.com/problems/watering-plants-ii/description/?envType=problem-list-v2&envId=two-pointers

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int count = 0;
        int n = plants.size();
        int l = 0, r = n - 1;

        int currA = capacityA, currB = capacityB;
        while (l <= r) {
            int refillA = 0, refillB = 0;

            refillA = currA >= plants[l] ? 0 : 1;
            refillB = currB >= plants[r] ? 0 : 1;

            if (l == r) {
                if (refillA == 0 || refillB == 0) 
                    return count;
                else return ++count;
            }

            currA = refillA == 0 ? currA - plants[l] : capacityA - plants[l];
            currB = refillB == 0 ? currB - plants[r] : capacityB - plants[r];

            ++l; --r;

            count += refillA + refillB;
        }

        return count;
    }
};
// Test cases
int main() {
    vector<int> plants;
    int capacityA, capacityB;
    int result;
    Solution solution;

    cout << "Test case 1" << endl;
    plants = {2, 2, 3, 3};
    capacityA = 5;
    capacityB = 5;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 1" << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 2" << endl;
    plants = {2, 2, 3, 4};
    capacityA = 3;
    capacityB = 4;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 2" << endl;
    cout << "Result   : " << result << endl << endl;


    cout << "Test case 3" << endl;
    plants = {5};
    capacityA = 10;
    capacityB = 8;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 0" << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 4" << endl;
    plants = {1, 2, 4, 4, 5};
    capacityA = 6;
    capacityB = 5;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 2" << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 5" << endl;
    plants = {2, 1, 1};
    capacityA = 2;
    capacityB = 2;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 0" << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 6" << endl;
    plants = {2, 3, 3};
    capacityA = 5;
    capacityB = 5;
    result = solution.minimumRefill(plants, capacityA, capacityB);
    cout << "Expected : 0" << endl;
    cout << "Result   : " << result << endl << endl;

    return 0;
}