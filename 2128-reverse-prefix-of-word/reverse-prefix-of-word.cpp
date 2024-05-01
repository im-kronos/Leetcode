class Solution {
public:
    string reversePrefix(string word, char ch) {
        int k=0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                for(int j=i;j>i/2;j--)
                {
                   swap(word[k++],word[j]);
                }
                break;
            }
        }
        return word;
    }
};