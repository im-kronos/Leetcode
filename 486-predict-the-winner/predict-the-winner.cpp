class Solution {
public:
    int subtree(vector<int>& nums, int left, int right, int score, bool player1)
    {
        if (left > right)
            return score;

        if (player1)
        {
            int takeLeft = subtree(nums, left + 1, right,
                                   score + nums[left], false);

            int takeRight = subtree(nums, left, right - 1,
                                    score + nums[right], false);

            return max(takeLeft, takeRight);
        }
        else
        {
            int takeLeft = subtree(nums, left + 1, right,
                                   score, true);

            int takeRight = subtree(nums, left, right - 1,
                                    score, true);

            return min(takeLeft, takeRight);
        }
    }

    bool predictTheWinner(vector<int>& nums)
    {
        int total = 0;
        for (int x : nums)
            total += x;

        int player1Score = subtree(nums, 0, nums.size() - 1, 0, true);

        return player1Score >= total - player1Score;
    }
};