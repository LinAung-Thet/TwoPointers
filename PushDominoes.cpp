// https://leetcode.com/problems/push-dominoes/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        if(n < 2) return dominoes;

        char prev = dominoes[0];
        int rCount = 0;
        string result = dominoes;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'R') {
                prev = 'R';
                rCount = 0;
                // The state of the prev is not necessary for the current domino (result is unchanged)
            }
            else if(dominoes[i] == '.') {  
                if(prev == 'R') {
                    result[i] = 'R';
                    ++rCount;
                }
                // The state of the prev being 'L' and '.' don't affect on the current domino.
            }
            else {  // (dominoes[i] == 'L') 
                prev = 'L';
                if(i > 0 && dominoes[i - 1] != '.') {
                    continue;
                }
                // Convert the previous '.'s until 'R' or 'L' is found.
                int j = i - 1;
                int lCount = 0;
                while(j >= 0){
                    if(dominoes[j] == 'L' || dominoes[j] == 'R') break;
                    result[j] = 'L';
                    if(rCount > 0) {
                        ++lCount;
                        if(lCount == (rCount + 1) / 2) {
                            result[j] = rCount % 2 == 1 ? '.' : 'L';
                            break;
                        }
                    }
                    --j;
                }
                rCount = 0;
            }

        }
        return result;
    }
};
// Test cases
int main() {
    Solution sol;
    string dominoes;

    // cout << "Test case 1" << endl;
    // dominoes = "RR.L";
    // cout << "Dominoes: " << dominoes << endl;
    // cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    // cout << "Expected: RR.L" << endl << endl;

    // cout << "Test case 2" << endl;
    // dominoes = ".L.R...LR..L..";
    // cout << "Dominoes: " << dominoes << endl;
    // cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    // cout << "Expected: LL.RR.LLRRLL.." << endl << endl;

    cout << "Test case 3" << endl;
    dominoes = "L.....RR.RL.....L.R.";
    cout << "Dominoes: " << dominoes << endl;
    cout << "Result: " << sol.pushDominoes(dominoes) << endl;
    cout << "Expected: L.....RRRRLLLLLLL.RR" << endl;

    return 0;
}