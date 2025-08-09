struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (!root) return 0;

    // If left subtree is NULL, recur for right subtree
    if (!root->left) return 1 + minDepth(root->right);

    // If right subtree is NULL, recur for left subtree
    if (!root->right) return 1 + minDepth(root->left);

    // If both children exist
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

