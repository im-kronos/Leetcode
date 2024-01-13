class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        vector<int>pseven(nums.size(),0);
        vector<int>psodd(nums.size(),0);
        pseven[0]=nums[0];
        psodd[0]=0;
        for(int i=1;i<nums.size();i++)
        {
            if(i%2==1)
            {
            pseven[i]=pseven[i-1];
            psodd[i]=psodd[i-1]+nums[i]; 
            }
            else
            {
            pseven[i]=nums[i]+pseven[i-1];
            psodd[i]=psodd[i-1];
            }
        }
        int evenSum=0;
        int oddSum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0){
            evenSum=pseven[i-1]+(psodd[n-1]-psodd[i]);
            oddSum=psodd[i-1]+(pseven[n-1]-pseven[i]);
            }
            if(i == 0){
                evenSum = psodd[n-1]-psodd[i];
                oddSum=pseven[n-1]-pseven[i];
            }
            if(evenSum==oddSum)
            {
                cnt++;
            }

        }
        return cnt;
        
    }
};