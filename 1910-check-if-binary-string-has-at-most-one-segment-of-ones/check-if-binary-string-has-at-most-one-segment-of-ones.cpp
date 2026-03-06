class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size()==1 && s[0]=='1')
        {
            return true;
        } else if(s.size()==1 && s[0]=='0')
        {
            return false;
        }
        
        int flag =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1' && s[i+1]=='0' && flag == 0)
            {
                flag++;
                continue;
            }

            if(flag != 0 && s[i]=='1')
            {
                return false;
            }
        }
        return true;
        
    }
};