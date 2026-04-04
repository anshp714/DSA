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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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
        cout << "Test Case 1: List with 5 nodes [1, 2, 3, 4, 5]" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        ListNode* middle = sol.middleNode(head);
        cout << "Middle node value: " << middle->val << endl;
        cout << "Expected: 3 (index 2, 0-based indexing)" << endl << endl;
        
        deleteList(head);
    }
    
    // Test Case 2: Even number of nodes (6 nodes)
    {
        cout << "Test Case 2: List with 6 nodes [1, 2, 3, 4, 5, 6]" << endl;
        vector<int> values = {1, 2, 3, 4, 5, 6};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        ListNode* middle = sol.middleNode(head);
        cout << "Middle node value: " << middle->val << endl;
        cout << "Expected: 4 (second middle node, index 3)" << endl << endl;
        
        deleteList(head);
    }
    
    // Test Case 3: Single node
    {
        cout << "Test Case 3: List with 1 node [1]" << endl;
        vector<int> values = {1};
        ListNode* head = createList(values);
        cout << "List: ";
        printList(head);
        cout << endl;
        
        ListNode* middle = sol.middleNode(head);
        cout << "Middle node value: " << middle->val << endl;
        cout << "Expected: 1" << endl;
        
        deleteList(head);
    }
    
    return 0;
}