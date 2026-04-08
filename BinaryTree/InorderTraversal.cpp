#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// Helper function to create a binary tree from array representation
TreeNode* createTree(const vector<int>& values, int index = 0) {
    if(index >= values.size() || values[index] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    
    return root;
}

// Helper function to delete tree (free memory)
void deleteTree(TreeNode* root) {
    if(root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1: Normal binary tree
    {
        cout << "Test Case 1: Normal binary tree [1, null, 2, 3]" << endl;
        // Tree:    1
        //           \
        //            2
        //           /
        //          3
        TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(3);
        
        vector<int> result = sol.inorderTraversal(root);
        
        cout << "Inorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: [1, 3, 2]" << endl << endl;
        
        deleteTree(root);
    }
    
    // Test Case 2: Empty tree
    {
        cout << "Test Case 2: Empty tree" << endl;
        TreeNode* root = nullptr;
        
        vector<int> result = sol.inorderTraversal(root);
        
        cout << "Inorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: []" << endl << endl;
    }
    
    // Test Case 3: Single node tree
    {
        cout << "Test Case 3: Single node tree [1]" << endl;
        TreeNode* root = new TreeNode(1);
        
        vector<int> result = sol.inorderTraversal(root);
        
        cout << "Inorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: [1]" << endl;
        
        deleteTree(root);
    }
    
    return 0;
}