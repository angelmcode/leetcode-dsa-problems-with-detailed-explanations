// Time Complexity: O(n+m) Space Complexity: O(1)
#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if (list1) {
         node->next = list1;
        } else{
         node->next = list2;
        }
        return dummy.next;
    }
};

int main() {
    // 1. Manually build List 1: 1 -> 2 -> 4
    ListNode* n3 = new ListNode(4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* l1 = new ListNode(1, n2);

    // 2. Manually build List 2: 1 -> 3 -> 4
    ListNode* m3 = new ListNode(4);
    ListNode* m2 = new ListNode(3, m3);
    ListNode* l2 = new ListNode(1, m2);

    // 3. Run the solution
    Solution sol;
    ListNode* result = sol.mergeTwoLists(l1, l2);

    ListNode* headToDelete = result;

    // 4. Print the result
    std::cout << "Merged List: ";
    while (result != nullptr) {
        std::cout << result->val << (result->next ? " -> " : "");
        result = result->next;
    }
    std::cout << std::endl;

    while (headToDelete != nullptr) {
        ListNode* temp = headToDelete;      // Save current node
        headToDelete = headToDelete->next;  // Move to next node
        delete temp;                        // Delete the saved node
        std::cout << "[Deleted node]" << std::endl; 
    }

    // Note: In a real app, you'd delete these nodes to free memory!
    return 0;
}