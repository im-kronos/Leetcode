class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto ch : s){
            if(st.empty())   st.push(ch);
            else{
                if(st.top()+32 == ch || st.top()-32 == ch)
                    st.pop();
                else
                    st.push(ch);
            }
        }
        string res;
        while(!st.empty()){
            res = st.top()+res;
            st.pop(); 
        }
        return res;
    }
};