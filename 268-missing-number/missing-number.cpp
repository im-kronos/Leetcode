class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tsum=0; 
        int rsum=0;
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            tsum+=i;
        }
        for(int i=0;i<n;i++)
        {
            rsum+=nums[i];
        }
        return tsum-rsum;
       
    }
        
};