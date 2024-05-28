class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0;
        int current_cost = 0;
        int max_length = 0;

        for (int i = 0; i < n; i++) {
            current_cost += abs(s[i] - t[i]);

            while (current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                start++;
            }

            max_length = max(max_length, i - start + 1);
        }

        return max_length;
    }
};