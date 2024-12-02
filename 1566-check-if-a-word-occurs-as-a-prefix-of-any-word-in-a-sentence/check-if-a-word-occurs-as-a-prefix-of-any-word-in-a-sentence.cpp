class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>words;
        string word="";
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                words.push_back(word);
                word="";
            }
            else
            {
            word=word+sentence[i];
            }
        }
        words.push_back(word);
        word="";

        int s_l = searchWord.length();
        for(int i=0;i<words.size();i++)
        {
            word = words[i].substr(0,s_l);
            cout<<word<<endl;
            if(word == searchWord)
            return i+1;
        }

        return -1;
        
    }
};