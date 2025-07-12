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
    // Recursive helper: removes nth node from end and returns updated list
    ListNode* removeNode(int n, int& backward, ListNode* curr) {
        if (!curr) return nullptr;

        curr->next = removeNode(n, backward, curr->next);
        ++backward;

        return (backward == n) ? curr->next : curr;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);      // Dummy node to handle head removal
        int backward = 0;
        dummy.next = removeNode(n, backward, dummy.next);
        return dummy.next;
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