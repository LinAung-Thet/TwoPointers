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
    ListNode* removeNode(int& n, int& forward, int& backward, ListNode* curr) {
        forward++;
        if(curr->next == nullptr) {
            backward = 1;
            if(n==1)    // last node
                return nullptr;
            return curr;
        }
        ListNode* nextNode = removeNode(n, forward, backward, curr->next);

        // if (backward > 0) {
            backward++;
            curr->next = nextNode;

            if(backward == n) {
                return nextNode;
            }
            else {
                return curr;
            }
        // }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode buff(0, head);
        int forward = 0, backward = 0;

        removeNode(n, forward, backward, &buff);

        return buff.next;
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