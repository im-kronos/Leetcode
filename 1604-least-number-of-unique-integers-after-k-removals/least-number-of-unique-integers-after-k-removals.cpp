class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto &i:arr)
        {
            m[i]++;
        }
        vector<pair<int,int>> p;
        for(auto &j:m)
        {
            p.push_back({j.second,j.first});
        }
        sort(p.begin(),p.end());
        int i;
        for(i=0;i<p.size();++i)
        {
            if(p[i].first<=k)
            {
                k-=p[i].first;
            }
            else
            {
                break;
            }
        }
        return p.size()-i;
    }
};