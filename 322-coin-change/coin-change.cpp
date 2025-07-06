class Solution {
public:
    int helper(vector<int>& coins, int amount , vector<int>&dp) {
        if (amount == 0) return 0;  
        if (amount < 0) return INT_MAX;   
        if(dp[amount]!= -1)
        {
            return dp[amount];
        }  
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, amount - coin, dp);
            if (res != INT_MAX) {
                minCoins = dp[amount]=min(minCoins, 1 + res);
            }
        }

        return dp[amount]=minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(10001, -1);
        int result = helper(coins, amount,dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
