class Solution {
public:
    
    int changeCoinRec(int amount, vector<int>& coins,vector<int>&dp){
        if(amount==0)
            return 0;
        
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int ans=INT_MAX;
        for(auto coin:coins){
            if(amount-coin>=0){
                int subProb=changeCoinRec(amount-coin, coins,dp);
                if(subProb!=INT_MAX){
                    ans=min(ans, subProb+1);
                }
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=changeCoinRec(amount, coins,dp);
        return (ans==INT_MAX ? -1 : ans);
    }
};