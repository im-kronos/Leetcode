class Solution {
public:
    string customSortString(string order, string s) {
        string start = "";
        string end = "";
        unordered_map<char, int> mp;
        
        // Count occurrences of characters in s
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        
        // Construct start and end strings based on order
        for (int i = 0; i < order.length(); i++) {
            if (mp.find(order[i]) != mp.end()) {
                start += string(mp[order[i]], order[i]);
                mp.erase(order[i]); // Remove processed characters
            } else {
                end += order[i]; // Append characters not present in s
            }
        }
        
        // Construct remaining string from characters not present in order
        string remaining = "";
        for (char c : s) {
            if (mp.find(c) != mp.end()) {
                remaining += string(mp[c], c);
                mp.erase(c); // Remove processed characters
            }
        }
        
        // Uncomment the line below to print for debugging
        // cout << start << " " << end << " " << remaining << endl;
        
        return start + remaining;
    }
};
