
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        vector<int> ans;
        int i;
       
        for (i =0 ; i < nums.size(); i++) 
        {
            if (map.count(target - nums[i]) && map[target - nums[i]] != i) 
            {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};


