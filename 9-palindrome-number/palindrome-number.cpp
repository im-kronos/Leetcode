class Solution {
public:
    bool isPalindrome(int x) {
        //t=x
        //y=x%10.  last digit
        //x=x/10. new x
        //rev=y+rev*10;

        int t=x;
        int y;
        long rev=0;
        while(x>0)
        {
            y=x%10;
            x=x/10;
            rev=y+(rev*10);
        }

        if(t==rev)
        {
            return true;
        }
        else
        {
            return false;
        }

        
    }
};