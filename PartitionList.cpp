// https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lower(0), higher(0);
        ListNode* h1 = &lower;
        ListNode* h2 = &higher;

        while(head) {
            if(head->val < x) {
                h1->next = head;
                h1 = h1->next;
            }
            else {
                h2->next = head;
                h2 = h2->next;
            }
            head = head->next;
        }
        h1->next = higher.next;
        h2->next = nullptr;

        return lower.next;
    }
};

// Test cases
int main() {
    Solution sol;
    ListNode* head;

    // Test case 1
    head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    head = sol.partition(head, 3);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl; 
    cout << "Expected: 1 2 2 4 3 5" << endl << endl;

    // Test case 2
    head = new ListNode(2, new ListNode(1));
    head = sol.partition(head, 2);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    cout << "Expected: 1 2" << endl << endl;

    return 0;
}