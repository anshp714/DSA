#include <iostream>
#include <vector>
using namespace std;

// Definition of doubly linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1) {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->val == target) {
                if(temp == head) {
                    head = head->next;
                }
                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;
                
                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;

                delete(temp);
                temp = nextNode;  
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Helper function to create doubly linked list from array
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for(int i = 1; i < values.size(); i++) {
        ListNode* newNode = new ListNode(values[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    return head;
}

// Helper function to print doubly linked list
void printList(ListNode* head) {
    cout << "[";
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val;
        if(current->next != nullptr) cout << " <-> ";
        current = current->next;
    }
    cout << "]";
}

// Helper function to delete entire list (free memory)
void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    
    // Test Case 1: Delete target from middle of list
    {
        cout << "Test Case 1: Delete target 2 from list" << endl;
        vector<int> values = {1, 2, 3, 2, 4, 2, 5};
        ListNode* head = createList(values);
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteAllOccurrences(head, 2);
        
        cout << "After deleting all 2's: ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 <-> 3 <-> 4 <-> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 2: Delete target from head
    {
        cout << "Test Case 2: Delete target from head" << endl;
        vector<int> values = {1, 1, 2, 3, 1, 4};
        ListNode* head = createList(values);
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteAllOccurrences(head, 1);
        
        cout << "After deleting all 1's: ";
        printList(result);
        cout << endl;
        cout << "Expected: [2 <-> 3 <-> 4]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 3: Delete all elements (list becomes empty)
    {
        cout << "Test Case 3: Delete all elements" << endl;
        vector<int> values = {5, 5, 5, 5};
        ListNode* head = createList(values);
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.deleteAllOccurrences(head, 5);
        
        cout << "After deleting all 5's: ";
        if(result == nullptr) {
            cout << "NULL (empty list)";
        } else {
            printList(result);
        }
        cout << endl;
        cout << "Expected: NULL (empty list)" << endl;
        
        if(result != nullptr) deleteList(result);
    }
    
    return 0;
}