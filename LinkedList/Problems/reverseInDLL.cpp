#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        ListNode* temp = nullptr;
        
        while (current != nullptr) {
            // Store previous pointer
            temp = current->prev;
            
            // Swap prev and next
            current->prev = current->next;
            current->next = temp;
            
            // Move to next node
            current = current->prev;
        }
        
        // temp->prev is the new head
        if (temp != nullptr) {
            return temp->prev;
        }
        return head;
    }
};

// Function to convert array to doubly linked list
ListNode* arrayToDLL(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    ListNode* prevNode = nullptr;
    
    for (size_t i = 1; i < arr.size(); i++) {
        ListNode* newNode = new ListNode(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    return head;
}

// Function to print DLL forward
void printDLLForward(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to print DLL backward
void printDLLBackward(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    
    // Go to the end
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // Print backwards
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << endl;
}

// Function to delete DLL and free memory
void deleteDLL(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to parse space-separated numbers from input
vector<int> parseInput(const string& input) {
    vector<int> result;
    stringstream ss(input);
    int num;
    
    while (ss >> num) {
        result.push_back(num);
    }
    
    return result;
}

// Function to run a single test case
void runTestCase(const vector<int>& arr, int testNumber) {
    cout << "\n=== Test Case " << testNumber << " ===" << endl;
    cout << "Input array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    // Convert array to DLL
    ListNode* head = arrayToDLL(arr);
    
    cout << "Original DLL (forward):  ";
    printDLLForward(head);
    
    cout << "Original DLL (backward): ";
    printDLLBackward(head);
    
    // Reverse the DLL
    Solution solution;
    ListNode* reversedHead = solution.reverseDLL(head);
    
    cout << "Reversed DLL (forward):  ";
    printDLLForward(reversedHead);
    
    cout << "Reversed DLL (backward): ";
    printDLLBackward(reversedHead);
    
    // Clean up
    deleteDLL(reversedHead);
    cout << "Memory freed for test case " << testNumber << endl;
}

int main() {
    cout << "=== Doubly Linked List Reversal Tester ===" << endl;
    cout << "Enter arrays of integers to test (space-separated numbers)" << endl;
    cout << "Type 'quit' to exit or 'demo' for demo test cases" << endl;
    
    string input;
    int testCaseNumber = 1;
    
    // Predefined test cases
    vector<vector<int>> predefinedTests = {
        {1, 2, 3, 4, 5},
        {10, 20, 30},
        {100},
        {},
        {5, 4, 3, 2, 1},
        {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}
    };
    
    // Test with user input
    while (true) {
        cout << "\n\nOptions:" << endl;
        cout << "1. Enter your own array" << endl;
        cout << "2. Run all predefined test cases" << endl;
        cout << "3. Run a specific predefined test case" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice (1-4): ";
        
        int choice;
        cin >> choice;
        cin.ignore(); // Clear newline
        
        if (choice == 1) {
            // User input
            cout << "\nEnter space-separated numbers for the array: ";
            getline(cin, input);
            
            if (input == "quit") {
                break;
            }
            
            vector<int> arr = parseInput(input);
            runTestCase(arr, testCaseNumber++);
        }
        else if (choice == 2) {
            // Run all predefined tests
            cout << "\n=== Running All Predefined Tests ===" << endl;
            for (size_t i = 0; i < predefinedTests.size(); i++) {
                runTestCase(predefinedTests[i], i + 1);
            }
        }
        else if (choice == 3) {
            // Run specific predefined test
            cout << "\nPredefined test cases:" << endl;
            for (size_t i = 0; i < predefinedTests.size(); i++) {
                cout << i + 1 << ". ";
                for (int num : predefinedTests[i]) {
                    cout << num << " ";
                }
                cout << endl;
            }
            cout << "Enter test case number (1-" << predefinedTests.size() << "): ";
            int testNum;
            cin >> testNum;
            cin.ignore();
            
            if (testNum >= 1 && testNum <= predefinedTests.size()) {
                runTestCase(predefinedTests[testNum - 1], testNum);
            } else {
                cout << "Invalid test case number!" << endl;
            }
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