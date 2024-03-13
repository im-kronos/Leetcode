class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) {
            return 1;
        }
        int totalSum = (n * (n + 1)) / 2;  
        int leftSum = 0;
        for (int i = 1; i <= n; i++)
         {
            if (leftSum == totalSum - leftSum - i) 
            {
                return i;
            }
            leftSum += i;  
        }
        return -1;  
    }
};
