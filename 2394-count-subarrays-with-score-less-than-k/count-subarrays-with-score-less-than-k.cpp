class Solution {
public:

    long long func(vector<int>& nums, long long k, int i, int j, long long sum) {
        if (j == nums.size()) {
            return 0;
        }

        sum += nums[j];

        while (i <= j && sum * (j - i + 1) >= k) {
            sum -= nums[i];
            i++;
        }
        return (j - i + 1) + func(nums, k, i, j + 1, sum);
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        return func(nums, k, 0, 0, 0);
    }
};
