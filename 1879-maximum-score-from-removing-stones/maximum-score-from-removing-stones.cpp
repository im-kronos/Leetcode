class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=0;
    priority_queue<int>pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    
    while(pq.size()>=2)
    {
        int num1=pq.top();  
        pq.pop();
        int num2=pq.top();
        pq.pop();
        
        num1--;
        num2--;
        
        ans++;
        
        if(num1>0)
        pq.push(num1);
        
        if(num2>0)
        pq.push(num2);
    }
    
    return ans;
        
    }
};