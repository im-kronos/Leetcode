class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int k = 0; 
        
        for (int i = 0; i < s.length(); i++) {
            if (k < spaces.size() && spaces[k] == i) {
                ans.push_back(' '); 
                k++; 
            }
            ans.push_back(s[i]); 
        }
        
        return ans;
    }
};
