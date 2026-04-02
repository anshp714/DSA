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
    ListNode* reverseList(ListNode* head) {
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL) {
            next = curr->next;    // Store next node
            curr->next = prev;     // Reverse current node's pointer
            prev = curr;           // Move prev forward
            curr = next;           // Move curr forward
        }
        return prev;  // New head of reversed list
    }
};

// Helper function to create linked list from array
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for(int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    cout << "[";
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val;
        if(current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << "]";
}

// Helper function to delete linked list (free memory)
void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    
    // Test Case 1: Reverse a list of 5 elements
    {
        cout << "Test Case 1: Reverse [1, 2, 3, 4, 5]" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* reversed = sol.reverseList(head);
        
        cout << "Reversed: ";
        printList(reversed);
        cout << endl;
        cout << "Expected: [5 -> 4 -> 3 -> 2 -> 1]" << endl << endl;
        
        deleteList(reversed);
    }
    
    // Test Case 2: Reverse a list of 2 elements
    {
        cout << "Test Case 2: Reverse [1, 2]" << endl;
        vector<int> values = {1, 2};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* reversed = sol.reverseList(head);
        
        cout << "Reversed: ";
        printList(reversed);
        cout << endl;
        cout << "Expected: [2 -> 1]" << endl << endl;
        
        deleteList(reversed);
    }
    
    // Test Case 3: Reverse a single element list
    {
        cout << "Test Case 3: Reverse [1]" << endl;
        vector<int> values = {1};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* reversed = sol.reverseList(head);
        
        cout << "Reversed: ";
        printList(reversed);
        cout << endl;
        cout << "Expected: [1]" << endl;
        
        deleteList(reversed);
    }
    
    return 0;
}