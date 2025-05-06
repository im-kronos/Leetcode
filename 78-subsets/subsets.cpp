class Solution {
public:
    vector<vector<int>> rets;

    void backtrack(vector<int>& nums, int index, vector<int>& curr) {
        rets.push_back(curr);

        for (int i = index; i < nums.size(); ++i) {
            curr.push_back(nums[i]);              
            backtrack(nums, i + 1, curr);         
            curr.pop_back();                      
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        return rets;
    }
};
