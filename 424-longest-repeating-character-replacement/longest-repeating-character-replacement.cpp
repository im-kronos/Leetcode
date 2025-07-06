class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxlen = 0;
        int maxCount = 0;  // Max frequency of any character in current window
        unordered_map<char, int> count;  // Frequency map for current window
        
        for (int right = 0; right < s.length(); right++) {
            // Add current character to window
            count[s[right]]++;
            
            // Update maxCount (most frequent character in current window)
            maxCount = max(maxCount, count[s[right]]);
            
            // If window size - maxCount > k, we need to shrink the window
            // This means we need more than k replacements to make all characters same
            if (right - left + 1 - maxCount > k) {
                count[s[left]]--;
                left++;
            }
            
            // Update maximum length found so far
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};