class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
    int profit[k + 1][n + 1];
	for (int i = 0; i <= k; i++) {
	    profit[i][0] = 0;
	}
	for (int i = 0; i <= n; i++) {
		profit[0][i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		int prevMaxProfit = INT_MIN;
		for (int j = 1; j < n; j++) {
			prevMaxProfit = max(prevMaxProfit, profit[i - 1][j - 1] - prices[j - 1]);
			profit[i][j] = max(profit[i][j - 1], prices[j] + prevMaxProfit);
		}
	}
	return profit[k][n - 1];
        
    }
};