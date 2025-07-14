// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=problem-list-v2&envId=two-pointers

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0, head);
        ListNode* curr = &dummy;
        ListNode* nextNode = curr->next;
        while(curr != nullptr) {
            int count = 0;

            while(nextNode != nullptr && nextNode->next != nullptr && 
                curr->next->val == nextNode->next->val) {
                ++count;
                nextNode = nextNode->next;
            }

            if(count > 0) {
                curr->next = nextNode->next;
                nextNode = curr->next;
            }
            else {
                curr = curr->next;
                if(curr == nullptr) break;
                nextNode = curr->next == nullptr ? nullptr : curr->next;
            }
        }

        return dummy.next;
    }
};

// Test cases
int main() {
    Solution sol;
    ListNode* head;

    // Test case 1
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
    head = sol.deleteDuplicates(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl; //
    cout << "Expected: 1 2 5" << endl << endl;

    // Test case 2
    head = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3)))));
    head = sol.deleteDuplicates(head);
    cout << "Result:   ";
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl; 
    cout << "Expected: 2 3" << endl << endl;


    return 0;
}