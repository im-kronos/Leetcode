class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        for (auto &domino : dominoes) {
            sort(domino.begin(), domino.end());
        }
        map<vector<int>, int> mp;
        for (const auto &domino : dominoes) {
            mp[domino]++;
        }
        for (const auto &m : mp) {
            if (m.second > 1) {
                count += (m.second * (m.second - 1)) / 2;
            }
        }

        return count;
    }
};
