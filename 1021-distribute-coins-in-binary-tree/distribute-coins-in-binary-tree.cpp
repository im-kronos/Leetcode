class Solution {
public:
    int moves = 0;
    
    // Helper function to calculate the balance of coins at each node
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Calculate the balance for left and right subtrees
        int leftBalance = helper(root->left);
        int rightBalance = helper(root->right);
        
        // Total moves is the sum of absolute balances
        moves += abs(leftBalance) + abs(rightBalance);
        
        // Return the balance of coins for the current node
        return root->val + leftBalance + rightBalance - 1;
    }

    int distributeCoins(TreeNode* root) {
        helper(root);
        return moves;
    }
};
