class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // Iterate over each string in the input vector
        for(auto str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sort the characters of the string
            mp[sortedStr].push_back(str);  // Map the sorted string to its original string
        }
        
        vector<vector<string>> ans;
        // Iterate over each key-value pair in the map
        for(auto ch : mp) {
            ans.push_back(ch.second);  // Add the vector of original strings to the final result
        }
        
        return ans;
    }
};