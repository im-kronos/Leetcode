class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        addRow(root, val, depth, 1);
        return root;
    }

private:
    void addRow(TreeNode* root, int val, int depth, int currentDepth) {
        if (!root) return;
        
        if (currentDepth == depth - 1) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            
            leftNode->left = root->left;
            rightNode->right = root->right;
            
            root->left = leftNode;
            root->right = rightNode;
            
            return;
        }
        
        addRow(root->left, val, depth, currentDepth + 1);
        addRow(root->right, val, depth, currentDepth + 1);
    }
};
