class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countzero=0;
        int productans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                countzero++;
            }
            else
            {
                productans*=nums[i];
            }
        }
        if(countzero>1)
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=0;
            }
        }
        else if(countzero==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                {
                nums[i]=0;
                }
                else
                {
                    nums[i]=productans;
                }
            }
        }
        else
        {
             for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                {
                nums[i]=productans/nums[i];
                }
                else
                {
                    nums[i]=productans;
                }
            }
        }

        return nums;
        }

};