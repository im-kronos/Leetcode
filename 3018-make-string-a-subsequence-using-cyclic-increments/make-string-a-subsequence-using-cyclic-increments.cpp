class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.length() > str1.length()) {
            return false;
        }
        
        int y = 0; 
        for (int i = 0; i < str1.length(); i++) {
            if (y < str2.length() && (str1[i] == str2[y] || str1[i] + 1 == str2[y] || (str1[i] == 'z' && str2[y] == 'a'))) {
                y++; 
            }
        }

        if(y == str2.length())
        {
            return true;
        }

        return false;;
    }
};