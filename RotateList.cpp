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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute length of list and get tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }

        // Step 2: Compute effective rotation
        k %= length;
        if (k == 0) return head;

        // Step 3: Connect tail to head to form a circular list
        tail->next = head;

        // Step 4: Find new tail (length - k - 1) and new head (length - k)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    ListNode* result;

    result = sol.rotateRight(head, k);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [4 5 1 2 3]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 2
    head = new ListNode(0, new ListNode(1, new ListNode(2)));
    k = 4;

    result = sol.rotateRight(head, k);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [2 0 1]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Test case 3
    head = nullptr;
    k = 1;

    result = sol.rotateRight(head, k);
    
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

    // Test case 4
    head = new ListNode(1, new ListNode(2));
    k = 2;

    result = sol.rotateRight(head, k);
    
    // Print the resulting list
    cout << "Result: [";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "]" << endl;
    cout << "Expected: [1 2]" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}