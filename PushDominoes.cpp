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
        string result = dominoes;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'R') {
                prev = 'R';
                // The state of the prev is not necessary for the current domino (result is unchanged)
            }
            else if(dominoes[i] == '.') {  
                if(prev == 'R')
                    result[i] = 'R';
                // The state of the prev being 'L' and '.' don't affect on the current domino.
            }
            else {  // (dominoes[i] == 'L') 
                prev = 'L';
                // Convert the previous dominoes until 'R' or 'L' is found.
                int j = i - 1;
                while(j >= 0){
                    if(dominoes[j] == '.') {
                        if(j > 0 && dominoes[j - 1] == 'R') {
                            result[j] = '.';
                            break;
                        }
                        else result[j] = 'L';
                        j--;
                    }
                    else if(dominoes[j] == 'R') {
                        result[j] = '.';
                        break;
                    }
                    else {      // (dominoes[j] == 'L') 
                        // The left of this domino has been handled at i-1 step.
                        break;
                    }
                }
            }

        }
        return result;
    }
};