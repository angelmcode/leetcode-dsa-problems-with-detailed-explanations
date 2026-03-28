// time complexity: O(n); Space COmplexity: O(1)
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;
        ListNode* first = head;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

    }
};

// --- Helper Functions ---

void printList(ListNode* node) {
    while (node) {
        cout << node->val << (node->next ? " -> " : "");
        node = node->next;
    }
    cout << endl;
}

int main() {
    // 1. Setup: Create list 1 -> 2 -> 3 -> 4 -> 5 on the heap
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original: ";
    printList(head);

    // 2. Execution
    Solution sol;
    sol.reorderList(head);

    cout << "Reordered: ";
    printList(head);

    // 3. Cleanup: Explicitly delete nodes to prevent memory leaks
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp; // Freeing the heap memory
    }
    
    cout << "Memory cleared." << endl;

    return 0;
}