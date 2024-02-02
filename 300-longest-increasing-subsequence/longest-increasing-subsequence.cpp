class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int n=1;n<nums.size();n++)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[n]>nums[i])
                {
                    dp[n]=max(dp[n],dp[i]+1);
                }
            }
        }

        sort(dp.rbegin(),dp.rend());
        return dp[0];
    }
};


/*
 we are asking previous elemnts how many elements are there which are less than the element

nums= 3 2 4 1 7 8 6 10 9
len=  1 1 1 1 1 1 1  1 1 

lower ones get added
3->1
2->1
4-> has 3 so 1+1=2
1->1
7-> has 4 so 2+1=3
8-> has 7 so 3+1=4
6-> has 4 so 2+1=3
10->has 8 so 4+1=5
9-> has 8 so 4+1=5
*/