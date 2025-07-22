// https://leetcode.com/problems/friends-of-appropriate-ages/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int freq[121] = {0}, n = ages.size();
        for(int i = 0; i < n; ++i) ++freq[ages[i]];
        for(int i = 1; i < 121; ++i) freq[i] += freq[i - 1];
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(ages[i] < 15) continue;
            int low = 0.5 * ages[i] + 7;
            res += freq[ages[i]] - freq[low] - 1;
        }
        return res;
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