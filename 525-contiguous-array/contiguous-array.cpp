class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                sum += -1;
            }
            else{
                sum += 1;
            } 
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            else{
                //std::cout<<sum<<" "<<i<<" "<<mp[sum]<<std::endl;
                ans = max(ans, i - mp[sum]);
            }
        }
        return ans;
    }
};