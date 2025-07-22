// https://leetcode.com/problems/friends-of-appropriate-ages/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> sorted = ages;
        sort(sorted.begin(), sorted.end());

        int total = 0;
        int n = sorted.size();

        for (int i = 0; i < n; ++i) {
            int ageX = sorted[i];
            if (ageX < 15) continue;  // No one under 15 can send requests

            // Find lower bound: ageY > 0.5 * ageX + 7
            int minAge = ageX / 2 + 7;
            auto lower = upper_bound(sorted.begin(), sorted.end(), minAge);
            auto upper = upper_bound(sorted.begin(), sorted.end(), ageX);

            int count = upper - lower;
            if (count > 0) total += count - 1;  // exclude self
        }

        return total;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> ages;

    cout << "Test case 1" << endl;
    ages = {16, 16};
    cout << "Ages: ";
    for (int age : ages) cout << age << " ";
    cout << endl;
    cout << "Friend requests: " << sol.numFriendRequests(ages) << endl;
    cout << "Expected       : 2" << endl << endl;

    cout << "Test case 2" << endl;
    ages = {16, 17, 18};
    cout << "Ages: ";
    for (int age : ages) cout << age << " ";
    cout << endl;
    cout << "Friend requests: " << sol.numFriendRequests(ages) << endl;
    cout << "Expected       : 2" << endl << endl;

    cout << "Test case 3" << endl;
    ages = {20, 30, 100, 110, 120};
    cout << "Ages: ";
    for (int age : ages) cout << age << " ";
    cout << endl;
    cout << "Friend requests: " << sol.numFriendRequests(ages) << endl;
    cout << "Expected       : 3" << endl << endl;

    cout << "Test case 4" << endl;
    ages = {101,56,69,48,30};
    cout << "Ages: ";
    for (int age : ages) cout << age << " ";
    cout << endl;
    cout << "Friend requests: " << sol.numFriendRequests(ages) << endl;
    cout << "Expected       : 4" << endl << endl;

    cout << "Test case 5" << endl;
    ages = {73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
    cout << "Ages: ";
    for (int age : ages) cout << age << " ";
    cout << endl;
    cout << "Friend requests: " << sol.numFriendRequests(ages) << endl;
    cout << "Expected       : 29" << endl << endl;

    return 0;
}