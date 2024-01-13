class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> csum(nums.size(), 0);
        csum[0] = nums[0]; 

        for (int i = 1; i < nums.size(); i++) {
            csum[i] = nums[i] + csum[i - 1];
        }

        int Lsum = 0;
        int Rsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                Lsum = csum[i - 1];
            }

            Rsum = csum[nums.size() - 1] - csum[i];

            if (Lsum == Rsum)
                return i;
        }

        return -1;
    }
};
