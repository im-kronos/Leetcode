class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return backtrack(s, 0, memo);
    }
    
    int backtrack(const string& s, int index, vector<int>& memo) {
        if (index == s.size()) {
            return 1; // Found a valid decoding
        }
        
        if (s[index] == '0') {
            return 0; // Cannot decode a leading zero
        }
        
        if (memo[index] != -1) {
            return memo[index]; // Return memoized result if available
        }
        
        int ways = backtrack(s, index + 1, memo); // Decode a single digit
        
        if (index + 1 < s.size() && isValidTwoDigits(s, index)) {
            ways += backtrack(s, index + 2, memo); // Decode two digits if possible
        }
        
        memo[index] = ways; // Memoize the result
        return ways;
    }
    
    bool isValidTwoDigits(const string& s, int index) {
        int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
        return num >= 10 && num <= 26;
    }
};
