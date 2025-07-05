class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string key=strs[i];
            sort(key.begin(),key.end());
            if(mp.find(key)!= mp.end())
            {
                mp[key].push_back(strs[i]); 
            }
            else
            {
            mp[key].push_back(strs[i]); 
            } 
        }

        for(auto mpx:mp)
        {
            ans.push_back(mpx.second);
        }

        return ans;
    }
};