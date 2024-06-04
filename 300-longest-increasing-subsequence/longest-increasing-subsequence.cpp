class Solution {
public:
    int lis(vector<int>& nums, int i, int prevIndex, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][prevIndex + 1] != -1) {
            return dp[i][prevIndex + 1];
        }
        
        int ans1 = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            ans1 = 1 + lis(nums, i + 1, i, dp);
        }
        
        int ans2 = lis(nums, i + 1, prevIndex, dp);
        
        return dp[i][prevIndex + 1] = max(ans1, ans2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lis(nums, 0, -1, dp);
    }
};
