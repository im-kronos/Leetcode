class Solution {
public:
    vector<string> keypad{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void solve(string digits, int i, string word) {
        //base case if whole string in digits.size() ie the answer 
        //whatever comes has reched the last index so it will be the answer
        if(i == digits.length()) {
            ans.push_back(word);
            return;
        }
        
        // this will take each char form particular index of digits[index] and add to word
        for(char ch : keypad[digits[i] - '0']) {
            solve(digits, i + 1, word + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "");
        return ans;
    }
};
