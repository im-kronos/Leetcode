class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        for(int i=0;i<32;i++)
        {
            int curr_sum=0;
            for(int j=0;j<nums.size();j++)
            {
               
               curr_sum = curr_sum+(nums[j]&1);  //add last no
               nums[j]=nums[j]>>1; //then update num 

            }
            curr_sum=curr_sum%3;  //3N+1
            ans=ans+(curr_sum<<i);   
        }

        return ans;
        
    }
};