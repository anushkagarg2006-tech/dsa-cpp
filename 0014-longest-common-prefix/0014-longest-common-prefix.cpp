class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        if (strs.size() == 1)
            return str;
        if (str == "")
            return str;
        for (int i = 1; i < strs.size(); i++) {
            string st = strs[i];
            int s = min(str.length(), st.length());
            if (s == 0)
                return "";
            int j=0;    
            for (j = 0; j < s; j++) {
                if (str[j] != st[j]) {
                    
                    break;
                }
            }str = str.substr(0, j );
        }
        return str;
    }
};