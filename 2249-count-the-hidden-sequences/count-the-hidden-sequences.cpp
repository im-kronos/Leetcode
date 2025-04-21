class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0;
        long long minnum = 0, maxnum = 0;

        for (int diff : differences) {
            prefix += diff;
            minnum = min(minnum, prefix);
            maxnum = max(maxnum, prefix);
        }

        long long minStart = lower - minnum;
        long long maxStart = upper - maxnum;

        if (minStart > maxStart) return 0;
        return (int)(maxStart - minStart + 1);
    }
};
