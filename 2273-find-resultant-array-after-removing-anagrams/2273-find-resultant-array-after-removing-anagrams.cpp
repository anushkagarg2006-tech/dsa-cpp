class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        if (words.size() == 1)
            return res;

        // Pehle word ki frequency map banayi
        unordered_map<char, int> m;
        for (char c : words[0]) {
            m[c]++;
        }
        
        string curr = words[0];

        for (int i = 1; i < words.size(); i++) {
            // AGAR LENGTH ALAG HAI -> Matlab anagram nahi ho sakte!
            // Toh ise result mein dalo aur map ko is naye word se reset karo.
            if (curr.length() != words[i].length()) {
                res.push_back(words[i]);
                curr = words[i];
                m.clear(); // Purana map saaf karo
                for (char c : curr) m[c]++;
                continue;
            }

            // Agar length same hai, toh check karo ki anagram hai ya nahi
            bool iss = true;
            unordered_map<char, int> temp_m = m; // Copy banayi taaki original map kharab na ho
            
            for (char ch : words[i]) {
                if (temp_m[ch] == 0) {
                    iss = false; // Character nahi mila ya frequency khatam ho gayi
                    break;
                }
                temp_m[ch]--;
            }

            // Agar anagram NAHI hai (!iss), toh ise result mein add karo
            if (!iss) {
                res.push_back(words[i]);
                curr = words[i];
                m.clear(); // Map ko naye current word se update karo
                for (char c : curr) {
                    m[c]++;
                }
            }
        }

        return res;
    }
};