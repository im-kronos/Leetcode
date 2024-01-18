class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n; // Total number of subsets is 2^n
    vector<vector<int>> ans;

    for (int i = 0; i < totalSubsets; ++i) {
        vector<int> currSubset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                currSubset.push_back(nums[j]);
            }
        }
        ans.push_back(currSubset);
    }

    return ans;
}

};