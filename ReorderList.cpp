// https://leetcode.com/problems/reorder-list/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderRight(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr;  // Cut off the first half

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    sol.reorderRight(head);
    
    // Print the resulting list
    cout << "Result  : ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    cout << "Expected: 1 4 2 3" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 2
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    sol.reorderRight(head);
    
    // Print the resulting list
    cout << "Result  : ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    cout << "Expected: 1 5 2 4 3" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}