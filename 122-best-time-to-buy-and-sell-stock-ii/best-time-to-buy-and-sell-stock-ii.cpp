class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int currP=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {
                currP+=(prices[i]-prices[i-1]);
            }
            maxP=max(currP,maxP);
        }
        return maxP;   
    }
};