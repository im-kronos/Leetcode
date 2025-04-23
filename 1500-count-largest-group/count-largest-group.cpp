class Solution {
public:
    int countLargestGroup(int n, int maxi = 0, int count = 0) {
        unordered_map <int,int> mp;
        for (int i = 1 ; i <= n ; i++) {
            int key = digsum(i);
            //increase the number of count in the map
            maxi = max(maxi, ++mp[key]);
        }
        for (auto& p : mp) 
        {
        if (p.second == maxi)
        {
           ++count;
        } 
        } 
        return count;
    }
    //for key
    int digsum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};