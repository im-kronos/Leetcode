#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) { 
            int j = i + k; 
            int count = 0;
            for (int t = 0; t < k - 1; t++) {
                if (nums[i + t + 1] > nums[i + t] && nums[j + t + 1] > nums[j + t]) {
                    count++;
                } else {
                    break;
                }
            }

            if (count == k - 1) {
                return true;
            }
        }

        return false;
    }
};
