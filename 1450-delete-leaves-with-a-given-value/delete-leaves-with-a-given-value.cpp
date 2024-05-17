void remove_leaf_nodes(TreeNode*& root, int target) {
    if (root == nullptr) { return; }
    remove_leaf_nodes(root->left, target);
    remove_leaf_nodes(root->right, target);

    if (root->left != nullptr || root->right != nullptr) {
        return; // not a leaf node
    }
    if (root->val != target) {
        return; // value mismatch
    }
    root = nullptr;
}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove_leaf_nodes(root, target);
        return root;
    }
};