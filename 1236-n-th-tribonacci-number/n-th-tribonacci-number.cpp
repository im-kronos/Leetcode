class Solution {
public:
    int calc(int n,vector<int>& dp) {
    if (n <= 2) {
        return dp[n];
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = calc(n - 1, dp) + calc(n - 2, dp) + calc(n - 3, dp);
    
    return dp[n];
}
  
    int tribonacci(int n) {
        vector<int> dp(38, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return calc(n, dp);
    }
    

};
