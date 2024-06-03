class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        for (char stone : stones) {
            mp[stone]++;
        }
        int sum = 0;
        for (char jewel : jewels) {
            sum += mp[jewel];
        }

        return sum;
    }
};
