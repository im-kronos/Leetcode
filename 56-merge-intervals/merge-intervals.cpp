class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>>ans;

        for(auto &interval:intervals)
        {
            if(ans.empty() || ans.back()[1]< interval[0])
            ans.push_back(interval);
            else
            ans.back()[1]=max(ans.back()[1],interval[1]);
        }

        return ans;


        
    }
};