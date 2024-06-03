class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>profit(3,vector<int>(n+1,0));
        for(int i=1;i<=2;i++)
        {
            int maxP=INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxP=max(maxP,profit[i-1][j-1]-prices[j-1]);
                profit[i][j]=max(profit[i][j-1],maxP+prices[j]);
            }

        }
         return profit[2][n-1];
    }
       
};