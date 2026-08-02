class Solution {
public:
    vector<vector<vector<int>>> memo;

    int subtree(vector<int>& nums, int left, int right, bool player1)
    {
        if (left > right)
            return 0;

        if (memo[left][right][player1] != -1)
            return memo[left][right][player1];

        if (player1)
        {
            int takeLeft = nums[left] + subtree(nums, left + 1, right, false);
            int takeRight = nums[right] + subtree(nums, left, right - 1, false);

            return memo[left][right][player1] = max(takeLeft, takeRight);
        }
        else
        {
            int takeLeft = subtree(nums, left + 1, right, true);
            int takeRight = subtree(nums, left, right - 1, true);

            // Player 2 minimizes Player 1's eventual score
            return memo[left][right][player1] = min(takeLeft, takeRight);
        }
    }

    bool stoneGame(vector<int>& nums)
    {
        int n = nums.size();
        memo.assign(n,vector<vector<int>>(n, vector<int>(2, -1)));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int player1Score = subtree(nums, 0, n - 1, true);

        return player1Score > total - player1Score;
    }
};