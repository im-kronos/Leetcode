class Solution {
public:
    vector<int> memo;

    int subtree(vector<int>& nums, int left)
    {
        if (left >= nums.size())
            return 0;

        if (memo[left] != INT_MIN)
            return memo[left];

        int sum = 0;
        int ans = INT_MIN;

        

        for (int i = left; i < min((int)nums.size(), left + 3); i++)
        {
            sum += nums[i];
            ans = max(ans, sum - subtree(nums, i + 1));
        }

        return memo[left] = ans;
    }

    string stoneGameIII(vector<int>& nums)
    {
        memo.assign(nums.size(), INT_MIN);

        int diff = subtree(nums, 0);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};