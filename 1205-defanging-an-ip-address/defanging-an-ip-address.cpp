class Solution {
public:
    string defangIPaddr(string address) {
        string add;
       
       for(char c:address)
       {
           if(c=='.')
           {
               add.push_back('[');
               add.push_back('.');
               add.push_back(']');
           }
           else
           {
               add.push_back(c);
           }
       }
       return add;
        
    }
};