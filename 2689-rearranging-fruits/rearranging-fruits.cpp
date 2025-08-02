class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        // Step 1: Frequency difference
        for (int val : basket1) freq[val]++;
        for (int val : basket2) freq[val]--;

        // Step 2: Check for odd frequency - not possible
        for (auto [val, count] : freq) {
            if (count % 2 != 0) return -1;
        }

        // Step 3: Create mismatch baskets
        vector<int> b1_excess, b2_excess;
        for (auto [val, count] : freq) {
            if (count > 0) {
                for (int i = 0; i < count / 2; ++i) b1_excess.push_back(val);
            } else if (count < 0) {
                for (int i = 0; i < -count / 2; ++i) b2_excess.push_back(val);
            }
        }

        // Step 4: Sort excess baskets
        sort(b1_excess.begin(), b1_excess.end());
        sort(b2_excess.begin(), b2_excess.end(), greater<int>()); // reverse for optimal cost

        // Step 5: Find minimum element overall
        int global_min = INT_MAX;
        for (int val : basket1) global_min = min(global_min, val);
        for (int val : basket2) global_min = min(global_min, val);

        // Step 6: Compute minimum swap cost
        long long min_cost = 0;
        for (int i = 0; i < b1_excess.size(); i++) {
            int a = b1_excess[i];
            int b = b2_excess[i];
            min_cost += min({a, b, 2 * global_min});
        }

        return min_cost;
    }
};
