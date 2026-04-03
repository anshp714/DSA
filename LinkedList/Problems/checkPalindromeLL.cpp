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

// Helper function to reverse linked list
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Fixed: Check if head is NULL or only one node
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the middle of the linked list
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half
        ListNode* newHead = reverseLinkedList(slow->next);
        
        // Compare first and second half
        ListNode* first = head;
        ListNode* second = newHead;
        
        while(second != NULL) {
            if(first->val != second->val) {
                reverseLinkedList(newHead); // Restore original list
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        // Restore original list (optional)
        reverseLinkedList(newHead);
        return true;
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
    
    // Test Case 1: Palindrome with odd number of nodes
    {
        cout << "Test Case 1: Palindrome [1, 2, 3, 2, 1]" << endl;
        vector<int> values = {1, 2, 3, 2, 1};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        bool result = sol.isPalindrome(head);
        cout << "Is palindrome? " << (result ? "true" : "false") << endl;
        cout << "Expected: true" << endl << endl;
        
        deleteList(head);
    }
    
    // Test Case 2: Not a palindrome
    {
        cout << "Test Case 2: Not palindrome [1, 2, 3, 4, 5]" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        bool result = sol.isPalindrome(head);
        cout << "Is palindrome? " << (result ? "true" : "false") << endl;
        cout << "Expected: false" << endl << endl;
        
        deleteList(head);
    }
    
    // Test Case 3: Palindrome with even number of nodes
    {
        cout << "Test Case 3: Palindrome [1, 2, 2, 1]" << endl;
        vector<int> values = {1, 2, 2, 1};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        bool result = sol.isPalindrome(head);
        cout << "Is palindrome? " << (result ? "true" : "false") << endl;
        cout << "Expected: true" << endl;
        
        deleteList(head);
    }
    
    return 0;
}