class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cumulativeSum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];
            int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            if (mp.count(remainder)) {
                if (i - mp[remainder] > 1) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};