class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count_zero=0;
        int count_ones=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                count_zero++;
            }
            else
            {
                count_ones++;
            }
        }

        string ans;
        while(count_ones>1)
        {
            ans+="1";
            count_ones--;
        }
        while(count_zero>0)
        {
            ans=ans+"0";
            count_zero--;

        }
        if(count_ones>0)
        {
            ans+="1";

        }
        return ans;
    
    }
};