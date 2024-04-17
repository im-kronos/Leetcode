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
    void traverse(TreeNode* root, string current, vector<string>& ans) {
        if (!root) return;
        current = char('a' + root->val) + current; // Prepend current character to the string
        if (!root->left && !root->right) { // If it's a leaf node
            ans.push_back(current);
            return;
        }
        traverse(root->left, current, ans);
        traverse(root->right, current, ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        vector<string> ans;
        traverse(root, "", ans);
        sort(ans.begin(), ans.end());
        return ans.empty() ? "" : ans[0];
    }
};