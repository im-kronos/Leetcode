class Solution {
public:
    vector<string> keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;  // Added declaration of ans vector

    void generateAllString(string input, int i, string out) {
        if (i == input.size()) {
            ans.push_back(out);
            return;
        }
        int digit = input[i] - '0';
        if (digit == 0) return generateAllString(input, i + 1, out);
        for (char c : keypad[digit]) {
            generateAllString(input, i + 1, out + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if(digits.empty()) return out;  // Added check for empty input
        generateAllString(digits, 0, "");
        return ans;  // Returning ans vector instead of out
    }
};