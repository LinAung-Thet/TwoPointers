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
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* left = head;
        ListNode* right = head;
        ListNode* last;
        int count = 0;

        // Place the sliding window which has k nodes in length
        for (int i = 0; i < k; i++) {
            if (right == nullptr)
                break;
            right = right->next;
            ++count;
        }

        if(count == k && right == nullptr) return head;
        if(count != k) { // k is greater than the length of the list
            k = k % count;

            // Place the sliding window again
            right = head;
            for (int i = 0; i < k; i++) {
                if (!right)
                    break;
                right = right->next;
            }
        }

        if (!right)
            return nullptr;

        // Move the window until the end
        while(right->next) {
            last = left;
            right = right->next;
            left = left->next;
        }

        // Bring the nodes in the window to the front
        // if(last)
        //     last->next = nullptr;
        right->next = head;
        head = left->next;
        left->next = nullptr;

        return head;
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