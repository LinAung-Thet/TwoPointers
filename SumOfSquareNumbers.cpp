// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 2) return true;

        int sqRoot = static_cast<int>(sqrt(c));
        int first = sqRoot, second = first / 2;

        while(first > sqRoot / 2) {
            int sqFirst = first * first;
            int second = static_cast<int>(sqrt(c - sqFirst));
            if(sqFirst + second * second == c) return true;
            --first;
        }
        return false;
    }
};
// Test cases
int main() {
    Solution sol;
    int c;

    std::cout << "Test case 1" << std::endl;
    c = 5;
    std::cout << "Input: " << c << std::endl;
    std::cout << "Result: " << (sol.judgeSquareSum(c) ? "true" : "false") << std::endl; 
    std::cout << "Expected: true" << std::endl << std::endl;

    std::cout << "Test case 2" << std::endl;
    c = 3;
    std::cout << "Input: " << c << std::endl;
    std::cout << "Result: " << (sol.judgeSquareSum(c) ? "true" : "false") << std::endl; 
    std::cout << "Expected: false" << std::endl << std::endl;

    std::cout << "Test case 3" << std::endl;
    c = 1;
    std::cout << "Input: " << c << std::endl;
    std::cout << "Result: " << (sol.judgeSquareSum(c) ? "true" : "false") << std::endl; 
    std::cout << "Expected: true" << std::endl << std::endl;

    std::cout << "Test case 4" << std::endl;
    c = 0;
    std::cout << "Input: " << c << std::endl;
    std::cout << "Result: " << (sol.judgeSquareSum(c) ? "true" : "false") << std::endl; 
    std::cout << "Expected: true" << std::endl << std::endl;

    return 0;
}