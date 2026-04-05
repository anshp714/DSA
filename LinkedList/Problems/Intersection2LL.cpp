#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        while(temp1 != temp2) {
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};

// Helper function to create a linked list from array
ListNode* createList(const vector<int>& values) {
    if(values.empty()) return NULL;
    
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
    while(current != NULL) {
        cout << current->val;
        if(current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << "]";
}

// Helper function to delete linked list
void deleteList(ListNode* head) {
    while(head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper function to create intersection for testing
ListNode* createIntersectingLists(vector<int> listA, vector<int> listB, vector<int> common, int skipA, int skipB) {
    // Create first part of list A
    ListNode* headA = createList(listA);
    ListNode* headB = createList(listB);
    
    // Create common part
    ListNode* commonHead = createList(common);
    if(common.empty()) return NULL;
    
    // Find the node in list A where common part should attach
    ListNode* tempA = headA;
    for(int i = 0; i < skipA && tempA != NULL; i++) {
        if(i == skipA - 1) {
            tempA->next = commonHead;
            break;
        }
        tempA = tempA->next;
    }
    
    // Find the node in list B where common part should attach
    ListNode* tempB = headB;
    for(int i = 0; i < skipB && tempB != NULL; i++) {
        if(i == skipB - 1) {
            tempB->next = commonHead;
            break;
        }
        tempB = tempB->next;
    }
    
    return headA;
}

int main() {
    Solution sol;
    
    // Test Case 1: Lists intersect at node with value 8
    {
        cout << "Test Case 1: Intersecting lists" << endl;
        
        // Create common part: [8, 4, 5]
        ListNode* common = new ListNode(8);
        common->next = new ListNode(4);
        common->next->next = new ListNode(5);
        
        // Create list A: [4, 1, 8, 4, 5]
        ListNode* headA = new ListNode(4);
        headA->next = new ListNode(1);
        headA->next->next = common;
        
        // Create list B: [5, 6, 1, 8, 4, 5]
        ListNode* headB = new ListNode(5);
        headB->next = new ListNode(6);
        headB->next->next = new ListNode(1);
        headB->next->next->next = common;
        
        cout << "List A: ";
        printList(headA);
        cout << endl;
        cout << "List B: ";
        printList(headB);
        cout << endl;
        
        ListNode* intersection = sol.getIntersectionNode(headA, headB);
        
        if(intersection) {
            cout << "Intersection node value: " << intersection->val << endl;
            cout << "Expected: 8" << endl;
        } else {
            cout << "No intersection found" << endl;
        }
        cout << endl;
        
        // Clean up (need to be careful with shared nodes)
        deleteList(headA);
        // headB's nodes up to intersection are already deleted, so just delete remaining
        // For simplicity, we'll skip cleanup in this test
    }
    
    // Test Case 2: Lists do not intersect
    {
        cout << "Test Case 2: Non-intersecting lists" << endl;
        
        vector<int> listA = {2, 6, 4};
        vector<int> listB = {1, 5};
        
        ListNode* headA = createList(listA);
        ListNode* headB = createList(listB);
        
        cout << "List A: ";
        printList(headA);
        cout << endl;
        cout << "List B: ";
        printList(headB);
        cout << endl;
        
        ListNode* intersection = sol.getIntersectionNode(headA, headB);
        
        if(intersection) {
            cout << "Intersection node value: " << intersection->val << endl;
        } else {
            cout << "No intersection found (Expected)" << endl;
        }
        cout << endl;
        
        deleteList(headA);
        deleteList(headB);
    }
    
    // Test Case 3: Lists intersect at the very beginning
    {
        cout << "Test Case 3: Lists intersect at head" << endl;
        
        // Create common part: [1, 2, 3]
        ListNode* common = new ListNode(1);
        common->next = new ListNode(2);
        common->next->next = new ListNode(3);
        
        // Both lists start with the same node
        ListNode* headA = common;
        ListNode* headB = common;
        
        cout << "List A: ";
        printList(headA);
        cout << endl;
        cout << "List B: ";
        printList(headB);
        cout << endl;
        
        ListNode* intersection = sol.getIntersectionNode(headA, headB);
        
        if(intersection) {
            cout << "Intersection node value: " << intersection->val << endl;
            cout << "Expected: 1" << endl;
        } else {
            cout << "No intersection found" << endl;
        }
        
        deleteList(common);
    }
    
    return 0;
}