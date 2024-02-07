class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Count occurrences of each character
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        // Stack to store characters
        stack<char> st;
        unordered_set<char> inStack;

       // Iterate over each character in the string 's'
       for (char ch : s) {
       // Decrement occurrence count of current character
       mp[ch]--;

    // Skip characters already in the stack
    if (inStack.count(ch))
        continue;

    // Pop characters from the stack while the current character is smaller than the top of the stack
    // and there are remaining occurrences of the top character in the string
    while (!st.empty() && ch < st.top() && mp[st.top()] > 0) {
        // Remove the top character from the 'inStack' set
        inStack.erase(st.top());
        // Pop the top character from the stack
        st.pop();
    }

    // Push the current character onto the stack
    st.push(ch);
    // Add the current character to the 'inStack' set
    inStack.insert(ch);
    
}

        // Construct the result string from the stack
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};