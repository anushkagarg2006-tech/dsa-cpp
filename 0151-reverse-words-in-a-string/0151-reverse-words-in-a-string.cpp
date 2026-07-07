class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        
        // Step 1: Extract words and push to stack
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = ""; // Reset for next word
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            st.push(word); // Push the last word if exists
        }
        
        // Step 2: Pop from stack to reverse the order
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " "; // Add space between words
            }
        }
        
        return result;
    }
};