// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=two-pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move 'fast' n steps ahead
        for (int i = 0; i < n; ++i)
            fast = fast->next;

        // If fast is nullptr, we are removing the head
        if (!fast)
            return head->next;

        // Move both pointers until 'fast' reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the nth node from the end
        slow->next = slow->next->next;

        return head;
    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    ListNode* result = sol.removeNthFromEnd(head, n);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [1 2 3 5]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 2
    head = new ListNode(1);
    n = 1;

    result = sol.removeNthFromEnd(head, n);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: []" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 3
    head = new ListNode(1, new ListNode(2));
    n = 1;

    result = sol.removeNthFromEnd(head, n);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [1]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 4
    head = new ListNode(1, new ListNode(2));
    n = 2;

    result = sol.removeNthFromEnd(head, n);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [2]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}