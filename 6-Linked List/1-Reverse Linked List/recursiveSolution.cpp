// Time Complexity: O(n) Space Complexity: O(n)
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if (head==nullptr){
        return nullptr;
       }

       ListNode* newhead = head;
       if (head->next != nullptr)
       {
        newhead = reverseList(head->next);
        head->next->next=head;
       }
       head->next=nullptr;
       return newhead;
    }
};

void printList(ListNode* head) {
    if (!head) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    while (head) {
        std::cout << head->val << (head->next ? "," : "");
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main() {
    // 1. Initialize nodes
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    ListNode* head  = new ListNode(0, node1);

    // 2. Original List (Note: This print won't work correctly AFTER reversal 
    // because the original head '0' will now be the tail.)
    std::cout << "Original List construction finished." << std::endl;
    std::cout << "Original List: ";
    printList(head);

    // 3. Reverse logic
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    // 4. Print Reversed
    std::cout << "Reversed List: ";
    printList(reversedHead);

    // 5. CLEANUP: Delete the nodes to prevent memory leaks
    // We use reversedHead because it's the current start of the list
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    
    std::cout << "Memory successfully cleared." << std::endl;

    return 0;
}