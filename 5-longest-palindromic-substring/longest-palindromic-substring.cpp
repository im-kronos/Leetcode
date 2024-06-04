class Solution {
public:

    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }


    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Expand around the single character center (odd length palindromes)
            int len1 = expandAroundCenter(s, i, i);
            // Expand around the space between two characters center (even length palindromes)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    

    
};
