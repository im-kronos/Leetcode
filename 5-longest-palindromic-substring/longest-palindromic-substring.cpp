class Solution {
public:
    string expand(int i, int j, string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string str1 = expand(i, i, s);
            if (str1.size() > ans.size()) {
                ans = str1;
            }

            string str2 = expand(i, i + 1, s);
            if (str2.size() > ans.size()) {
                ans = str2;
            }
        }

        return ans;
    }
};