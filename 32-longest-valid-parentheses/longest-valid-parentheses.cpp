class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> st;
        st.push(-1);
        int max_len = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    max_len = max(max_len,i-st.top());
                }
            }
        }
        return max_len;
    }
};