// https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=two-pointers

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        
        if (nums.size() < 3) {
            return answer;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int low = i + 1, high = nums.size() - 1;
            
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum > 0) {
                    high--;
                } else if (sum < 0) {
                    low++;
                } else {
                    answer.push_back({nums[i], nums[low], nums[high]});
                    int last_low_occurrence = nums[low], last_high_occurrence = nums[high];
                    
                    while (low < high && nums[low] == last_low_occurrence) {
                        low++;
                    }
                    
                    while (low < high && nums[high] == last_high_occurrence) {
                        high--;
                    }
                }
            }
        }
        
        return answer;
    }
};

// Test cases
int main() {
    Solution sol;
    vector<int> nums;
    string expected;
    
    // Test case 1
    nums = {-1, 0, 1, 2, -1, -4};
    expected = "[[-1,-1,2],[-1,0,1]]";
    vector<vector<int>> result = sol.threeSum(nums);
    cout << "Expected: " << expected << endl;
    cout << "Result: ";
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Test case 2
    nums = {0, 1, 1};
    result = sol.threeSum(nums);
    expected = "[]";
    cout << "Expected: " << expected << endl;
    cout << "Result: ";
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Test case 3
    nums = {0, 0, 0};
    result = sol.threeSum(nums);
    expected = "[[0,0,0]]";
    cout << "Expected: " << expected << endl;
    cout << "Result: ";
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}