#include <vector>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        
        // Calculate total number of 1s in the array
        for (int num : nums) {
            totalOnes += num;
        }

        // Handle the special case where there are no 1s or all elements are 1s
        if (totalOnes == 0 || totalOnes == n) {
            return 0;
        }

        // Use a sliding window to find the maximum number of 1s in a window of size totalOnes
        int maxOnesInWindow = 0, currentOnes = 0;

        // Extend the window by concatenating the array with itself
        for (int i = 0; i < 2 * n; i++) {
            currentOnes += nums[i % n];
            if (i >= totalOnes) {
                currentOnes -= nums[(i - totalOnes) % n];
            }
            maxOnesInWindow = std::max(maxOnesInWindow, currentOnes);
        }

        // The minimum number of swaps is the number of 0s in the best window of size totalOnes
        return totalOnes - maxOnesInWindow;
    }
};
