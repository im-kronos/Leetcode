class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>num(nums.begin(),nums.end());
        int ans=0;
        int start;
        for(auto x:num)
        {
            if(num.count(x-1)==0)
            start=x+1;
            int len=1;
            while(num.count(start)==true)
            {
                len++;
                start++;
            }
            ans=max(ans,len);
        }
        return ans;
        
    }    
    
};