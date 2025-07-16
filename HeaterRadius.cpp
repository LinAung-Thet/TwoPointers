// https://leetcode.com/problems/heaters/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;

        for (int house : houses) {
            // Find the insertion point (lower bound) for the house in heaters
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int dist1 = (it == heaters.end()) ? INT_MAX : *it - house;
            int dist2 = (it == heaters.begin()) ? INT_MAX : house - *(prev(it));

            // Minimal distance to a heater
            int closest = min(dist1, dist2);

            // Update max distance
            radius = max(radius, closest);
        }

        return radius;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> houses, heaters;

    cout<< "Test case 1" << endl;
    houses = {1, 2, 3};
    heaters = {2};
    cout << "Houses  : 1 2 3" << endl;
    cout << "Heaters : 2" << endl;
    cout << "Radius  : " << sol.findRadius(houses, heaters) << endl; 
    cout << "Expected: 1" << endl << endl;

    cout<< "Test case 2" << endl;
    houses = {1, 2, 3, 4};
    heaters = {1, 4};
    cout << "Houses  : 1 2 3 4" << endl;
    cout << "Heaters : 1 4" << endl;
    cout << "Radius  : " << sol.findRadius(houses, heaters) << endl; 
    cout << "Expected: 1" << endl << endl;

    cout<< "Test case 3" << endl;
    houses = {1, 5};
    heaters = {2};
    cout << "Houses  : 1 5" << endl;
    cout << "Heaters : 2" << endl;
    cout << "Radius  : " << sol.findRadius(houses, heaters) << endl; 
    cout << "Expected: 3" << endl << endl;

    cout<< "Test case 4" << endl;
    houses = {35308228,158374933,75260298,824938981,595028635,962408013,137623865,997389814,20739063};
    heaters = {635339425,654001669,777724115,269220094,34075629,478446501,864546517};
    cout << "Houses  : 35308228 158374933 75260298 824938981 595028635 962408013 137623865 997389814 20739063" << endl;
    cout << "Heaters : 635339425 654001669 777724115 269220094 34075629 478446501 864546517" << endl;
    cout << "Radius  : " << sol.findRadius(houses, heaters) << endl; 
    cout << "Expected: 132843297" << endl << endl;

    cout<< "Test case 5" << endl;
    houses = {617819336,399125485,156091745,356425228};
    heaters = {585640194,937186357};
    cout << "Houses  : 617819336 399125485 156091745 356425228" << endl;
    cout << "Heaters : 585640194 937186357" << endl;
    cout << "Radius  : " << sol.findRadius(houses, heaters) << endl; 
    cout << "Expected: 429548449" << endl << endl;

    return 0;
}