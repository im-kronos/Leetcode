class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return {nums[0]};
        }
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>> pq;

        for(auto m : mp){
            pq.push(make_pair(m.second,m.first));
        }
        vector<int> res;

        for(int i =  0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        } 
        return res;
        
    }
};