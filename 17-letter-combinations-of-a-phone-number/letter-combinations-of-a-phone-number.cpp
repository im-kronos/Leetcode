class Solution {
public:
    vector<string> keypad{" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        for(auto t:keypad[digits[0]-'0']){
            string s(1, t); 
            ans.push_back(s);
        }

        for(int i=1;i<digits.size();i++) {
            vector<string>temp;
            for(auto t:keypad[digits[i]-'0'])
            {
                for(auto a:ans)
                {
                    temp.push_back(a+t);
                }
            }
            ans.clear();
            ans = temp;
        }
        return ans;
    }
};