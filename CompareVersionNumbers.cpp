// https://leetcode.com/problems/compare-version-numbers/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t start1 = 0, start2 = 0, end1 = 0, end2 = 0;
        string subV1, subV2;
        int v1, v2;

        string delim = ".";
        while(end1 != string::npos || end2 != string::npos) {
            v1 = 0; v2 = 0; // Reset for each segment

            if(end1 != string::npos) {
                end1 = version1.find(delim, start1);
                if(end1 == string::npos) {
                    subV1 = version1.substr(start1);
                }
                else {
                    subV1 = version1.substr(start1, end1 - start1);
                    start1 = end1 + 1; // size of delim
                }
                v1 = stoi(subV1);
            }

            if(end2 != string::npos) {
                end2 = version2.find(delim, start2);
                if(end2 == string::npos) {
                    subV2 = version2.substr(start2);
                }
                else {
                    subV2 = version2.substr(start2, end2 - start2);
                    start2 = end2 + 1;
                }
                v2 = stoi(subV2);
            }

            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
        }
        return 0;
    }
};
// Test cases
int main() {
    Solution sol;
    string v1, v2;

    // Test case 1
    v1 = "1.2"; v2 = "1.10";
    cout << "Compare " << v1 << " and " << v2 << ": "  << sol.compareVersion(v1, v2) << endl;
    cout << "Expected: -1" << endl << endl;

    // Test case 2
    v1 = "1.01"; v2 = "1.001";
    cout << "Compare " << v1 << " and " << v2 << ": "  << sol.compareVersion(v1, v2) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test case 3
    v1 = "1.0"; v2 = "1.0.0.0";
    cout << "Compare " << v1 << " and " << v2 << ": "  << sol.compareVersion(v1, v2) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test case 4
    v1 = "1.0.1"; v2 = "1";
    cout << "Compare " << v1 << " and " << v2 << ": "  << sol.compareVersion(v1, v2) << endl;
    cout << "Expected: 1" << endl << endl;

    
    return 0;
}