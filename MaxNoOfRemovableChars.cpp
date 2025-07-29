// https://leetcode.com/problems/maximum-number-of-removable-characters/submissions/1714193617/

#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
private:
    bool check(string s , string p){
        int j = 0, n = s.length(), m = p.length();
        for(int i = 0; i < n && j < m; ++i){
            if(s[i] == p[j]) ++j;
        }
        return j == m;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        while(left <= right){
            int mid = left + (right - left) / 2;
            string removed = s;
            for(int i = 0; i < mid; ++i) removed[removable[i]] = '#';
            if(check(removed , p)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

// Test cases
int main() {
    Solution solution;
    string s, p;
    vector<int> removable;
    int result;

    cout << "Test case 1" << endl;
    s = {"abcacb"};
    p = {"ab"};
    removable = {3, 1, 0};
    cout << "s : " << s << endl;
    cout << "p : " << p << endl;
    result = solution.maximumRemovals(s, p, removable);
    cout << "Expected : " << 2 << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 2" << endl;
    s = {"abcbddddd"};
    p = {"abcd"};
    removable = {3, 2, 1, 4, 5, 6};
    cout << "s : " << s << endl;
    cout << "p : " << p << endl;
    result = solution.maximumRemovals(s, p, removable);
    cout << "Expected : " << 1 << endl;
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 3" << endl;
    s = {"abcacb"};
    p = {"abc"};
    removable = {0, 1, 2, 3, 4};
    cout << "s : " << s << endl;
    cout << "p : " << p << endl;
    result = solution.maximumRemovals(s, p, removable);
    cout << "Expected : " << 0 << endl;
    cout << "Result   : " << result << endl << endl;

}