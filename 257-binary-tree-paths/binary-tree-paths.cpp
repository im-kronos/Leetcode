class Solution
{
    public:
        void printleaves(TreeNode *root, vector<string> &paths, string s)
        {
            if (root == nullptr)
            {
                return;
            }

            s += to_string(root->val);

            if (root->left == nullptr && root->right == nullptr)
            {
                paths.push_back(s);
            }
            else
            {
                s += "->";
                if (root->left != NULL)
                    printleaves(root->left, paths, s);
                if (root->right != NULL)
                    printleaves(root->right, paths, s);
            }
        }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> paths;
        printleaves(root, paths, "");
        return paths;
    }
};