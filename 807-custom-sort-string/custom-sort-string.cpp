class Solution {
public:
    string customSortString(string order, string s) {
        string start = "";
        string end = "";
        unordered_map<char, int> mp;
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        

        for (int i = 0; i < order.length(); i++) {
            if (mp.find(order[i]) != mp.end()) {
                start += string(mp[order[i]], order[i]);
                mp.erase(order[i]); 
            } 
        }

        string remaining = "";
        for (char c : s) {
            if (mp.find(c) != mp.end()) {
                remaining += string(mp[c], c);
                mp.erase(c); 
            }
        }

        return start + remaining;
    }
};
