/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> arr;
        if (root == nullptr) return arr; // ✅ check before calling
        printTree(root, arr);
        return arr;
    }
    private:
    void printTree(TreeNode* root, vector<int>& arr) 
   {
        // Inorder: Left → Root → Right
        if (root == nullptr) return; // ✅ safe check
        printTree(root->left, arr);
        arr.push_back(root->val);
        printTree(root->right, arr);
   }
};