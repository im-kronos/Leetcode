class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        if(nums[0]!=0)
        {
            return 0;
        }
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                return nums[i]-1;
            }
        }
        return nums[i-1]+1;
    }
        
};