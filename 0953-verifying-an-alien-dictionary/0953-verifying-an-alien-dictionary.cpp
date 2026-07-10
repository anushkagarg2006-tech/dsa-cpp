class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int freq[26] = {0};
        for (int i = 0; i < 26; i++) {
            freq[order[i] - 'a'] = i + 1;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string curr = words[i];
            string prev = words[i + 1];
            int p = 0;
            int f = 0;
            if (curr.length() > prev.length() && curr.substr(0, prev.length()) == prev) {
                return false;
            }
            int mini = min(curr.length(), prev.length());

            while (p < mini) {
                if (curr[p] == prev[f]) {
                    p++;
                    f++;
                } else if (freq[curr[p] - 'a'] < freq[prev[f] - 'a']) {
                    break;
                } else {
                    return false;
                }

            }
        }
        return true;
    }
};