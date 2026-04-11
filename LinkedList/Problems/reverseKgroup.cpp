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
    ListNode* reverse(ListNode* head) {
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* kNode(ListNode* temp, int k){
        while(temp != NULL && k > 1){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* kthNode = kNode(temp, k);

            if(kthNode == NULL){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if(temp == head){
                head = newHead;
            } else {
                prev->next = newHead;
            }

            prev = temp;
            temp = next;
        }

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
    
    // Test Case 1: k = 2
    {
        cout << "Test Case 1: Reverse in groups of 2" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        int k = 2;
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.reverseKGroup(head, k);
        
        cout << "After reversing in groups of " << k << ": ";
        printList(result);
        cout << endl;
        cout << "Expected: [2 -> 1 -> 4 -> 3 -> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 2: k = 3
    {
        cout << "Test Case 2: Reverse in groups of 3" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        int k = 3;
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.reverseKGroup(head, k);
        
        cout << "After reversing in groups of " << k << ": ";
        printList(result);
        cout << endl;
        cout << "Expected: [3 -> 2 -> 1 -> 4 -> 5]" << endl << endl;
        
        deleteList(result);
    }
    
    // Test Case 3: k = 1 (no change)
    {
        cout << "Test Case 3: Reverse in groups of 1" << endl;
        vector<int> values = {1, 2, 3, 4, 5};
        ListNode* head = createList(values);
        int k = 1;
        
        cout << "Original list: ";
        printList(head);
        cout << endl;
        
        ListNode* result = sol.reverseKGroup(head, k);
        
        cout << "After reversing in groups of " << k << ": ";
        printList(result);
        cout << endl;
        cout << "Expected: [1 -> 2 -> 3 -> 4 -> 5]" << endl;
        
        deleteList(result);
    }
    
    return 0;
}