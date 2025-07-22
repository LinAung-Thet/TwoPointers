// https://leetcode.com/problems/most-profit-assigning-work/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();

        // Step 1: Pair each job's difficulty and profit, then sort by difficulty
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        // Step 2: Sort workers by ability
        sort(worker.begin(), worker.end());

        int maxProfitSoFar = 0;
        int jobIndex = 0;
        int totalProfit = 0;

        // Step 3: For each worker, find the best job they can perform
        for (int ability : worker) {
            while (jobIndex < n && jobs[jobIndex].first <= ability) {
                maxProfitSoFar = max(maxProfitSoFar, jobs[jobIndex].second);
                ++jobIndex;
            }
            totalProfit += maxProfitSoFar;
        }

        return totalProfit;
    }
};
// Test cases
int main() {
    Solution sol;
    vector<int> difficulty;
    vector<int> profit;
    vector<int> worker;
    int result;
    
    cout << "Test case 1" << endl;
    difficulty = {2, 4, 6, 8, 10};
    profit = {10, 20, 30, 40, 50};
    worker = {4, 5, 6, 7};

    cout << "Test case 1" << endl;
    cout << "Input difficulties: ";
    for (int d : difficulty) cout << d << " ";
    cout << "\nInput profits: ";
    for (int p : profit) cout << p << " ";
    cout << "\nInput workers: ";
    for (int w : worker) cout << w << " ";
    
    result = sol.maxProfitAssignment(difficulty, profit, worker);
    cout << "\nTotal profit: " << result << endl; 
    cout << "Expected      : 100" << endl << endl;
    
    cout << "Test case 2" << endl;
    difficulty = {85,47,57};
    profit = {24,66,99};
    worker = {40,25,25};

    cout << "Test case 1" << endl;
    cout << "Input difficulties: ";
    for (int d : difficulty) cout << d << " ";
    cout << "\nInput profits: ";
    for (int p : profit) cout << p << " ";
    cout << "\nInput workers: ";
    for (int w : worker) cout << w << " ";
    
    result = sol.maxProfitAssignment(difficulty, profit, worker);
    cout << "\nTotal profit: " << result << endl; 
    cout << "Expected      : 0" << endl << endl;

    return 0;
}