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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        // Fixed: Move fast pointer 2 steps ahead initially
        // to make slow point to the node before middle
        fast = fast->next->next;
        
        ListNode* temp;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
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
    
    // Test Case 1: Odd number of nodes (5 nodes)
    {
        cout << "Test Case 1: Delete middle of [1, 2, 3, 4, 5]" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteMiddle(head);
        
        cout << "After deleting middle: ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 -> 2 -> 4 -> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 2: Even number of nodes (6 nodes)
    {
        cout << "Test Case 2: Delete middle of [1, 2, 3, 4, 5, 6]" << endl;
        vector<int> values = {1, 2, 3, 4, 5, 6};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteMiddle(head);
        
        cout << "After deleting middle: ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 -> 2 -> 3 -> 5 -> 6]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 3: Single node
    {
        cout << "Test Case 3: Delete middle of [1]" << endl;
        vector<int> values = {1};
        ListNode* head = createList(values);
        cout << "Original: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteMiddle(head);
        
        cout << "After deleting middle: ";
        if(result == NULL) {
            cout << "NULL (empty list)";
        } else {
            printList(result);
        }
        cout << endl;
        cout << "Expected: NULL (empty list)" << endl;
        
        if(result != NULL) deleteList(result);
    }
    
    return 0;
}