#include<string>
class Solution {
public:
    int minPartitions(string n) {
        
        vector<int>a;
        for(int i=0;i<n.length();i++)
        {
           a.push_back(int(n[i])-48);
           
        }

       return  *max_element(a.begin(), a.end());

    }
};