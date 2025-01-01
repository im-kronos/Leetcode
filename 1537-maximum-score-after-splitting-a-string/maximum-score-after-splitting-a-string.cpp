class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        int ans = 0;
        for (int i = 1; i < s.size(); i++) 
        {
            if (s[i] == '1') 
            {
            one++;
            }
        }

        int zero=0;
        for (int i = 1; i < s.size(); i++) 
        {
            if (s[i - 1] == '0') 
            {
            zero++; 
            }
            ans = max(ans, one + zero);
            if (s[i] == '1') 
            {
            one--;
            }
        }
        return ans;
    }
};