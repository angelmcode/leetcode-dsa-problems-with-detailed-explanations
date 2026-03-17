// Time Complexity: O(n+m) Space Complexity: O(n+m)
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
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
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