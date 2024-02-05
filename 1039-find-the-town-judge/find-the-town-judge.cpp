class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> count;

        for (int i = 0; i < trust.size(); i++) {
            count[trust[i][1]]++;  // Use trust[i][1] to access the person being trusted
            count[trust[i][0]]--;  // Decrement count for the person doing the trusting
        }

        for (const auto& entry : count) {
            if (entry.second == (n - 1)) {  // Check if the count is (n-1)
                return entry.first;
            }
        }
        if(n==1)
        return 1;

        return -1;
        
    }
};
