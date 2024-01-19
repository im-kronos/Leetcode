class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n)
        {
            n=n&(n-1);   //update last 1 to 0 each time where there is rightmost 1 {using n&(n-1)}
            cnt++;
        }
        return cnt;
    }
};