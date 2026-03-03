class Solution {
public:
    unordered_map<int, string> mp;

    string reverseStr(string num)
    {
        reverse(num.begin(), num.end());
        return num;
    }

    string inverse(string num)
    {
        for(int i = 0; i < num.size(); i++)
        {
            if(num[i] == '0')
                num[i] = '1';
            else
                num[i] = '0';
        }
        return num;
    }

    char findKthBit(int n, int k) {

        mp[1] = "0";

        for(int i = 2; i <= n; i++)
        {
            mp[i] = mp[i-1] + "1" + reverseStr(inverse(mp[i-1]));
        }

        return mp[n][k-1];
    }
};