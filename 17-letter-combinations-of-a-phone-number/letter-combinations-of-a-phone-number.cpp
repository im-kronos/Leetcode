class Solution {
public:
    vector<string> keypad{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void solve(string digits, int i, string word) {
        //base case if whole string in digits.size() gets over
        if(i == digits.length()) {
            ans.push_back(word);
            return;
        }

        for(char ch : keypad[digits[i] - '0']) {
            solve(digits, i + 1, word + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "");
        return ans;
    }
};
