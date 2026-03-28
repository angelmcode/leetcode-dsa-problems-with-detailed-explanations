// time complexity: O(n); Space COmplexity: O(n) 
#include <iostream>
#include <vector>

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
        if (!head) return;
        vector<ListNode*> v;
        ListNode* curr = head;
        while(curr){
            v.push_back(curr);
            curr=curr->next;
        }
        int l=1; int r=v.size()-1;
        while(l<=r){
            head->next = v[r];
            head = head->next;
            if(l!=r){
                head->next = v[l];
                head = head->next;
            }
            l++;
            r--;
        }
        head->next = nullptr;
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