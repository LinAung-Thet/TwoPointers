// https://leetcode.com/problems/string-compression/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n < 2) return n;

        int left = 0, right = 1, c = 0;
        while(left < n) {
            int d = 0;
            chars[c++] = chars[left];
            while(right < n && chars[left] == chars[right]) {
                ++d;
                ++right;
            }
            d = d > 0 ? ++d : d;

            stack<char> s;
            while(d > 0) {
                if(d == 10) {
                    s.push('0');
                    s.push('1');
                    break;
                }
                s.push(d % 10 + '0');
                d = d / 10;
            }
            while(!s.empty()) {
                chars[c++] = s.top();
                s.pop();
            }
        
            left = right++;
        }
        return c;
    }
};

// Test cases
int main() {
    Solution sol;
    vector<char> chars;

    // Test case 1
    chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = sol.compress(chars);
    cout << "Input  : a, a, b, b, c, c, c" << endl; 
    cout << "Result : ";
    for (int i = 0; i < result; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "Expected: a 2 b 2 c 3" << endl << endl;

    // Test case 2
    chars = {'a'};
    result = sol.compress(chars);
    cout << "Input  : a" << endl;
    cout << "Result : ";
    for (int i = 0; i < result; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "Expected: a" << endl << endl;

    // Test case 3
    chars = {'a', 'b', 'c'};
    result = sol.compress(chars);
    cout << "Input  : a, b, c" << endl;
    cout << "Result : ";
    for (int i = 0; i < result; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "Expected: a b c" << endl << endl;

    // Test case 4
    chars = {'a', 'b', 'b', 'b', 'b', 'b',  'b', 'b', 'b', 'b', 'b', 'b', 'b',};
    result = sol.compress(chars);
    cout << "Input  : a, b, b, b, b, b, b, b, b, b, b, b, b" << endl;
    cout << "Result : ";
    for (int i = 0; i < result; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "Expected: a b 1 2" << endl << endl;

    // Test case 5
    chars = {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'};
    result = sol.compress(chars);
    cout << "Input  : o, o, o, o, o, o, o, o, o, o" << endl;
    cout << "Result : ";
    for (int i = 0; i < result; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    cout << "Expected: o 1 0" << endl << endl;

    return 0;
}