class Solution {
public:

    string count(string count, string num){
        return count+num;
    }


    string countAndSay(int n) {
        string ans ="1";
        if(n==1)
        {
            return ans;
        }
         while (--n) { 
            string temp = ans;
            ans = ""; 
            int counter = 1; 
            for (int i = 0; i < temp.size(); i++) {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                    counter++;
                } else {
                    ans = ans + count(to_string(counter), string(1, temp[i]));
                    counter = 1; 
                }
            }
        }
        
        return ans;
    }
};