class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n)
        {
            n=n&(n-1);   //update n where there is rightmost 1 {using n&(n-1)}
            cnt++;
        }
        return cnt;
    }
};