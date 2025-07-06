class Solution {
public:
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i == word1.size()) return word2.size() - j;  
        if (j == word2.size()) return word1.size() - i;  
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = helper(word1, word2, i + 1, j + 1, dp);
        }

        int insertOp = 1 + helper(word1, word2, i, j + 1, dp);
        int deleteOp = 1 + helper(word1, word2, i + 1, j, dp);
        int replaceOp = 1 + helper(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, 0, 0, dp);
    }
};
