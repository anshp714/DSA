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
    void postorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
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
    
    // Test Case 1: Normal binary tree [1, null, 2, 3]
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
        
        vector<int> result = sol.postorderTraversal(root);
        
        cout << "Postorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: [3, 2, 1]" << endl << endl;
        
        deleteTree(root);
    }
    
    // Test Case 2: Empty tree
    {
        cout << "Test Case 2: Empty tree" << endl;
        TreeNode* root = nullptr;
        
        vector<int> result = sol.postorderTraversal(root);
        
        cout << "Postorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: []" << endl << endl;
    }
    
    // Test Case 3: Full binary tree
    {
        cout << "Test Case 3: Full binary tree [1, 2, 3]" << endl;
        // Tree:    1
        //         / \
        //        2   3
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        
        vector<int> result = sol.postorderTraversal(root);
        
        cout << "Postorder traversal: ";
        printVector(result);
        cout << endl;
        cout << "Expected: [2, 3, 1]" << endl;
        
        deleteTree(root);
    }
    
    return 0;
}