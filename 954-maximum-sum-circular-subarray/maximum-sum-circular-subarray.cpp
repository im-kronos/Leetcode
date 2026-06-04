class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int totalSum = 0;
        int currmax , currmin =0;

        for(auto &x:nums)
        {
            totalSum+=x;
            currmax = max(x, x+currmax);
            maxSum = max(maxSum,currmax);

            currmin = min(x,currmin+x);
            minSum = min(minSum,currmin );
        }

        if(currmax<0) return maxSum;

        return max(maxSum , totalSum - minSum);
        
    }
};