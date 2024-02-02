class Solution {
public:
   int solve(string &s1, string &s2, int m, int n,vector<vector<int>>&dp) {
       // Base cases
       if (m == 0) {
           return n;
       }
       if (n == 0) {
           return m;
       }

       if(dp[m][n]!=-1)
       {
           return dp[m][n];
       }
       
       // If matching
       if (s1[m - 1] == s2[n - 1]) {
           return dp[m][n]= solve(s1, s2, m - 1, n - 1,dp);
       }
       
       // Three operations
       int op1 = dp[m][n]=1 + solve(s1, s2, m, n - 1,dp);
       int op2 = dp[m][n]= 1 + solve(s1, s2, m - 1, n - 1,dp);
       int op3 = dp[m][n]=1 + solve(s1, s2, m - 1, n,dp);
       
       return dp[m][n]=min(op1, min(op2, op3));
   }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        int ans = solve(word1, word2, word1.length(), word2.length(),dp);
        return ans;
    }
};