class Solution {
public:

    int helper(string &s1, string &s2 , int i ,int j, vector<vector<int>>&dp)
    {
        if (i < 0 || j < 0) return 0;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

         if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + helper(s1, s2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = max(helper(s1, s2, i, j - 1, dp),helper(s1, s2, i - 1, j, dp));
        }
    }


    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return helper(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};