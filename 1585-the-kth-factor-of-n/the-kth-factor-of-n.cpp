class Solution {
public:
    int kthFactor(int n, int k) {
        int check=0;
        int val;
      for(int i=1;i<=n;i++)
      {
         if(n%i==0)
         {
             val=i;
             check++;
             if(check==k)
             {
                 break;
             }
             else
             {
                 val=-1;
             }

         }
      } 
      return val; 
    }
};