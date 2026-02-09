#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr || carry) {
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        return dummyHead->next;
    }
};

// Helper function to convert array to linked list (stored in reverse)
ListNode* arrayToList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    
    for (int num : arr) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    
    return dummy->next;
}

// Helper function to convert array to linked list (stored normally)
ListNode* arrayToNormalList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    return head;
}

// Helper function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    return prev;
}

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    cout << "Result: ";
    while (curr) {
        cout << curr->val;
        if (curr->next) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to print linked list in reverse (for verification)
void printListReverse(ListNode* head) {
    vector<int> values;
    ListNode* curr = head;
    
    while (curr) {
        values.push_back(curr->val);
        curr = curr->next;
    }
    
    cout << "Reversed: ";
    for (int i = values.size() - 1; i >= 0; i--) {
        cout << values[i];
        if (i > 0) cout << "";
    }
    cout << endl;
}

// Helper function to delete linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to parse input string to vector of integers
vector<int> parseInput(const string& input) {
    vector<int> result;
    stringstream ss(input);
    int num;
    
    while (ss >> num) {
        result.push_back(num);
    }
    
    return result;
}

// Test function for a single test case
void testAddTwoNumbers(const vector<int>& arr1, const vector<int>& arr2, int testNum) {
    cout << "\n=== Test Case " << testNum << " ===" << endl;
    
    // Convert arrays to linked lists (numbers stored in reverse)
    ListNode* l1 = arrayToList(arr1);
    ListNode* l2 = arrayToList(arr2);
    
    cout << "Number 1 (stored in reverse): ";
    printList(l1);
    
    cout << "Number 2 (stored in reverse): ";
    printList(l2);
    
    // Add the two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    cout << "Sum (stored in reverse): ";
    printList(result);
    
    // Print in actual number format for verification
    ListNode* reversedResult = reverseList(result);
    cout << "Actual sum (normal order): ";
    printList(reversedResult);
    
    // Clean up
    deleteList(l1);
    deleteList(l2);
    deleteList(reversedResult);
}

int main() {
    cout << "=== Add Two Numbers (Linked Lists) Tester ===" << endl;
    cout << "Note: Numbers are stored in reverse order in linked lists" << endl;
    cout << "Example: [2,4,3] represents 342" << endl;
    
    // Predefined test cases (LeetCode style)
    vector<pair<vector<int>, vector<int>>> testCases = {
        // Test Case 1: Basic addition
        {{2, 4, 3}, {5, 6, 4}},          // 342 + 465 = 807
        // Test Case 2: Different lengths
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}}, // 9999999 + 9999 = 10009998
        // Test Case 3: One empty list
        {{}, {1, 2, 3}},                 // 0 + 321 = 321
        // Test Case 4: Single digits
        {{5}, {5}},                      // 5 + 5 = 10
        // Test Case 5: Large numbers
        {{1}, {9, 9, 9, 9, 9, 9}},       // 1 + 999999 = 1000000
        // Test Case 6: Carry propagation
        {{9, 9, 9}, {1}},                // 999 + 1 = 1000
        // Test Case 7: Both empty
        {{}, {}},                        // 0 + 0 = 0
        // Test Case 8: Random numbers
        {{7, 8, 9}, {3, 2, 1}}           // 987 + 123 = 1110
    };
    
    int choice;
    
    while (true) {
        cout << "\n\n===== MENU =====" << endl;
        cout << "1. Run all predefined test cases" << endl;
        cout << "2. Run specific test case" << endl;
        cout << "3. Enter custom test case" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // Clear newline
        
        if (choice == 1) {
            // Run all test cases
            cout << "\n=== Running All Predefined Test Cases ===" << endl;
            for (size_t i = 0; i < testCases.size(); i++) {
                testAddTwoNumbers(testCases[i].first, testCases[i].second, i + 1);
            }
        }
        else if (choice == 2) {
            // Run specific test case
            cout << "\nAvailable test cases:" << endl;
            for (size_t i = 0; i < testCases.size(); i++) {
                cout << i + 1 << ". ";
                cout << "[";
                for (size_t j = 0; j < testCases[i].first.size(); j++) {
                    cout << testCases[i].first[j];
                    if (j < testCases[i].first.size() - 1) cout << ",";
                }
                cout << "] + [";
                for (size_t j = 0; j < testCases[i].second.size(); j++) {
                    cout << testCases[i].second[j];
                    if (j < testCases[i].second.size() - 1) cout << ",";
                }
                cout << "]" << endl;
            }
            
            cout << "Enter test case number (1-" << testCases.size() << "): ";
            int testNum;
            cin >> testNum;
            cin.ignore();
            
            if (testNum >= 1 && testNum <= testCases.size()) {
                testAddTwoNumbers(testCases[testNum - 1].first, 
                                 testCases[testNum - 1].second, 
                                 testNum);
            } else {
                cout << "Invalid test case number!" << endl;
            }
        }
        else if (choice == 3) {
            // Custom test case
            cout << "\n=== Custom Test Case ===" << endl;
            
            string input1, input2;
            
            cout << "Enter first number digits (space-separated, in reverse order): ";
            getline(cin, input1);
            vector<int> arr1 = parseInput(input1);
            
            cout << "Enter second number digits (space-separated, in reverse order): ";
            getline(cin, input2);
            vector<int> arr2 = parseInput(input2);
            
            // Convert to linked lists
            ListNode* l1 = arrayToList(arr1);
            ListNode* l2 = arrayToList(arr2);
            
            cout << "\nNumber 1 (reverse): ";
            printList(l1);
            cout << "Number 2 (reverse): ";
            printList(l2);
            
            // Perform addition
            Solution solution;
            ListNode* result = solution.addTwoNumbers(l1, l2);
            
            cout << "Sum (reverse): ";
            printList(result);
            
            // Calculate actual numbers for verification
            ListNode* reversedResult = reverseList(result);
            cout << "Actual sum: ";
            printList(reversedResult);
            
            // Clean up
            deleteList(l1);
            deleteList(l2);
            deleteList(reversedResult);
        }
        else if (choice == 4) {
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice! Please enter 1-4." << endl;
        }
    }
    
    return 0;
}