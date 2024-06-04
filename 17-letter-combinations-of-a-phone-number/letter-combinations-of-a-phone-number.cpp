class Solution {
public:
    vector<string>keypad{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    
    void solve(string digits,int i,string word)
    {
       if(i==digits.length())
       {
        ans.push_back(word);
        return;
       }

       int digit=digits[i]-'0';
       if(digit==0)
       {
        solve(digits,i+1,word);
       }
       for(char ch:keypad[digit])
       {
        solve(digits,i+1,word+ch);
       }

    }


    vector<string> letterCombinations(string digits) {
        if(digits=="")
        {
            return ans;
        }
        solve(digits,0,"");
        return ans;
    }
};