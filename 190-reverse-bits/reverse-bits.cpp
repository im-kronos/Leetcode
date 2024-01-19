class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int num =0;
         for(int i=0;i<=31;i++)
         {
        // num=(num<<1)|(n&1);  // here we shift num 's bit to left + n's last bit
        // n=n>>1;  //update n

         num=(num<<1) | (n>>i)&1;

         }
  


        return num;
    }
};


