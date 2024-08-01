class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto det:details)
        {
        int age=(10*(det[11]-'0'))+(det[12]-'0');
        if(age>60)
        {
            count++;
        }
        }
        return count;
        
    }
};