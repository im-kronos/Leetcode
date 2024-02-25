class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string t=words[i];
            reverse(t.begin(),t.end());
            if(s==t)
            {
                return s;
                break;
            }
        }
        return "";
        
    }
};