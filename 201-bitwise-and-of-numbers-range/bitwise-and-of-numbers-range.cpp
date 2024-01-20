class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
       
        while(left!=right)
        {
            right=right>>1;
            left=left>>1;
            count++;
        }

        right=right<<count;
        

        
        return right;
        
    }
};