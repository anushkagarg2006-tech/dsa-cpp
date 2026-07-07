class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {

            string s = words[i];
            string t = pattern;
            int mapST[256];
            int mapTS[256];

            // initialize arrays
            for (int i = 0; i < 256; i++) {
                mapST[i] = -1;
                mapTS[i] = -1;
            }
            bool iss = true;
            for (int i = 0; i < s.length(); i++) {
                char c1 = s[i];
                char c2 = t[i];

                // check mapping consistency
                if (mapST[c1] == -1 && mapTS[c2] == -1) {
                    mapST[c1] = c2;
                    mapTS[c2] = c1;
                } else if (mapST[c1] != c2 || mapTS[c2] != c1) {
                    iss = false;
                    break;
                }
            }
            if (iss)
                res.push_back(s);
        }

        return res;
    }
};