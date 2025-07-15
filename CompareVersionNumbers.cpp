// https://leetcode.com/problems/compare-version-numbers/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.length(), n2 = version2.length();

        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;

            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }

            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            ++i;  // skip the dot
            ++j;
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