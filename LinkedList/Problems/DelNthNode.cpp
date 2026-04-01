#include <iostream>
#include <vector>  // Added this include
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // If fast is NULL, we need to remove the head node
        if(fast == NULL) return head->next;
        
        // Move both pointers until fast reaches the end
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
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
    
    // Test Case 1: Remove 2nd node from end
    {
        cout << "Test Case 1: Remove 2nd node from end" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.removeNthFromEnd(head, 2);
        
        cout << "After removing 2nd node from end: ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 -> 2 -> 3 -> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 2: Remove head node
    {
        cout << "Test Case 2: Remove head node (n = length)" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.removeNthFromEnd(head, 5);
        
        cout << "After removing 5th node from end (head): ";
        printList(result);
        cout << endl;
        cout << "Expected: [2 -> 3 -> 4 -> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 3: Remove last node
    {
        cout << "Test Case 3: Remove last node (n = 1)" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.removeNthFromEnd(head, 1);
        
        cout << "After removing last node: ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 -> 2 -> 3 -> 4]" << endl;
        
        deleteList(result);
    }
    
    return 0;
}