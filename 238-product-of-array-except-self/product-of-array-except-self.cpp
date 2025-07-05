class Solution {
public:
    //(Using extra space)
    // T.C : O(n)
    // S.C : O(n)
    // cal product of without itself for right and left and then take product
    // for each index and add into res 1  1  2  6 24 12 4  1
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        // left side product
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        // right side product
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};