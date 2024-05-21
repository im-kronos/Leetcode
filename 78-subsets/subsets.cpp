class Solution {
public:
    void subset_maker(vector<int>& nums, int i, vector<int>& current, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(current);
            return;
        }
        

        subset_maker(nums, i + 1, current, ans);

        current.push_back(nums[i]);
        subset_maker(nums, i + 1, current, ans);
        current.pop_back(); 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        subset_maker(nums, 0, current, ans);
        return ans;
    }
};
