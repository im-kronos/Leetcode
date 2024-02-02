class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int n=1;n<nums.size();n++)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[n]>nums[i])
                {
                    dp[n]=max(dp[n],dp[i]+1);
                }
            }
        }

        sort(dp.rbegin(),dp.rend());
        return dp[0];
    }
};