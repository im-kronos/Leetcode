class Solution {
public:

    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {  
            //expand till palindrome
            left--;    
            right++;
        }
        //length of palindromic string
        return (right - 1) - (left + 1) + 1;
    }


    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        int len;
        
        for (int i = 0; i < s.size(); i++) 
        {
            // Expand around the single character center (odd length palindromes)
            int len1 = expandAroundCenter(s, i, i);
            // Expand around the space between two characters center (even length palindromes)
            int len2 = expandAroundCenter(s, i, i + 1);
            len = max(len1, len2);
            //to store the start and end of pointers
            if (len > end - start) //new highest maximum length
            {
                //explanation
                // if i=2 len=4 ie. abbbb
                //                    ^
                //.  new end= i+(len/2)
                //.  new start= i-(len-1)/2  

                start = i - (len - 1) / 2;    //we are going bacK.  new start<---start. (bigger len)
                end = i + len / 2;          //we are going forward.  end---->new end (bigger len)
            }
        }
        
        return s.substr(start,end-start+1);
    }
    

    
};
