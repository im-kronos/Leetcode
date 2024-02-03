class Solution {
public:

   bool check(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
       if (i == s.length() && j == p.length()) {
           return true;
       }
       if (dp[i][j] != -1) {
           return dp[i][j];
       }

       bool ans = false;
       if (i < s.length() && j < p.length() && (s[i] == p[j] || p[j] == '?')) {
           ans = check(s, p, i + 1, j + 1, dp);
       }
       if (j < p.length() && p[j] == '*') {
           ans = (i < s.length() ? check(s, p, i + 1, j, dp) : false) || (check(s, p, i, j + 1, dp));
       }
       return dp[i][j] = ans;
   }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return check(s, p, 0, 0, dp);
    }
};