class Solution {
public:
    int solve(int n,int count,vector<int>&dp)
    {
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        if(dp[n]!=0)
        {
            return dp[n];
        }
        count+=solve(n-1,count,dp)+solve(n-2,count,dp);
        dp[n]=count;
        return count;
    }

    int climbStairs(int n) {
        int count=0;
        vector<int>dp(n+1,0);
        return solve(n,count,dp);
    }
};