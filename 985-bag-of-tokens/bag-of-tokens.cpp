class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int s=0;
        int l=0;
        int r=tokens.size()-1;
        int maxi=0;
        while(l<=r)
        {
            if(power>=tokens[l])
            {
                power-=tokens[l];
                l++;
                s++;
                maxi=max(s,maxi);
            }
            else if(s>0)
            {
                power+=tokens[r];
                s--;
                r--;
            }
            else
            {
                break;
            }

        }
        return maxi;
    }
};