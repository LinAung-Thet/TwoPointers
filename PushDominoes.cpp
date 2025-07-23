// https://leetcode.com/problems/push-dominoes/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n, 0);

        // Apply rightward force
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') f = n;
            else if (dominoes[i] == 'L') f = 0;
            else f = max(f - 1, 0);
            force[i] += f;
        }

        // Apply leftward force
        f = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') f = n;
            else if (dominoes[i] == 'R') f = 0;
            else f = max(f - 1, 0);
            force[i] -= f;
        }

        // Resolve final states based on net force
        string result;
        for (int i = 0; i < n; ++i) {
            if (force[i] > 0) result += 'R';
            else if (force[i] < 0) result += 'L';
            else result += '.';
        }

        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    string dominoes;

    cout << "Test case 1" << endl;
    dominoes = "RR.L";
    cout << "Dominoes: " << dominoes << endl;
    cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    cout << "Expected: RR.L" << endl << endl;

    cout << "Test case 2" << endl;
    dominoes = ".L.R...LR..L..";
    cout << "Dominoes: " << dominoes << endl;
    cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    cout << "Expected: LL.RR.LLRRLL.." << endl << endl;

    cout << "Test case 3" << endl;
    dominoes = "L.....RR.RL.....L.R.";
    cout << "Dominoes: " << dominoes << endl;
    cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    cout << "Expected: L.....RRRRLLLLLLL.RR" << endl;

    return 0;
}