class Solution {
public:
    static bool compare(pair<char,int>&a,pair<char,int>&b)
    {
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &t:s)
        {
            mp[t]++;    
        }
        vector<pair<char,int>>arr(mp.begin(),mp.end());
        sort(arr.begin(),arr.end(),compare);
        string ans="";
        for(auto &a:arr)
        {
            int temp=a.second;
            while(temp>0)
            {
                ans+=a.first;
                temp--;
            }
        }
        return ans;



        
    }
};