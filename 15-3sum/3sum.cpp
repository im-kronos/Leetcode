class Solution {
public:
    // Function to find all unique triplets in the array that sum up to zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Vector to store the triplets

        // Sorting the input array to simplify the solution
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            // Initialize the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate elements to avoid duplicate triplets

            int j = i + 1; // Pointer for the second element of the triplet
            int k = nums.size() - 1; // Pointer for the third element of the triplet

            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet

                if (currentSum < 0) {
                    j++; // Move the second pointer to the right to increase the sum
                } else if (currentSum > 0) {
                    k--; // Move the third pointer to the left to decrease the sum
                } else {
                    // Found a triplet with sum zero
                    vector<int> temp = {nums[i], nums[j], nums[k]}; // Create a triplet vector
                    ans.push_back(temp); // Add the triplet to the result vector

                    j++; // Move the second pointer to the right
                    k--; // Move the third pointer to the left

                    // Skip duplicate elements to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans; // Return the vector containing all unique triplets
    }
};
