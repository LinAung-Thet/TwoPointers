// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=problem-list-v2&envId=two-pointers

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int freq[100001]={0};
        #pragma unroll
        for(int x: nums )
            freq[x]++;
        int l=0, r=100000, maxP=0, pairN=1, rN=0, lN=0;
        #pragma unroll
        while (l < r) {
            #pragma unroll
            while (lN < pairN) {
                lN += freq[l++];
            }
            #pragma unroll
            while (rN < pairN) {
                rN += freq[r--];
            }
            maxP = max(maxP, l+r);
            pairN++;
        }
        return maxP;
    }
};
// Test cases
int main()
{
    vector<int> input;
    int result;
    Solution solution;

    cout << "Test case 1" << endl;
    input = {3,5,2,3};
    cout << "Input : ";
    for(int i = 0; i < input.size(); i++)
        cout << input[i] << " ";
    cout << endl;
    cout << "Expected : 7" << endl;
    result = solution.minPairSum(input);
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 2" << endl;
    input = {3,5, 4,2,4,6};
    cout << "Input : ";
    for(int i = 0; i < input.size(); i++)
        cout << input[i] << " ";
    cout << endl;
    cout << "Expected : 8" << endl;
    result = solution.minPairSum(input);
    cout << "Result   : " << result << endl << endl;

    cout << "Test case 1" << endl;
    input = {5,2,1,1,4,4,1,2,1,5};
    cout << "Input : ";
    for(int i = 0; i < input.size(); i++)
        cout << input[i] << " ";
    cout << endl;
    cout << "Expected : 6" << endl;
    result = solution.minPairSum(input);
    cout << "Result   : " << result << endl << endl;

    return 0;
}