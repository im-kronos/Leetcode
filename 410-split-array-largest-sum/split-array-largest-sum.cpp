class Solution {
public:

    bool check(const vector<int>& nums, int k, int gap) {
        int count = 1;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (current_sum + nums[i] > gap) {
                current_sum = nums[i];
                count++;
                if (count > k) {
                    return false;
                }
            } else {
                current_sum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
