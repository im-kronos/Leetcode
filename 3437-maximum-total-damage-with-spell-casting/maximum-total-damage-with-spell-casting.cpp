#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    unordered_map<int,long long> mp;
    vector<long long> keys, sums, memo;
    vector<int> nextIdx;

    long long func(int pos) {
        int m = keys.size();
        if (pos >= m) return 0;
        if (memo[pos] != LLONG_MIN) return memo[pos];

        // skip current
        long long ans = func(pos + 1);

        // take current and jump to next non-conflicting index
        long long take = sums[pos] + func(nextIdx[pos]);
        memo[pos] = max(ans, take);
        return memo[pos];
    }

    long long maximumTotalDamage(vector<int>& power) {
        mp.clear();
        for (int x : power) mp[x] += (long long)x; // total damage per distinct value

        vector<pair<long long,long long>> v;
        v.reserve(mp.size());
        for (auto &p : mp) v.emplace_back(p.first, p.second);
        sort(v.begin(), v.end());

        int m = v.size();
        keys.assign(m, 0);
        sums.assign(m, 0);
        for (int i = 0; i < m; ++i) {
            keys[i] = v[i].first;
            sums[i] = v[i].second;
        }

        nextIdx.assign(m, m);
        for (int i = 0; i < m; ++i) {
            int nxt = upper_bound(keys.begin() + i + 1, keys.end(), keys[i] + 2) - keys.begin();
            nextIdx[i] = nxt;
        }

        memo.assign(m, LLONG_MIN);
        return func(0);
    }
};