class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

         int maxCount = 0;
    int majorityElement = 0;
    for (auto it : mp) {
        if (it.second > maxCount) {
            maxCount = it.second;
            majorityElement = it.first;
        }
    }
    return majorityElement;
    }   
       
    
};