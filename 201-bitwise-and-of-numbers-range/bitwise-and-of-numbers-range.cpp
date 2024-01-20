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
        right=right<<count;  //or left also
        return right;
        
    }
};
/* here the logic is 

from 1 to 3
          0 0 1
          0 1 0
          0 1 1
      --------------
        0 th pos is fixed while 0 and 1 pos is different
        so 0 0 0 will be ans 


        so key is to traverse till m=n while reducing its value 
        m=m>>1 n=n>>1.  then counting no of changes
        then adding that much 0 at the end of left or right 
        using left shift
        */
