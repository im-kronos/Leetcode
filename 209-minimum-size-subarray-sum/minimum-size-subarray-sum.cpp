class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=0;
        int e=0;
        int curr_sum=nums[0];
        int l=INT_MAX;
        int n=nums.size();
/*
        while(s<e)
        {
            
            if(curr_sum<target)
            {
                e++;
                curr_sum=curr_sum+nums[e];
                continue;
            }
            else
            if(curr_sum>target)
            {
                curr_sum=curr_sum-nums[s];
                s++;
            
            }

            if(curr_sum==target)
            {
                l=min(e-s+1,l);
                curr_sum=curr_sum-nums[s];
                s++;
                
            }


        }
        return l;
        */

       int ans=INT_MAX;
       int window;
       
        while(e<n)
        {
            if(curr_sum<target)
            {
                e++;
                if(e==n)
                break;

                curr_sum+=nums[e];
                continue;
            }
            else if(curr_sum>=target)
            {
                window=(e-s+1);
                ans=min(ans,window);
            }
            curr_sum-=nums[s];
            s++;
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
        
    }

};