class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : a) {
            mp[num]++;
        }
        for (auto num : b) {
            mp[num]++;
        }
        for (auto& pair : mp) {
            if (pair.second >= 2) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};
