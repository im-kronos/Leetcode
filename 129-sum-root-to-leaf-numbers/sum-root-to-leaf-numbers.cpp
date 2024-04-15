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
    void dp(TreeNode* root, string currentPath, vector<string>& nums) {

        if (root == nullptr) return;
        currentPath += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            nums.push_back(currentPath);
            return;
        }

        dp(root->left, currentPath, nums);
        dp(root->right, currentPath, nums);
    }

    int sumNumbers(TreeNode* root) {
        vector<string> nums;
        dp(root, "", nums);

        int sum = 0;
        for (const string& num : nums) {
            sum += stoi(num);
        }

        return sum;
    }
};