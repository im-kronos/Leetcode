class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s)
        {
            mp[ch]++;
        }
        int sum=0;
        int flag=-1;
        for(auto m:mp)
        {
            if(m.second%2==0)
            {
                sum+=m.second;
            }
            else
            {
                sum+=m.second-1;
                flag++;
            }
        }
        if(flag!=-1)
        {
            sum=sum+1;
        }
        return sum;

        
        
    }
};