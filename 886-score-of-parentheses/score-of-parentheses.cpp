class Solution {
public:
    int scoreOfParentheses(string s) {

        int score=0;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(score);
                score=0;
            }
            else
            {
                if(score==0)
                {
                    score=1;
                }
                else
                {
                    score*=2;
                }
                score+=st.top();
                st.pop();
            }
        }
        return score;
        
    }
};