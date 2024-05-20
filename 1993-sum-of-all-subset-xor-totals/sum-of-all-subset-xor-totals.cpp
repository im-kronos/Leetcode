class Solution {
public:

    int subsets(vector<int>&nums,int level,int currentxor )
    {
        if(level==nums.size())
        {
            return currentxor;
        }
        int include=subsets(nums,level+1,currentxor^nums[level]);
        int exclude=subsets(nums,level+1,currentxor);
        return include+exclude;
    }

    int subsetXORSum(vector<int>& nums) {
      return subsets(nums,0,0);  
    }
};