class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int count =0;
        int maxi = 0;
        for(auto m:mp)
        {
            maxi = max(maxi, m.second);
        }
        for(auto m:mp)
        {
            if(m.second== maxi)
            {
                count++;
            }
        }
        return maxi*count;
    }
};