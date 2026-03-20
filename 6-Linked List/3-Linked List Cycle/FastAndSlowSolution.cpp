// Time Complexity: O(n) Space Complexity: O(1)
#include <iostream>
#include <unordered_set>

using namespace std;

// 1. Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if (slow==fast) return true;
        }
        return false;
    }
};

int main() {
    // --- SETUP ---
    // Create nodes on the Heap
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(0);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;


    // --- EXECUTION ---
    Solution sol;
    if (sol.hasCycle(node1)) {
        cout << "Result: Cycle detected in the linked list." << endl;
    } else {
        cout << "Result: No cycle detected." << endl;
    }

    // --- HEAP DELETION (Memory Cleanup) ---
    // We must break the cycle before deleting, or we'll loop forever!
    node4->next = nullptr; 
    
    ListNode* temp = node1;
    while (temp != nullptr) {
        ListNode* nextNode = temp->next;
        delete temp;  // Free the memory
        temp = nextNode;
    }

    cout << "Memory cleaned up successfully." << endl;
    return 0;
}