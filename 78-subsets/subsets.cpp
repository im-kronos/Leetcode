class Solution {
public:
    void subsetsHelper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int index, int n) {
        if (index >= n) {
            ans.push_back(temp);
            return;
        }

        // Exclude 
        subsetsHelper(ans, nums, temp, index + 1, n);
        // Include 
        temp.push_back(nums[index]);
        subsetsHelper(ans, nums, temp, index + 1, n);
        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsHelper(ans, nums, temp, 0, nums.size());
        return ans;
    }
};
