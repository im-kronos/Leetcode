class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i]) > 0 && mp[s[i]] >= left) {
                // Character seen before and within current substring
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i; // Update character position
            ans = max(ans, i - left + 1); // Update longest substring length
        }

        return ans;
    }
};