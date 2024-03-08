class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto i:nums)
        {
            map[i]++;
        }
        vector<int>freq;
        int maxi=-1;
        int ans;
        for(auto n:map)
        {
             if(maxi<n.second)
            {
                maxi=n.second;
                ans=maxi;
            } 
            else
            if(maxi==n.second)
            {
                ans+=maxi;
            }
        
           
        }
            
          return ans;  
        
    }
};